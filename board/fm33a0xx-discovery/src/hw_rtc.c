/*
 / _____)             _              | |
 ( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
 (______/|_____)_|_|_| \__)_____)\____)_| |_|
 (C)2013 Semtech

 Description: MCU RTC timer

 License: Revised BSD License, see LICENSE.TXT file include in the project

 Maintainer: Miguel Luis and Gregory Cristian
 */
/*******************************************************************************
 * @file    hw_rtc.c
 * @author  MCD Application Team
 * @version V1.1.1
 * @date    01-June-2017
 * @brief   driver for RTC
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V.
 * All rights reserved.</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted, provided that the following conditions are met:
 *
 * 1. Redistribution of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of other
 *    contributors to this software may be used to endorse or promote products
 *    derived from this software without specific written permission.
 * 4. This software, including modifications and/or derivative works of this
 *    software, must execute solely and exclusively on microcontroller or
 *    microprocessor devices manufactured by or for STMicroelectronics.
 * 5. Redistribution and use of this software other than as permitted under
 *    this license is void and will automatically terminate your rights under
 *    this license.
 *
 * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
 * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
 * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "hw.h"
#include "low_power.h"
#include "timeServer.h"

#define RTC_DEBUG_ENABLE                            1
#define RTC_DEBUG_DISABLE                           0

#define RTC_DEBUG_GPIO_STATE                        RTC_DEBUG_DISABLE
#define RTC_DEBUG_PRINTF_STATE                      RTC_DEBUG_DISABLE

#define MIN_ALARM_DELAY                             3 // in ticks

/*!
 * \brief Indicates if the RTC is already Initialized or not
 */
static bool RtcInitialized = false;
static volatile bool RtcTimeoutPendingInterrupt = false;
static volatile bool RtcTimeoutPendingPolling = false;

typedef enum AlarmStates_e
{
    ALARM_STOPPED = 0,
    ALARM_RUNNING = !ALARM_STOPPED
} AlarmStates_t;

/*!
 * RTC timer context 
 */
typedef struct
{
    uint32_t Time;  // Reference time
    uint32_t Delay; // Reference Timeout duration
    uint32_t AlarmState;
}RtcTimerContext_t;

/*!
 * Keep the value of the RTC timer when the RTC alarm is set
 * Set with the \ref RtcSetTimerContext function
 * Value is kept as a Reference to calculate alarm
 */
static RtcTimerContext_t RtcTimerContext;

#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
Gpio_t DbgRtcPin0;
Gpio_t DbgRtcPin1;
#endif

/*!
 * Used to store the Seconds and SubSeconds.
 * 
 * WARNING: Temporary fix fix. Should use MCU NVM internal
 *          registers
 */
uint32_t RtcBkupRegisters[] = { 0, 0 };

/*!
 * \brief Callback for the hw_timer when alarm expired
 */
static void RtcAlarmIrq( void );

/*!
 * \brief Callback for the hw_timer when counter overflows
 */
static void RtcOverflowIrq( void );

uint32_t RtcSetTimerContext( void );

void LPTIMER_init(void)
{
	LPTIM_InitTypeDef init_para;

	//使能LPTIMER的外设时钟
	RCC_PERCLK_SetableEx( LPTFCLK, 		DISABLE );		//LPTIM功能时钟使能
	RCC_PERCLK_SetableEx( LPTRCLK, 		DISABLE );		//LPTIM总线时钟使能
		RCC_PERCLK_SetableEx( LPTFCLK, 		ENABLE );		//LPTIM功能时钟使能
	RCC_PERCLK_SetableEx( LPTRCLK, 		ENABLE );		//LPTIM总线时钟使能
	

	init_para.LPTIM_TMODE = LPTIM_LPTCFG_TMODE_PWMIM;//设置工作模式为TIMEOUT
	init_para.LPTIM_MODE = LPTIM_LPTCFG_MODE_CONTINUE;//设置计数模式为连续计数模式

	init_para.LPTIM_PWM = LPTIM_LPTCFG_PWM_TOGGLE;//选择PWM输出模式
	init_para.LPTIM_POLAR = LPTIM_LPTCFG_POLARITY_POS;//产生输出波形上升沿
  init_para.LPTIM_target_value = 0xFFFF;

	init_para.LPTIM_TRIG_CFG = LPTIM_LPTCFG_TRIGCFG_POS;//外部输入信号上升沿trigger
	init_para.LPTIM_FLTEN = DISABLE;//使能数字滤波
	
	init_para.LPTIM_LPTIN_EDGE = LPTIM_LPTCFG_EDGESEL_POS;
	
	init_para.LPTIM_CLK_SEL = LPTIM_LPTCFG_CLKSEL_LSCLK;//选择外设时钟
	init_para.LPTIM_CLK_DIV = LPTIM_LPTCFG_DIVSEL_32;//32分频，如果PCLK为8M,则分频时钟为250k

	LPTIM_Init(&init_para);//初始化LPTIMER
  LPTIM_LPTCTRL_LPTEN_Setable(ENABLE);
  LPTIM_LPTIE_OVIE_Setable(ENABLE);
	//使能LPTIMER的外设中断
	NVIC_DisableIRQ(LPTIM_IRQn);
	NVIC_SetPriority(LPTIM_IRQn, 2);
	NVIC_EnableIRQ(LPTIM_IRQn);		
}

