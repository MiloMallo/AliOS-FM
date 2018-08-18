/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2013 Semtech

Description: contains hardaware configuration Macros and Constants

License: Revised BSD License, see LICENSE.TXT file include in the project

Maintainer: Miguel Luis and Gregory Cristian
*/
/******************************************************************************
 * @file    eml3047_hw_conf.h
 * @author  MCD Application Team
 * @version V1.1.1
 * @date    01-June-2017
 * @brief   contains hardaware configuration Macros and Constants
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FM33A0_HW_CONF_H__
#define __FM33A0_HW_CONF_H__

#ifdef __cplusplus
extern "C" {
#endif
  
#include "soc.h"

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* LORA I/O definition */
#if 0
  #define RADIO_RESET_PORT                          GPIOB
  #define RADIO_RESET_PIN                           GPIO_PIN_0

  #define RADIO_MOSI_PORT                           GPIOB
  #define RADIO_MOSI_PIN                            GPIO_PIN_5

  #define RADIO_MISO_PORT                           GPIOB
  #define RADIO_MISO_PIN                            GPIO_PIN_4

  #define RADIO_SCLK_PORT                           GPIOA
  #define RADIO_SCLK_PIN                            GPIO_PIN_5

  #define RADIO_NSS_PORT                            GPIOA
  #define RADIO_NSS_PIN                             GPIO_PIN_4

  #define RADIO_DIO_0_PORT                          GPIOB
  #define RADIO_DIO_0_PIN                           GPIO_PIN_6

  #define RADIO_DIO_1_PORT                          GPIOA
  #define RADIO_DIO_1_PIN                           GPIO_PIN_12

  #define RADIO_DIO_2_PORT                          GPIOA
  #define RADIO_DIO_2_PIN                           GPIO_PIN_11

  #define RADIO_DIO_3_PORT                          GPIOA
  #define RADIO_DIO_3_PIN                           GPIO_PIN_8

  #ifdef RADIO_DIO_4 
  #define RADIO_DIO_4_PORT                          GPIOA
  #define RADIO_DIO_4_PIN                           GPIO_PIN_9
  #endif

  #ifdef RADIO_DIO_5 
  #define RADIO_DIO_5_PORT                          GPIOC
  #define RADIO_DIO_5_PIN                           GPIO_PIN_7
  #endif

  //#define RADIO_TCXO_VCC_PORT                       GPIOA
  //#define RADIO_TCXO_VCC_PIN                        GPIO_PIN_12

  #define RADIO_ANT_SWITCH_PORT                     GPIOA
  #define RADIO_ANT_SWITCH_PIN                      GPIO_PIN_7

  #define BAT_LEVEL_PORT                            GPIOA
  #define BAT_LEVEL_PIN                             GPIO_PIN_4
  /*  SPI MACRO redefinition */

  #define SPI_CLK_ENABLE()                __HAL_RCC_SPI1_CLK_ENABLE()

  #define SPI1_AF                          GPIO_AF0_SPI1  

  /* ADC MACRO redefinition */

  #define BAT_LEVEL_PORT  GPIOA //CRF2
  #define BAT_LEVEL_PIN  GPIO_PIN_4
  #define ADC_READ_CHANNEL                 ADC_CHANNEL_4
  #define ADCCLK_ENABLE()                 __HAL_RCC_ADC1_CLK_ENABLE();
  #define ADCCLK_DISABLE()                __HAL_RCC_ADC1_CLK_DISABLE();



  /* --------------------------- RTC HW definition -------------------------------- */

  #define RTC_OUTPUT       DBG_RTC_OUTPUT

  #define RTC_Alarm_IRQn              RTC_IRQn
  /* --------------------------- UART HW definition -------------------------------*/

  /* Definition for UARTx clock resources */
  #define UARTX                           LPUART1
  #define UARTX_CLK_ENABLE()              LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_LPUART1)
  #define UARTX_RX_GPIO_CLK_ENABLE()      LL_IOP_GRP1_EnableClock(RCC_IOPENR_GPIOBEN)
  #define UARTX_TX_GPIO_CLK_ENABLE()      LL_IOP_GRP1_EnableClock(RCC_IOPENR_GPIOBEN)

  #define UARTX_FORCE_RESET()             LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_LPUART1)
  #define UARTX_RELEASE_RESET()           LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_LPUART1)

  #define UARTX_TX_PIN                    GPIO_PIN_2
  #define UARTX_TX_GPIO_PORT              GPIOA
  #define UARTX_TX_AF                     GPIO_AF6_LPUART1
  #define UARTX_RX_PIN                    GPIO_PIN_3
  #define UARTX_RX_GPIO_PORT              GPIOA
  #define UARTX_RX_AF                     GPIO_AF6_LPUART1

  /* Definition for USARTx's NVIC */
  #define UARTX_IRQn                      LPUART1_IRQn
  #define UARTX_IRQHandler                LPUART1_IRQHandler
