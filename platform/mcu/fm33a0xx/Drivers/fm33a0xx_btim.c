/**
  ******************************************************************************
  * @file    fm33a0xx_btim.c
  * @author  FM33a0 Application Team
  * @version V2.0.2
  * @date    
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33a0xx_btim.h"  


/** @addtogroup fm33a0_StdPeriph_Driver
  * @{
  */

/** @defgroup BTIM 
  * @brief BTIM driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup BTIM_Private_Functions
  * @{
  */ 

//Code_Start
//2018-04-02-13-20-21
//FM33A0XX_Driver_Gen_V1.4

/*********************************
basic timer��λ����������ƺ��� 
���ܣ�BT��λ��������ͣ����
����: ENABLE ���λ������
      DISABLE ֹͣ��λ������
      BTIM1/BTIM2  ��ʱ������
���: ��
*********************************/
void BTIMx_BTCR1_CHEN_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTCR1 |= (BTIMx_BTCR1_CHEN_Msk);
	}
	else
	{
		BTIMx->BTCR1 &= ~(BTIMx_BTCR1_CHEN_Msk);
	}
}
/*********************************
basic timer��λ����������λ״̬��ȡ���� 
���ܣ���ȡBT��λ��������ͣ����״̬
����: BTIM1/BTIM2  ��ʱ������
���: ENABLE ��ǰBT��λ����������
      DISABLE ��ǰBT��λ��������ֹͣ
*********************************/
FunState BTIMx_BTCR1_CHEN_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTCR1 & (BTIMx_BTCR1_CHEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
basic timer��λ����������ƺ��� 
���ܣ�BT��λ��������ͣ����
����: ENABLE ���λ������
      DISABLE ֹͣ��λ������
      BTIM1/BTIM2  ��ʱ������
���: ��
*********************************/
void BTIMx_BTCR1_CLEN_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTCR1 |= (BTIMx_BTCR1_CLEN_Msk);
	}
	else
	{
		BTIMx->BTCR1 &= ~(BTIMx_BTCR1_CLEN_Msk);
	}
}
/*********************************
basic timer��λ����������λ״̬��ȡ���� 
���ܣ���ȡBT��λ��������ͣ����״̬
����: BTIM1/BTIM2  ��ʱ������
���: ENABLE ��ǰBT��λ����������
      DISABLE ��ǰBT��λ��������ֹͣ
*********************************/
FunState BTIMx_BTCR1_CLEN_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTCR1 & (BTIMx_BTCR1_CLEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
basic timer����ģʽ���ú��� 
���ܣ�����BT����ģʽ
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCR1_MODE_8BITS_TIM_CNT/BTIMx_BTCR1_MODE_16BITS_CAP 8λ/16λ��ʱ��      
���: ��
*********************************/
void BTIMx_BTCR1_MODE_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR1;
	tmpreg &= ~(BTIMx_BTCR1_MODE_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR1_MODE_Msk);
	BTIMx->BTCR1 = tmpreg;
}
/*********************************
basic timer��ȡ����ģʽ���ú��� 
���ܣ���ȡBT����ģʽ
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCR1_MODE_8BITS_TIM_CNT/BTIMx_BTCR1_MODE_16BITS_CAP 8λ/16λ��ʱ��
*********************************/
uint32_t BTIMx_BTCR1_MODE_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR1 & BTIMx_BTCR1_MODE_Msk);
}

/*********************************
basic timer����ģʽ���ú��� 
���ܣ�����BT�ļ����ػ�׽��
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCR1_EDGESEL_POS/BTIMx_BTCR1_EDGESEL_NEG �����ػ�׽��Ϊ������/�½���      
���: ��
*********************************/
void BTIMx_BTCR1_EDGESEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR1;
	tmpreg &= ~(BTIMx_BTCR1_EDGESEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR1_EDGESEL_Msk);
	BTIMx->BTCR1 = tmpreg;
}
/*********************************
basic timer��ȡ����ģʽ���ú��� 
���ܣ���ȡBT�ļ����ػ�׽�ؾ��巽ʽ
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCR1_EDGESEL_POS/BTIMx_BTCR1_EDGESEL_NEG �����ػ�׽��Ϊ������/�½��� 
*********************************/
uint32_t BTIMx_BTCR1_EDGESEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR1 & BTIMx_BTCR1_EDGESEL_Msk);
}


/*********************************
basic timer����ģʽ���ú��� 
���ܣ�����BT�Ĳ�׽ģʽ���ƣ�����׽ģʽ����Ч��
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCR1_CAPMOD_PAUSE_PERIOD/BTIMx_BTCR1_CAPMOD_PAUSE_WIDTH �������ڲ�׽/�����Ȳ�׽
���: ��
*********************************/
void BTIMx_BTCR1_CAPMOD_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR1;
	tmpreg &= ~(BTIMx_BTCR1_CAPMOD_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR1_CAPMOD_Msk);
	BTIMx->BTCR1 = tmpreg;
}
/*********************************
basic timer��ȡ����ģʽ���ú��� 
���ܣ���ȡBT�Ĳ�׽ģʽ���ƣ�����׽ģʽ����Ч������
����: BTIM1/BTIM2  ��ʱ������    
���: BTIMx_BTCR1_CAPMOD_PAUSE_PERIOD/BTIMx_BTCR1_CAPMOD_PAUSE_WIDTH �������ڲ�׽/�����Ȳ�׽
*********************************/
uint32_t BTIMx_BTCR1_CAPMOD_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR1 & BTIMx_BTCR1_CAPMOD_Msk);
}


/*********************************
basic timer����ģʽ���ú��� 
���ܣ�����BT�Ĵ����㲶׽ģʽ�����Ƿ�����
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCR1_CAPCLR_CAP_CNT_NO_CLR/BTIMx_BTCR1_CAPCLR_CAP_CNT_CLR  ��׽�������������/��׽�����������    
���: ��
*********************************/
void BTIMx_BTCR1_CAPCLR_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR1;
	tmpreg &= ~(BTIMx_BTCR1_CAPCLR_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR1_CAPCLR_Msk);
	BTIMx->BTCR1 = tmpreg;
}
/*********************************
basic timer��ȡ����ģʽ���ú��� 
���ܣ���ȡBT�Ĳ�׽ģʽ������������
����: BTIM1/BTIM2  ��ʱ������    
���: BTIMx_BTCR1_CAPCLR_CAP_CNT_NO_CLR/BTIMx_BTCR1_CAPCLR_CAP_CNT_CLR  ��׽�������������/��׽�����������    
*********************************/
uint32_t BTIMx_BTCR1_CAPCLR_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR1 & BTIMx_BTCR1_CAPCLR_Msk);
}

/*********************************
basic timer����ģʽ���ú��� 
���ܣ�����BT�Ƿ񵥴β�׽
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCR1_CAPONCE_CONTINUE/BTIMx_BTCR1_CAPONCE_SINGLE    ������׽/���β�׽
���: ��
*********************************/
void BTIMx_BTCR1_CAPONCE_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR1;
	tmpreg &= ~(BTIMx_BTCR1_CAPONCE_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR1_CAPONCE_Msk);
	BTIMx->BTCR1 = tmpreg;
}
/*********************************
basic timer����ģʽ���ú��� 
���ܣ���BT���ò�׽��ʽ
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCR1_CAPONCE_CONTINUE/BTIMx_BTCR1_CAPONCE_SINGLE    ������׽/���β�׽
*********************************/
uint32_t BTIMx_BTCR1_CAPONCE_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR1 & BTIMx_BTCR1_CAPONCE_Msk);
}

