/******************************************************************************
 * @file    vcom.c
 * @author  MCD Application Team
 * @version V1.1.1
 * @date    01-June-2017
 * @brief   manages virtual com port
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

#include "hw.h"
#include "vcom.h"
#include "hw_gpio.h"
#include <stdarg.h>
#include "low_power.h"

/* Force include of hal uart in order to inherite HAL_UART_StateTypeDef definition */

#include <k_api.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* based on UART_HandleTypeDef */
static struct
{
    char buffTx[256]; /**< buffer to transmit */
    char buffRx[256]; /**< Circular buffer of received chars */
    int rx_idx_free; /**< 1st free index in BuffRx */
    int rx_idx_toread; /**< next char to read in buffRx, when not rx_idx_free */
    HW_LockTypeDef Lock; /**< Locking object */

//    __IO HAL_UART_StateTypeDef gState; /**< UART state information related to global Handle management
//     and also related to Tx operations. */
//    __IO HAL_UART_StateTypeDef RxState; /**< UART state information related to Rx operations. */
} uart_context;

static char dbgTxBuff[256];

/* Private function prototypes -----------------------------------------------*/
/**
 * @brief  Transmit uart_context.buffTx from start to len - 1
 * @param  1st index to transmit
 * @param  Last index not to transmit
 * @return Last index not transmitted
 */
static int buffer_transmit( int start, int len );

/**
 * @brief  Takes one character that has been received and save it in uart_context.buffRx
 * @param  received character
 */
static void receive( char rx );

/* Functions Definition ------------------------------------------------------*/

extern uart_dev_t uart_0;

static int dbg_buffer_transmit( int start, int len )
{
  #if 0
    int i;
    for ( i = start; i < len; i++ )
    {
        LL_USART_ClearFlag_TC( USART4 );
        LL_USART_TransmitData8( USART4, dbgTxBuff[i] );

        while ( LL_USART_IsActiveFlag_TC( USART4 ) != SET )
        {
            ;
        }
    }
    LL_USART_ClearFlag_TC( USART4 );
    return len;
  #else
//    int i;
//    for ( i = start; i < len; i++ )
//    {
//        UARTx_TXREG_Write(VDBGUART, dbgTxBuff[i]);
//      while (UART_UARTIF_RxTxIF_ChkEx(VDBGUART, TxInt) == 0);
//    }
    hal_uart_send(&uart_0, &dbgTxBuff[start], len - start, len - start);
    return len;
  #endif
}

void DBG_Uart_Deinit( void )
{
  #if 0
    LL_USART_DeInit( USART4 );

    /*##-1- Reset peripherals ##################################################*/
    LL_APB1_GRP1_ForceReset( LL_APB1_GRP1_PERIPH_USART4 );
    LL_APB1_GRP1_ReleaseReset( LL_APB1_GRP1_PERIPH_USART4 );

    /*##-2- Disable peripherals and GPIO Clocks #################################*/
    /* Configure UART Tx as alternate function  */
    HW_GPIO_DeInit( GPIOA, GPIO_PIN_0 );
    /* Configure UART Rx as alternate function  */
    HW_GPIO_DeInit( GPIOA, GPIO_PIN_1 );

    /*##-3- Disable the NVIC for UART ##########################################*/
    NVIC_DisableIRQ( USART4_5_IRQn );
  #else
    //LL_USART_DeInit( USART4 );
    //串口恢复初始化
    UARTx_Deinit(VDBGUART);

    /*##-1- Reset peripherals ##################################################*/
//    LL_APB1_GRP1_ForceReset( LL_APB1_GRP1_PERIPH_USART4 );
//    LL_APB1_GRP1_ReleaseReset( LL_APB1_GRP1_PERIPH_USART4 );

    /*##-2- Disable peripherals and GPIO Clocks #################################*/
    /* Configure UART Tx as alternate function  */
//    HW_GPIO_DeInit( GPIOA, GPIO_PIN_0 );
    /* Configure UART Rx as alternate function  */
//    HW_GPIO_DeInit( GPIOA, GPIO_PIN_1 );
    CloseIO(VDBGRX_Port, VDBGRX_Pin);
    CloseIO(VDBGTX_Port, VDBGTX_Pin);    

    /*##-3- Disable the NVIC for UART ##########################################*/
//    NVIC_DisableIRQ( USART4_5_IRQn );
    NVIC_DisableIRQ( VDBG_IRQn );

  #endif
}

