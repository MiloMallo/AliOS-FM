/**
  ******************************************************************************
  * @file    fm33a0xx_etim.c
  * @author  FM33a0 Application Team
  * @version V2.0.2
  * @date    26-2-2018
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33a0xx_etim.h"  


/** @addtogroup fm33a0_StdPeriph_Driver
  * @{
  */

/** @defgroup ETIM 
  * @brief ETIM driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

//Code_Start
//2018-04-02-13-21-03
//FM33A0XX_Driver_Gen_V1.4

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�ET�������ⲿ�������������˲���������
����: ETIM1/ETIM2/ETIM3/ETIM4  ��ʱ������
			ENABLE/DISABLE 		�����������ź������˲�/�ر����������ź������˲�
���: ��
*********************************/
void ETIMx_ETxCR_EXFLT_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxCR |= (ETIMx_ETxCR_EXFLT_Msk);
	}
	else
	{
		ETIMx->ETxCR &= ~(ETIMx_ETxCR_EXFLT_Msk);
	}
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET�������ⲿ�������������˲���������
����: ETIM1/ETIM2/ETIM3/ETIM4  ��ʱ������
���: ENABLE/DISABLE 		�����������ź������˲�/�ر����������ź������˲�
*********************************/
FunState ETIMx_ETxCR_EXFLT_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxCR & (ETIMx_ETxCR_EXFLT_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�ET������PWM���ʹ������
����: ETIM1/ETIM2/ETIM3/ETIM4  ��ʱ������
			ENABLE/DISABLE 		PWM���ʹ��/PWM�����ֹ
���: ��
*********************************/
void ETIMx_ETxCR_PWM_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxCR |= (ETIMx_ETxCR_PWM_Msk);
	}
	else
	{
		ETIMx->ETxCR &= ~(ETIMx_ETxCR_PWM_Msk);
	}
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET������PWM���ʹ������
����: ETIM1/ETIM2/ETIM3/ETIM4  ��ʱ������
���: ENABLE/DISABLE 		PWM���ʹ��/PWM�����ֹ
*********************************/
FunState ETIMx_ETxCR_PWM_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxCR & (ETIMx_ETxCR_PWM_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ�ET������������
����: ETIM1/ETIM2/ETIM3/ETIM4  ��ʱ������
			ENABLE/DISABLE 		 ���ʱ��/ֹͣ��ʱ��
���: ��
*********************************/
void ETIMx_ETxCR_CEN_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxCR |= (ETIMx_ETxCR_CEN_Msk);
	}
	else
	{
		ETIMx->ETxCR &= ~(ETIMx_ETxCR_CEN_Msk);
	}
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET������������
����: ETIM1/ETIM2/ETIM3/ETIM4  ��ʱ������
���: ENABLE/DISABLE 		 ���ʱ��/ֹͣ��ʱ��
*********************************/
FunState ETIMx_ETxCR_CEN_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxCR & (ETIMx_ETxCR_CEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET����������ģʽ
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			ETIMx_ETxCR_MOD_COUNTER		0 = ����ģʽ
			/ETIMx_ETxCR_MOD_CAPTURE	1 = ��׽ģʽ
���: ��
*********************************/
void ETIMx_ETxCR_MOD_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxCR;
	tmpreg &= ~(ETIMx_ETxCR_MOD_Msk);
	tmpreg |= (SetValue & ETIMx_ETxCR_MOD_Msk);
	ETIMx->ETxCR = tmpreg;
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET����������ģʽ
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ETIMx_ETxCR_MOD_COUNTER		0 = ����ģʽ
			/ETIMx_ETxCR_MOD_CAPTURE	1 = ��׽ģʽ
*********************************/
uint32_t ETIMx_ETxCR_MOD_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxCR & ETIMx_ETxCR_MOD_Msk);
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET��������������
����: ETIM1/ETIM2/ETIM3/ETIM4  ��ʱ������
			ENABLE/DISABLE 		 ET1��ET3����ET2��ET4��������32bit��ʱ��/16bit��ʱ����������
���: ��
*********************************/
void ETIMx_ETxCR_CASEN_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxCR |= (ETIMx_ETxCR_CASEN_Msk);
	}
	else
	{
		ETIMx->ETxCR &= ~(ETIMx_ETxCR_CASEN_Msk);
	}
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET������������������
����: ETIM1/ETIM2/ETIM3/ETIM4  ��ʱ������
���: ENABLE/DISABLE 		 ET1��ET3����ET2��ET4��������32bit��ʱ��/16bit��ʱ����������
*********************************/
FunState ETIMx_ETxCR_CASEN_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxCR & (ETIMx_ETxCR_CASEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET����������ģʽ���ط�ʽ(����ʱ��ѡ��mcu_clkʱ��λ��Ч�����ǲ���mcu_clkʱ�������ؼ���)
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			ETIMx_ETxCR_EDGESEL_RISING		0 = ����ģʽ��������
			/ETIMx_ETxCR_EDGESEL_FALLING	1 = ����ģʽ���½���
���: ��
*********************************/
void ETIMx_ETxCR_EDGESEL_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxCR;
	tmpreg &= ~(ETIMx_ETxCR_EDGESEL_Msk);
	tmpreg |= (SetValue & ETIMx_ETxCR_EDGESEL_Msk);
	ETIMx->ETxCR = tmpreg;
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET����������ģʽ���ط�ʽ(����ʱ��ѡ��mcu_clkʱ��λ��Ч�����ǲ���mcu_clkʱ�������ؼ���)
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ETIMx_ETxCR_EDGESEL_RISING		0 = ����ģʽ��������
			/ETIMx_ETxCR_EDGESEL_FALLING	1 = ����ģʽ���½���
*********************************/
uint32_t ETIMx_ETxCR_EDGESEL_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxCR & ETIMx_ETxCR_EDGESEL_Msk);
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET��������׽ģʽ
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			ETIMx_ETxCR_CAPMOD_PERIOD		0 = �������ڲ�׽
			/ETIMx_ETxCR_CAPMOD_PULSE		1 = ����׽
���: ��
*********************************/
void ETIMx_ETxCR_CAPMOD_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxCR;
	tmpreg &= ~(ETIMx_ETxCR_CAPMOD_Msk);
	tmpreg |= (SetValue & ETIMx_ETxCR_CAPMOD_Msk);
	ETIMx->ETxCR = tmpreg;
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET��������׽ģʽ
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ETIMx_ETxCR_CAPMOD_PERIOD		0 = �������ڲ�׽
			/ETIMx_ETxCR_CAPMOD_PULSE		1 = ����׽
*********************************/
uint32_t ETIMx_ETxCR_CAPMOD_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxCR & ETIMx_ETxCR_CAPMOD_Msk);
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET�����������㲶׽ģʽ
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			ENABLE/DISABLE		�¼�������׽��ʹ�ܺ����������0����׽����һ����Ч��֮��timer�ſ�ʼ����/ ��׽�����㣬������һֱ���ɼ���
���: ��
*********************************/
void ETIMx_ETxCR_CAPCLR_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxCR |= (ETIMx_ETxCR_CAPCLR_Msk);
	}
	else
	{
		ETIMx->ETxCR &= ~(ETIMx_ETxCR_CAPCLR_Msk);
	}
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡ��ET�����������㲶׽ģʽ����
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ENABLE/DISABLE		�¼�������׽��ʹ�ܺ����������0����׽����һ����Ч��֮��timer�ſ�ʼ����/ ��׽�����㣬������һֱ���ɼ���
*********************************/
FunState ETIMx_ETxCR_CAPCLR_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxCR & (ETIMx_ETxCR_CAPCLR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET���������β�׽��Ч
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			ENABLE/DISABLE		���β�׽��Ч/������׽
���: ��
*********************************/
void ETIMx_ETxCR_CAPONCE_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxCR |= (ETIMx_ETxCR_CAPONCE_Msk);
	}
	else
	{
		ETIMx->ETxCR &= ~(ETIMx_ETxCR_CAPONCE_Msk);
	}
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET���������β�׽��Ч����
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ENABLE/DISABLE		���β�׽��Ч/������׽
*********************************/
FunState ETIMx_ETxCR_CAPONCE_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxCR & (ETIMx_ETxCR_CAPONCE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET��������׽��ѡ��
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			ETIMx_ETxCR_CAPEDGE_RISING		0 = ���ڲ�׽ģʽʱ���ز�׽
			ETIMx_ETxCR_CAPEDGE_FALLING		1 = ���ڲ�׽ģʽʱ���ز�׽
���: ��
*********************************/
void ETIMx_ETxCR_CAPEDGE_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxCR;
	tmpreg &= ~(ETIMx_ETxCR_CAPEDGE_Msk);
	tmpreg |= (SetValue & ETIMx_ETxCR_CAPEDGE_Msk);
	ETIMx->ETxCR = tmpreg;
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET��������׽��ѡ������
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ETIMx_ETxCR_CAPEDGE_RISING		0 = ���ڲ�׽ģʽʱ���ز�׽
			ETIMx_ETxCR_CAPEDGE_FALLING		1 = ���ڲ�׽ģʽʱ���ز�׽
*********************************/
uint32_t ETIMx_ETxCR_CAPEDGE_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxCR & ETIMx_ETxCR_CAPEDGE_Msk);
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET�ڲ��ź�2Դѡ��(��׽Դ)
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			ETIMx_ETxINSEL_SIG2SEL_GROUP2		0 = ��չ��ʱ��3���ڲ��ź�2ѡ��Group2
			/ETIMx_ETxINSEL_SIG2SEL_GROUP1	1 = ��չ��ʱ��3���ڲ��ź�2ѡ��Group1
