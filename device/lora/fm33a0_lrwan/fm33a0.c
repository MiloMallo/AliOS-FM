/*
 * Copyright (C) 2015-2018 Alibaba Group Holding Limited
 */

/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2013 Semtech

Description: SX1276 driver specific target board functions implementation

License: Revised BSD License, see LICENSE.TXT file include in the project

Maintainer: Miguel Luis and Gregory Cristian
*/
 /*******************************************************************************
  * @file    fm33a0.c
  * @author  FMSH Team
  * @version V0.0.0
  * @date    20-July-2018
  * @brief   driver LoRa module murata cmwx1zzabz-078
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2018 FMSH</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of FMSH nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/

#include "hw.h"
#include "radio.h"
#include "sx1276.h"
#include "fm33a0.h"
#include "delay.h"
#include "timeServer.h"
#include "soc.h"
#include "soc_init.h"



void GPIO_IRQHandler(void)
{
	#ifdef BLACK_BOARD
		if(SET == GPIO_EXTI_EXTIxIF_ChkEx(GPIOB, GPIO_Pin_13))
		{
			GPIO_EXTI_EXTIxIF_ClrEx(GPIOB, GPIO_Pin_13);
	    HW_GPIO_IrqHandler(0);
		}
	  	if(SET == GPIO_EXTI_EXTIxIF_ChkEx(GPIOB, GPIO_Pin_12))
		{
			GPIO_EXTI_EXTIxIF_ClrEx(GPIOB, GPIO_Pin_12);
	    HW_GPIO_IrqHandler(1);
		}
	  	if(SET == GPIO_EXTI_EXTIxIF_ChkEx(GPIOB, GPIO_Pin_15))
		{
			GPIO_EXTI_EXTIxIF_ClrEx(GPIOB, GPIO_Pin_15);
	    HW_GPIO_IrqHandler(2);
		}
	  	if(SET == GPIO_EXTI_EXTIxIF_ChkEx(GPIOB, GPIO_Pin_14))
		{
			GPIO_EXTI_EXTIxIF_ClrEx(GPIOB, GPIO_Pin_14);
	    HW_GPIO_IrqHandler(3);
		}
	#else
		if(SET == GPIO_EXTI_EXTIxIF_ChkEx(GPIOA, GPIO_Pin_0))
		{
			GPIO_EXTI_EXTIxIF_ClrEx(GPIOA, GPIO_Pin_0);
	    HW_GPIO_IrqHandler(0);
		}
	  	if(SET == GPIO_EXTI_EXTIxIF_ChkEx(GPIOA, GPIO_Pin_1))
		{
			GPIO_EXTI_EXTIxIF_ClrEx(GPIOA, GPIO_Pin_1);
	    HW_GPIO_IrqHandler(1);
		}
	  	if(SET == GPIO_EXTI_EXTIxIF_ChkEx(GPIOA, GPIO_Pin_2))
		{
			GPIO_EXTI_EXTIxIF_ClrEx(GPIOA, GPIO_Pin_2);
	    HW_GPIO_IrqHandler(2);
		}
	  	if(SET == GPIO_EXTI_EXTIxIF_ChkEx(GPIOA, GPIO_Pin_3))
		{
			GPIO_EXTI_EXTIxIF_ClrEx(GPIOA, GPIO_Pin_3);
	    HW_GPIO_IrqHandler(3);
		}
	#endif
}


#define IRQ_HIGH_PRIORITY  0

/* Delay in ms between radio set in sleep mode and TCXO off*/
#define TCXO_OFF_DELAY 3

#define TCXO_ON()   //HW_GPIO_Write( RADIO_TCXO_VCC_PORT, RADIO_TCXO_VCC_PIN, 1) 

#define TCXO_OFF()  //HW_GPIO_Write( RADIO_TCXO_VCC_PORT, RADIO_TCXO_VCC_PIN, 0) 

static void SX1276AntSwInit( void );
  
static void SX1276AntSwDeInit( void );

void SX1276SetXO( uint8_t state );

uint32_t SX1276GetWakeTime( void );

void SX1276IoIrqInit( DioIrqHandler **irqHandlers );

void SX1276_SetAntSw( uint8_t opMode );

uint8_t SX1276GetPaSelect( uint32_t channel );