void Uartx_Init(UARTx_Type* UARTx)
{
	UART_SInitTypeDef UART_para;
	RCC_ClocksType RCC_Clocks;
	volatile uint8_t tmp08;
	
	RCC_PERCLK_SetableEx(UARTCOMCLK, ENABLE);	//UART0~5共享寄存器时钟使能
	
	tmp08 = ((uint32_t)UARTx - UART0_BASE)>>5;	//获取uart	
	switch(tmp08)
	{
		case 0:
			RCC_PERCLK_SetableEx(UART0CLK, ENABLE);	//UARTx时钟使能
			//	UART0 IO 配置
			AltFunIO(GPIOF, GPIO_Pin_3, 0);		//PF3 UART0 RX
			AltFunIO(GPIOF, GPIO_Pin_4, 0);		//PF4 UART0 TX
		
			/*NVIC中断配置*/
			NVIC_DisableIRQ(UART0_IRQn);
			NVIC_SetPriority(UART0_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(UART0_IRQn);	
			break;
		
		case 1:
			RCC_PERCLK_SetableEx(UART1CLK, ENABLE);	//UARTx时钟使能	
			//	UART1 IO 配置
			AltFunIO(GPIOB, GPIO_Pin_0, 0);		//PB0 UART1 RX
			AltFunIO(GPIOB, GPIO_Pin_1, 0);		//PB1 UART1 TX
			
			//AltFunIO(GPIOE, GPIO_Pin_3, 0);		//PE3 UART1 RX
			//AltFunIO(GPIOE, GPIO_Pin_4, 0);		//PE4 UART1 TX
		
			/*NVIC中断配置*/
			NVIC_DisableIRQ(UART1_IRQn);
			NVIC_SetPriority(UART1_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(UART1_IRQn);	
			break;
		
		case 2:
			RCC_PERCLK_SetableEx(UART2CLK, ENABLE);	//UARTx时钟使能	
			//	UART2 IO 配置
			AltFunIO(GPIOB, GPIO_Pin_2, 0);		//PB2 UART2 RX
			AltFunIO(GPIOB, GPIO_Pin_3, 0);		//PB3 UART2 TX	
		
			/*NVIC中断配置*/
			NVIC_DisableIRQ(UART2_IRQn);
			NVIC_SetPriority(UART2_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(UART2_IRQn);	
			break;
		
		case 3:
			RCC_PERCLK_SetableEx(UART3CLK, ENABLE);	//UARTx时钟使能	
			//	UART3 IO 配置
			AltFunIO(GPIOC, GPIO_Pin_10, 0);	//PC10 UART3 RX
			AltFunIO(GPIOC, GPIO_Pin_11, 0);	//PC11 UART3 TX
		
			/*NVIC中断配置*/
			NVIC_DisableIRQ(UART3_IRQn);
			NVIC_SetPriority(UART3_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(UART3_IRQn);	
			break;
		
		case 4:
			RCC_PERCLK_SetableEx(UART4CLK, ENABLE);	//UARTx时钟使能	
			//	UART4 IO 配置
			AltFunIO(GPIOD, GPIO_Pin_0, 0);		//PD0 UART4 RX
			AltFunIO(GPIOD, GPIO_Pin_1, 0);		//PD1 UART4 TX
			//仅100脚
			//AltFunIO(GPIOD, GPIO_Pin_9, 0);		//PD9 UART4 RX
			//AltFunIO(GPIOD, GPIO_Pin_10, 0);	//PD10 UART4 TX
		
			/*NVIC中断配置*/
			NVIC_DisableIRQ(UART4_IRQn);
			NVIC_SetPriority(UART4_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(UART4_IRQn);	
			break;
		
		case 5:
			RCC_PERCLK_SetableEx(UART5CLK, ENABLE);	//UARTx时钟使能	
			//	UART5 IO 配置
			AltFunIO(GPIOC, GPIO_Pin_4, 0);		//PC4 UART5 RX
			AltFunIO(GPIOC, GPIO_Pin_5, 0);		//PC5 UART5 TX	
		
			/*NVIC中断配置*/
			NVIC_DisableIRQ(UART5_IRQn);
			NVIC_SetPriority(UART5_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(UART5_IRQn);	
			break;
		
		default:
			break;
	}

	//UART初始化配置
	UART_para.BaudRate = 115200;			//波特率
	UART_para.DataBit = Eight8Bit;		//数据位数
	UART_para.ParityBit = EVEN;			//奇偶校验
	UART_para.StopBit = OneBit;			//停止位
	
	RCC_GetClocksFreq(&RCC_Clocks);//获取APB时钟频率
	UART_SInit(UARTx, &UART_para, RCC_Clocks.APBCLK_Frequency);	//初始化uart
}

void DBG_Uart_Init( void )
{
  #if 0
    LL_USART_InitTypeDef USART_InitStruct;

    LL_GPIO_InitTypeDef GPIO_InitStruct;

    DBG_Uart_Deinit( );
    /* Peripheral clock enable */
    LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_USART4 );

    /**USART4 GPIO Configuration
     PA0   ------> USART4_TX
     PA1   ------> USART4_RX
     */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_6;
    LL_GPIO_Init( GPIOA, &GPIO_InitStruct );

    GPIO_InitStruct.Pin = LL_GPIO_PIN_1;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_6;
    LL_GPIO_Init( GPIOA, &GPIO_InitStruct );

    USART_InitStruct.BaudRate = 115200;
    USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
    USART_InitStruct.Parity = LL_USART_PARITY_NONE;
#ifdef CONFIG_LINKWAN_AT
    USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
#else
    USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX;
#endif
    USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;

    LL_USART_Init( USART4, &USART_InitStruct );

    LL_USART_DisableOverrunDetect( USART4 );

    LL_USART_ConfigAsyncMode( USART4 );

    LL_USART_Enable( USART4 );
    NVIC_SetPriority(USART4_5_IRQn, 0);
    NVIC_EnableIRQ(USART4_5_IRQn);
    LL_USART_EnableIT_RXNE(USART4);
  #else
//    LL_USART_InitTypeDef USART_InitStruct;

//    LL_GPIO_InitTypeDef GPIO_InitStruct;

    DBG_Uart_Deinit( );
    
    
    /* Peripheral clock enable */
//    LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_USART4 );

    /**USART4 GPIO Configuration
     PA0   ------> USART4_TX
     PA1   ------> USART4_RX
     */
//    GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
//    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
//    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
//    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
//    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
//    GPIO_InitStruct.Alternate = LL_GPIO_AF_6;
//    LL_GPIO_Init( GPIOA, &GPIO_InitStruct );

//    GPIO_InitStruct.Pin = LL_GPIO_PIN_1;
//    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
//    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
//    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
//    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
//    GPIO_InitStruct.Alternate = LL_GPIO_AF_6;
//    LL_GPIO_Init( GPIOA, &GPIO_InitStruct );

    //串口IO初始化
    AltFunIO(VDBGRX_Port, VDBGRX_Pin, 0);	  //PC10 UART3 RX
		AltFunIO(VDBGTX_Port, VDBGTX_Pin, 0);	   //PC11 UART3 TX

    
//    USART_InitStruct.BaudRate = 115200;
//    USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
//    USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
//    USART_InitStruct.Parity = LL_USART_PARITY_NONE;
//#ifdef CONFIG_LINKWAN_AT
//    USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
//#else
//    USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX;
//#endif
//    USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
//    USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;

//    LL_USART_Init( USART4, &USART_InitStruct );

//    LL_USART_DisableOverrunDetect( USART4 );

//    LL_USART_ConfigAsyncMode( USART4 );

//    LL_USART_Enable( USART4 );
//    NVIC_SetPriority(USART4_5_IRQn, 0);
//    NVIC_EnableIRQ(USART4_5_IRQn);
//    LL_USART_EnableIT_RXNE(USART4);

    //串口初始化
    Uartx_Init(VDBGUART);
    UARTx_RXSTA_RXEN_Setable(VDBGUART, ENABLE);		//打开接收使能
    UARTx_TXSTA_TXEN_Setable(VDBGUART, ENABLE);		//打开发送使能
//    UART_UARTIF_RxTxIF_ClrEx(VDBGUART);	//清除发送中断标志    
    UART_UARTIE_RxTxIE_SetableEx(VDBGUART, RxInt, ENABLE);//打开接收中断
  #endif
}

void DBG_Send( const char *format, ... )
{
    va_list args;
    static __IO uint16_t len = 0;
    uint16_t current_len;
    int start;
    int stop;
    CPSR_ALLOC();

    va_start( args, format );

    RHINO_CPU_INTRPT_DISABLE();
    if ( len != 0 )
    {
        if ( len != sizeof(uart_context.buffTx) )
        {
            current_len = len; /* use current_len instead of volatile len in below computation */
            len = current_len + vsnprintf( dbgTxBuff + current_len,
                                           sizeof(dbgTxBuff) - current_len,
                                           format, args );
        }
        RHINO_CPU_INTRPT_ENABLE();
        va_end( args );
        return;
    }
    else
    {
        len = vsnprintf( dbgTxBuff, sizeof(dbgTxBuff), format, args );
    }

    current_len = len;
    RHINO_CPU_INTRPT_ENABLE();

    start = 0;

    do
    {
        stop = dbg_buffer_transmit( start, current_len );

        {
            RHINO_CPU_INTRPT_DISABLE();
            if ( len == stop )
            {
                len = 0;
                RHINO_CPU_INTRPT_ENABLE();
            }
            else
            {
                start = stop;
                current_len = len;
                RHINO_CPU_INTRPT_ENABLE();
            }
        }
    } while ( current_len != stop );

    va_end( args );
}

void vcom_Init( void )
{
  #if 0
    LL_LPUART_InitTypeDef LPUART_InitStruct;

    /*## Configure the UART peripheral ######################################*/
    /* Put the UART peripheral in the Asynchronous mode (UART Mode) */
    /* UART1 configured as follow:
     - Word Length = 8 Bits
     - Stop Bit = One Stop bit
     - Parity = ODD parity
     - BaudRate = 921600 baud
     - Hardware flow control disabled (RTS and CTS signals) */

    /*
     * Clock initialization:
     * - LSE source selection
     * - LPUART clock enable
     * - GPIO clocks are enabled in vcom_IoInit()
     */
    LL_RCC_SetLPUARTClockSource( LL_RCC_LPUART1_CLKSOURCE_HSI );
    UARTX_CLK_ENABLE();
    vcom_IoInit( );

    LPUART_InitStruct.BaudRate = 9600;
    LPUART_InitStruct.DataWidth = LL_LPUART_DATAWIDTH_8B;
    LPUART_InitStruct.StopBits = LL_LPUART_STOPBITS_1;
    LPUART_InitStruct.Parity = LL_LPUART_PARITY_NONE;
    LPUART_InitStruct.TransferDirection = LL_LPUART_DIRECTION_TX_RX;
    LPUART_InitStruct.HardwareFlowControl = LL_LPUART_HWCONTROL_NONE;

    if ( LL_LPUART_Init( UARTX, &LPUART_InitStruct ) != SUCCESS )
    {
        Error_Handler( );
    }

    /* Configuring the LPUART specific LP feature - the wakeup from STOP */
    LL_LPUART_EnableInStopMode( UARTX );

    /* WakeUp from stop mode on start bit detection*/
    LL_LPUART_SetWKUPType( UARTX, LL_LPUART_WAKEUP_ON_STARTBIT );
    //LL_LPUART_SetWKUPType(UARTX, LL_LPUART_WAKEUP_ON_RXNE);
    LL_LPUART_EnableIT_WKUP( UARTX );

    LL_LPUART_Enable( UARTX );
    while ( LL_LPUART_IsActiveFlag_TEACK( UARTX ) == RESET )
    {
        ;
    }
    while ( LL_LPUART_IsActiveFlag_REACK( UARTX ) == RESET )
    {
        ;
    }

    uart_context.gState = HAL_UART_STATE_READY;
    uart_context.RxState = HAL_UART_STATE_READY;
  #else
//    LL_LPUART_InitTypeDef LPUART_InitStruct;

    /*## Configure the UART peripheral ######################################*/
    /* Put the UART peripheral in the Asynchronous mode (UART Mode) */
    /* UART1 configured as follow:
     - Word Length = 8 Bits
     - Stop Bit = One Stop bit
     - Parity = ODD parity
     - BaudRate = 921600 baud
     - Hardware flow control disabled (RTS and CTS signals) */

    /*
     * Clock initialization:
     * - LSE source selection
     * - LPUART clock enable
     * - GPIO clocks are enabled in vcom_IoInit()
     */
//    LL_RCC_SetLPUARTClockSource( LL_RCC_LPUART1_CLKSOURCE_HSI );
//    UARTX_CLK_ENABLE();

    //串口IO口初始化
    vcom_IoInit( );

//    LPUART_InitStruct.BaudRate = 9600;
//    LPUART_InitStruct.DataWidth = LL_LPUART_DATAWIDTH_8B;
//    LPUART_InitStruct.StopBits = LL_LPUART_STOPBITS_1;
//    LPUART_InitStruct.Parity = LL_LPUART_PARITY_NONE;
//    LPUART_InitStruct.TransferDirection = LL_LPUART_DIRECTION_TX_RX;
//    LPUART_InitStruct.HardwareFlowControl = LL_LPUART_HWCONTROL_NONE;

//    if ( LL_LPUART_Init( UARTX, &LPUART_InitStruct ) != SUCCESS )
//    {
//        Error_Handler( );
//    }
    
    //串口初始化
    Uartx_Init(VCOMUART);

    /* Configuring the LPUART specific LP feature - the wakeup from STOP */
//    LL_LPUART_EnableInStopMode( UARTX );

    /* WakeUp from stop mode on start bit detection*/
//    LL_LPUART_SetWKUPType( UARTX, LL_LPUART_WAKEUP_ON_STARTBIT );
    //LL_LPUART_SetWKUPType(UARTX, LL_LPUART_WAKEUP_ON_RXNE);
//    LL_LPUART_EnableIT_WKUP( UARTX );

//    LL_LPUART_Enable( UARTX );
//    while ( LL_LPUART_IsActiveFlag_TEACK( UARTX ) == RESET )
//    {
//        ;
//    }
//    while ( LL_LPUART_IsActiveFlag_REACK( UARTX ) == RESET )
//    {
//        ;
//    }

//    uart_context.gState = HAL_UART_STATE_READY;
//    uart_context.RxState = HAL_UART_STATE_READY;
    
    //串口使能
    UARTx_RXSTA_RXEN_Setable(VCOMUART, ENABLE);		//打开接收使能
    UARTx_TXSTA_TXEN_Setable(VCOMUART, ENABLE);		//打开发送使能
//    UART_UARTIF_RxTxIF_ClrEx(VCOMUART);	//清除发送中断标志    
//    UART_UARTIE_RxTxIE_SetableEx(VCOMUART, RxInt, ENABLE);//打开接收中断
  #endif
}

void vcom_DeInit( void )
{
  #if 0
    LL_LPUART_DeInit( UARTX );

    /*##-1- Reset peripherals ##################################################*/
    UARTX_FORCE_RESET();
    UARTX_RELEASE_RESET();

    /*##-2- Disable peripherals and GPIO Clocks #################################*/
    /* Configure UART Tx as alternate function  */
    HW_GPIO_DeInit( UARTX_TX_GPIO_PORT, UARTX_TX_PIN );
    /* Configure UART Rx as alternate function  */
    HW_GPIO_DeInit( UARTX_RX_GPIO_PORT, UARTX_RX_PIN );

    /*##-3- Disable the NVIC for UART ##########################################*/
    NVIC_DisableIRQ( UARTX_IRQn );
  #else
//    LL_LPUART_DeInit( UARTX );
    UARTx_Deinit(VCOMUART);

    /*##-1- Reset peripherals ##################################################*/
//    UARTX_FORCE_RESET();
//    UARTX_RELEASE_RESET();

    /*##-2- Disable peripherals and GPIO Clocks #################################*/
    /* Configure UART Tx as alternate function  */
//    HW_GPIO_DeInit( UARTX_TX_GPIO_PORT, UARTX_TX_PIN );
    /* Configure UART Rx as alternate function  */
//    HW_GPIO_DeInit( UARTX_RX_GPIO_PORT, UARTX_RX_PIN );
    CloseIO(VCOMRX_Port, VCOMRX_Pin);
    CloseIO(VCOMTX_Port, VCOMTX_Pin);

    /*##-3- Disable the NVIC for UART ##########################################*/
//    NVIC_DisableIRQ( UARTX_IRQn );
    NVIC_DisableIRQ(VCOM_IRQn);
  #endif
}

void vcom_Send( const char *format, ... )
{
    va_list args;
    static __IO uint16_t len = 0;
    uint16_t current_len;
    int start;
    int stop;
    CPSR_ALLOC();

    va_start( args, format );

    RHINO_CPU_INTRPT_DISABLE();
    if ( len != 0 )
    {
        if ( len != sizeof(uart_context.buffTx) )
        {
            current_len = len; /* use current_len instead of volatile len in below computation */
            len = current_len + vsnprintf( uart_context.buffTx + current_len,
                                           sizeof(uart_context.buffTx) - current_len,
                                           format, args );
        }
        RHINO_CPU_INTRPT_ENABLE();
        va_end( args );
        return;
    }
    else
    {
        len = vsnprintf( uart_context.buffTx, sizeof(uart_context.buffTx), format, args );
    }

    current_len = len;
    RHINO_CPU_INTRPT_ENABLE();

    start = 0;

    do
    {
        stop = buffer_transmit( start, current_len );

        {
            RHINO_CPU_INTRPT_DISABLE();
            if ( len == stop )
            {
                len = 0;
                RHINO_CPU_INTRPT_ENABLE();
            }
            else
            {
                start = stop;
                current_len = len;
                RHINO_CPU_INTRPT_ENABLE();
            }
        }
    } while ( current_len != stop );

    va_end( args );
}

void vcom_ReceiveInit( void )
{
  #if 0
    if ( uart_context.RxState != HAL_UART_STATE_READY )
    {
        return;
    }

    /* Process Locked */
    HW_LOCK( &uart_context );

    uart_context.RxState = HAL_UART_STATE_BUSY_RX;

    /* Enable the UART Parity Error Interrupt */
    LL_LPUART_EnableIT_PE( UARTX );

    /* Enable the UART Error Interrupt: (Frame error, noise error, overrun error) */
    LL_LPUART_EnableIT_ERROR( UARTX );

    /* Process Unlocked */
    HW_UNLOCK( &uart_context );
  #else
//    if ( uart_context.RxState != HAL_UART_STATE_READY )
//    {
//        return;
//    }

    /* Process Locked */
    HW_LOCK( &uart_context );

//    uart_context.RxState = HAL_UART_STATE_BUSY_RX;

    /* Enable the UART Parity Error Interrupt */
//    LL_LPUART_EnableIT_PE( UARTX );

    /* Enable the UART Error Interrupt: (Frame error, noise error, overrun error) */
//    LL_LPUART_EnableIT_ERROR( UARTX );

    /* Process Unlocked */
    HW_UNLOCK( &uart_context );
  #endif
}

void vcom_IoInit( void )
{
  #if 0
    GPIO_InitTypeDef GPIO_InitStruct;

    /* UART TX GPIO pin configuration  */
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    GPIO_InitStruct.Alternate = UARTX_TX_AF;

    HW_GPIO_Init( UARTX_TX_GPIO_PORT, UARTX_TX_PIN, &GPIO_InitStruct );

    /* UART RX GPIO pin configuration  */
    GPIO_InitStruct.Alternate = UARTX_RX_AF;

    HW_GPIO_Init( UARTX_RX_GPIO_PORT, UARTX_RX_PIN, &GPIO_InitStruct );

    /*##-3- Configure the NVIC for UART ########################################*/
    /* NVIC for UART */
    NVIC_SetPriority( UARTX_IRQn, 0 );
    NVIC_EnableIRQ( UARTX_IRQn );

    /* enable RXNE */
    LL_LPUART_EnableIT_RXNE( UARTX );
  #else
    AltFunIO(VCOMRX_Port, VCOMRX_Pin, 0);	//PC10 UART3 RX
	  AltFunIO(VCOMTX_Port, VCOMTX_Pin, 0);	//PC11 UART3 TX
    
    NVIC_SetPriority(VCOM_IRQn, 2);//中断优先级配置
    NVIC_EnableIRQ(VCOM_IRQn);	
    
    UART_UARTIE_RxTxIE_SetableEx(VCOMUART, RxInt, ENABLE);//打开接收中断
  #endif
}

void vcom_IoDeInit( void )
{
  #if 0
    GPIO_InitTypeDef GPIO_InitStructure = { 0 };

    GPIO_InitStructure.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStructure.Pull = GPIO_NOPULL;

    HW_GPIO_Init( UARTX_TX_GPIO_PORT, UARTX_TX_PIN, &GPIO_InitStructure );

    HW_GPIO_Init( UARTX_RX_GPIO_PORT, UARTX_RX_PIN, &GPIO_InitStructure );
  #else
    CloseIO(VCOMRX_Port, VCOMRX_Pin);
    CloseIO(VCOMTX_Port, VCOMTX_Pin);
  #endif
}

FlagStatus IsNewCharReceived( void )
{
    FlagStatus status;
    CPSR_ALLOC();
    RHINO_CPU_INTRPT_DISABLE();

    status = ((uart_context.rx_idx_toread == uart_context.rx_idx_free) ? RESET : SET);

    RHINO_CPU_INTRPT_ENABLE();
    return status;
}

uint8_t GetNewChar( void )
{
    uint8_t NewChar;
    CPSR_ALLOC();
    RHINO_CPU_INTRPT_DISABLE();

    NewChar = uart_context.buffRx[uart_context.rx_idx_toread];
    uart_context.rx_idx_toread = (uart_context.rx_idx_toread + 1) % sizeof(uart_context.buffRx);

    RHINO_CPU_INTRPT_ENABLE();
    return NewChar;
}

void vcom_IRQHandler( void )
{
  #if 0
    int rx_ready = 0;
    char rx;

    /* UART Wake Up interrupt occured ------------------------------------------*/
    if ( LL_LPUART_IsActiveFlag_WKUP( UARTX ) && (LL_LPUART_IsEnabledIT_WKUP( UARTX ) != RESET) )
    {
        LL_LPUART_ClearFlag_WKUP( UARTX );

        /* forbid stop mode */
        LowPower_Disable( e_LOW_POWER_UART );

        /* Enable the UART Data Register not empty Interrupt */
        LL_LPUART_EnableIT_RXNE( UARTX );
    }

    if ( LL_LPUART_IsActiveFlag_RXNE( UARTX ) && (LL_LPUART_IsEnabledIT_RXNE( UARTX ) != RESET) )
    {
        /* no need to clear the RXNE flag because it is auto cleared by reading the data*/
        rx = LL_LPUART_ReceiveData8( UARTX );
        rx_ready = 1;
        //PRINTF("%02X\n", rx);

        /* allow stop mode*/
        LowPower_Enable( e_LOW_POWER_UART );
    }

    if ( LL_LPUART_IsActiveFlag_PE( UARTX ) || LL_LPUART_IsActiveFlag_FE( UARTX ) || LL_LPUART_IsActiveFlag_ORE( UARTX )
         || LL_LPUART_IsActiveFlag_NE( UARTX ) )
    {
        PRINTF("Error when receiving\n")
        ;
        /* clear error IT */
        LL_LPUART_ClearFlag_PE( UARTX );
        LL_LPUART_ClearFlag_FE( UARTX );
        LL_LPUART_ClearFlag_ORE( UARTX );
        LL_LPUART_ClearFlag_NE( UARTX );

        rx = 0x01;
        rx_ready = 1;
    }

    if ( rx_ready == 1 )
    {
        receive( rx );
    }
  #else
    int rx_ready = 0;
    char rx;

//    /* UART Wake Up interrupt occured ------------------------------------------*/
//    if ( LL_LPUART_IsActiveFlag_WKUP( UARTX ) && (LL_LPUART_IsEnabledIT_WKUP( UARTX ) != RESET) )
//    {
//        LL_LPUART_ClearFlag_WKUP( UARTX );

//        /* forbid stop mode */
//        LowPower_Disable( e_LOW_POWER_UART );

//        /* Enable the UART Data Register not empty Interrupt */
//        LL_LPUART_EnableIT_RXNE( UARTX );
//    }

//    if ( LL_LPUART_IsActiveFlag_RXNE( UARTX ) && (LL_LPUART_IsEnabledIT_RXNE( UARTX ) != RESET) )
//    {
//        /* no need to clear the RXNE flag because it is auto cleared by reading the data*/
//        rx = LL_LPUART_ReceiveData8( UARTX );
//        rx_ready = 1;
//        //PRINTF("%02X\n", rx);

//        /* allow stop mode*/
//        LowPower_Enable( e_LOW_POWER_UART );
//    }

    //接收中断处理
    if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(VCOMUART, RxInt))
      &&(SET == UART_UARTIF_RxTxIF_ChkEx(VCOMUART, RxInt)))
    {
      //中断转发接收到的数据
      rx = UARTx_RXREG_Read(UART3);//接收中断标志仅可通过读取rxreg寄存器清除
      rx_ready = 1;
    }
    
    //接受出错不做处理
//    if ( LL_LPUART_IsActiveFlag_PE( UARTX ) || LL_LPUART_IsActiveFlag_FE( UARTX ) || LL_LPUART_IsActiveFlag_ORE( UARTX )
//         || LL_LPUART_IsActiveFlag_NE( UARTX ) )
//    {
//        PRINTF("Error when receiving\n")
//        ;
//        /* clear error IT */
//        LL_LPUART_ClearFlag_PE( UARTX );
//        LL_LPUART_ClearFlag_FE( UARTX );
//        LL_LPUART_ClearFlag_ORE( UARTX );
//        LL_LPUART_ClearFlag_NE( UARTX );

//        rx = 0x01;
//        rx_ready = 1;
//    }

    if ( rx_ready == 1 )
    {
        receive( rx );
    }
    
    	//发送中断处理
    if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART3, TxInt))
      &&(SET == UART_UARTIF_RxTxIF_ChkEx(UART3, TxInt)))
    {
      UART_UARTIF_RxTxIF_ClrEx(UART3);	//清除发送中断标志
    }
  #endif  
   
}

