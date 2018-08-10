/**
  ******************************************************************************
  * @file    fm33a0xx_lptim.c
  * @author  FM33a0xx Application Team
  * @version V2.0.2
  * @date    
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33a0xx_lptim.h" 


/** @addtogroup fm33a0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup LPTIM 
  * @brief LPTIM driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


//Code_Start
//2018-04-02-13-22-48
//FM33A0XX_Driver_Gen_V1.4

/********************************
LPTIM�ⲿTrigger�˲�ʹ�ܺ���
����:�ⲿTrigger�˲�ʹ��
����:ʹ��״̬

********************************/
void LPTIM_LPTCFG_FLTEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->LPTCFG &= ~(LPTIM_LPTCFG_FLTEN_Msk);
	}
	else
	{
		LPTIM->LPTCFG |= (LPTIM_LPTCFG_FLTEN_Msk);
	}
}
/********************************
��ȡLPTIM�ⲿTrigger�˲�ʹ��״̬����
����:��ȡ�ⲿTrigger�˲�ʹ��״̬
���:ʹ��״̬

********************************/
FunState LPTIM_LPTCFG_FLTEN_Getable(void)
{
	if (LPTIM->LPTCFG & (LPTIM_LPTCFG_FLTEN_Msk))
	{
		return DISABLE;
	}
	else
	{
		return ENABLE;
	}
}

/********************************
LPTIM����ʱ�ӷ�Ƶѡ����
����:����ʱ�ӷ�Ƶѡ��
����:��Ƶ��ֵ

********************************/
void LPTIM_LPTCFG_DIVSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->LPTCFG;
	tmpreg &= ~(LPTIM_LPTCFG_DIVSEL_Msk);
	tmpreg |= (SetValue & LPTIM_LPTCFG_DIVSEL_Msk);
	LPTIM->LPTCFG = tmpreg;
}
/********************************
��ȡLPTIM����ʱ�ӷ�Ƶ��ֵ����
����:��ȡ����ʱ�ӷ�Ƶ��ֵ
���:��Ƶ��ֵ

********************************/
uint32_t LPTIM_LPTCFG_DIVSEL_Get(void)
{
	return (LPTIM->LPTCFG & LPTIM_LPTCFG_DIVSEL_Msk);
}

/********************************
LPTIM����ʱ��Դѡ����
����:����ʱ��Դѡ��
����:ʱ��Դ����

********************************/
void LPTIM_LPTCFG_CLKSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->LPTCFG;
	tmpreg &= ~(LPTIM_LPTCFG_CLKSEL_Msk);
	tmpreg |= (SetValue & LPTIM_LPTCFG_CLKSEL_Msk);
	LPTIM->LPTCFG = tmpreg;
}
/********************************
��ȡLPTIM����ʱ��Դ����
����:��ȡ����ʱ��Դѡ��
���:��ȡʱ��Դ����

********************************/
uint32_t LPTIM_LPTCFG_CLKSEL_Get(void)
{
	return (LPTIM->LPTCFG & LPTIM_LPTCFG_CLKSEL_Msk);
}

/********************************
LPTIM�������ѡ����
����:�������ѡ��
����:�������ѡ�����
	0��LPTIN�������ؼ���
	1��LPTIN���½��ؼ���
********************************/
void LPTIM_LPTCFG_EDGESEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->LPTCFG;
	tmpreg &= ~(LPTIM_LPTCFG_EDGESEL_Msk);
	tmpreg |= (SetValue & LPTIM_LPTCFG_EDGESEL_Msk);
	LPTIM->LPTCFG = tmpreg;
}
/********************************
��ȡLPTIM�������ѡ����
����:��ȡLPTIM�������ѡ��
���:��ȡLPTIM�������
	0��LPTIN�������ؼ���
	1��LPTIN���½��ؼ���
********************************/
uint32_t LPTIM_LPTCFG_EDGESEL_Get(void)
{
	return (LPTIM->LPTCFG & LPTIM_LPTCFG_EDGESEL_Msk);
}