void SX1276SetAntSwLowPower( bool status );

void SX1276SetRfTxPower( int8_t power );

void SX1276SetAntSw( uint8_t opMode );
/*!
 * \brief Controls the antena switch if necessary.
 *
 * \remark see errata note
 *
 * \param [IN] opMode Current radio operating mode
 */
static LoRaBoardCallback_t BoardCallbacks = { SX1276SetXO,
                                              SX1276GetWakeTime,
                                              SX1276IoIrqInit,
                                              SX1276SetRfTxPower,
                                              SX1276SetAntSwLowPower,
                                              SX1276SetAntSw};

/*!
 * Radio driver structure initialization
 */
const struct Radio_s Radio =
{
  SX1276IoInit,
  SX1276IoDeInit,
  SX1276Init,
  SX1276GetStatus,
  SX1276SetModem,
  SX1276SetChannel,
  SX1276IsChannelFree,
  SX1276Random,
  SX1276SetRxConfig,
  SX1276SetTxConfig,
  SX1276CheckRfFrequency,
  SX1276GetTimeOnAir,
  SX1276Send,
  SX1276SetSleep,
  SX1276SetStby, 
  SX1276SetRx,
  SX1276StartCad,
  SX1276SetTxContinuousWave,
  SX1276ReadRssi,
  SX1276Write,
  SX1276Read,
  SX1276WriteBuffer,
  SX1276ReadBuffer,
  SX1276SetSyncWord,
  SX1276SetMaxPayloadLength,
  SX1276GetRadioWakeUpTime
};

uint32_t SX1276GetWakeTime( void )
{
  return  BOARD_WAKEUP_TIME;
}

void SX1276SetXO( uint8_t state )
{

  if (state == SET )
  {
    TCXO_ON(); 
    
    DelayMs( BOARD_WAKEUP_TIME ); //start up time of TCXO
  }
  else
  {
    TCXO_OFF(); 
  }
}
void SX1276IoInit( void )
{
  #if 0 //使用hal层代码实现
    gpio_dev_t gpio_dev;
    
    gpio_dev.port = RADIO_DIO_0_PORT;
    gpio_dev.config = RADIO_DIO_0_CONFIG;
    hal_gpio_init(&gpio_dev);
    
    gpio_dev.port = RADIO_DIO_1_PORT;
    gpio_dev.config = RADIO_DIO_1_CONFIG;
    hal_gpio_init(&gpio_dev);
    
    gpio_dev.port = RADIO_DIO_2_PORT;
    gpio_dev.config = RADIO_DIO_2_CONFIG;
    hal_gpio_init(&gpio_dev);
    
    gpio_dev.port = RADIO_DIO_3_PORT;
    gpio_dev.config = RADIO_DIO_3_CONFIG;
    hal_gpio_init(&gpio_dev);
  #else //直接使用底层实现
    SX1276BoardInit( &BoardCallbacks );
  
    RCC_PERCLK_SetableEx(EXTI2CLK, ENABLE);		//EXTI外部引脚中断采样时钟，IO数字滤波时钟使能
    RCC_PERCLK_SetableEx(EXTI1CLK, ENABLE);		//EXTI外部引脚中断采样时钟，IO数字滤波时钟使能
    RCC_PERCLK_SetableEx(EXTI0CLK, ENABLE);		//EXTI外部引脚中断采样时钟，IO数字滤波时钟使能
    RCC_PERCLK_SetableEx(PDCCLK, ENABLE);		//IO控制时钟寄存器使能
	
    #ifdef BLACK_BOARD
	    InputIO( GPIOB, GPIO_Pin_13, 0);		//PB13; //KEY
	    InputIO( GPIOB, GPIO_Pin_12, 0);		//PB12; //KEY
	    InputIO( GPIOB, GPIO_Pin_15, 0);		//PB15; //KEY
	    InputIO( GPIOB, GPIO_Pin_14, 0);		//PB14; //KEY
        
	    //FM33A0XX的7组GPIO（A~G）最多可以产生24个外部引脚中断，部分IO不能同时开启中断功能
	    GPIO_EXTI_Init( GPIOB, GPIO_Pin_13, EXTI_RISING);	//PB13输入中断打开
	    GPIO_EXTI_Init( GPIOB, GPIO_Pin_12, EXTI_RISING);	//PB12输入中断打开
	    GPIO_EXTI_Init( GPIOB, GPIO_Pin_15, EXTI_RISING);	//PB15输入中断打开
	    GPIO_EXTI_Init( GPIOB, GPIO_Pin_14, EXTI_RISING);	//PB14输入中断打开
	#else
		InputIO( GPIOA, GPIO_Pin_0, 0);		//PA0; //KEY
	    InputIO( GPIOA, GPIO_Pin_1, 0);		//PA1; //KEY
	    InputIO( GPIOA, GPIO_Pin_2, 0);		//PA2; //KEY
	    InputIO( GPIOA, GPIO_Pin_3, 0);		//PA3; //KEY
        
	    //FM33A0XX的7组GPIO（A~G）最多可以产生24个外部引脚中断，部分IO不能同时开启中断功能
	    GPIO_EXTI_Init( GPIOA, GPIO_Pin_0, EXTI_RISING);	//PA0输入中断打开
	    GPIO_EXTI_Init( GPIOA, GPIO_Pin_1, EXTI_RISING);	//PA1输入中断打开
	    GPIO_EXTI_Init( GPIOA, GPIO_Pin_2, EXTI_RISING);	//PA2输入中断打开
	    GPIO_EXTI_Init( GPIOA, GPIO_Pin_3, EXTI_RISING);	//PA3输入中断打开
	#endif
	
    
      /*NVIC中断配置*/
    NVIC_DisableIRQ(GPIO_IRQn);
    NVIC_SetPriority(GPIO_IRQn,2);//中断优先级配置
    NVIC_EnableIRQ(GPIO_IRQn);
  #endif
}