/*********************************
basic timer���ģʽ���ú��� 
���ܣ�����BT PWM����Ƿ���Ч
����: BTIM1/BTIM2  ��ʱ������
      ENABLE/DISABLE   PWM���ģʽ��Ч/��Ч
���: ��
*********************************/
void BTIMx_BTCR1_PWM_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTCR1 |= (BTIMx_BTCR1_PWM_Msk);
	}
	else
	{
		BTIMx->BTCR1 &= ~(BTIMx_BTCR1_PWM_Msk);
	}
}
/*********************************
basic timer���ģʽ���ú��� 
���ܣ���BT���� PWM����Ƿ���Ч
����: BTIM1/BTIM2  ��ʱ������
���: ENABLE/DISABLE   PWM���ģʽ��Ч/��Ч
*********************************/
FunState BTIMx_BTCR1_PWM_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTCR1 & (BTIMx_BTCR1_PWM_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
basic timer�������ڲ�����Դ�ź�ѡ�����ú��� 
���ܣ�����BT �������ڲ�����Դ�ź�ѡ��
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCR2_SIG2SEL_GROUP1/BTIMx_BTCR2_SIG2SEL_GROUP2 �ڲ�����Դѡ��Group1/Group2
���: ��
*********************************/
void BTIMx_BTCR2_SIG2SEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR2;
	tmpreg &= ~(BTIMx_BTCR2_SIG2SEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR2_SIG2SEL_Msk);
	BTIMx->BTCR2 = tmpreg;
}
/*********************************
basic timer�������ڲ�����Դ�ź�ѡ�����ú���
���ܣ���ȡBT�������ڲ�����Դ�ź�ѡ��
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCR2_SIG2SEL_GROUP1/BTIMx_BTCR2_SIG2SEL_GROUP2 �ڲ�����Դѡ��Group1/Group2
*********************************/
uint32_t BTIMx_BTCR2_SIG2SEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR2 & BTIMx_BTCR2_SIG2SEL_Msk);
}

/*********************************
basic timer�������ڲ���׽Դ�ź�ѡ�����ú��� 
���ܣ�����BT �������ڲ���׽Դ�ź�ѡ��
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCR2_SIG1SEL_GROUP1/BTIMx_BTCR2_SIG1SEL_GROUP2 �ڲ���׽Դѡ��Group1/Group2
���: ��
*********************************/
void BTIMx_BTCR2_SIG1SEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR2;
	tmpreg &= ~(BTIMx_BTCR2_SIG1SEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR2_SIG1SEL_Msk);
	BTIMx->BTCR2 = tmpreg;
}
/*********************************
basic timer�������ڲ���׽Դ�ź�ѡ�����ú���
���ܣ���ȡBT�������ڲ���׽Դ�ź�ѡ��
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCR2_SIG1SEL_GROUP1/BTIMx_BTCR2_SIG1SEL_GROUP2 �ڲ���׽Դѡ��Group1/Group2
*********************************/
uint32_t BTIMx_BTCR2_SIG1SEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR2 & BTIMx_BTCR2_SIG1SEL_Msk);
}

/*********************************
basic timer��������λ������Դѡ�����ú��� 
���ܣ�����BT ��λ������Դѡ��
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCR2_CNTHSEL_CNTL/BTIMx_BTCR2_CNTHSEL_CAPSRC/BTIMx_BTCR2_CNTHSEL_CNTSRC_DIR ���λ���������16λ������/ѡ���ڲ���׽�ź�Դ/ѡ���ڲ������ź�Դ���ⲿDIR�������
���: ��
*********************************/
void BTIMx_BTCR2_CNTHSEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR2;
	tmpreg &= ~(BTIMx_BTCR2_CNTHSEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR2_CNTHSEL_Msk);
	BTIMx->BTCR2 = tmpreg;
}
/*********************************
basic timer��������λ������Դѡ�����ú���
���ܣ���ȡBT��������λ������Դѡ��
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCR2_CNTHSEL_CNTL/BTIMx_BTCR2_CNTHSEL_CAPSRC/BTIMx_BTCR2_CNTHSEL_CNTSRC_DIR ���λ���������16λ������/ѡ���ڲ���׽�ź�Դ/ѡ���ڲ������ź�Դ���ⲿDIR�������
*********************************/
uint32_t BTIMx_BTCR2_CNTHSEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR2 & BTIMx_BTCR2_CNTHSEL_Msk);
}

/*********************************
basic timer�������ⲿ����DIR�������ú��� 
���ܣ�����BT �ⲿ����DIR����
����: BTIM1/BTIM2  ��ʱ������
      ENABLE/DISABLE	�ⲿ����DIR������Ч/��Ч
���: ��
*********************************/
void BTIMx_BTCR2_DIREN_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTCR2 |= (BTIMx_BTCR2_DIREN_Msk);
	}
	else
	{
		BTIMx->BTCR2 &= ~(BTIMx_BTCR2_DIREN_Msk);
	}
}
/*********************************
basic timer�������ⲿ����DIR�������ú��� 
���ܣ���ȡBT�ⲿ����DIR����״̬
����: BTIM1/BTIM2  ��ʱ������
���: NABLE/DISABLE	�ⲿ����DIR������Ч/��Ч
*********************************/
FunState BTIMx_BTCR2_DIREN_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTCR2 & (BTIMx_BTCR2_DIREN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
basic timer�������ڲ�����DIR�������ú��� 
���ܣ�����BT �ڲ�����DIR����
����: BTIM1/BTIM2  ��ʱ������
      ENABLE/DISABLE	�ڲ�����DIR������Ч/��Ч
���: ��
*********************************/
void BTIMx_BTCR2_STDIR_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTCR2 |= (BTIMx_BTCR2_STDIR_Msk);
	}
	else
	{
		BTIMx->BTCR2 &= ~(BTIMx_BTCR2_STDIR_Msk);
	}
}
/*********************************
basic timer�������ڲ�����DIR�������ú��� 
���ܣ���ȡBT�ڲ�����DIR����״̬
����: BTIM1/BTIM2  ��ʱ������
���: NABLE/DISABLE	�ڲ�����DIR������Ч/��Ч
*********************************/
FunState BTIMx_BTCR2_STDIR_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTCR2 & (BTIMx_BTCR2_STDIR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
basic timer��λ���������ƺ��� 
���ܣ�����BT ��λ������ʹ�ܿ���ѡ���ź�
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCR2_SRCSEL_STDIR_EXSIG2/BTIMx_BTCR2_SRCSEL_WITHOUT_DIR	��λ��������STDIR���ⲿEX_SIG2�������/��λ����������DIR����
���: ��
*********************************/
void BTIMx_BTCR2_SRCSEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR2;
	tmpreg &= ~(BTIMx_BTCR2_SRCSEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR2_SRCSEL_Msk);
	BTIMx->BTCR2 = tmpreg;
}