���: ��
*********************************/
void ETIMx_ETxINSEL_SIG2SEL_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxINSEL;
	tmpreg &= ~(ETIMx_ETxINSEL_SIG2SEL_Msk);
	tmpreg |= (SetValue & ETIMx_ETxINSEL_SIG2SEL_Msk);
	ETIMx->ETxINSEL = tmpreg;
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET�ڲ��ź�2Դѡ��(��׽Դ)
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ETIMx_ETxINSEL_SIG2SEL_GROUP2		0 = ��չ��ʱ�����ڲ��ź�2ѡ��Group2
			/ETIMx_ETxINSEL_SIG2SEL_GROUP1	1 = ��չ��ʱ�����ڲ��ź�2ѡ��Group1
*********************************/
uint32_t ETIMx_ETxINSEL_SIG2SEL_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxINSEL & ETIMx_ETxINSEL_SIG2SEL_Msk);
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET�ڲ��ź�1Դѡ���ڼ���ģʽ�¼���Դ���ɴ�ѡ�񣬲�׽ģʽ�¼���Դ��
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			ETIMx_ETxINSEL_SIG1SEL_GROUP1			0 = ��չ��ʱ�����ڲ��ź�1ѡ��Group1
			/ETIMx_ETxINSEL_SIG1SEL_GROUP2		1 = ��չ��ʱ�����ڲ��ź�1ѡ��Group2 
���: ��
*********************************/
void ETIMx_ETxINSEL_SIG1SEL_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxINSEL;
	tmpreg &= ~(ETIMx_ETxINSEL_SIG1SEL_Msk);
	tmpreg |= (SetValue & ETIMx_ETxINSEL_SIG1SEL_Msk);
	ETIMx->ETxINSEL = tmpreg;
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET�ڲ��ź�1Դѡ���ڼ���ģʽ�¼���Դ���ɴ�ѡ�񣬲�׽ģʽ�¼���Դ��
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ETIMx_ETxINSEL_SIG1SEL_GROUP1			0 = ��չ��ʱ�����ڲ��ź�1ѡ��Group1
			/ETIMx_ETxINSEL_SIG1SEL_GROUP2		1 = ��չ��ʱ�����ڲ��ź�1ѡ��Group2 