void SX1276IoIrqInit( DioIrqHandler **irqHandlers )
{
  HW_GPIO_SetIrq( 0, irqHandlers[0] );
  HW_GPIO_SetIrq( 1, irqHandlers[1] );
  HW_GPIO_SetIrq( 2, irqHandlers[2] );
  HW_GPIO_SetIrq( 3, irqHandlers[3] );
}


void SX1276IoDeInit( void )
{
  #if 0 //使用hal层代码实现
    gpio_dev_t gpio_dev;
    
    gpio_dev.port = RADIO_DIO_0_PORT;
    gpio_dev.config = RADIO_DIO_0_CONFIG;
    hal_gpio_init(&gpio_dev);
    
    gpio_dev.port = RADIO_DIO_1_PORT;
    gpio_dev.config = RADIO_DIO_1_CONFIG;
    hal_gpio_init(&gpio_dev);
    
    gpio_dev.port = RADIO_DIO_2_PORT;
    gpio_dev.config = RADIO_DIO_2_CONFIG;
    hal_gpio_init(&gpio_dev);
    
    gpio_dev.port = RADIO_DIO_3_PORT;
    gpio_dev.config = RADIO_DIO_3_CONFIG;
    hal_gpio_init(&gpio_dev);
  #else //直接使用底层实现
    RCC_PERCLK_SetableEx(EXTI2CLK, DISABLE);		//EXTI外部引脚中断采样时钟，IO数字滤波时钟使能
    RCC_PERCLK_SetableEx(EXTI1CLK, DISABLE);		//EXTI外部引脚中断采样时钟，IO数字滤波时钟使能
    RCC_PERCLK_SetableEx(EXTI0CLK, DISABLE);		//EXTI外部引脚中断采样时钟，IO数字滤波时钟使能
    
    //FM33A0XX的7组GPIO（A~G）最多可以产生24个外部引脚中断，部分IO不能同时开启中断功能
	#ifdef BLACK_BOARD
	    GPIO_EXTI_Init( GPIOB, GPIO_Pin_13, EXTI_DISABLE);	//PB13输入中断关闭
	    GPIO_EXTI_Init( GPIOB, GPIO_Pin_12, EXTI_DISABLE);	//PB12输入中断关闭
	    GPIO_EXTI_Init( GPIOB, GPIO_Pin_15, EXTI_DISABLE);	//PB15输入中断关闭
	    GPIO_EXTI_Init( GPIOB, GPIO_Pin_14, EXTI_DISABLE);	//PB14输入中断关闭
	#else
		GPIO_EXTI_Init( GPIOA, GPIO_Pin_0, EXTI_DISABLE);	//PA0输入中断关闭
	    GPIO_EXTI_Init( GPIOA, GPIO_Pin_1, EXTI_DISABLE);	//PA1输入中断关闭
	    GPIO_EXTI_Init( GPIOA, GPIO_Pin_2, EXTI_DISABLE);	//PA2输入中断关闭
	    GPIO_EXTI_Init( GPIOA, GPIO_Pin_3, EXTI_DISABLE);	//PA3输入中断关闭
	#endif
    
      /*NVIC中断配置*/
    NVIC_DisableIRQ(GPIO_IRQn);
    NVIC_SetPriority(GPIO_IRQn,2);//中断优先级配置
    NVIC_DisableIRQ(GPIO_IRQn);
  #endif
}