/*********************************
basic timer��λ���������ƺ��� 
���ܣ���ȡBT��λ������ʹ�ܿ���ѡ���ź�
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCR2_SRCSEL_STDIR_EXSIG2/BTIMx_BTCR2_SRCSEL_WITHOUT_DIR	��λ��������STDIR���ⲿEX_SIG2�������/��λ����������DIR����
*********************************/
uint32_t BTIMx_BTCR2_SRCSEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR2 & BTIMx_BTCR2_SRCSEL_Msk);
}

/*********************************
basic timer�����ź�2���ƺ��� 
���ܣ�����BT �����ź�2����
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCR2_DIRPO_NO_ANTI/BTIMx_BTCR2_DIRPO_ANTI	���ⲿ����DIR�źŲ�����/���ⲿ����DIR�ź�ȡ����
���: ��
*********************************/
void BTIMx_BTCR2_DIRPO_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR2;
	tmpreg &= ~(BTIMx_BTCR2_DIRPO_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR2_DIRPO_Msk);
	BTIMx->BTCR2 = tmpreg;
}
/*********************************
basic timer�����ź�2���ƺ��� 
���ܣ���ȡBT�����ź�2����
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCR2_DIRPO_NO_ANTI/BTIMx_BTCR2_DIRPO_ANTI	���ⲿ����DIR�źŲ�����/���ⲿ����DIR�ź�ȡ����
*********************************/
uint32_t BTIMx_BTCR2_DIRPO_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR2 & BTIMx_BTCR2_DIRPO_Msk);
}

/*********************************
basic timer RTCOUT2�ź�Դѡ���� 
���ܣ�����BT RTCOUT2�ź�Դ
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCFG1_RTCSEL2_RTC_32768/	RTCģ�������32768Hz�ź�
      BTIMx_BTCFG1_RTCSEL2_RTC_SEC/	RTCģ����������ź�
      BTIMx_BTCFG1_RTCSEL2_RTC_MIN/	RTCģ������ķ��ź�
      BTIMx_BTCFG1_RTCSEL2_LPTIM_OUT	LPTIMģ��������ź�
���: ��
*********************************/
void BTIMx_BTCFG1_RTCSEL2_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG1;
	tmpreg &= ~(BTIMx_BTCFG1_RTCSEL2_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG1_RTCSEL2_Msk);
	BTIMx->BTCFG1 = tmpreg;
}
/*********************************
basic timer RTCOUT2�ź�Դѡ���� 
���ܣ���ȡBT RTCOUT2�ź�Դ����
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCFG1_RTCSEL2_RTC_32768/	RTCģ�������32768Hz�ź�
      BTIMx_BTCFG1_RTCSEL2_RTC_SEC/	RTCģ����������ź�
      BTIMx_BTCFG1_RTCSEL2_RTC_MIN/	RTCģ������ķ��ź�
      BTIMx_BTCFG1_RTCSEL2_LPTIM_OUT	LPTIMģ��������ź�
*********************************/
uint32_t BTIMx_BTCFG1_RTCSEL2_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG1 & BTIMx_BTCFG1_RTCSEL2_Msk);
}


/*********************************
basic timer RTCOUT1�ź�Դѡ���� 
���ܣ�����BT RTCOUT1�ź�Դ
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCFG1_RTCSEL1_RTC_32768/	RTCģ�������32768Hz�ź�
      BTIMx_BTCFG1_RTCSEL1_RTC_SEC/	RTCģ����������ź�
      BTIMx_BTCFG1_RTCSEL1_RTC_MIN/	RTCģ������ķ��ź�
      BTIMx_BTCFG1_RTCSEL1_LPTIM_OUT	LPTIMģ��������ź�
���: ��
*********************************/
void BTIMx_BTCFG1_RTCSEL1_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG1;
	tmpreg &= ~(BTIMx_BTCFG1_RTCSEL1_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG1_RTCSEL1_Msk);
	BTIMx->BTCFG1 = tmpreg;
}
/*********************************
basic timer RTCOUT1�ź�Դѡ����  
���ܣ���ȡBT RTCOUT1�ź�Դ����
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCFG1_RTCSEL1_RTC_32768/	RTCģ�������32768Hz�ź�
      BTIMx_BTCFG1_RTCSEL1_RTC_SEC/	RTCģ����������ź�
      BTIMx_BTCFG1_RTCSEL1_RTC_MIN/	RTCģ������ķ��ź�
      BTIMx_BTCFG1_RTCSEL1_LPTIM_OUT	LPTIMģ��������ź�
*********************************/
uint32_t BTIMx_BTCFG1_RTCSEL1_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG1 & BTIMx_BTCFG1_RTCSEL1_Msk);
}

/*********************************
basic timer Group2�ź�Դѡ���� 
���ܣ�����BT Group2�ź�Դ
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCFG1_GRP2SEL_APBCLK/	ϵͳʱ��APBCLK
      BTIMx_BTCFG1_GRP2SEL_RTCOUT2/	RTCʱ��RTCOUT2
      BTIMx_BTCFG1_GRP2SEL_IN_SIG2/	�ڲ������ź�2
      BTIMx_BTCFG1_GRP2SEL_EX_SIG2	�ⲿ�����ź�2
���: ��
*********************************/
void BTIMx_BTCFG1_GRP2SEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG1;
	tmpreg &= ~(BTIMx_BTCFG1_GRP2SEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG1_GRP2SEL_Msk);
	BTIMx->BTCFG1 = tmpreg;
}
/*********************************
basic timer Group2�ź�Դѡ����
���ܣ���ȡBT Group2�ź�Դ����
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCFG1_GRP2SEL_APBCLK/	ϵͳʱ��APBCLK
      BTIMx_BTCFG1_GRP2SEL_RTCOUT2/	RTCʱ��RTCOUT2
      BTIMx_BTCFG1_GRP2SEL_IN_SIG2/	�ڲ������ź�2
      BTIMx_BTCFG1_GRP2SEL_EX_SIG2	�ⲿ�����ź�2
*********************************/
uint32_t BTIMx_BTCFG1_GRP2SEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG1 & BTIMx_BTCFG1_GRP2SEL_Msk);
}
/*********************************
basic timer Group1�ź�Դѡ���� 
���ܣ�����BT Group1�ź�Դ
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCFG1_GRP1SEL_APBCLK/	ϵͳʱ��APBCLK
      BTIMx_BTCFG1_GRP1SEL_RTCOUT2/	RTCʱ��RTCOUT2
      BTIMx_BTCFG1_GRP1SEL_IN_SIG2/	�ڲ������ź�2
      BTIMx_BTCFG1_GRP1SEL_EX_SIG2	�ⲿ�����ź�2
���: ��
*********************************/
void BTIMx_BTCFG1_GRP1SEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG1;
	tmpreg &= ~(BTIMx_BTCFG1_GRP1SEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG1_GRP1SEL_Msk);
	BTIMx->BTCFG1 = tmpreg;
}
/*********************************
basic timer Group1�ź�Դѡ����
���ܣ���ȡBT Group1�ź�Դ����
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCFG1_GRP1SEL_APBCLK/	ϵͳʱ��APBCLK
      BTIMx_BTCFG1_GRP1SEL_RTCOUT2/	RTCʱ��RTCOUT2
      BTIMx_BTCFG1_GRP1SEL_IN_SIG2/	�ڲ������ź�2
      BTIMx_BTCFG1_GRP1SEL_EX_SIG2	�ⲿ�����ź�2
*********************************/
uint32_t BTIMx_BTCFG1_GRP1SEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG1 & BTIMx_BTCFG1_GRP1SEL_Msk);
}