/********************************
LPTIM�ⲿ��������ѡ����
����:�ⲿ��������ѡ��
����:�ⲿ��������ѡ�����

********************************/
void LPTIM_LPTCFG_TRIGCFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->LPTCFG;
	tmpreg &= ~(LPTIM_LPTCFG_TRIGCFG_Msk);
	tmpreg |= (SetValue & LPTIM_LPTCFG_TRIGCFG_Msk);
	LPTIM->LPTCFG = tmpreg;
}
/********************************
��ȡLPTIM�ⲿ��������ѡ����
����:��ȡLPTIM�ⲿ��������ѡ��
���:��ȡLPTIM�ⲿ��������

********************************/
uint32_t LPTIM_LPTCFG_TRIGCFG_Get(void)
{
	return (LPTIM->LPTCFG & LPTIM_LPTCFG_TRIGCFG_Msk);
}

/* ������μ���ѡ�� ��غ��� */
void LPTIM_LPTCFG_POLARITY_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->LPTCFG;
	tmpreg &= ~(LPTIM_LPTCFG_POLARITY_Msk);
	tmpreg |= (SetValue & LPTIM_LPTCFG_POLARITY_Msk);
	LPTIM->LPTCFG = tmpreg;
}

uint32_t LPTIM_LPTCFG_POLARITY_Get(void)
{
	return (LPTIM->LPTCFG & LPTIM_LPTCFG_POLARITY_Msk);
}

/********************************
LPTIM�������ģʽѡ����
����:�������ģʽѡ��
����:�������ģʽ����
0�����ڷ������ģʽ
1��PWM���ģʽ
********************************/
void LPTIM_LPTCFG_PWM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->LPTCFG;
	tmpreg &= ~(LPTIM_LPTCFG_PWM_Msk);
	tmpreg |= (SetValue & LPTIM_LPTCFG_PWM_Msk);
	LPTIM->LPTCFG = tmpreg;
}
/********************************
��ȡLPTIM�������ģʽѡ����
����:��ȡ�������ģʽ
���:��ȡ�������ģʽ
0�����ڷ������ģʽ
1��PWM���ģʽ
********************************/
uint32_t LPTIM_LPTCFG_PWM_Get(void)
{
	return (LPTIM->LPTCFG & LPTIM_LPTCFG_PWM_Msk);
}

/********************************
LPTIM����ģʽѡ����
����:����ģʽѡ��
����:����ģʽѡ�����
0����������ģʽ
1�����μ���ģʽ
********************************/
void LPTIM_LPTCFG_MODE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->LPTCFG;
	tmpreg &= ~(LPTIM_LPTCFG_MODE_Msk);
	tmpreg |= (SetValue & LPTIM_LPTCFG_MODE_Msk);
	LPTIM->LPTCFG = tmpreg;
}

/********************************
��ȡLPTIM����ģʽѡ����
����:��ȡ����ģʽѡ��
���:����ģʽѡ�����
0����������ģʽ
1�����μ���ģʽ
********************************/
uint32_t LPTIM_LPTCFG_MODE_Get(void)
{
	return (LPTIM->LPTCFG & LPTIM_LPTCFG_MODE_Msk);
}

/********************************
LPTIM����ģʽѡ����
����:����ģʽѡ��
����:����ģʽѡ�����
********************************/
void LPTIM_LPTCFG_TMODE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->LPTCFG;
	tmpreg &= ~(LPTIM_LPTCFG_TMODE_Msk);
	tmpreg |= (SetValue & LPTIM_LPTCFG_TMODE_Msk);
	LPTIM->LPTCFG = tmpreg;
}
/********************************
��ȡLPTIM����ģʽѡ����
����:LPTIM����ģʽѡ��
���:����ģʽѡ�����
********************************/
uint32_t LPTIM_LPTCFG_TMODE_Get(void)
{
	return (LPTIM->LPTCFG & LPTIM_LPTCFG_TMODE_Msk);
}
/********************************
LPTIMд����ֵ����
����:д�����ֵ
����:����ֵ
********************************/
void LPTIM_LPTCNT_Write(uint32_t SetValue)
{
	LPTIM->LPTCNT = (SetValue & LPTIM_LPTCNT_CNT16_Msk);
}