void SX1276SetRfTxPower( int8_t power )
{
    uint8_t paConfig = 0;
    uint8_t paDac = 0;

    paConfig = SX1276Read( REG_PACONFIG );
    paDac = SX1276Read( REG_PADAC );

    paConfig = ( paConfig & RF_PACONFIG_PASELECT_MASK ) | SX1276GetPaSelect( SX1276.Settings.Channel );
    paConfig = ( paConfig & RF_PACONFIG_MAX_POWER_MASK ) | 0x70;

    if( ( paConfig & RF_PACONFIG_PASELECT_PABOOST ) == RF_PACONFIG_PASELECT_PABOOST )
    {
        if( power > 17 )
        {
            paDac = ( paDac & RF_PADAC_20DBM_MASK ) | RF_PADAC_20DBM_ON;
        }
        else
        {
            paDac = ( paDac & RF_PADAC_20DBM_MASK ) | RF_PADAC_20DBM_OFF;
        }
        if( ( paDac & RF_PADAC_20DBM_ON ) == RF_PADAC_20DBM_ON )
        {
            if( power < 5 )
            {
                power = 5;
            }
            if( power > 20 )
            {
                power = 20;
            }
            paConfig = ( paConfig & RF_PACONFIG_OUTPUTPOWER_MASK ) | ( uint8_t )( ( uint16_t )( power - 5 ) & 0x0F );
        }
        else
        {
            if( power < 2 )
            {
                power = 2;
            }
            if( power > 17 )
            {
                power = 17;
            }
            paConfig = ( paConfig & RF_PACONFIG_OUTPUTPOWER_MASK ) | ( uint8_t )( ( uint16_t )( power - 2 ) & 0x0F );
        }
    }
    else
    {
        if( power < -1 )
        {
            power = -1;
        }
        if( power > 14 )
        {
            power = 14;
        }
        paConfig = ( paConfig & RF_PACONFIG_OUTPUTPOWER_MASK ) | ( uint8_t )( ( uint16_t )( power + 1 ) & 0x0F );
    }
    SX1276Write( REG_PACONFIG, paConfig );
    SX1276Write( REG_PADAC, paDac );
}
uint8_t SX1276GetPaSelect( uint32_t channel )
{
    return RF_PACONFIG_PASELECT_PABOOST;//RF_PACONFIG_PASELECT_RFO;
}



void SX1276SetAntSwLowPower( bool status )
{
    if( status == false )
    {
      SX1276AntSwInit( );
    }
    else 
    {
      SX1276AntSwDeInit( );
    }
}

static void SX1276AntSwInit( void )
{
  #if 0
    GPIO_InitTypeDef initStruct={0};

    initStruct.Mode =GPIO_MODE_OUTPUT_PP;
    initStruct.Pull = GPIO_NOPULL; 
    initStruct.Speed = GPIO_SPEED_HIGH;
    
    HW_GPIO_Init( RADIO_ANT_SWITCH_PORT, RADIO_ANT_SWITCH_PIN, &initStruct  ); 
    HW_GPIO_Write( RADIO_ANT_SWITCH_PORT, RADIO_ANT_SWITCH_PIN, 0);
  //  
  //  HW_GPIO_Init( RADIO_ANT_SWITCH_PORT_TX_BOOST, RADIO_ANT_SWITCH_PIN_TX_BOOST, &initStruct  ); 
  //  HW_GPIO_Write( RADIO_ANT_SWITCH_PORT_TX_BOOST, RADIO_ANT_SWITCH_PIN_TX_BOOST, 0);
  //  
  //  HW_GPIO_Init( RADIO_ANT_SWITCH_PORT_TX_RFO, RADIO_ANT_SWITCH_PIN_TX_RFO, &initStruct  ); 
  //  HW_GPIO_Write( RADIO_ANT_SWITCH_PORT_TX_RFO, RADIO_ANT_SWITCH_PIN_TX_RFO, 0);
  #else //使用soc
    gpio_dev_t gpio_dev;
    
    gpio_dev.port = RADIO_ANT_SWITCH_PORT;
    gpio_dev.config = RADIO_ANT_SWITCH_CONFIG;
    
    hal_gpio_init(&gpio_dev);
    hal_gpio_output_low(&gpio_dev);
  #endif
}