/*********************************
basic timer �ⲿ�����ź�Դ2ѡ���� 
���ܣ�����BT �ⲿ�����ź�Դ2
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCFG2_EXSEL2_BT_IN0	�ⲿ����1
      BTIMx_BTCFG2_EXSEL2_BT_IN1	�ⲿ����2
      BTIMx_BTCFG2_EXSEL2_BT_IN2	�ⲿ����3
      BTIMx_BTCFG2_EXSEL2_BT_IN3	�ⲿ����4
���: ��
*********************************/
void BTIMx_BTCFG2_EXSEL2_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG2;
	tmpreg &= ~(BTIMx_BTCFG2_EXSEL2_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG2_EXSEL2_Msk);
	BTIMx->BTCFG2 = tmpreg;
}
/*********************************
basic timer �ⲿ�����ź�Դ2ѡ���� 
���ܣ���ȡBT �ⲿ�����ź�Դ2����
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCFG2_EXSEL2_BT_IN0	�ⲿ����1
      BTIMx_BTCFG2_EXSEL2_BT_IN1	�ⲿ����2
      BTIMx_BTCFG2_EXSEL2_BT_IN2	�ⲿ����3
      BTIMx_BTCFG2_EXSEL2_BT_IN3	�ⲿ����4
*********************************/
uint32_t BTIMx_BTCFG2_EXSEL2_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG2 & BTIMx_BTCFG2_EXSEL2_Msk);
}

/*********************************
basic timer �ⲿ�����ź�Դ1ѡ���� 
���ܣ�����BT �ⲿ�����ź�Դ1
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCFG2_EXSEL1_BT_IN0	�ⲿ����1
      BTIMx_BTCFG2_EXSEL1_BT_IN1	�ⲿ����2
      BTIMx_BTCFG2_EXSEL1_BT_IN2	�ⲿ����3
      BTIMx_BTCFG2_EXSEL1_BT_IN3	�ⲿ����4
���: ��
*********************************/
void BTIMx_BTCFG2_EXSEL1_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG2;
	tmpreg &= ~(BTIMx_BTCFG2_EXSEL1_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG2_EXSEL1_Msk);
	BTIMx->BTCFG2 = tmpreg;
}
/*********************************
basic timer �ⲿ�����ź�Դ1ѡ���� 
���ܣ���ȡBT �ⲿ�����ź�Դ1����
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCFG2_EXSEL1_BT_IN0	�ⲿ����1
      BTIMx_BTCFG2_EXSEL1_BT_IN1	�ⲿ����2
      BTIMx_BTCFG2_EXSEL1_BT_IN2	�ⲿ����3
      BTIMx_BTCFG2_EXSEL1_BT_IN3	�ⲿ����4
*********************************/
uint32_t BTIMx_BTCFG2_EXSEL1_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG2 & BTIMx_BTCFG2_EXSEL1_Msk);
}

/*********************************
basic timer �ڲ������ź�Դ2ѡ���� 
���ܣ�����BT �ڲ������ź�Դ2
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCFG2_INSEL2_UART_RX3	ѡ��UART3�����ź����ź�Դ
      BTIMx_BTCFG2_INSEL2_UART_RX4	ѡ��UART4�����ź����ź�Դ
      BTIMx_BTCFG2_INSEL2_UART_RX5	ѡ��UART5�����ź����ź�Դ
      BTIMx_BTCFG2_INSEL2_RCLP		ѡ��RCLP���ź�Դ
      BTIMx_BTCFG2_INSEL2_BT1_OUT	ѡ��BT1��������ź�Դ
���: ��
*********************************/
void BTIMx_BTCFG2_INSEL2_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG2;
	tmpreg &= ~(BTIMx_BTCFG2_INSEL2_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG2_INSEL2_Msk);
	BTIMx->BTCFG2 = tmpreg;
}
/*********************************
basic timer �ڲ������ź�Դ2ѡ���� 
���ܣ���ȡBT �ڲ������ź�Դ2����
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCFG2_INSEL2_UART_RX3	�ź�ԴΪUART3�����ź�
      BTIMx_BTCFG2_INSEL2_UART_RX4	�ź�ԴΪUART4�����ź�
      BTIMx_BTCFG2_INSEL2_UART_RX5	�ź�ԴΪUART5�����ź�
      BTIMx_BTCFG2_INSEL2_RCLP		�ź�ԴΪRCLP���ź�Դ
      BTIMx_BTCFG2_INSEL2_BT1_OUT	�ź�ԴΪBT1�����
*********************************/
uint32_t BTIMx_BTCFG2_INSEL2_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG2 & BTIMx_BTCFG2_INSEL2_Msk);
}
/*********************************
basic timer �ڲ������ź�Դ1ѡ���� 
���ܣ�����BT �ڲ������ź�Դ1
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTCFG2_INSEL1_UART_RX0	ѡ��UART0�����ź����ź�Դ
      BTIMx_BTCFG2_INSEL1_UART_RX1	ѡ��UART1�����ź����ź�Դ
      BTIMx_BTCFG2_INSEL1_UART_RX2	ѡ��UART2�����ź����ź�Դ
      BTIMx_BTCFG2_INSEL1_RCLP		ѡ��RCLP���ź�Դ
���: ��
*********************************/
void BTIMx_BTCFG2_INSEL1_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG2;
	tmpreg &= ~(BTIMx_BTCFG2_INSEL1_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG2_INSEL1_Msk);
	BTIMx->BTCFG2 = tmpreg;
}

/*********************************
basic timer �ڲ������ź�Դ1ѡ���� 
���ܣ���ȡBT �ڲ������ź�Դ1����
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTCFG2_INSEL1_UART_RX0	�ź�ԴΪUART0�����ź�
      BTIMx_BTCFG2_INSEL1_UART_RX1	�ź�ԴΪUART1�����ź�
      BTIMx_BTCFG2_INSEL1_UART_RX2	�ź�ԴΪUART2�����ź�
      BTIMx_BTCFG2_INSEL1_RCLP		�ź�ԴΪRCLP���ź�Դ
*********************************/
uint32_t BTIMx_BTCFG2_INSEL1_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG2 & BTIMx_BTCFG2_INSEL1_Msk);
}