*********************************/
uint32_t ETIMx_ETxINSEL_SIG1SEL_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxINSEL & ETIMx_ETxINSEL_SIG1SEL_Msk);
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET GROUP2 �ź�ѡ��
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			ETIMx_ETxINSEL_GRP2SEL_ET1_UART0_RX				ET1 000 = UART0_RX
			/ETIMx_ETxINSEL_GRP2SEL_ET1_UART1_RX			ET1 001 = UART1_RX
			/ETIMx_ETxINSEL_GRP2SEL_ET1_XTLF					ET1 010 = XTLF
			/ETIMx_ETxINSEL_GRP2SEL_ET1_ET1_IN1				ET1 011 = ET1_IN1
			/ETIMx_ETxINSEL_GRP2SEL_ET1_ET1_IN2				ET1 100 = ET1_IN2
			/ETIMx_ETxINSEL_GRP2SEL_ET1_CMP1O					ET1 101 = CMP1O���Ƚ���1�����
			/ETIMx_ETxINSEL_GRP2SEL_ET1_CMP2O					ET1 110 = CMP2O���Ƚ���2���
			/ETIMx_ETxINSEL_GRP2SEL_ET1_LPTO					ET1 111 = LPTO
			/ETIMx_ETxINSEL_GRP2SEL_ET2_UART2_RX			ET2 000 = UART2_RX
			/ETIMx_ETxINSEL_GRP2SEL_ET2_UART3_RX			ET2 001 = UART3_RX
			/ETIMx_ETxINSEL_GRP2SEL_ET2_XTLF					ET2 010 = XTLF
			/ETIMx_ETxINSEL_GRP2SEL_ET2_ET2_IN1				ET2 011 = ET2_IN1
			/ETIMx_ETxINSEL_GRP2SEL_ET2_ET2_IN2				ET2 100 = ET2_IN2
			/ETIMx_ETxINSEL_GRP2SEL_ET2_CMP1O					ET2 101 = CMP1O���Ƚ���1�����
			/ETIMx_ETxINSEL_GRP2SEL_ET2_CMP2O					ET2 110 = CMP2O���Ƚ���2�����
			/ETIMx_ETxINSEL_GRP2SEL_ET2_LPTO					ET2 111 = LPTO
			/ETIMx_ETxINSEL_GRP2SEL_ET3_ET3_IN12			ET3 000 = ET3_IN1
			/ETIMx_ETxINSEL_GRP2SEL_ET3_XTLF					ET3 001 = XTLF
			/ETIMx_ETxINSEL_GRP2SEL_ET3_UART4_RX			ET3 010 = UART4_RX
			/ETIMx_ETxINSEL_GRP2SEL_ET3_UART5_RX			ET3 011 = UART5_RX
			/ETIMx_ETxINSEL_GRP2SEL_ET3_RTCSEC				ET3 100 = RTCSEC
			/ETIMx_ETxINSEL_GRP2SEL_ET4_ET4_IN1				ET4 000 = ET4_IN1
			/ETIMx_ETxINSEL_GRP2SEL_ET4_XTLF					ET4 001 = XTLF
			/ETIMx_ETxINSEL_GRP2SEL_ET4_UART_RX22			ET4 010 = UART_RX2
			/ETIMx_ETxINSEL_GRP2SEL_ET4_UART_RX0			ET4 011 = UART_RX0
			/ETIMx_ETxINSEL_GRP2SEL_ET4_CMP1O					ET4 100 = CMP1O���Ƚ���1�����
			/ETIMx_ETxINSEL_GRP2SEL_ET4_CMP2O					ET4 101 = CMP2O���Ƚ���2�����
			/ETIMx_ETxINSEL_GRP2SEL_ET4_RTCSEC				ET4 110= RTCSEC
			/ETIMx_ETxINSEL_GRP2SEL_ET4_LPTO					ET4 111= LPTO