#else
  #ifdef BLACK_BOARD
  	#define RADIO_RESET_PORT                          0x16  //PB6
  	#define RADIO_RESET_CONFIG                        OUTPUT_PUSH_PULL
  
    #define RADIO_NSS_PORT                            0x5F  //PF15
    #define RADIO_NSS_CONFIG                          OUTPUT_PUSH_PULL
    
    #define RADIO_MOSI_PORT                           0x5C  //PF12
    #define RADIO_MOSI_CONFIG                         OUTPUT_PUSH_PULL

    #define RADIO_MISO_PORT                           0x5D  //PF13
    #define RADIO_MISO_CONFIG                         OUTPUT_PUSH_PULL

    #define RADIO_SCLK_PORT                           0x5E  //PF14
    #define RADIO_SCLK_CONFIG                         OUTPUT_PUSH_PULL
	
    #define RADIO_DIO_0_PORT                          0x1D  //PB13 EXTI0[5]
    #define RADIO_DIO_0_CONFIG                        IRQ_MODE

    #define RADIO_DIO_1_PORT                          0x1C  //PB12 EXTI0[4]
    #define RADIO_DIO_1_CONFIG                        IRQ_MODE

    #define RADIO_DIO_2_PORT                          0x1F  //PB15 EXTI0[7]
    #define RADIO_DIO_2_CONFIG                        IRQ_MODE

    #define RADIO_DIO_3_PORT                          0x1E  //PB14 EXTI0[6]
    #define RADIO_DIO_3_CONFIG                        IRQ_MODE
  #else
  	#define RADIO_RESET_PORT                          0x08  //PA8
  	#define RADIO_RESET_CONFIG                        OUTPUT_PUSH_PULL
  
    #define RADIO_NSS_PORT                            0x32  //PD2
    #define RADIO_NSS_CONFIG                          OUTPUT_PUSH_PULL
    
    #define RADIO_MOSI_PORT                           0x35  //PD5
    #define RADIO_MOSI_CONFIG                         OUTPUT_PUSH_PULL

    #define RADIO_MISO_PORT                           0x34  //PD4
    #define RADIO_MISO_CONFIG                         OUTPUT_PUSH_PULL

    #define RADIO_SCLK_PORT                           0x33  //PD3
    #define RADIO_SCLK_CONFIG                         OUTPUT_PUSH_PULL
    
    #define RADIO_DIO_0_PORT                          0x00  //PA0 EXTI0[0]
    #define RADIO_DIO_0_CONFIG                        IRQ_MODE

    #define RADIO_DIO_1_PORT                          0x01  //PA1 EXTI0[1]
    #define RADIO_DIO_1_CONFIG                        IRQ_MODE

    #define RADIO_DIO_2_PORT                          0x02  //PA2 EXTI0[2]
    #define RADIO_DIO_2_CONFIG                        IRQ_MODE

    #define RADIO_DIO_3_PORT                          0x03  //PA3 EXTI0[3]
    #define RADIO_DIO_3_CONFIG                        IRQ_MODE
  #endif

  #ifdef RADIO_DIO_4 
  #define RADIO_DIO_4_PORT                          0x04  //PA4 rsvd
  #define RADIO_DIO_4_CONFIG                        OUTPUT_PUSH_PULL
  #endif

  #ifdef RADIO_DIO_5 
  #define RADIO_DIO_5_PORT                          0x04  //PA4 rsvd
  #define RADIO_DIO_5_CONFIG                        OUTPUT_PUSH_PULL
  #endif

  //#define RADIO_TCXO_VCC_PORT                     GPIOA
  //#define RADIO_TCXO_VCC_PIN                      GPIO_PIN_12

  #define RADIO_ANT_SWITCH_PORT                     0x04  //PA4 rsvd
  #define RADIO_ANT_SWITCH_CONFIG                   OUTPUT_PUSH_PULL

  #define BAT_LEVEL_PORT                            0x04  //PA4 rsvd
  #define BAT_LEVEL_CONFIG                          OUTPUT_PUSH_PULL
  /*  SPI MACRO redefinition */

  #define SPI_CLK_ENABLE()                __HAL_RCC_SPI1_CLK_ENABLE()

  #define SPI1_AF                          GPIO_AF0_SPI1  

  /* ADC MACRO redefinition */

  #define BAT_LEVEL_PORT  GPIOA //CRF2
  #define BAT_LEVEL_PIN  GPIO_PIN_4
  #define ADC_READ_CHANNEL                 ADC_CHANNEL_4
  #define ADCCLK_ENABLE()                 __HAL_RCC_ADC1_CLK_ENABLE();
  #define ADCCLK_DISABLE()                __HAL_RCC_ADC1_CLK_DISABLE();



  /* --------------------------- RTC HW definition -------------------------------- */

  #define RTC_OUTPUT       DBG_RTC_OUTPUT

  #define RTC_Alarm_IRQn              RTC_IRQn
  /* --------------------------- UART HW definition -------------------------------*/

  #if 0
    /* Definition for UARTx clock resources */
    #define UARTX                           LPUART1
    #define UARTX_CLK_ENABLE()              LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_LPUART1)
    #define UARTX_RX_GPIO_CLK_ENABLE()      LL_IOP_GRP1_EnableClock(RCC_IOPENR_GPIOBEN)
    #define UARTX_TX_GPIO_CLK_ENABLE()      LL_IOP_GRP1_EnableClock(RCC_IOPENR_GPIOBEN)

    #define UARTX_FORCE_RESET()             LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_LPUART1)
    #define UARTX_RELEASE_RESET()           LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_LPUART1)

    #define UARTX_TX_PIN                    GPIO_PIN_2
    #define UARTX_TX_GPIO_PORT              GPIOA
    #define UARTX_TX_AF                     GPIO_AF6_LPUART1
    #define UARTX_RX_PIN                    GPIO_PIN_3
    #define UARTX_RX_GPIO_PORT              GPIOA
    #define UARTX_RX_AF                     GPIO_AF6_LPUART1

    /* Definition for USARTx's NVIC */
    #define UARTX_IRQn                      LPUART1_IRQn
    #define UARTX_IRQHandler                LPUART1_IRQHandler
  #else