/*********************************
basic timer group1����Ԥ��Ƶ���ƺ��� 
���ܣ�����BT group1Ԥ��Ƶ
����: BTIM1/BTIM2  ��ʱ������
      �����Ƶֵ��00-FF��00��ʾ1��Ƶ��FF��ʾ256��Ƶ
���: ��
*********************************/
void BTIMx_BTPRES_Write(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	BTIMx->BTPRES = (SetValue & BTIMx_BTPRES_PRESCALE_Msk);
}
/*********************************
basic timer group1����Ԥ��Ƶ���ƺ��� 
���ܣ���ȡBT group1Ԥ��Ƶ
����: BTIM1/BTIM2  ��ʱ������
      
���: 00-FF 00��ʾ1��Ƶ��FF��ʾ256��Ƶ
*********************************/
uint32_t BTIMx_BTPRES_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTPRES & BTIMx_BTPRES_PRESCALE_Msk);
}
/*********************************
basic timer group1���ؿ��ƺ��� 
���ܣ�ʹ��BT��λ����
����: BTIM1/BTIM2  ��ʱ������
      ENABLE ��λ������
      DISABLE ��λ����ֹͣ
���: ��
*********************************/
void BTIMx_BTLOADCR_LHEN_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTLOADCR |= (BTIMx_BTLOADCR_LHEN_Msk);
	}
	else
	{
		BTIMx->BTLOADCR &= ~(BTIMx_BTLOADCR_LHEN_Msk);
	}
}
/*********************************
basic timer group1���ؿ��ƺ��� 
���ܣ�ʹ��BT��λ����
����: BTIM1/BTIM2  ��ʱ������
      ENABLE ��λ������
      DISABLE ��λ����ֹͣ
���: ��
*********************************/
void BTIMx_BTLOADCR_LLEN_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTLOADCR |= (BTIMx_BTLOADCR_LLEN_Msk);
	}
	else
	{
		BTIMx->BTLOADCR &= ~(BTIMx_BTLOADCR_LLEN_Msk);
	}
}

/*********************************
basic timer ����������ֵ��غ��� 
���ܣ���ȡ��������λ����ֵ
����: BTIM1/BTIM2  ��ʱ������
���: 0000-FFFF �������ֵ
*********************************/
uint32_t BTIMx_BTCNTL_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCNTL & BTIMx_BTCNTL_CNTL_Msk);
}

/*********************************
basic timer ����������ֵ��غ��� 
���ܣ���ȡ��������λ����ֵ
����: BTIM1/BTIM2  ��ʱ������
���: 0000-FFFF �������ֵ
*********************************/
uint32_t BTIMx_BTCNTH_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCNTH & BTIMx_BTCNTH_CNTH_Msk);
}

/*********************************
basic timer ������Ԥ������غ��� 
���ܣ����ü�������λԤ����
����: BTIM1/BTIM2  ��ʱ������
      0000-FFFF  ����Ԥ����ֵ
*********************************/
void BTIMx_BTPRESET_PRESETH_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTPRESET;
	tmpreg &= ~(BTIMx_BTPRESET_PRESETH_Msk);
	tmpreg |= (SetValue & BTIMx_BTPRESET_PRESETH_Msk);
	BTIMx->BTPRESET = tmpreg;
}
/*********************************
basic timer ������Ԥ������غ��� 
���ܣ���ȡ��������λԤ����
����: BTIM1/BTIM2  ��ʱ������
���: 0000-FFFF  ����Ԥ����ֵ
*********************************/
uint32_t BTIMx_BTPRESET_PRESETH_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTPRESET & BTIMx_BTPRESET_PRESETH_Msk);
}

/*********************************
basic timer ������Ԥ������غ��� 
���ܣ����ü�������λԤ����
����: BTIM1/BTIM2  ��ʱ������
      0000-FFFF  ����Ԥ����ֵ
*********************************/
void BTIMx_BTPRESET_PRESETL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTPRESET;
	tmpreg &= ~(BTIMx_BTPRESET_PRESETL_Msk);
	tmpreg |= (SetValue & BTIMx_BTPRESET_PRESETL_Msk);
	BTIMx->BTPRESET = tmpreg;
}

/*********************************
basic timer ������Ԥ������غ��� 
���ܣ���ȡ��������λԤ����
����: BTIM1/BTIM2  ��ʱ������
���: 0000-FFFF  ����Ԥ����ֵ
*********************************/
uint32_t BTIMx_BTPRESET_PRESETL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTPRESET & BTIMx_BTPRESET_PRESETL_Msk);
}

/*********************************
basic timer ��������������غ��� 
���ܣ����ü�������λ������
����: BTIM1/BTIM2  ��ʱ������
      0000-FFFF  ���������ֵ
*********************************/
void BTIMx_BTLOADL_Write(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	BTIMx->BTLOADL = (SetValue & BTIMx_BTLOADL_LOADL_Msk);
}
/*********************************
basic timer ��������������غ��� 
���ܣ���ȡ��������λ������
����: BTIM1/BTIM2  ��ʱ������
���: 0000-FFFF  ���������ֵ
*********************************/
uint32_t BTIMx_BTLOADL_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTLOADL & BTIMx_BTLOADL_LOADL_Msk);
}

/*********************************
basic timer ��������������غ��� 
���ܣ����ü�������λ������
����: BTIM1/BTIM2  ��ʱ������
      0000-FFFF  ���������ֵ
*********************************/
void BTIMx_BTLOADH_Write(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	BTIMx->BTLOADH = (SetValue & BTIMx_BTLOADH_LOADH_Msk);
}
/*********************************
basic timer ��������������غ��� 
���ܣ���ȡ��������λ������
����: BTIM1/BTIM2  ��ʱ������
���: 0000-FFFF  ���������ֵ
*********************************/
uint32_t BTIMx_BTLOADH_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTLOADH & BTIMx_BTLOADH_LOADH_Msk);
}
/*********************************
basic timer �������Ƚ�ֵ��غ��� 
���ܣ����ü�������λ�Ƚ�ֵ
����: BTIM1/BTIM2  ��ʱ������
      0000-FFFF  ����Ƚ�ֵ
*********************************/
void BTIMx_BTCMPL_Write(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	BTIMx->BTCMPL = (SetValue & BTIMx_BTCMPL_CMPL_Msk);
}
/*********************************
basic timer �������Ƚ�ֵ��غ���
���ܣ���ȡ��������λ�Ƚ�ֵ
����: BTIM1/BTIM2  ��ʱ������
���: 0000-FFFF  ����Ƚ�ֵ
*********************************/
uint32_t BTIMx_BTCMPL_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCMPL & BTIMx_BTCMPL_CMPL_Msk);
}

/*********************************
basic timer �������Ƚ�ֵ��غ��� 
���ܣ����ü�������λ�Ƚ�ֵ
����: BTIM1/BTIM2  ��ʱ������
      0000-FFFF  ����Ƚ�ֵ
*********************************/
void BTIMx_BTCMPH_Write(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	BTIMx->BTCMPH = (SetValue & BTIMx_BTCMPH_CMPH_Msk);
}
/*********************************
basic timer �������Ƚ�ֵ��غ���
���ܣ���ȡ��������λ�Ƚ�ֵ
����: BTIM1/BTIM2  ��ʱ������
���: 0000-FFFF  ����Ƚ�ֵ
*********************************/
uint32_t BTIMx_BTCMPH_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCMPH & BTIMx_BTCMPH_CMPH_Msk);
}