���: ��
*********************************/
void ETIMx_ETxINSEL_GRP2SEL_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxINSEL;
	tmpreg &= ~(ETIMx_ETxINSEL_GRP2SEL_Msk);
	tmpreg |= (SetValue & ETIMx_ETxINSEL_GRP2SEL_Msk);
	ETIMx->ETxINSEL = tmpreg;
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET GROUP2 �ź�ѡ��
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ETIMx_ETxINSEL_GRP2SEL_ET1_UART0_RX				ET1 000 = UART0_RX
			/ETIMx_ETxINSEL_GRP2SEL_ET1_UART1_RX			ET1 001 = UART1_RX
			/ETIMx_ETxINSEL_GRP2SEL_ET1_XTLF					ET1 010 = XTLF
			/ETIMx_ETxINSEL_GRP2SEL_ET1_ET1_IN1				ET1 011 = ET1_IN1
			/ETIMx_ETxINSEL_GRP2SEL_ET1_ET1_IN2				ET1 100 = ET1_IN2
			/ETIMx_ETxINSEL_GRP2SEL_ET1_CMP1O					ET1 101 = CMP1O���Ƚ���1�����
			/ETIMx_ETxINSEL_GRP2SEL_ET1_CMP2O					ET1 110 = CMP2O���Ƚ���2���
			/ETIMx_ETxINSEL_GRP2SEL_ET1_LPTO					ET1 111 = LPTO
			/ETIMx_ETxINSEL_GRP2SEL_ET2_UART2_RX			ET2 000 = UART2_RX
			/ETIMx_ETxINSEL_GRP2SEL_ET2_UART3_RX			ET2 001 = UART3_RX
			/ETIMx_ETxINSEL_GRP2SEL_ET2_XTLF					ET2 010 = XTLF
			/ETIMx_ETxINSEL_GRP2SEL_ET2_ET2_IN1				ET2 011 = ET2_IN1
			/ETIMx_ETxINSEL_GRP2SEL_ET2_ET2_IN2				ET2 100 = ET2_IN2
			/ETIMx_ETxINSEL_GRP2SEL_ET2_CMP1O					ET2 101 = CMP1O���Ƚ���1�����
			/ETIMx_ETxINSEL_GRP2SEL_ET2_CMP2O					ET2 110 = CMP2O���Ƚ���2�����
			/ETIMx_ETxINSEL_GRP2SEL_ET2_LPTO					ET2 111 = LPTO
			/ETIMx_ETxINSEL_GRP2SEL_ET3_ET3_IN12			ET3 000 = ET3_IN1
			/ETIMx_ETxINSEL_GRP2SEL_ET3_XTLF					ET3 001 = XTLF
			/ETIMx_ETxINSEL_GRP2SEL_ET3_UART4_RX			ET3 010 = UART4_RX
			/ETIMx_ETxINSEL_GRP2SEL_ET3_UART5_RX			ET3 011 = UART5_RX
			/ETIMx_ETxINSEL_GRP2SEL_ET3_RTCSEC				ET3 100 = RTCSEC
			/ETIMx_ETxINSEL_GRP2SEL_ET4_ET4_IN1				ET4 000 = ET4_IN1
			/ETIMx_ETxINSEL_GRP2SEL_ET4_XTLF					ET4 001 = XTLF
			/ETIMx_ETxINSEL_GRP2SEL_ET4_UART_RX22			ET4 010 = UART_RX2
			/ETIMx_ETxINSEL_GRP2SEL_ET4_UART_RX0			ET4 011 = UART_RX0
			/ETIMx_ETxINSEL_GRP2SEL_ET4_CMP1O					ET4 100 = CMP1O���Ƚ���1�����
			/ETIMx_ETxINSEL_GRP2SEL_ET4_CMP2O					ET4 101 = CMP2O���Ƚ���2�����
			/ETIMx_ETxINSEL_GRP2SEL_ET4_RTCSEC				ET4 110= RTCSEC
			/ETIMx_ETxINSEL_GRP2SEL_ET4_LPTO					ET4 111= LPTO
*********************************/
uint32_t ETIMx_ETxINSEL_GRP2SEL_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxINSEL & ETIMx_ETxINSEL_GRP2SEL_Msk);
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET GROUP1 �ź�ѡ��
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			ETIMx_ETxINSEL_GRP1SEL_ET1_APBCLK			ET1 00 = APBCLK
			/ETIMx_ETxINSEL_GRP1SEL_ET1_XTLF			ET1 01 = XTLF
			/ETIMx_ETxINSEL_GRP1SEL_ET1_RCLP			ET1 10 = RCLP
			/ETIMx_ETxINSEL_GRP1SEL_ET1_ET1_IN0		ET1 11 = ET1_IN0
			/ETIMx_ETxINSEL_GRP1SEL_ET2_APBCLK		ET2 00 = APBCLK
			/ETIMx_ETxINSEL_GRP1SEL_ET2_XTLF			ET2 01 = XTLF
			/ETIMx_ETxINSEL_GRP1SEL_ET2_RCLP			ET2 10 = RCLP
			/ETIMx_ETxINSEL_GRP1SEL_ET2_ET2_IN0		ET2 11 = ET2_IN0
			/ETIMx_ETxINSEL_GRP1SEL_ET3_APBCLK		ET3 00 = APBCLK
			/ETIMx_ETxINSEL_GRP1SEL_ET3_ET3_IN0		ET3 01 = ET3_IN0
			/ETIMx_ETxINSEL_GRP1SEL_ET3_RTCSEC		ET3 10 = RTCSEC
			/ETIMx_ETxINSEL_GRP1SEL_ET3_RCLP			ET3 11 = RCLP
			/ETIMx_ETxINSEL_GRP1SEL_ET4_APBCLK		ET4 00 = APBCLK
			/ETIMx_ETxINSEL_GRP1SEL_ET4_ET4_IN0		ET4 01 = ET4_IN0
			/ETIMx_ETxINSEL_GRP1SEL_ET4_RTC64HZ		ET4 10 = RTC64HZ/
			/ETIMx_ETxINSEL_GRP1SEL_ET4_LPTO			ET4 11 = LPTO