void HW_RTC_Init( void )
{
    if( RtcInitialized == false )
    {
#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
        GpioInit( &DbgRtcPin0, RTC_DBG_PIN_0, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 0 );
        GpioInit( &DbgRtcPin1, RTC_DBG_PIN_1, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 0 );
#endif
        // RTC timer
        LPTIMER_init( );
        RtcTimerContext.AlarmState = ALARM_STOPPED;
        RtcSetTimerContext( );
        RtcInitialized = true;
    }
}
uint32_t totalTicks=0;
  uint32_t  HwTimerGetTime(void)
{
  return totalTicks+LPTIM_LPTCNT_Read();
}

uint32_t RtcSetTimerContext( void )
{
    RtcTimerContext.Time = ( uint32_t )HwTimerGetTime( );
    return ( uint32_t )RtcTimerContext.Time;
}

uint32_t RtcGetTimerContext( void )
{
    return RtcTimerContext.Time;
}

uint32_t RtcGetMinimumTimeout( void )
{
    return( MIN_ALARM_DELAY );
}

uint32_t RtcMs2Tick( TimerTime_t milliseconds )
{
    return ( uint32_t )( milliseconds<<10 )/1000;
}

TimerTime_t RtcTick2Ms( uint32_t tick )
{
    uint32_t seconds = tick >> 10;

    tick = tick & 0x3FF;
    return ( ( seconds * 1000 ) + ( ( tick * 1000 ) >> 10 ) );
}
uint32_t RtcGetTimerValue( void );
void RtcDelayMs( TimerTime_t milliseconds )
{
    uint32_t delayTicks = 0;
    uint32_t refTicks = RtcGetTimerValue( );

    delayTicks = RtcMs2Tick( milliseconds );

    // Wait delay ms
    while( ( ( RtcGetTimerValue( ) - refTicks ) ) < delayTicks )
    {
        __NOP( );
    }
}
void RtcStartAlarm( uint32_t timeout );
void RtcSetAlarm( uint32_t timeout )
{
    RtcStartAlarm( timeout );
}

void RtcStopAlarm( void )
{
    RtcTimerContext.AlarmState = ALARM_STOPPED;
}
bool HwTimerLoadAbsoluteTicks(uint32_t ticks)
{
  if((ticks - HwTimerGetTime() - 1) >= (-1 >> 1)) {
        // if difference is more than half of max assume timer has passed
        return false;
    }
    if((ticks - HwTimerGetTime()) < 5) {
        // if too close the matching interrupt does not trigger, so handle same as passed
        return false;
    }
  if(ticks-HwTimerGetTime()<65536)
  {
    LPTIM_LPTCMP_Write(ticks&0xFFFF);
    LPTIM_LPTIE_COMPIE_Setable(ENABLE);
    PRINTF("alarm compset 1 :%d, all %d\r\n",ticks&0xFFFF, ticks);
  }
  return true;
}
void RtcStartAlarm( uint32_t timeout )
{
//    CRITICAL_SECTION_BEGIN( );

    RtcStopAlarm( );

    RtcTimerContext.Delay = timeout;

#if( RTC_DEBUG_PRINTF_STATE == RTC_DEBUG_ENABLE )
    printf( "TIMEOUT \t%010ld\t%010ld\r\n", RtcTimerContext.Time, RtcTimerContext.Delay );
#endif
#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
    GpioWrite( &DbgRtcPin0, 0 );
    GpioWrite( &DbgRtcPin1, 0 );
#endif

    RtcTimeoutPendingInterrupt = true;
    RtcTimeoutPendingPolling = false;

    RtcTimerContext.AlarmState = ALARM_RUNNING;
    if( HwTimerLoadAbsoluteTicks( RtcTimerContext.Time + RtcTimerContext.Delay ) == false )
    {
        // If timer already passed
        if( RtcTimeoutPendingInterrupt == true )
        {
            // And interrupt not handled, mark as polling
            RtcTimeoutPendingPolling = true;
            RtcTimeoutPendingInterrupt = false;
            TimerIrqHandler( );
#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
            GpioWrite( &DbgRtcPin0, 1 );
#endif
        }
    }
//    CRITICAL_SECTION_END( );
}