static void SX1276AntSwDeInit( void )
{
  #if 0
    GPIO_InitTypeDef initStruct={0};

    initStruct.Mode = GPIO_MODE_ANALOG ;
    
    initStruct.Pull = GPIO_NOPULL;
    initStruct.Speed = GPIO_SPEED_HIGH;

    HW_GPIO_Init( RADIO_ANT_SWITCH_PORT, RADIO_ANT_SWITCH_PIN, &initStruct  ); 
    HW_GPIO_Write( RADIO_ANT_SWITCH_PORT, RADIO_ANT_SWITCH_PIN, 0);
    
  //  HW_GPIO_Init( RADIO_ANT_SWITCH_PORT_TX_BOOST, RADIO_ANT_SWITCH_PIN_TX_BOOST, &initStruct  ); 
  //  HW_GPIO_Write( RADIO_ANT_SWITCH_PORT_TX_BOOST, RADIO_ANT_SWITCH_PIN_TX_BOOST, 0);
  //  
  //  HW_GPIO_Init( RADIO_ANT_SWITCH_PORT_TX_RFO, RADIO_ANT_SWITCH_PIN_TX_RFO, &initStruct  ); 
  //  HW_GPIO_Write( RADIO_ANT_SWITCH_PORT_TX_RFO, RADIO_ANT_SWITCH_PIN_TX_RFO, 0);
  #else
    gpio_dev_t gpio_dev;
    
    gpio_dev.port = RADIO_ANT_SWITCH_PORT;
    gpio_dev.config = OUTPUT_OPEN_DRAIN_PULL_UP;
    
    hal_gpio_init(&gpio_dev);
    hal_gpio_output_low(&gpio_dev);
  #endif
}

void SX1276SetAntSw( uint8_t opMode )
{
  #if 0
    uint8_t paConfig =  SX1276Read( REG_PACONFIG );
    switch( opMode )
    {
      case RFLR_OPMODE_TRANSMITTER:
        HW_GPIO_Write( RADIO_ANT_SWITCH_PORT, RADIO_ANT_SWITCH_PIN, 0 );
        SX1276.RxTx = 1;
      break;
      case RFLR_OPMODE_RECEIVER:
      case RFLR_OPMODE_RECEIVER_SINGLE:
      case RFLR_OPMODE_CAD:
      default:
       SX1276.RxTx = 0;
       HW_GPIO_Write( RADIO_ANT_SWITCH_PORT, RADIO_ANT_SWITCH_PIN, 1 );
       break;
    }
  #else
    gpio_dev_t gpio_dev;
    uint8_t paConfig =  SX1276Read( REG_PACONFIG );
    
    gpio_dev.port = RADIO_ANT_SWITCH_PORT;
    gpio_dev.config = RADIO_ANT_SWITCH_CONFIG;  
    
    switch( opMode )
    {
      case RFLR_OPMODE_TRANSMITTER:
        hal_gpio_output_low(&gpio_dev);
        SX1276.RxTx = 1;
      break;
      case RFLR_OPMODE_RECEIVER:
      case RFLR_OPMODE_RECEIVER_SINGLE:
      case RFLR_OPMODE_CAD:
      default:
       SX1276.RxTx = 0;
       hal_gpio_output_high(&gpio_dev);
       break;
    }
  #endif
}





bool SX1276CheckRfFrequency( uint32_t frequency )
{
    // Implement check. Currently all frequencies are supported
    return true;
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