���: ��
*********************************/
void ETIMx_ETxINSEL_GRP1SEL_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxINSEL;
	tmpreg &= ~(ETIMx_ETxINSEL_GRP1SEL_Msk);
	tmpreg |= (SetValue & ETIMx_ETxINSEL_GRP1SEL_Msk);
	ETIMx->ETxINSEL = tmpreg;
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET GROUP1 �ź�ѡ��
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ETIMx_ETxINSEL_GRP1SEL_ET1_APBCLK			ET1 00 = APBCLK
			/ETIMx_ETxINSEL_GRP1SEL_ET1_XTLF			ET1 01 = XTLF
			/ETIMx_ETxINSEL_GRP1SEL_ET1_RCLP			ET1 10 = RCLP
			/ETIMx_ETxINSEL_GRP1SEL_ET1_ET1_IN0		ET1 11 = ET1_IN0
			/ETIMx_ETxINSEL_GRP1SEL_ET2_APBCLK		ET2 00 = APBCLK
			/ETIMx_ETxINSEL_GRP1SEL_ET2_XTLF			ET2 01 = XTLF
			/ETIMx_ETxINSEL_GRP1SEL_ET2_RCLP			ET2 10 = RCLP
			/ETIMx_ETxINSEL_GRP1SEL_ET2_ET2_IN0		ET2 11 = ET2_IN0
			/ETIMx_ETxINSEL_GRP1SEL_ET3_APBCLK		ET3 00 = APBCLK
			/ETIMx_ETxINSEL_GRP1SEL_ET3_ET3_IN0		ET3 01 = ET3_IN0
			/ETIMx_ETxINSEL_GRP1SEL_ET3_RTCSEC		ET3 10 = RTCSEC
			/ETIMx_ETxINSEL_GRP1SEL_ET3_RCLP			ET3 11 = RCLP
			/ETIMx_ETxINSEL_GRP1SEL_ET4_APBCLK		ET4 00 = APBCLK
			/ETIMx_ETxINSEL_GRP1SEL_ET4_ET4_IN0		ET4 01 = ET4_IN0
			/ETIMx_ETxINSEL_GRP1SEL_ET4_RTC64HZ		ET4 10 = RTC64HZ/
			/ETIMx_ETxINSEL_GRP1SEL_ET4_LPTO			ET4 11 = LPTO