uint32_t RtcGetTimerValue( void )
{
    return ( uint32_t )HwTimerGetTime( );
}

uint32_t RtcGetTimerElapsedTime( void )
{
    return ( uint32_t)( HwTimerGetTime( ) - RtcTimerContext.Time );
}

uint32_t RtcGetCalendarTime( uint16_t *milliseconds )
{
    uint32_t ticks = 0;

    uint32_t calendarValue = HwTimerGetTime( );

    uint32_t seconds = ( uint32_t )calendarValue >> 10;

    ticks =  ( uint32_t )calendarValue & 0x3FF;

    *milliseconds = RtcTick2Ms( ticks );

    return seconds;
}

//void RtcBkupWrite( uint32_t data0, uint32_t data1 )
//{
//    CRITICAL_SECTION_BEGIN( );
//    RtcBkupRegisters[0] = data0;
//    RtcBkupRegisters[1] = data1;
//    CRITICAL_SECTION_END( );
//}

//void RtcBkupRead( uint32_t* data0, uint32_t* data1 )
//{
//    CRITICAL_SECTION_BEGIN( );
//    *data0 = RtcBkupRegisters[0];
//    *data1 = RtcBkupRegisters[1];
//    CRITICAL_SECTION_END( );
//}

//void RtcProcess( void )
//{
//    CRITICAL_SECTION_BEGIN( );

//    if( (  RtcTimerContext.AlarmState == ALARM_RUNNING ) && ( RtcTimeoutPendingPolling == true ) )
//    {
//        if( RtcGetTimerElapsedTime( ) >= RtcTimerContext.Delay )
//        {
//            RtcTimerContext.AlarmState = ALARM_STOPPED;

//            // Because of one shot the task will be removed after the callback
//            RtcTimeoutPendingPolling = false;
//#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
//            GpioWrite( &DbgRtcPin0, 0 );
//            GpioWrite( &DbgRtcPin1, 1 );
//#endif
//            // NOTE: The handler should take less then 1 ms otherwise the clock shifts
//            TimerIrqHandler( );
//#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
//            GpioWrite( &DbgRtcPin1, 0 );
//#endif
//        }
//    }
//    CRITICAL_SECTION_END( );
//}

TimerTime_t RtcTempCompensation( TimerTime_t period, float temperature )
{
    return period;
}

static void RtcAlarmIrq( void )
{
    RtcTimerContext.AlarmState = ALARM_STOPPED;
    // Because of one shot the task will be removed after the callback
    RtcTimeoutPendingInterrupt = false;
#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
    GpioWrite( &DbgRtcPin1, 1 );
#endif
    // NOTE: The handler should take less then 1 ms otherwise the clock shifts
    TimerIrqHandler( );
#if( RTC_DEBUG_GPIO_STATE == RTC_DEBUG_ENABLE )
    GpioWrite( &DbgRtcPin1, 0 );
#endif
}

void LPTIM_IRQHandler()
{
  if(LPTIM_LPTIF_OVIF_Chk()==SET)
  {
    totalTicks+=0x10000;//每次高16位加1
    if(RtcTimeoutPendingInterrupt==true)
    {
      if(( RtcTimerContext.Time + RtcTimerContext.Delay )-HwTimerGetTime()<65536)
      {
        
        {
          HwTimerLoadAbsoluteTicks( RtcTimerContext.Time + RtcTimerContext.Delay );
        }
      }
    }
    LPTIM_LPTIF_OVIF_Clr();
  }
  else if(LPTIM_LPTIF_COMPIF_Chk()==SET)//比较事件
  {
    LPTIM_LPTIF_COMPIF_Clr();
    LPTIM_LPTIE_COMPIE_Setable(DISABLE);
    
    RtcAlarmIrq();
    
    return ;
  }
  
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