/********************************
��ȡLPTIM����ֵ����
����:��ȡ����ֵ
���:����ֵ
********************************/
uint32_t LPTIM_LPTCNT_Read(void)
{
	return (LPTIM->LPTCNT & LPTIM_LPTCNT_CNT16_Msk);
}
/********************************
LPTIMд�Ƚ�ֵ����
����:д��Ƚ�ֵ
����:�Ƚ�ֵ
********************************/
void LPTIM_LPTCMP_Write(uint32_t SetValue)
{
	LPTIM->LPTCMP = (SetValue & LPTIM_LPTCMP_COMPARE_REG_Msk);
}
/********************************
��ȡLPTIM�Ƚ�ֵ����
����:��ȡ�Ƚ�ֵ
���:�Ƚ�ֵ
********************************/
uint32_t LPTIM_LPTCMP_Read(void)
{
	return (LPTIM->LPTCMP & LPTIM_LPTCMP_COMPARE_REG_Msk);
}
/********************************
LPTIMдĿ��ֵ����
����:д��Ŀ��ֵ
����:Ŀ��ֵ
********************************/
void LPTIM_LPTTARGET_Write(uint32_t SetValue)
{
	LPTIM->LPTTARGET = (SetValue & LPTIM_LPTTARGET_TARGET_REG_Msk);
}
/********************************
��ȡLPTIMĿ��ֵ����
����:��ȡĿ��ֵ
���:Ŀ��ֵ
********************************/
uint32_t LPTIM_LPTTARGET_Read(void)
{
	return (LPTIM->LPTTARGET & LPTIM_LPTTARGET_TARGET_REG_Msk);
}