/*********************************
basic timer ����������������� 
���ܣ����ü���������������
����: BTIM1/BTIM2  ��ʱ������
      0000-0FFF    ���Ϊ30.5*(1+SetValue)
*********************************/
void BTIMx_BTOUTCNT_Write(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	BTIMx->BTOUTCNT = (SetValue & BTIMx_BTOUTCNT_OUTCNT_Msk);
}
/*********************************
basic timer ����������������� 
���ܣ���ȡ���������������ȶ���
����: BTIM1/BTIM2  ��ʱ������
���: 0000-0FFF  ������Ϊ30.5*(1+����ֵ)
*********************************/
uint32_t BTIMx_BTOUTCNT_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTOUTCNT & BTIMx_BTOUTCNT_OUTCNT_Msk);
}

/*********************************
basic timer ������������ƺ��� 
���ܣ����ü���������Ƿ�����
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTOCR_OUTCLR/BTIMx_BTOCR_OUTCLR_CLR		���д����Ч/�������(�������˷���������ߣ�δ�����������)
*********************************/
void BTIMx_BTOCR_OUTCLR_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTOCR;
	tmpreg &= ~(BTIMx_BTOCR_OUTCLR_Msk);
	tmpreg |= (SetValue & BTIMx_BTOCR_OUTCLR_Msk);
	BTIMx->BTOCR = tmpreg;
}
/*********************************
basic timer ������������ƺ��� 
���ܣ���ȡ����������Ƿ�����
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTOCR_OUTCLR/BTIMx_BTOCR_OUTCLR_CLR		���д����Ч/�������(�������˷���������ߣ�δ�����������)
*********************************/
uint32_t BTIMx_BTOCR_OUTCLR_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTOCR & BTIMx_BTOCR_OUTCLR_Msk);
}

/*********************************
basic timer ������������ƺ��� 
���ܣ����ü����������ƽ
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTOCR_OUTINV_NOT_ANTI/BTIMx_BTOCR_OUTINV_ANTI	�����ƽ��ȡ��/�����ƽȡ��
*********************************/
void BTIMx_BTOCR_OUTINV_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTOCR;
	tmpreg &= ~(BTIMx_BTOCR_OUTINV_Msk);
	tmpreg |= (SetValue & BTIMx_BTOCR_OUTINV_Msk);
	BTIMx->BTOCR = tmpreg;
}
/*********************************
basic timer ������������ƺ��� 
���ܣ���ȡ�����������ƽ
����: BTIM1/BTIM2  ��ʱ������
���: 	BTIMx_BTOCR_OUTMOD_PULSE/BTIMx_BTOCR_OUTMOD_ANTI_LEVEL	�����ƽ��ȡ��/�����ƽȡ��
*********************************/
uint32_t BTIMx_BTOCR_OUTINV_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTOCR & BTIMx_BTOCR_OUTINV_Msk);
}

/*********************************
basic timer ������������ƺ��� 
���ܣ����ü��������ģʽ
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTOCR_OUTINV_NOT_ANTI/BTIMx_BTOCR_OUTINV_ANTI	������壬��ȿɵ�/���֮ǰ�ķ����ƽ
���: ��
*********************************/   
void BTIMx_BTOCR_OUTMOD_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTOCR;
	tmpreg &= ~(BTIMx_BTOCR_OUTMOD_Msk);
	tmpreg |= (SetValue & BTIMx_BTOCR_OUTMOD_Msk);
	BTIMx->BTOCR = tmpreg;
}
/*********************************
basic timer ������������ƺ��� 
���ܣ���ȡ���������ģʽ
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTOCR_OUTINV_NOT_ANTI/BTIMx_BTOCR_OUTINV_ANTI	������壬��ȿɵ�/���֮ǰ�ķ����ƽ
*********************************/
uint32_t BTIMx_BTOCR_OUTMOD_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTOCR & BTIMx_BTOCR_OUTMOD_Msk);
}

/*********************************
basic timer ������������ƺ��� 
���ܣ����ü���������ź�Դ
����: BTIM1/BTIM2  ��ʱ������
      BTIMx_BTOCR_OUTSEL_CMPH/		�����λ�������Ƚ��źţ�������ģʽ��Ч
      BTIMx_BTOCR_OUTSEL_CMPL/		�����λ�������Ƚ��źţ�������ģʽ��Ч
      BTIMx_BTOCR_OUTSEL_GROUP1/	���Group1�������źţ���������׽ģʽ��Ч	
      BTIMx_BTOCR_OUTSEL_GROUP2/	���Group2�������źţ���������׽ģʽ��Ч
      BTIMx_BTOCR_OUTSEL_PWM		PWM���
���: ��
*********************************/  
void BTIMx_BTOCR_OUTSEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTOCR;
	tmpreg &= ~(BTIMx_BTOCR_OUTSEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTOCR_OUTSEL_Msk);
	BTIMx->BTOCR = tmpreg;
}
/*********************************
basic timer ������������ƺ��� 
���ܣ���ȡ����������ź�Դ
����: BTIM1/BTIM2  ��ʱ������
���: BTIMx_BTOCR_OUTSEL_CMPH/		�����λ�������Ƚ��źţ�������ģʽ��Ч
      BTIMx_BTOCR_OUTSEL_CMPL/		�����λ�������Ƚ��źţ�������ģʽ��Ч
      BTIMx_BTOCR_OUTSEL_GROUP1/	���Group1�������źţ���������׽ģʽ��Ч	
      BTIMx_BTOCR_OUTSEL_GROUP2/	���Group2�������źţ���������׽ģʽ��Ч
      BTIMx_BTOCR_OUTSEL_PWM		PWM���
*********************************/
uint32_t BTIMx_BTOCR_OUTSEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTOCR & BTIMx_BTOCR_OUTSEL_Msk);
}