/* Private functions Definition ------------------------------------------------------*/

static int buffer_transmit( int start, int len )
{
  #if 0
    int i;
    for ( i = start; i < len; i++ )
    {
        LL_LPUART_ClearFlag_TC( UARTX );
        LL_LPUART_TransmitData8( UARTX, uart_context.buffTx[i] );

        while ( LL_LPUART_IsActiveFlag_TC( UARTX ) != SET )
        {
            ;
        }
    }
    LL_LPUART_ClearFlag_TC( UARTX );
    return len;
  #else
    int i;
    for ( i = start; i < len; i++ )
    {
        while (UART_UARTIF_RxTxIF_ChkEx(VCOMUART, TxInt) == 0);

        UARTx_TXREG_Write(VCOMUART, uart_context.buffTx[i]);
    }
    return len;
  #endif
}

static void receive( char rx )
{
    int next_free;

    /** no need to clear the RXNE flag because it is auto cleared by reading the data*/
    uart_context.buffRx[uart_context.rx_idx_free] = rx;
    next_free = (uart_context.rx_idx_free + 1) % sizeof(uart_context.buffRx);
    if ( next_free != uart_context.rx_idx_toread )
    {
        /* this is ok to read as there is no buffer overflow in input */
        uart_context.rx_idx_free = next_free;
    }
    else
    {
        /* force the end of a command in case of overflow so that we can process it */
        uart_context.buffRx[uart_context.rx_idx_free] = '\r';
        PRINTF("uart_context.buffRx buffer overflow %d\r\n")
        ;
    }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