/********************************
LPTIM�ⲿ�����жϺ���
����:�ⲿ�����ж�����
����:�ⲿ�����жϴ���
1���ⲿ���������ж�ʹ��
0���ⲿ���������жϽ�ֹ
********************************/
void LPTIM_LPTIE_TRIGIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->LPTIE |= (LPTIM_LPTIE_TRIGIE_Msk);
	}
	else
	{
		LPTIM->LPTIE &= ~(LPTIM_LPTIE_TRIGIE_Msk);
	}
}
/********************************
��ȡLPTIM�ⲿ�����жϺ���
����:��ȡ�ⲿ�����ж�����
���:�ⲿ�����жϴ���
1���ⲿ���������ж�ʹ��
0���ⲿ���������жϽ�ֹ
********************************/
FunState LPTIM_LPTIE_TRIGIE_Getable(void)
{
	if (LPTIM->LPTIE & (LPTIM_LPTIE_TRIGIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
LPTIM����������жϺ���
����:����������ж�����
����:����������жϴ���
1������������ж�ʹ��
0������������жϽ�ֹ
********************************/
void LPTIM_LPTIE_OVIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->LPTIE |= (LPTIM_LPTIE_OVIE_Msk);
	}
	else
	{
		LPTIM->LPTIE &= ~(LPTIM_LPTIE_OVIE_Msk);
	}
}
/********************************
��ȡLPTIM����������жϺ���
����:��ȡ����������ж�����
���:����������жϴ���
1������������ж�ʹ��
0������������жϽ�ֹ
********************************/
FunState LPTIM_LPTIE_OVIE_Getable(void)
{
	if (LPTIM->LPTIE & (LPTIM_LPTIE_OVIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
LPTIM�Ƚ�ֵƥ���жϺ���
����:�Ƚ�ֵƥ���ж�����
����:�Ƚ�ֵƥ���жϴ���
1��������ֵ�ͱȽ�ֵƥ���ж�ʹ��
0��������ֵ�ͱȽ�ֵƥ���жϽ�ֹ
********************************/
void LPTIM_LPTIE_COMPIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->LPTIE |= (LPTIM_LPTIE_COMPIE_Msk);
	}
	else
	{
		LPTIM->LPTIE &= ~(LPTIM_LPTIE_COMPIE_Msk);
	}
}
/********************************
��ȡLPTIM�Ƚ�ֵƥ���жϺ���
����:��ȡ�Ƚ�ֵƥ���ж�����
���:�Ƚ�ֵƥ���жϴ���
1��������ֵ�ͱȽ�ֵƥ���ж�ʹ��
0��������ֵ�ͱȽ�ֵƥ���жϽ�ֹ
********************************/
FunState LPTIM_LPTIE_COMPIE_Getable(void)
{
	if (LPTIM->LPTIE & (LPTIM_LPTIE_COMPIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
���LPTIM�ⲿ������־����
����:���LPTIM�ⲿ������־
********************************/
void LPTIM_LPTIF_TRIGIF_Clr(void)
{
	LPTIM->LPTIF = LPTIM_LPTIF_TRIGIF_Msk;
}
/********************************
���LPTIM�ⲿ������־����
����:���LPTIM�ⲿ������־
�����LPTIM�ⲿ������־
********************************/
FlagStatus LPTIM_LPTIF_TRIGIF_Chk(void)
{
	if (LPTIM->LPTIF & LPTIM_LPTIF_TRIGIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
���LPTIM�����������־����
����:���LPTIM�����������־
********************************/
void LPTIM_LPTIF_OVIF_Clr(void)
{
	LPTIM->LPTIF = LPTIM_LPTIF_OVIF_Msk;
}
/********************************
���LPTIM�����������־����
����:���LPTIM�����������־
�����LPTIM�����������־
********************************/
FlagStatus LPTIM_LPTIF_OVIF_Chk(void)
{
	if (LPTIM->LPTIF & LPTIM_LPTIF_OVIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
���LPTIM�Ƚ�ֵƥ���־����
����:���LPTIM�Ƚ�ֵƥ���־
********************************/
void LPTIM_LPTIF_COMPIF_Clr(void)
{
	LPTIM->LPTIF = LPTIM_LPTIF_COMPIF_Msk;
}
/********************************
���LPTIM�Ƚ�ֵƥ���־����
����:���LPTIM�Ƚ�ֵƥ���־
�����LPTIM�Ƚ�ֵƥ���־
********************************/
FlagStatus LPTIM_LPTIF_COMPIF_Chk(void)
{
	if (LPTIM->LPTIF & LPTIM_LPTIF_COMPIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
LPTIM����ʹ�ܺ���
����:LPTIM����ʹ��
���룺LPTIM����ʹ�ܴ���
1��ʹ�ܼ���������
0����ֹ����������
********************************/
void LPTIM_LPTCTRL_LPTEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->LPTCTRL |= (LPTIM_LPTCTRL_LPTEN_Msk);
	}
	else
	{
		LPTIM->LPTCTRL &= ~(LPTIM_LPTCTRL_LPTEN_Msk);
	}
}
/********************************
��ȡLPTIM����ʹ�ܺ���
����:��ȡLPTIM����ʹ��
�����LPTIM����ʹ�ܴ���
1��ʹ�ܼ���������
0����ֹ����������
********************************/
FunState LPTIM_LPTCTRL_LPTEN_Getable(void)
{
	if (LPTIM->LPTCTRL & (LPTIM_LPTCTRL_LPTEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
LPTIM���мĴ������㺯��
����:LPTIM���мĴ�������
********************************/
void LPTIM_Deinit(void)
{
	LPTIM->LPTCFG = 0x00000000;
	//LPTIM->LPTCNT = ;
	LPTIM->LPTCMP = 0x00000000;
	LPTIM->LPTTARGET = 0x00000000;
	LPTIM->LPTIE = 0x00000000;
	//LPTIM->LPTIF = ;
	LPTIM->LPTCTRL = 0x00000000;
}
//Code_End

/********************************
LPTIM��ʼ������
����:LPTIM��ʼ��
********************************/
void LPTIM_Init(LPTIM_InitTypeDef* para)
{	
	LPTIM_LPTCFG_FLTEN_Setable(para->LPTIM_FLTEN);
	LPTIM_LPTCFG_DIVSEL_Set(para->LPTIM_CLK_DIV);
	LPTIM_LPTCFG_CLKSEL_Set(para->LPTIM_CLK_SEL);
	LPTIM_LPTCFG_EDGESEL_Set(para->LPTIM_LPTIN_EDGE);
	LPTIM_LPTCFG_TRIGCFG_Set(para->LPTIM_TRIG_CFG);
	LPTIM_LPTCFG_POLARITY_Set(para->LPTIM_POLAR);
	LPTIM_LPTCFG_PWM_Set(para->LPTIM_PWM);
	LPTIM_LPTCFG_MODE_Set(para->LPTIM_MODE);
	LPTIM_LPTCFG_TMODE_Set(para->LPTIM_TMODE);

	LPTIM_LPTCMP_Write(para->LPTIM_compare_value);
	LPTIM_LPTTARGET_Write(para->LPTIM_target_value);
}


/******END OF FILE****/