/*********************************
basic timer�������ж�ʹ�ܿ��ƺ��� 
���ܣ�ʹ��BT��λ�ȽϷ����ź�
����: BTIM1/BTIM2  ��ʱ������	 
      ENABLE/DISABLE 			��λ�ȽϷ����ź��ж�ʹ��/��λ�ȽϷ����ź��жϽ�ֹ
���: ��
*********************************/
void BTIMx_BTIE_CMPHIE_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTIE |= (BTIMx_BTIE_CMPHIE_Msk);
	}
	else
	{
		BTIMx->BTIE &= ~(BTIMx_BTIE_CMPHIE_Msk);
	}
}
/*********************************
basic timer�������ж�ʹ�ܿ��ƺ��� 
���ܣ���ȡBT��λ�ȽϷ����ź�״̬
����: BTIM1/BTIM2  ��ʱ������	 
���: ENABLE/DISABLE 			��λ�ȽϷ����ź��ж�ʹ��/��λ�ȽϷ����ź��жϽ�ֹ
*********************************/
FunState BTIMx_BTIE_CMPHIE_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIE & (BTIMx_BTIE_CMPHIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
basic timer�������ж�ʹ�ܿ��ƺ��� 
���ܣ�ʹ��BT��λ�ȽϷ����ź�
����: BTIM1/BTIM2  ��ʱ������	 
      ENABLE/DISABLE 			��λ�ȽϷ����ź��ж�ʹ��/��λ�ȽϷ����ź��жϽ�ֹ
���: ��
*********************************/
void BTIMx_BTIE_CMPLIE_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTIE |= (BTIMx_BTIE_CMPLIE_Msk);
	}
	else
	{
		BTIMx->BTIE &= ~(BTIMx_BTIE_CMPLIE_Msk);
	}
}
/*********************************
basic timer�������ж�ʹ�ܿ��ƺ��� 
���ܣ���ȡBT��λ�ȽϷ����ź�״̬
����: BTIM1/BTIM2  ��ʱ������	 
���: ENABLE/DISABLE 			��λ�ȽϷ����ź��ж�ʹ��/��λ�ȽϷ����ź��жϽ�ֹ
*********************************/
FunState BTIMx_BTIE_CMPLIE_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIE & (BTIMx_BTIE_CMPLIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/*********************************
basic timer�������ж�ʹ�ܿ��ƺ��� 
���ܣ�ʹ��BT��λ��������ź�
����: BTIM1/BTIM2  ��ʱ������	 
      ENABLE/DISABLE 			��λ��������ź��ж�ʹ��/��λ��������ź��жϽ�ֹ
���: ��
*********************************/
void BTIMx_BTIE_OVHIE_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTIE |= (BTIMx_BTIE_OVHIE_Msk);
	}
	else
	{
		BTIMx->BTIE &= ~(BTIMx_BTIE_OVHIE_Msk);
	}
}
/*********************************
basic timer�������ж�ʹ�ܿ��ƺ��� 
���ܣ���ȡBT��λ��������ź�״̬
����: BTIM1/BTIM2  ��ʱ������	 
���: ENABLE/DISABLE 			��λ��������ź��ж�ʹ��/��λ��������ź��жϽ�ֹ
*********************************/
FunState BTIMx_BTIE_OVHIE_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIE & (BTIMx_BTIE_OVHIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/*********************************
basic timer�������ж�ʹ�ܿ��ƺ��� 
���ܣ�ʹ��BT��λ��������ź�
����: BTIM1/BTIM2  ��ʱ������	 
      ENABLE/DISABLE 			��λ��������ź��ж�ʹ��/��λ��������ź��жϽ�ֹ
���: ��
*********************************/
void BTIMx_BTIE_OVLIE_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTIE |= (BTIMx_BTIE_OVLIE_Msk);
	}
	else
	{
		BTIMx->BTIE &= ~(BTIMx_BTIE_OVLIE_Msk);
	}
}
/*********************************
basic timer�������ж�ʹ�ܿ��ƺ��� 
���ܣ���ȡBT��λ��������ź�״̬
����: BTIM1/BTIM2  ��ʱ������	 
���: ENABLE/DISABLE 			��λ��������ź��ж�ʹ��/��λ��������ź��жϽ�ֹ
*********************************/
FunState BTIMx_BTIE_OVLIE_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIE & (BTIMx_BTIE_OVLIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/*********************************
basic timer�������ж�ʹ�ܿ��ƺ��� 
���ܣ�ʹ��BT��׽�����ź�
����: BTIM1/BTIM2  ��ʱ������	 
      ENABLE/DISABLE 			��׽�����ź��ж�ʹ��/��׽�����ź��жϽ�ֹ
���: ��
*********************************/
void BTIMx_BTIE_CAPIE_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTIE |= (BTIMx_BTIE_CAPIE_Msk);
	}
	else
	{
		BTIMx->BTIE &= ~(BTIMx_BTIE_CAPIE_Msk);
	}
}
/*********************************
basic timer�������ж�ʹ�ܿ��ƺ��� 
���ܣ���ȡBT��׽�����ź�״̬
����: BTIM1/BTIM2  ��ʱ������	 
���: ENABLE/DISABLE 			��׽�����ź��ж�ʹ��/��׽�����ź��жϽ�ֹ
*********************************/
FunState BTIMx_BTIE_CAPIE_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIE & (BTIMx_BTIE_CAPIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
basic timer�������ж��źź��� 
���ܣ���BT��������׽��״̬
����: BTIM1/BTIM2  ��ʱ������
���: ��
*********************************/
void BTIMx_BTIF_EDGESTA_Clr(BTIMx_Type* BTIMx)
{
	BTIMx->BTIF = BTIMx_BTIF_EDGESTA_Msk;
}
/*********************************
basic timer�������ж��źź��� 
���ܣ���ȡBT��������׽��״̬
����: BTIM1/BTIM2  ��ʱ������	 
���: SET/RESET 			�����Ȳ�׽ģʽʱ��ʾ��׽������/�����Ȳ�׽ģʽʱ��ʾ��׽������
*********************************/
FlagStatus BTIMx_BTIF_EDGESTA_Chk(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIF & BTIMx_BTIF_EDGESTA_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
basic timer�������ж��źź��� 
���ܣ���BT��������λ�ȽϷ����ź�״̬
����: BTIM1/BTIM2  ��ʱ������
���: ��
*********************************/
void BTIMx_BTIF_CMPHIF_Clr(BTIMx_Type* BTIMx)
{
	BTIMx->BTIF = BTIMx_BTIF_CMPHIF_Msk;
}
/*********************************
basic timer�������ж��źź��� 
���ܣ���ȡBT��������λ�ȽϷ����ź�״̬
����: BTIM1/BTIM2  ��ʱ������	 
���: SET/RESET 			��ǰ��������ֵ���ڵȹ����Ĵ�����ֵ/��ǰ��������ֵС�ڹ����Ĵ�����ֵ
*********************************/
FlagStatus BTIMx_BTIF_CMPHIF_Chk(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIF & BTIMx_BTIF_CMPHIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
basic timer�������ж��źź��� 
���ܣ���BT��������λ�ȽϷ����ź�״̬
����: BTIM1/BTIM2  ��ʱ������
���: ��
*********************************/
void BTIMx_BTIF_CMPLIF_Clr(BTIMx_Type* BTIMx)
{
	BTIMx->BTIF = BTIMx_BTIF_CMPLIF_Msk;
}

/*********************************
basic timer�������ж��źź��� 
���ܣ���ȡBT��������λ�ȽϷ����ź�״̬
����: BTIM1/BTIM2  ��ʱ������	 
���: SET/RESET 			��ǰ��������ֵ���ڵȹ����Ĵ�����ֵ/��ǰ��������ֵС�ڹ����Ĵ�����ֵ
*********************************/
FlagStatus BTIMx_BTIF_CMPLIF_Chk(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIF & BTIMx_BTIF_CMPLIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
basic timer�������ж��źź��� 
���ܣ���BT��������λ��������ź�״̬
����: BTIM1/BTIM2  ��ʱ������
���: ��
*********************************/
void BTIMx_BTIF_OVHIF_Clr(BTIMx_Type* BTIMx)
{
	BTIMx->BTIF = BTIMx_BTIF_OVHIF_Msk;
}
/*********************************
basic timer�������ж��źź��� 
���ܣ���ȡBT��������λ��������ź�״̬
����: BTIM1/BTIM2  ��ʱ������	 
���: SET/RESET 			�����������/δ�������
*********************************/
FlagStatus BTIMx_BTIF_OVHIF_Chk(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIF & BTIMx_BTIF_OVHIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
basic timer�������ж��źź��� 
���ܣ���BT��������λ��������ź�״̬
����: BTIM1/BTIM2  ��ʱ������
���: ��
*********************************/
void BTIMx_BTIF_OVLIF_Clr(BTIMx_Type* BTIMx)
{
	BTIMx->BTIF = BTIMx_BTIF_OVLIF_Msk;
}
/*********************************
basic timer�������ж��źź��� 
���ܣ���ȡBT��������λ��������ź�״̬
����: BTIM1/BTIM2  ��ʱ������	 
���: SET/RESET 			�����������/δ�������
*********************************/
FlagStatus BTIMx_BTIF_OVLIF_Chk(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIF & BTIMx_BTIF_OVLIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


/*********************************
basic timer�������ж��źź��� 
���ܣ���BT��������׽�����ź�״̬
����: BTIM1/BTIM2  ��ʱ������
���: ��
*********************************/
void BTIMx_BTIF_CAPIF_Clr(BTIMx_Type* BTIMx)
{
	BTIMx->BTIF = BTIMx_BTIF_CAPIF_Msk;
}
/*********************************
basic timer�������ж��źź��� 
���ܣ���ȡBT��������׽�����ź�״̬
����: BTIM1/BTIM2  ��ʱ������	 
���: SET/RESET 			��׽��ָ������/δ��׽��ָ������
*********************************/
FlagStatus BTIMx_BTIF_CAPIF_Chk(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIF & BTIMx_BTIF_CAPIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
basic timer���������庯�� 
���ܣ��ر�BT���������й���(ȱʡ����)
����: BTIM1/BTIM2  ��ʱ������	 
���: ��
*********************************/
void BTIMx_Deinit(BTIMx_Type* BTIMx)
{
	BTIMx->BTCR1 = 0x00000000;
	BTIMx->BTCR2 = 0x00000000;
	BTIMx->BTCFG1 = 0x00000000;
	BTIMx->BTCFG2 = 0x00000000;
	BTIMx->BTPRES = 0x00000000;
	BTIMx->BTLOADCR = 0x00000000;
	//BTIMx->BTCNTL = ;
	//BTIMx->BTCNTH = ;
	BTIMx->BTPRESET = 0x00000000;
	BTIMx->BTLOADL = 0x00000000;
	BTIMx->BTLOADH = 0x00000000;
	//BTIMx->BTCMPL = ;
	//BTIMx->BTCMPH = ;
	BTIMx->BTOUTCNT = 0x00000000;
	BTIMx->BTOCR = 0x00000000;
	BTIMx->BTIE = 0x00000000;
	//BTIMx->BTIF = ;
}
//Code_End



void BTIMx_Init(BTIMx_Type* BTIMx, BTIM_InitTypeDef* para)
{
	BTIMx_Deinit(BTIMx);

	//��׽����ѡ��
	BTIMx_BTCR1_CAPMOD_Set(BTIMx, para->cap_para.CAPMOD);//��׽ģʽ���ƣ������Ȼ���������
	BTIMx_BTCR1_CAPCLR_Set(BTIMx, para->cap_para.CAPCLR);//��׽�Ƿ���Ҫ���������
	BTIMx_BTCR1_CAPONCE_Set(BTIMx, para->cap_para.CAPONCE);//��׽�Ƿ񵥴β�׽

	//�ź�ѡ����
	BTIMx_BTCFG1_RTCSEL1_Set(BTIMx, para->sig_src_para.RTCSEL1);//ѡ��RTCOUT1�ź�ѡ��
	BTIMx_BTCFG1_RTCSEL2_Set(BTIMx, para->sig_src_para.RTCSEL2);//ѡ��RTCOUT2�ź�ѡ��
	BTIMx_BTCFG2_INSEL1_Set(BTIMx, para->sig_src_para.INSEL1);//ѡ���ڲ������ź�1
	BTIMx_BTCFG2_INSEL2_Set(BTIMx, para->sig_src_para.INSEL2);//ѡ���ڲ������ź�2
    BTIMx_BTCFG2_EXSEL1_Set(BTIMx, para->sig_src_para.EXSEL1);//ѡ���ⲿ�����ź�1
    BTIMx_BTCFG2_EXSEL2_Set(BTIMx, para->sig_src_para.EXSEL2);//ѡ���ⲿ�����ź�2
	
	
	BTIMx_BTCFG1_GRP1SEL_Set(BTIMx, para->sig_src_para.GRP1SEL);//ѡ��GROUP1�ź�ѡ��
	BTIMx_BTCFG1_GRP2SEL_Set(BTIMx, para->sig_src_para.GRP2SEL);//ѡ��GROUP2�ź�ѡ��
	
	BTIMx_BTCR2_SIG2SEL_Set(BTIMx, para->sig_src_para.CNTSRC);//ѡ���ڲ�����Դ�ź�
	BTIMx_BTCR2_SIG1SEL_Set(BTIMx, para->sig_src_para.CAPSRC);//ѡ���ڲ���׽Դ�ź�

	BTIMx_BTCR2_CNTHSEL_Set(BTIMx, para->sig_src_para.CNTHSEL);//��λ����������Դѡ��
	BTIMx_BTCR2_SRCSEL_Set(BTIMx, para->sig_src_para.SRCSEL);//ѡ���λ�������Ƿ�ʹ��

	//DIR������
	BTIMx_BTCR2_DIREN_Setable(BTIMx, para->dir_para.DIREN);//�ⲿdir���ƻ�ʹ��
	//BTIMx_BTCR2_STDIR_Setable(BTIMx, para->dir_para.STDIR);//�ڲ�dir�����źţ����Ӧ�ò���Ҫ
	BTIMx_BTCR2_DIRPO_Set(BTIMx, para->dir_para.DIRPO);//�ⲿ����dir�źż���ѡ��


	//���������
	BTIMx_BTCR1_MODE_Set(BTIMx, para->ctrl_para.MODE);//����ģʽ��16λ��׽����8λ��ʱ����
	BTIMx_BTCR1_EDGESEL_Set(BTIMx, para->ctrl_para.EDGESEL);//��ѡ�������ػ����½���
	BTIMx_BTPRES_Write(BTIMx, para->ctrl_para.PRESCALE);//ѡ���Ƶϵ��

	BTIMx_BTPRESET_PRESETH_Set(BTIMx, para->ctrl_para.PRESETH);//��λԤ����ֵ
	BTIMx_BTPRESET_PRESETL_Set(BTIMx, para->ctrl_para.PRESETL);//��λԤ����ֵ

	BTIMx_BTLOADH_Write(BTIMx, para->ctrl_para.LOADH);//��λ����ֵ
	BTIMx_BTLOADL_Write(BTIMx, para->ctrl_para.LOADL);//��λ����ֵ
	
	//��������
	BTIMx_BTOCR_OUTMOD_Set(BTIMx, para->out_para.OUTMOD);//���ģʽѡ��
	BTIMx_BTOCR_OUTSEL_Set(BTIMx, para->out_para.OUTSEL);//����ź�ѡ��
	BTIMx_BTOUTCNT_Write(BTIMx, para->out_para.OUTCNT);//�������������
	BTIMx_BTOCR_OUTINV_Set(BTIMx, para->out_para.OUTINV);//�����ƽ����ѡ��
	
}