*********************************/
uint32_t ETIMx_ETxINSEL_GRP1SEL_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxINSEL & ETIMx_ETxINSEL_GRP1SEL_Msk);
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET Signal1(����Դ)��Ԥ��Ƶ
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			SetValue: 00-FF(00��ʾ1��Ƶ��FF��ʾ256��Ƶ)
���: ��
*********************************/
void ETIMx_ETxPESCALE1_Write(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	ETIMx->ETxPESCALE1 = (SetValue & ETIMx_ETxPESCALE1_PRESCALE1_Msk);
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET Signal1(����Դ) ��Ԥ��Ƶ
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: 00-FF(00��ʾ1��Ƶ��FF��ʾ256��Ƶ)
*********************************/
uint32_t ETIMx_ETxPESCALE1_Read(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxPESCALE1 & ETIMx_ETxPESCALE1_PRESCALE1_Msk);
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET Signal2(��׽Դ)��Ԥ��Ƶ
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			SetValue: 00-FF(00��ʾ1��Ƶ��FF��ʾ256��Ƶ)
���: ��
*********************************/
void ETIMx_ETxPESCALE2_Write(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	ETIMx->ETxPESCALE2 = (SetValue & ETIMx_ETxPESCALE2_PRESCALE2_Msk);
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET Signal2(��׽Դ)��Ԥ��Ƶ
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: 00-FF(00��ʾ1��Ƶ��FF��ʾ256��Ƶ)
*********************************/
uint32_t ETIMx_ETxPESCALE2_Read(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxPESCALE2 & ETIMx_ETxPESCALE2_PRESCALE2_Msk);
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET ������ֵ
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			SetValue: 00-FFFF
���: ��
*********************************/
void ETIMx_ETxIVR_Write(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	ETIMx->ETxIVR = (SetValue & ETIMx_ETxIVR_INITVALUE_Msk);
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET ����ֵ
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: 00-FFFF
*********************************/
uint32_t ETIMx_ETxIVR_Read(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxIVR & ETIMx_ETxIVR_INITVALUE_Msk);
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET �Ƚ�ֵ(��ֵ�����ֵ�Ƚϣ������ֵ>=��ֵ�����������ƥ���ź����������ģ�飬��������Ӧ�ж�)
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			SetValue: 00-FFFF
���: ��
*********************************/
void ETIMx_ETxCMP_Write(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	ETIMx->ETxCMP = (SetValue & ETIMx_ETxCMP_CMP_Msk);
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET �Ƚ�ֵ
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: 00-FFFF
*********************************/
uint32_t ETIMx_ETxCMP_Read(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxCMP & ETIMx_ETxCMP_CMP_Msk);
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET �Ƚ��ж�
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			ENABLE/DISABLE		�Ƚ��ж�ʹ��/�Ƚ��жϽ�ֹ	
���: ��
*********************************/
void ETIMx_ETxIE_CMPIE_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxIE |= (ETIMx_ETxIE_CMPIE_Msk);
	}
	else
	{
		ETIMx->ETxIE &= ~(ETIMx_ETxIE_CMPIE_Msk);
	}
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET �Ƚ��ж�����
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ENABLE/DISABLE		�Ƚ��ж�ʹ��/�Ƚ��жϽ�ֹ	
*********************************/
FunState ETIMx_ETxIE_CMPIE_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIE & (ETIMx_ETxIE_CMPIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET ��׽�ж�
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			ENABLE/DISABLE		��׽�ж�ʹ��/��׽�жϽ�ֹ	
���: ��
*********************************/
void ETIMx_ETxIE_CAPIE_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxIE |= (ETIMx_ETxIE_CAPIE_Msk);
	}
	else
	{
		ETIMx->ETxIE &= ~(ETIMx_ETxIE_CAPIE_Msk);
	}
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET ��׽�ж�
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ENABLE/DISABLE		��׽�ж�ʹ��/��׽�жϽ�ֹ	
*********************************/
FunState ETIMx_ETxIE_CAPIE_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIE & (ETIMx_ETxIE_CAPIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�����ET ����ж�
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
			ENABLE/DISABLE		����ж�ʹ��/����жϽ�ֹ	
���: ��
*********************************/
void ETIMx_ETxIE_OVIE_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxIE |= (ETIMx_ETxIE_OVIE_Msk);
	}
	else
	{
		ETIMx->ETxIE &= ~(ETIMx_ETxIE_OVIE_Msk);
	}
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET ����ж�
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ENABLE/DISABLE		����ж�ʹ��/����жϽ�ֹ	
*********************************/
FunState ETIMx_ETxIE_OVIE_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIE & (ETIMx_ETxIE_OVIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ET �Ƚ��жϱ�־
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ��
*********************************/
void ETIMx_ETxIF_CMPIF_Clr(ETIMx_Type* ETIMx)
{
	ETIMx->ETxIF = ETIMx_ETxIF_CMPIF_Msk;
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET �Ƚ��жϱ�־
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: SET/RESET			�ѷ����Ƚ��ж�/δ�����Ƚ��ж�
*********************************/
FlagStatus ETIMx_ETxIF_CMPIF_Chk(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIF & ETIMx_ETxIF_CMPIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET ��׽��״̬
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: SET/RESET			�����Ȳ�׽ģʽʱ��ʾ��׽������/�����Ȳ�׽ģʽʱ��ʾ��׽������
*********************************/
FlagStatus ETIMx_ETxIF_EDGESTA_Chk(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIF & ETIMx_ETxIF_EDGESTA_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ET ������׽�źű�־
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ��
*********************************/
void ETIMx_ETxIF_CAPIF_Clr(ETIMx_Type* ETIMx)
{
	ETIMx->ETxIF = ETIMx_ETxIF_CAPIF_Msk;
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET ������׽�źű�־
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: SET/RESET			��׽��ָ������/δ��׽��ָ������
*********************************/
FlagStatus ETIMx_ETxIF_CAPIF_Chk(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIF & ETIMx_ETxIF_CAPIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ET ��������źű�־
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ��
*********************************/
void ETIMx_ETxIF_OVIF_Clr(ETIMx_Type* ETIMx)
{
	ETIMx->ETxIF = ETIMx_ETxIF_OVIF_Msk;
}
/*********************************
externded timer��λ���������ƺ��� 
���ܣ���ȡET ��������źű�־
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: SET/RESET			�����������/δ�������
*********************************/
FlagStatus ETIMx_ETxIF_OVIF_Chk(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIF & ETIMx_ETxIF_OVIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
externded timer��λ���������ƺ��� 
���ܣ�ET��ʼ��Ϊȱʡ����
����: ETIM1/ETIM2/ETIM3/ETIM4  	��ʱ������
���: ��
*********************************/
void ETIMx_Deinit(ETIMx_Type* ETIMx)
{
	ETIMx->ETxCR = 0x00000000;
	ETIMx->ETxINSEL = 0x00000000;
	ETIMx->ETxPESCALE1 = 0x00000000;
	ETIMx->ETxPESCALE2 = 0x00000000;
	ETIMx->ETxIVR = 0x00000000;
	ETIMx->ETxCMP = 0x00000000;
	ETIMx->ETxIE = 0x00000000;
	//ETIMx->ETxIF = 0x00000000;
}
//Code_End


/*ETIMx ��ʼ�����ú���*/
void ETIMx_Init(ETIMx_Type* ETIMx, ETIM_InitTypeDef* para)
{
	//�ź�Դ����
	ETIMx_ETxINSEL_SIG1SEL_Set(ETIMx, para->sig_src_para.SIG1SEL);		/* �ڲ��ź�1Դѡ���ڼ���ģʽ�¼���Դ���ɴ�ѡ�񣬲�׽ģʽ�¼���Դ�� */
	ETIMx_ETxINSEL_SIG2SEL_Set(ETIMx, para->sig_src_para.SIG2SEL);		/* �ڲ��ź�2Դѡ��(��׽Դ) */
	ETIMx_ETxINSEL_GRP1SEL_Set(ETIMx, para->sig_src_para.GRP1SEL);		/* GROUP1 �ź�ѡ����� */
	ETIMx_ETxINSEL_GRP2SEL_Set(ETIMx, para->sig_src_para.GRP2SEL);		/* GROUP2 �ź�ѡ����� */
	ETIMx_ETxPESCALE1_Write(ETIMx, para->sig_src_para.PRESCALE1);		/* ETxԤ��Ƶ�Ĵ���1 */
	ETIMx_ETxPESCALE2_Write(ETIMx, para->sig_src_para.PRESCALE2);		/* ETxԤ��Ƶ�Ĵ���2 */
	
	//���������
	ETIMx_ETxCR_EXFLT_Setable(ETIMx, para->ctrl_para.EXFLT);		/* �������������˲�ʹ�� */
	ETIMx_ETxCR_MOD_Set(ETIMx, para->ctrl_para.MOD);				/* ����ģʽѡ�� */
	ETIMx_ETxCR_CASEN_Setable(ETIMx, para->ctrl_para.CASEN);		/* ��չ��ʱ������ʹ�� */
	ETIMx_ETxCR_EDGESEL_Set(ETIMx, para->ctrl_para.EDGESEL);		/* ����ģʽ���ط�ʽѡ�񣨼���ʱ��ѡ��mcu_clkʱ��λ��Ч�����ǲ���mcu_clkʱ�������ؼ����� */

	ETIMx_ETxCR_PWM_Setable(ETIMx, para->ctrl_para.PWM);		/* PWM������� */

	ETIMx_ETxCR_CAPMOD_Set(ETIMx, para->ctrl_para.CAPMOD);			/* ��׽ģʽ���� */
	ETIMx_ETxCR_CAPCLR_Setable(ETIMx, para->ctrl_para.CAPCLR);		/* �����㲶׽ģʽ���� */
	ETIMx_ETxCR_CAPONCE_Setable(ETIMx, para->ctrl_para.CAPONCE);	/* ���β�׽���� */
	ETIMx_ETxCR_CAPEDGE_Set(ETIMx, para->ctrl_para.CAPEDGE);		/* ��׽��ѡ�� */

	ETIMx_ETxIVR_Write(ETIMx, para->ctrl_para.INITVALUE);	/* ETx��ֵ�Ĵ��� */
	ETIMx_ETxCMP_Write(ETIMx, para->ctrl_para.CMP);			/* ETx�ȽϼĴ��� */

	ETIMx_ETxIE_CMPIE_Setable(ETIMx, para->ctrl_para.CMPIE);		/* ��չ��ʱ���Ƚ��ж�ʹ�� */
	ETIMx_ETxIE_CAPIE_Setable(ETIMx, para->ctrl_para.CAPIE);		/* ��չ��ʱ����׽�ж�ʹ�� */
	ETIMx_ETxIE_OVIE_Setable(ETIMx, para->ctrl_para.OVIE);			/* ��չ��ʱ������ж�ʹ�� */

	ETIMx_ETxCR_CEN_Setable(ETIMx, para->ctrl_para.CEN);		/* ����� */
}


/******END OF FILE****/