//    #define VDBGRX_Pin						GPIO_Pin_3
//    #define VDBGRX_Port 					GPIOF
//    #define VDBGTX_Pin						GPIO_Pin_4
//    #define VDBGTX_Port 					GPIOF  
//    #define VDBGUART 						  UART0 
//    #define VDBG_IRQn             UART0_IRQn

    #ifdef BLACK_BOARD
	    #define VDBGRX_Pin						GPIO_Pin_0
      #define VDBGRX_Port 					GPIOB
      #define VDBGTX_Pin						GPIO_Pin_1
      #define VDBGTX_Port 					GPIOB  
      #define VDBGUART 						UART1 
      #define VDBG_IRQn             			UART1_IRQn
    #else
      #define VDBGRX_Pin						GPIO_Pin_2
      #define VDBGRX_Port 					GPIOB
      #define VDBGTX_Pin						GPIO_Pin_3
      #define VDBGTX_Port 					GPIOB  
      #define VDBGUART 						UART2 
      #define VDBG_IRQn             			UART2_IRQn
    #endif
    
    #define VCOMRX_Pin						GPIO_Pin_10
    #define VCOMRX_Port 					GPIOC
    #define VCOMTX_Pin						GPIO_Pin_11
    #define VCOMTX_Port 					GPIOC  
    #define VCOMUART 						  UART3 
    #define VCOM_IRQn             UART3_IRQn
		
//	  #define VCOMRX_Pin						GPIO_Pin_2
//		#define VCOMRX_Port 					GPIOB
//		#define VCOMTX_Pin						GPIO_Pin_3
//		#define VCOMTX_Port 					GPIOB  
//		#define VCOMUART 						  UART2 
//		#define VCOM_IRQn             UART2_IRQn
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* __32L082MLM_HW_CONF_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
