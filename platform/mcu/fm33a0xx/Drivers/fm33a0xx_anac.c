/**
  ******************************************************************************
  * @file    fm33a0xx_anac.c
  * @author  FM33a0 Application Team
  * @version V2.0.2
  * @date    23-1-2018
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33a0xx_anac.h" 


/** @addtogroup fm33a0_StdPeriph_Driver
  * @{
  */

/** @defgroup ANAC 
  * @brief ANAC driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

//Code_Start
//2018-04-02-13-20-01
//FM33A0XX_Driver_Gen_V1.4

/********************************
PDR�µ縴λ��ѹ���ú���
����:�µ縴λ��ѹ����
���룺�����µ縴λ��ѹ��bit2:1��
���:��
********************************/
void ANAC_PDRCON_PDRCFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->PDRCON;
	tmpreg &= ~(ANAC_PDRCON_PDRCFG_Msk);
	tmpreg |= (SetValue & ANAC_PDRCON_PDRCFG_Msk);
	ANAC->PDRCON = tmpreg;
}
/********************************
��PDR�µ縴λ�Ĵ���λ����
����:��PDR�µ縴λ��ѹֵ�Ĵ���λ
���룺��
���:PDR�Ĵ�����ѹֵ
********************************/
uint32_t ANAC_PDRCON_PDRCFG_Get(void)
{
	return (ANAC->PDRCON & ANAC_PDRCON_PDRCFG_Msk);
}

/*********************************
PDR�µ縴λ���ƺ��� 
���ܣ�PDR�µ縴λ��ͣ����
����: ENABLE ���µ縴λ
      DISABLE ֹͣ�µ縴λ
���: ��
*********************************/
void ANAC_PDRCON_PDREN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->PDRCON |= (ANAC_PDRCON_PDREN_Msk);
	}
	else
	{
		ANAC->PDRCON &= ~(ANAC_PDRCON_PDREN_Msk);
	}
}
/********************************
��PDR�µ縴λ����״̬����
����:��PDR�µ縴λ����״̬
���룺��
���:ENABLE ����
     DISABLE ��ֹͣ
********************************/
FunState ANAC_PDRCON_PDREN_Getable(void)
{
	if (ANAC->PDRCON & (ANAC_PDRCON_PDREN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
BOR�µ縴λ��ѹ���ú���
����:�µ縴λ��ѹ����
���룺����BOR�µ縴λ��ѹ��bit2:1��
���:��
********************************/
void ANAC_BORCON_BOR_PDRCFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->BORCON;
	tmpreg &= ~(ANAC_BORCON_BOR_PDRCFG_Msk);
	tmpreg |= (SetValue & ANAC_BORCON_BOR_PDRCFG_Msk);
	ANAC->BORCON = tmpreg;
}

/********************************
��BOR�µ縴λ�Ĵ�����ѹֵ����
����:��BOR�µ縴λ��ѹֵ�Ĵ���λ
���룺��
���:BOR�Ĵ�����ѹֵ
********************************/
uint32_t ANAC_BORCON_BOR_PDRCFG_Get(void)
{
	return (ANAC->BORCON & ANAC_BORCON_BOR_PDRCFG_Msk);
}


/*********************************
BOR�µ縴λ���ƺ��� 
���ܣ�BOR�µ縴λ��ͣ����
����: ENABLE ���µ縴λ
      DISABLE ֹͣ�µ縴λ
���: ��
*********************************/
void ANAC_BORCON_OFF_BOR_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->BORCON |= (ANAC_BORCON_OFF_BOR_Msk);
	}
	else
	{
		ANAC->BORCON &= ~(ANAC_BORCON_OFF_BOR_Msk);
	}
}
/********************************
��BOR�µ縴λ����״̬����
����:��BOR�µ縴λ����״̬
���룺��
���:ENABLE ����
     DISABLE ��ֹͣ
********************************/
FunState ANAC_BORCON_OFF_BOR_Getable(void)
{
	if (ANAC->BORCON & (ANAC_BORCON_OFF_BOR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
SVD��Դ�����ж�ʹ�ܿ��ƺ��� 
���ܣ�SVD��Դ�����ж���ͣ����
����: ENABLE ��SVD��Դ�����ж�
      DISABLE ֹͣSVD��Դ�����ж�
���: ��
*********************************/
void ANAC_SVDCFG_PFIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->SVDCFG |= (ANAC_SVDCFG_PFIE_Msk);
	}
	else
	{
		ANAC->SVDCFG &= ~(ANAC_SVDCFG_PFIE_Msk);
	}
}
/********************************
��SVD��Դ�����жϿ���״̬����
����:SVD��Դ�����жϿ���״̬
���룺��
���:ENABLE ����
     DISABLE ��ֹͣ
********************************/
FunState ANAC_SVDCFG_PFIE_Getable(void)
{
	if (ANAC->SVDCFG & (ANAC_SVDCFG_PFIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/*********************************
SVD��Դ�ָ��ж�ʹ�ܿ��ƺ��� 
���ܣ�SVD��Դ�ָ��ж���ͣ����
����: ENABLE ��SVD��Դ�ָ��ж�
      DISABLE ֹͣSVD��Դ�ָ��ж�
���: ��
*********************************/
void ANAC_SVDCFG_PRIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->SVDCFG |= (ANAC_SVDCFG_PRIE_Msk);
	}
	else
	{
		ANAC->SVDCFG &= ~(ANAC_SVDCFG_PRIE_Msk);
	}
}

/********************************
��SVD��Դ�ָ��жϿ���״̬����
����:SVD��Դ�ָ��жϿ���״̬
���룺��
���:ENABLE ����
     DISABLE ��ֹͣ
********************************/
FunState ANAC_SVDCFG_PRIE_Getable(void)
{
	if (ANAC->SVDCFG & (ANAC_SVDCFG_PRIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
SVD������ֵ���ú���
����:SVD������ֵ��ѹ����
���룺���ñ�����ѹ��bit7:4��
���:��
********************************/
void ANAC_SVDCFG_SVDLVL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->SVDCFG;
	tmpreg &= ~(ANAC_SVDCFG_SVDLVL_Msk);
	tmpreg |= (SetValue & ANAC_SVDCFG_SVDLVL_Msk);
	ANAC->SVDCFG = tmpreg;
}
/********************************
��SVD������ֵ����
����:��ȡSVD������ֵ
���룺��
���:SVD������ֵ
********************************/
uint32_t ANAC_SVDCFG_SVDLVL_Get(void)
{
	return (ANAC->SVDCFG & ANAC_SVDCFG_SVDLVL_Msk);
}

/********************************
SVD�����˲�����״̬����
����:SVD��Դ�ָ��жϿ���״̬
���룺ENABLE �������˲���SVDMODE=1ʱ������1��
      DISABLE ֹͣ�����˲�
���: ��
********************************/
void ANAC_SVDCFG_DFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->SVDCFG |= (ANAC_SVDCFG_DFEN_Msk);
	}
	else
	{
		ANAC->SVDCFG &= ~(ANAC_SVDCFG_DFEN_Msk);
	}
}
/********************************
��SVD�����˲�����״̬����
����:SVD�����˲�����״̬
���룺��
���:ENABLE ����
     DISABLE ��ֹͣ
********************************/
FunState ANAC_SVDCFG_DFEN_Getable(void)
{
	if (ANAC->SVDCFG & (ANAC_SVDCFG_DFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
SVD����ģʽѡ����
����:SVD����ģʽѡ��
���룺1����Ъʹ��ģʽ����Ъʹ��ģʽ�±��뿪�������˲���
      0����ʹ��ģʽ
���: ��
********************************/
void ANAC_SVDCFG_SVDMOD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->SVDCFG;
	tmpreg &= ~(ANAC_SVDCFG_SVDMOD_Msk);
	tmpreg |= (SetValue & ANAC_SVDCFG_SVDMOD_Msk);
	ANAC->SVDCFG = tmpreg;
}
/********************************
��SVD����ģʽ����
����:��SVD����ģʽ
���룺��
���:����ģʽ״̬λ
********************************/
uint32_t ANAC_SVDCFG_SVDMOD_Get(void)
{
	return (ANAC->SVDCFG & ANAC_SVDCFG_SVDMOD_Msk);
}

/********************************
SVD��Ъʹ�ܼ�����ú���
����:SVD��Ъʹ�ܼ��
���룺00��15.625ms
      01��62.5ms
      10��256ms
      11��1s
���: ��
********************************/
void ANAC_SVDCFG_SVDITVL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->SVDCFG;
	tmpreg &= ~(ANAC_SVDCFG_SVDITVL_Msk);
	tmpreg |= (SetValue & ANAC_SVDCFG_SVDITVL_Msk);
	ANAC->SVDCFG = tmpreg;
}
/********************************
��SVD��Ъʹ�ܼ��ʱ�����ú���
����:��SVD����ģʽ
���룺��
���:��Ъʹ�ܼ��ʱ��״̬λ
********************************/
uint32_t ANAC_SVDCFG_SVDITVL_Get(void)
{
	return (ANAC->SVDCFG & ANAC_SVDCFG_SVDITVL_Msk);
}

/*********************************
SVD����ʹ�ܿ��ƺ��� 
���ܣ�SVD����ʹ����ͣ����
����: ENABLE ��SVD����ʹ��
      DISABLE ֹͣSVD����ʹ��
���: ��
*********************************/
void ANAC_SVDCON_SVDTE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->SVDCON |= (ANAC_SVDCON_SVDTE_Msk);
	}
	else
	{
		ANAC->SVDCON &= ~(ANAC_SVDCON_SVDTE_Msk);
	}
}
/*********************************
��SVD����ʹ�ܿ���״̬���� 
���ܣ���SVD����ʹ�ܿ���״̬
����: ��
���: ENABLE ��SVD����ʹ��
      DISABLE ֹͣSVD����ʹ��
*********************************/
FunState ANAC_SVDCON_SVDTE_Getable(void)
{
	if (ANAC->SVDCON & (ANAC_SVDCON_SVDTE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
SVDʹ�ܿ��ƺ��� 
���ܣ�SVDʹ����ͣ����
����: ENABLE ��SVDʹ��
      DISABLE ֹͣSVDʹ��
���: ��
*********************************/
void ANAC_SVDCON_SVDEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->SVDCON |= (ANAC_SVDCON_SVDEN_Msk);
	}
	else
	{
		ANAC->SVDCON &= ~(ANAC_SVDCON_SVDEN_Msk);
	}
}

/*********************************
��SVDʹ�ܿ���״̬���� 
���ܣ���SVDʹ�ܿ���״̬
����: ��
���: ENABLE ��SVDʹ��
      DISABLE ֹͣSVDʹ��
*********************************/
FunState ANAC_SVDCON_SVDEN_Getable(void)
{
	if (ANAC->SVDCON & (ANAC_SVDCON_SVDEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/*********************************
��SVD��Դ��������״̬���� 
���ܣ���SVD��Դ������״̬
����: ��
���: SET   ��Դ��ѹ����SVD��ǰ��ֵ
      RESET ��Դ��ѹ����SVD��ǰ��ֵ
*********************************/
FlagStatus ANAC_SVDSIF_SVDO_Chk(void)
{
	if (ANAC->SVDSIF & ANAC_SVDSIF_SVDO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
SVD��Դ�����жϱ�־�Ĵ������� 
���ܣ���Դ�����жϱ�־����Դ��ѹ���䵽SVD��ֵ֮��ʱ��λ�����д1����
����: ��
���: ��
*********************************/
void ANAC_SVDSIF_PFF_Clr(void)
{
	ANAC->SVDSIF = ANAC_SVDSIF_PFF_Msk;
}
/*********************************
��SVD��Դ�����жϱ�־�Ĵ���״̬���� 
���ܣ���SVD��Դ�����жϱ�־״̬
����: ��
���: SET   �ж�״̬Ϊ1
      RESET  �ж�״̬Ϊ0
*********************************/
FlagStatus ANAC_SVDSIF_PFF_Chk(void)
{
	if (ANAC->SVDSIF & ANAC_SVDSIF_PFF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
SVD��Դ�ָ��жϱ�־�Ĵ������� 
���ܣ���Դ�ָ��жϱ�־����Դ��ѹ������SVD��ֵ֮��ʱ��λ�����д1����
����: ��
���: ��
*********************************/
void ANAC_SVDSIF_PRF_Clr(void)
{
	ANAC->SVDSIF = ANAC_SVDSIF_PRF_Msk;
}
/*********************************
��SVD��Դ�ָ��жϱ�־�Ĵ���״̬���� 
���ܣ���SVD��Դ�ָ��жϱ�־״̬
����: ��
���: SET   �ж�״̬Ϊ1
      RESET  �ж�״̬Ϊ0
*********************************/
FlagStatus ANAC_SVDSIF_PRF_Chk(void)
{
	if (ANAC->SVDSIF & ANAC_SVDSIF_PRF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
��SVD�ڲ��˲���ĵ�ѹ����־�Ĵ���״̬���� 
���ܣ���SVDSVD�ڲ��˲���ĵ�ѹ����־״̬���ڲ�ʹ�������˲�ʱ�����źŵ�ͬ��SVDO���������д�˼Ĵ�����
����: ��
���: SET   ��Ƿѹ
      RESET  Ƿѹ
*********************************/
FlagStatus ANAC_SVDALM_SVDALM_B_Chk(void)
{
	if (ANAC->SVDALM & ANAC_SVDALM_SVDALM_B_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
XTLF��Ƶ��ⱨ���ж�ʹ������ƺ��� 
���ܣ�XTLF��Ƶ��ⱨ���ж���ͣ����
����: ENABLE ��XTLF��Ƶ��ⱨ���ж�
      DISABLE ֹͣXTLF��Ƶ��ⱨ���ж�
���: ��
*********************************/
void ANAC_FDETIE_FDET_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->FDETIE |= (ANAC_FDETIE_FDET_IE_Msk);
	}
	else
	{
		ANAC->FDETIE &= ~(ANAC_FDETIE_FDET_IE_Msk);
	}
}
/*********************************
XTLF��Ƶ��ⱨ���ж�ʹ�ܿ���λ״̬��ȡ���� 
���ܣ���ȡXTLF��Ƶ��ⱨ���ж�ʹ�ܿ���״̬
����:��
���: ENABLE XTLF��Ƶ��ⱨ���ж�����
      DISABLE XTLF��Ƶ��ⱨ���ж���ֹͣ
*********************************/
FunState ANAC_FDETIE_FDET_IE_Getable(void)
{
	if (ANAC->FDETIE & (ANAC_FDETIE_FDET_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/*********************************
XTLFͣ����ģ�����״̬��ȡ���� 
���ܣ���ȡXTLFͣ����ģ�����״̬
����:��
���: SET    XTLFδͣ��
      RESET  XTLFͣ��
*********************************/
FlagStatus ANAC_FDETIF_FDETO_Chk(void)
{
	if (ANAC->FDETIF & ANAC_FDETIF_FDETO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
XTLFͣ�����жϱ�־�Ĵ������� 
���ܣ���XTLFͣ�����жϱ�־
����: ͣ�����жϱ�־�Ĵ�����XTLFͣ��ʱӲ���첽��λ�����д1���㣻ֻ����FDETO��Ϊ0������²��ܹ�����˼Ĵ���
���: ��
*********************************/
void ANAC_FDETIF_FDETIF_Clr(void)
{
	ANAC->FDETIF = ANAC_FDETIF_FDETIF_Msk;
}
/*********************************
XTLFͣ�����жϱ�־��ȡ���� 
���ܣ�XTLFͣ�����жϱ�־��ȡ
����:��
���: SET   ������־
      RESET δ������־
*********************************/
FlagStatus ANAC_FDETIF_FDETIF_Chk(void)
{
	if (ANAC->FDETIF & ANAC_FDETIF_FDETIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/*********************************
ADC�ж�ʹ�ܿ��ƺ��� 
���ܣ�ADC�ж���ͣ����
����: ENABLE ���λ������
      DISABLE ֹͣ��λ������
���: ��
*********************************/
void ANAC_ADCCON_ADC_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->ADCCON |= (ANAC_ADCCON_ADC_IE_Msk);
	}
	else
	{
		ANAC->ADCCON &= ~(ANAC_ADCCON_ADC_IE_Msk);
	}
}
/*********************************
ADC�ж�ʹ��״̬��ȡ���� 
���ܣ�ADC�ж�ʹ��״̬
����: ��
���: ENABLE   ADC�ж�����
      DISABLE  ADC�ж���ֹͣ
*********************************/
FunState ANAC_ADCCON_ADC_IE_Getable(void)
{
	if (ANAC->ADCCON & (ANAC_ADCCON_ADC_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
ADC�ⲿ��ѹͨ��ѡ���� 
���ܣ�ADC�ⲿ��ѹͨ��ѡ��
����: 0��ADC�����¶ȴ�����
      1��ADC���ڲ����ⲿ��ѹ
���: ��
*********************************/
void ANAC_ADCCON_ADC_VANA_EN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->ADCCON;
	tmpreg &= ~(ANAC_ADCCON_ADC_VANA_EN_Msk);
	tmpreg |= (SetValue & ANAC_ADCCON_ADC_VANA_EN_Msk);
	ANAC->ADCCON = tmpreg;
}
/*********************************
ADC�ⲿ��ѹͨ����ȡ���ú��� 
���ܣ���ȡADC�ⲿ��ѹͨ��ģʽ
����: ��
���: ͨ���Ĵ���ֵ
*********************************/
uint32_t ANAC_ADCCON_ADC_VANA_EN_Get(void)
{
	return (ANAC->ADCCON & ANAC_ADCCON_ADC_VANA_EN_Msk);
}

/*********************************
ADCʹ���źź��� 
���ܣ�ADCʹ��
����:  ENABLE   ADC����
       DISABLE  ADC��ֹͣ
���: ��
*********************************/
void ANAC_ADCCON_ADC_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->ADCCON |= (ANAC_ADCCON_ADC_EN_Msk);
	}
	else
	{
		ANAC->ADCCON &= ~(ANAC_ADCCON_ADC_EN_Msk);
	}
}
/*********************************
ADCʹ��״̬��ȡ���� 
���ܣ���ȡADC�Ƿ�ʹ��
����: ��
���:  ENABLE   ADC����
       DISABLE  ADC��ֹͣ
*********************************/
FunState ANAC_ADCCON_ADC_EN_Getable(void)
{
	if (ANAC->ADCCON & (ANAC_ADCCON_ADC_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
ADCTRIMֵ���ú��� 
���ܣ�ADCTRIMֵ����
����: ADC TRIMֵ
���:  ��
*********************************/
void ANAC_ADCTRIM_Write(uint32_t SetValue)
{
	ANAC->ADCTRIM = (SetValue & ANAC_ADCTRIM_ADC_TRIM_Msk);
}
/*********************************
��ȡADCTRIMֵ���� 
���ܣ���ȡADCTRIMֵ
����: ��
���:  ADC TRIMֵ
*********************************/
uint32_t ANAC_ADCTRIM_Read(void)
{
	return (ANAC->ADCTRIM & ANAC_ADCTRIM_ADC_TRIM_Msk);
}

/*********************************
��ȡADC����ֵ���� 
���ܣ���ȡADC�������ֵ
����: ��
���:  ADC�������ֵ
*********************************/
uint32_t ANAC_ADCDATA_Read(void)
{
	return (ANAC->ADCDATA & ANAC_ADCDATA_ADC_DATA_Msk);
}


/*********************************
ADCת������жϱ�־���� 
���ܣ�ADCת������жϱ�־��ADCת������жϱ�־��Ӳ����λ�����д1���㣬д0��Ч
����: ��
���:  ��
*********************************/
void ANAC_ADCIF_ADC_IF_Clr(void)
{
	ANAC->ADCIF = ANAC_ADCIF_ADC_IF_Msk;
}

FlagStatus ANAC_ADCIF_ADC_IF_Chk(void)
{
	if (ANAC->ADCIF & ANAC_ADCIF_ADC_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


/*********************************
ADC�ж�״̬��־��ȡ���� 
���ܣ���ȡADC�Ƿ��жϱ�־
����: ��
���:  SET    �����жϱ�־
       RESET  δ�����жϱ�־
*********************************/
void ANAC_ADCINSEL_BUFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->ADCINSEL |= (ANAC_ADCINSEL_BUFEN_Msk);
	}
	else
	{
		ANAC->ADCINSEL &= ~(ANAC_ADCINSEL_BUFEN_Msk);
	}
}

/*********************************
ADCͨ��bufferʹ�ܺ��� 
���ܣ�ADCͨ��buffer�Ƿ�ʹ��
����: ENABLE   ��buffer
      DISABLE  ֹͣbuffer
���: ��
*********************************/
FunState ANAC_ADCINSEL_BUFEN_Getable(void)
{
	if (ANAC->ADCINSEL & (ANAC_ADCINSEL_BUFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
ADCͨ��bufferʹ��״̬��־��ȡ���� 
���ܣ���ȡADCͨ��bufferʹ��״̬��־
����: ��
���: ENABLE   ��buffer
      DISABLE  ֹͣbuffer
*********************************/
void ANAC_ADCINSEL_BUFBYP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->ADCINSEL |= (ANAC_ADCINSEL_BUFBYP_Msk);
	}
	else
	{
		ANAC->ADCINSEL &= ~(ANAC_ADCINSEL_BUFBYP_Msk);
	}
}
/*********************************
ADCͨ��buffer Bypass ���ú��� 
���ܣ�����ADCͨ��buffer�Ƿ�Bypass��ʹ��ADC�����ⲿ�ź�����ʱ����ҪBypass Buffer��ʹ��ADC������Դ��ѹʱ�����뽫��λ��1
����: ENABLE   ��Bypass
      DISABLE  ֹͣBypass
���: ��
*********************************/
FunState ANAC_ADCINSEL_BUFBYP_Getable(void)
{
	if (ANAC->ADCINSEL & (ANAC_ADCINSEL_BUFBYP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/*********************************
ADCͨ��ѡ���� 
���ܣ�ADC����ͨ��ѡ��
����: ADC_IN1��ADC_IN8   VDD
���: ��
*********************************/
void ANAC_ADCINSEL_BUFSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->ADCINSEL;
	tmpreg &= ~(ANAC_ADCINSEL_BUFSEL_Msk);
	tmpreg |= (SetValue & ANAC_ADCINSEL_BUFSEL_Msk);
	ANAC->ADCINSEL = tmpreg;
}


/*********************************
ADCͨ��ѡ���ȡ���� 
���ܣ���ȡADC
����: ��
���: ѡȡ��ADCͨ��
*********************************/
uint32_t ANAC_ADCINSEL_BUFSEL_Get(void)
{
	return (ANAC->ADCINSEL & ANAC_ADCINSEL_BUFSEL_Msk);
}

/*********************************
TRNG���������ƺ��� 
���ܣ�RNGʹ�ܼĴ��������д1������������������Զ�����
����: ENABLE   �������
      DISABLE  ֹͣ�����
���: ��
*********************************/
void ANAC_TRNGCON_TRNGEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->TRNGCON |= (ANAC_TRNGCON_TRNGEN_Msk);
	}
	else
	{
		ANAC->TRNGCON &= ~(ANAC_TRNGCON_TRNGEN_Msk);
	}
}
/*********************************
TRNG����������״̬���� 
���ܣ���ȡRNG״̬
����: ��
���: ENABLE   �������
      DISABLE  ֹͣ�����
*********************************/
FunState ANAC_TRNGCON_TRNGEN_Getable(void)
{
	if (ANAC->TRNGCON & (ANAC_TRNGCON_TRNGEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
�Ƚ���1���״̬��ȡ���� 
���ܣ���ȡ�Ƚ�������ߵ�
����: ��
���: SET   �Ƚ��������
      RESET �Ƚ��������
*********************************/
FlagStatus ANAC_COMP1CR_CMP1O_Chk(void)
{
	if (ANAC->COMP1CR & ANAC_COMP1CR_CMP1O_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
�Ƚ���1��������ѡ���� 
���ܣ��Ƚ���1��������ѡ��
����: PF6 PF1 PG2 PG3
���: ��
*********************************/
void ANAC_COMP1CR_V1PSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->COMP1CR;
	tmpreg &= ~(ANAC_COMP1CR_V1PSEL_Msk);
	tmpreg |= (SetValue & ANAC_COMP1CR_V1PSEL_Msk);
	ANAC->COMP1CR = tmpreg;
}
/*********************************
�Ƚ���1��������Դ��ȡ���� 
���ܣ���ȡ�Ƚ���1��������Դ
����: ��
���: PF6 PF1 PG2 PG3
*********************************/
uint32_t ANAC_COMP1CR_V1PSEL_Get(void)
{
	return (ANAC->COMP1CR & ANAC_COMP1CR_V1PSEL_Msk);
}

/*********************************
�Ƚ���1��������ѡ���� 
���ܣ��Ƚ���1��������ѡ��
����: PF5 PF0   Vref_0.8V  Vref/2_0.4V
���: ��
*********************************/
void ANAC_COMP1CR_V1NSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->COMP1CR;
	tmpreg &= ~(ANAC_COMP1CR_V1NSEL_Msk);
	tmpreg |= (SetValue & ANAC_COMP1CR_V1NSEL_Msk);
	ANAC->COMP1CR = tmpreg;
}
/*********************************
�Ƚ���1��������Դ��ȡ���� 
���ܣ���ȡ�Ƚ���1��������Դ
����: ��
���: PF5 PF0   Vref_0.8V  Vref/2_0.4V
*********************************/
uint32_t ANAC_COMP1CR_V1NSEL_Get(void)
{
	return (ANAC->COMP1CR & ANAC_COMP1CR_V1NSEL_Msk);
}

/*********************************
�Ƚ���1ʹ�ܿ��ƺ��� 
���ܣ��Ƚ���1ʹ��
����: ENABLE   ��Ƚ���1
      DISABLE  ֹͣ�Ƚ���1
���: ��
*********************************/
void ANAC_COMP1CR_CMP1EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMP1CR |= (ANAC_COMP1CR_CMP1EN_Msk);
	}
	else
	{
		ANAC->COMP1CR &= ~(ANAC_COMP1CR_CMP1EN_Msk);
	}
}
/*********************************
�Ƚ���1״̬��ȡ���� 
���ܣ���ȡ�Ƚ���1״̬
����: ��
���: ENABLE   ��Ƚ���1
      DISABLE  ֹͣ�Ƚ���1
*********************************/
FunState ANAC_COMP1CR_CMP1EN_Getable(void)
{
	if (ANAC->COMP1CR & (ANAC_COMP1CR_CMP1EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/*********************************
�Ƚ���2���״̬��ȡ���� 
���ܣ���ȡ�Ƚ�������ߵ�
����: ��
���: SET   �Ƚ��������
      RESET �Ƚ��������
*********************************/
FlagStatus ANAC_COMP2CR_CMP2O_Chk(void)
{
	if (ANAC->COMP2CR & ANAC_COMP2CR_CMP2O_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
�Ƚ���2��������ѡ���� 
���ܣ��Ƚ���2��������ѡ��
����: PC15 PE4
���: ��
*********************************/
void ANAC_COMP2CR_V2PSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->COMP2CR;
	tmpreg &= ~(ANAC_COMP2CR_V2PSEL_Msk);
	tmpreg |= (SetValue & ANAC_COMP2CR_V2PSEL_Msk);
	ANAC->COMP2CR = tmpreg;
}
/*********************************
�Ƚ���2��������Դ��ȡ���� 
���ܣ���ȡ�Ƚ���1��������Դ
����: ��
���: PC15 PE4
*********************************/
uint32_t ANAC_COMP2CR_V2PSEL_Get(void)
{
	return (ANAC->COMP2CR & ANAC_COMP2CR_V2PSEL_Msk);
}

/*********************************
�Ƚ���2��������ѡ���� 
���ܣ��Ƚ���2��������ѡ��
����: PC14 PE3   Vref_0.8V  Vref/2_0.4V
���: ��
*********************************/
void ANAC_COMP2CR_V2NSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->COMP2CR;
	tmpreg &= ~(ANAC_COMP2CR_V2NSEL_Msk);
	tmpreg |= (SetValue & ANAC_COMP2CR_V2NSEL_Msk);
	ANAC->COMP2CR = tmpreg;
}
/*********************************
�Ƚ���2��������Դ��ȡ���� 
���ܣ���ȡ�Ƚ���1��������Դ
����: ��
���: PC14 PE3   Vref_0.8V  Vref/2_0.4V
*********************************/
uint32_t ANAC_COMP2CR_V2NSEL_Get(void)
{
	return (ANAC->COMP2CR & ANAC_COMP2CR_V2NSEL_Msk);
}

/*********************************
�Ƚ���2ʹ�ܿ��ƺ��� 
���ܣ��Ƚ���2ʹ��
����: ENABLE   ��Ƚ���2
      DISABLE  ֹͣ�Ƚ���2
���: ��
*********************************/
void ANAC_COMP2CR_CMP2EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMP2CR |= (ANAC_COMP2CR_CMP2EN_Msk);
	}
	else
	{
		ANAC->COMP2CR &= ~(ANAC_COMP2CR_CMP2EN_Msk);
	}
}
/*********************************
�Ƚ���2״̬��ȡ���� 
���ܣ���ȡ�Ƚ���2״̬
����: ��
���: ENABLE   ��Ƚ���2
      DISABLE  ֹͣ�Ƚ���2
*********************************/
FunState ANAC_COMP2CR_CMP2EN_Getable(void)
{
	if (ANAC->COMP2CR & (ANAC_COMP2CR_CMP2EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
�Ƚ���2�����˲����ú��� 
���ܣ��Ƚ���2�����˲��������
����: ENABLE   �������˲�
      DISABLE  ֹͣ�����˲�
���: ��
*********************************/
void ANAC_COMPICR_CMP2DF_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMPICR |= (ANAC_COMPICR_CMP2DF_Msk);
	}
	else
	{
		ANAC->COMPICR &= ~(ANAC_COMPICR_CMP2DF_Msk);
	}
}
/*********************************
�Ƚ���2�����˲�״̬��ȡ���� 
���ܣ���ȡ�Ƚ���2�����˲�״̬
����: ��
���: ENABLE   ��Ƚ���2�����˲�
      DISABLE  ֹͣ�Ƚ���2�����˲�
*********************************/
FunState ANAC_COMPICR_CMP2DF_Getable(void)
{
	if (ANAC->COMPICR & (ANAC_COMPICR_CMP2DF_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
�Ƚ���1�����˲����ú��� 
���ܣ��Ƚ���1�����˲��������
����: ENABLE   �������˲�
      DISABLE  ֹͣ�����˲�
���: ��
*********************************/
void ANAC_COMPICR_CMP1DF_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMPICR |= (ANAC_COMPICR_CMP1DF_Msk);
	}
	else
	{
		ANAC->COMPICR &= ~(ANAC_COMPICR_CMP1DF_Msk);
	}
}
/*********************************
�Ƚ���1�����˲�״̬��ȡ���� 
���ܣ���ȡ�Ƚ���1�����˲�״̬
����: ��
���: ENABLE   ��Ƚ���1�����˲�
      DISABLE  ֹͣ�Ƚ���1�����˲�
*********************************/
FunState ANAC_COMPICR_CMP1DF_Getable(void)
{
	if (ANAC->COMPICR & (ANAC_COMPICR_CMP1DF_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
�Ƚ���Buffer Bypass���ƺ��� 
���ܣ��Ƚ���Buffer Bypassѡ��
����: ENABLE   ��Ƚ���Buffer Bypass
      DISABLE  ֹͣ�Ƚ���Buffer Bypass
���: ��
*********************************/
void ANAC_COMPICR_BUFBYP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMPICR |= (ANAC_COMPICR_BUFBYP_Msk);
	}
	else
	{
		ANAC->COMPICR &= ~(ANAC_COMPICR_BUFBYP_Msk);
	}
}
/*********************************
�Ƚ���Buffer Bypass״̬��ȡ���� 
���ܣ���ȡ�Ƚ���Buffer Bypass״̬
����: ��
���: ENABLE   �Ƚ���Buffer Bypassʹ��
      DISABLE  �Ƚ���Buffer Bypass��ֹ
*********************************/
FunState ANAC_COMPICR_BUFBYP_Getable(void)
{
	if (ANAC->COMPICR & (ANAC_COMPICR_BUFBYP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
�Ƚ���Buffer ���ƺ��� 
���ܣ��Ƚ���Buffer ѡ��
����: ENABLE   ��Ƚ���Buffer 
      DISABLE  ֹͣ�Ƚ���Buffer 
���: ��
*********************************/
void ANAC_COMPICR_BUFENB_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMPICR &= ~(ANAC_COMPICR_BUFENB_Msk);
	}
	else
	{
		ANAC->COMPICR |= (ANAC_COMPICR_BUFENB_Msk);
	}
}
/*********************************
�Ƚ���Buffer ״̬��ȡ���� 
���ܣ���ȡ�Ƚ���Buffer״̬
����: ��
���: ENABLE   �Ƚ���Buffer��
      DISABLE  �Ƚ���Buffer��ֹͣ
*********************************/
FunState ANAC_COMPICR_BUFENB_Getable(void)
{
	if (ANAC->COMPICR & (ANAC_COMPICR_BUFENB_Msk))
	{
		return DISABLE;
	}
	else
	{
		return ENABLE;
	}
}


/*********************************
�Ƚ���2�ж�Դѡ���� 
���ܣ��Ƚ���2�ж�Դѡ��bit[5:4]
����: 00/11���Ƚ���2����������½��ز����ж�
      01���Ƚ���2��������ز����ж�
      10���Ƚ���2����½��ز����ж�
���: ��
*********************************/
void ANAC_COMPICR_CMP2SEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->COMPICR;
	tmpreg &= ~(ANAC_COMPICR_CMP2SEL_Msk);
	tmpreg |= (SetValue & ANAC_COMPICR_CMP2SEL_Msk);
	ANAC->COMPICR = tmpreg;
}
/*********************************
�Ƚ���2�ж�Դ��ȡ���� 
���ܣ���ȡ�Ƚ���2�ж�Դbit[5:4]
����: ��
���: 00/11���Ƚ���2����������½��ز����ж�
      01���Ƚ���2��������ز����ж�
      10���Ƚ���2����½��ز����ж�
*********************************/
uint32_t ANAC_COMPICR_CMP2SEL_Get(void)
{
	return (ANAC->COMPICR & ANAC_COMPICR_CMP2SEL_Msk);
}

/*********************************
�Ƚ���1�ж�Դѡ���� 
���ܣ��Ƚ���1�ж�Դѡ��bit[3:2]
����: 00/11���Ƚ���1����������½��ز����ж�
      01���Ƚ���1��������ز����ж�
      10���Ƚ���1����½��ز����ж�
���: ��
*********************************/
void ANAC_COMPICR_CMP1SEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->COMPICR;
	tmpreg &= ~(ANAC_COMPICR_CMP1SEL_Msk);
	tmpreg |= (SetValue & ANAC_COMPICR_CMP1SEL_Msk);
	ANAC->COMPICR = tmpreg;
}
/*********************************
�Ƚ���1�ж�Դ��ȡ���� 
���ܣ���ȡ�Ƚ���1�ж�Դbit[3:2]
����: ��
���: 00/11���Ƚ���1����������½��ز����ж�
      01���Ƚ���1��������ز����ж�
      10���Ƚ���1����½��ز����ж�
*********************************/
uint32_t ANAC_COMPICR_CMP1SEL_Get(void)
{
	return (ANAC->COMPICR & ANAC_COMPICR_CMP1SEL_Msk);
}

/*********************************
�Ƚ���2�ж�ʹ�ܿ��ƺ��� 
���ܣ��Ƚ���2�жϿ��ƿ���
����: ENABLE   ��Ƚ���2�ж�
      DISABLE  ֹͣ�Ƚ���2�жϲ�
���: ��
*********************************/
void ANAC_COMPICR_CMP2IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMPICR |= (ANAC_COMPICR_CMP2IE_Msk);
	}
	else
	{
		ANAC->COMPICR &= ~(ANAC_COMPICR_CMP2IE_Msk);
	}
}

/*********************************
�Ƚ���2�ж�ʹ��״̬���� 
���ܣ���ȡ�Ƚ���2�жϿ���״̬
����: ��
���: ENABLE   �Ƚ���2�ж���
      DISABLE  �Ƚ���2�жϲ�ֹͣ
*********************************/
FunState ANAC_COMPICR_CMP2IE_Getable(void)
{
	if (ANAC->COMPICR & (ANAC_COMPICR_CMP2IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
�Ƚ���1�ж�ʹ�ܿ��ƺ��� 
���ܣ��Ƚ���1�жϿ��ƿ���
����: ENABLE   ��Ƚ���1�ж�
      DISABLE  ֹͣ�Ƚ���1�жϲ�
���: ��
*********************************/
void ANAC_COMPICR_CMP1IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMPICR |= (ANAC_COMPICR_CMP1IE_Msk);
	}
	else
	{
		ANAC->COMPICR &= ~(ANAC_COMPICR_CMP1IE_Msk);
	}
}
/*********************************
�Ƚ���1�ж�ʹ��״̬���� 
���ܣ���ȡ�Ƚ���1�жϿ���״̬
����: ��
���: ENABLE   �Ƚ���1�ж���
      DISABLE  �Ƚ���1�жϲ�ֹͣ
*********************************/
FunState ANAC_COMPICR_CMP1IE_Getable(void)
{
	if (ANAC->COMPICR & (ANAC_COMPICR_CMP1IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
�Ƚ���2�жϱ�־���ƺ��� 
���ܣ��Ƚ���2�жϱ�־����
����: Ӳ����λ�����д1����
���: ��
*********************************/
void ANAC_COMPIF_CMP2IF_Clr(void)
{
	ANAC->COMPIF = ANAC_COMPIF_CMP2IF_Msk;
}
/*********************************
�Ƚ���2�жϱ�־״̬���� 
���ܣ���ȡ�Ƚ���2�жϱ�־״̬
����: ��
���: SET    �Ƚ���2�����жϱ�־
      RESET  �Ƚ���2δ�����жϱ�־
*********************************/
FlagStatus ANAC_COMPIF_CMP2IF_Chk(void)
{
	if (ANAC->COMPIF & ANAC_COMPIF_CMP2IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
�Ƚ���1�жϱ�־���ƺ��� 
���ܣ��Ƚ���1�жϱ�־����
����: Ӳ����λ�����д1����
���: ��
*********************************/
void ANAC_COMPIF_CMP1IF_Clr(void)
{
	ANAC->COMPIF = ANAC_COMPIF_CMP1IF_Msk;
}
/*********************************
�Ƚ���1�жϱ�־״̬���� 
���ܣ���ȡ�Ƚ���1�жϱ�־״̬
����: ��
���: SET    �Ƚ���1�����жϱ�־
      RESET  �Ƚ���1δ�����жϱ�־
*********************************/
FlagStatus ANAC_COMPIF_CMP1IF_Chk(void)
{
	if (ANAC->COMPIF & ANAC_COMPIF_CMP1IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void ANAC_Deinit(void)
{
	ANAC->PDRCON = 0x00000003;
	ANAC->BORCON = 0x00000002;
	ANAC->SVDCFG = 0x00000008;
	ANAC->SVDCON = 0x00000000;
	//ANAC->SVDSIF = ;
	//ANAC->SVDALM = ;
	ANAC->FDETIE = 0x00000000;
	//ANAC->FDETIF = ;
	ANAC->ADCCON = 0x00000000;
	ANAC->ADCTRIM = 0x00000000;
	//ANAC->ADCDATA = ;
	//ANAC->ADCIF = ;
	ANAC->ADCINSEL = 0x00000000;
	ANAC->TRNGCON = 0x00000000;
	ANAC->COMP1CR = 0x00000000;
	ANAC->COMP2CR = 0x00000000;
	ANAC->COMPICR = 0x00000040;
	//ANAC->COMPIF = ;
}
//Code_End



/*********************************
SVD��ʼ�����ú��� 
���ܣ�SVD��ʼ������
����: ANAC_SVD_InitTypeDef* para���ṹ�庯�������ù���ģʽ����ֵ�������˲��ȹ���
���: ��
*********************************/
void ANAC_SVD_Init(ANAC_SVD_InitTypeDef* para)
{
	ANAC_SVDCFG_SVDMOD_Set(para->SVDMOD);	//SVD����ģʽѡ��
	ANAC_SVDCFG_SVDITVL_Set(para->SVDITVL);	//SVD��Ъʹ�ܼ������
	ANAC_SVDCFG_SVDLVL_Set(para->SVDLVL);	//SVD������ֵ����
	ANAC_SVDCFG_DFEN_Setable(para->DFEN);	//SVD�����˲����ã�SVDMODE=1ʱ������1��
	ANAC_SVDCFG_PFIE_Setable(para->PFIE);	//SVD��Դ�����ж�����
	ANAC_SVDCFG_PRIE_Setable(para->PRIE);	//SVD��Դ�ָ��ж�����
	ANAC_SVDCON_SVDTE_Setable(DISABLE);	//�رղ��Թ���
	ANAC_SVDCON_SVDEN_Setable(para->SVDEN);	//SVDʹ������
}

/*********************************
ADC��ʼ�����ú��� 
���ܣ�ADC��ʼ������
����: ANAC_ADC_InitTypeDef* para���ṹ�庯��������ADCTRIM�����ⲿͨ����buff�ȹ���
���: ��
*********************************/
void ANAC_ADC_Init(ANAC_ADC_InitTypeDef* para)
{
	ANAC_ADCTRIM_Write(para->ADC_TRIM);				//<��Ч�ο���ѹ��У�Ĵ���
	ANAC_ADCCON_ADC_VANA_EN_Set(para->ADC_VANA_EN);	//<�ڲ�ͨ�����ⲿͨ��ѡ��
	ANAC_ADCINSEL_BUFSEL_Set(para->BUFSEL);			//<ADC����ͨ��ѡ��
	ANAC_ADCINSEL_BUFBYP_Setable(para->BUFBYP);		//<ADC����Buffer Bypass��ADC����Buffer Bypass��ʹ��ADC�����ⲿ�ź�����ʱ���ر�bypass�� ʹ��ADC�����ڲ��ź�ʱ�����뽫��λ��1��bypass��
	ANAC_ADCINSEL_BUFEN_Setable(para->BUFEN);		//<ADC����ͨ��Bufferʹ�ܣ���������
	ANAC_ADCCON_ADC_IE_Setable(para->ADC_IE);		//<ADC�ж�ʹ��
	ANAC_ADCCON_ADC_EN_Setable(para->ADC_EN);		//<ADCʹ��
}

/*********************************
ADC����ͨ�����ú��� 
���ܣ�ADCͨ������
����: CH_PTAT  CH_VDD  CH_IN1-8
���: ��
*********************************/
void ANAC_ADC_Channel_SetEx(uint8_t ChSel_def)
{
	switch( ChSel_def )
	{
		case CH_PTAT://�¶ȴ�����ͨ��
			ANAC_ADCCON_ADC_VANA_EN_Set(ANAC_ADCCON_ADC_VANA_EN_PTAT);	//����	
			ANAC_ADCTRIM_Write(const_adc_TrimT);						//���òο���ѹ
			ANAC_ADCINSEL_BUFBYP_Setable(ENABLE);	//�ڲ��źŲ�����bypassbuffer
			ANAC_ADCINSEL_BUFEN_Setable(ENABLE);	//
			break;

		case CH_VDD://��ԴVDDͨ��
			ANAC_ADCCON_ADC_VANA_EN_Set(ANAC_ADCCON_ADC_VANA_EN_VOLTAGE);	//��VDD��ѹ��ע��ADC����Ϊ4.5V��2.2mV*0x7FF��,����4.5V�ĵ�ѹ����0x7FF
			ANAC_ADCTRIM_Write(const_adc_TrimV);							//���òο���ѹ
			ANAC_ADCINSEL_BUFBYP_Setable(ENABLE);		//�ڲ�����
			ANAC_ADCINSEL_BUFEN_Setable(ENABLE);		//��ѹ
			ANAC_ADCINSEL_BUFSEL_Set(ANAC_ADCINSEL_BUFSEL_VDD);//vdd
			break;
		
		case CH_IN1://�ⲿ����ͨ��
		case CH_IN2:
		case CH_IN3:
		case CH_IN4:
		case CH_IN5:
		case CH_IN6:
		case CH_IN7:
		case CH_IN8:
			ANAC_ADCCON_ADC_VANA_EN_Set(ANAC_ADCCON_ADC_VANA_EN_VOLTAGE);	//���ѹ�������ѹ���ɸ���оƬVDD��ע��ADC����Ϊ4.5V��2.2mV*0x7FF��,����4.5V�ĵ�ѹ����0x7FF
			ANAC_ADCTRIM_Write(const_adc_TrimV);							//���òο���ѹ
			ANAC_ADCINSEL_BUFBYP_Setable(DISABLE);	//�ⲿ�źŲ������ر�bypassbuffer
			ANAC_ADCINSEL_BUFEN_Setable(ENABLE);	//��bufferen
			ANAC_ADCINSEL_BUFSEL_Set((ANAC_ADCINSEL_BUFSEL_ADC_IN1 + (ChSel_def - CH_IN1)));//����ͨ��ѡ��
			break;
		
		default:
			break;
	}
}


/*ADC ��ѹ���㺯��
	���룺ADֵ	 float�ͣ����㴦��ƽ��ֵ��
	�������ѹ@mV float��
*/
//�����ѹ����100mV����Խ����̫׼ȷ
//�����ѹ����4.4V����Խ����̫׼ȷ
//�����ѹ���ɳ�����Դ��ѹ
//�����ѹ���ɳ���4.5V
/*********************************
ADC��ѹ���㺯�� 
���ܣ�����ADC������ѹֵ
����: ADCֵ
���: ��ѹֵ
*********************************/
float ANAC_ADC_VoltageCalc(float fADCData)
{
	float fVolt = 0;
		
	if( (const_adc_Slope > 2000) && (const_adc_Slope < 2400) )
	{
		//ʹ�óɲ�����	
		//ADCֵ����Ϊ��ѹֵ
//		fVolt = fADCData*((const_adc_Slope/1000.0))+(float)const_adc_Offset/100.0;	
		if(fADCData <= 30)
			fVolt = 0;
		else if(fADCData <= 50)
			fVolt = (fADCData-30)*5;
		else if(fADCData <= 150)
			fVolt = (fADCData*(const_adc_Slope/1000.0));
		else if(fADCData <= 500)
			fVolt = (fADCData*0.98*(const_adc_Slope/1000.0));
		else
			fVolt = (fADCData*(const_adc_Slope/1000.0))+const_adc_Offset/100.0;	
	}
	else
	{
		//������ʱʹ��
		fVolt = (fADCData - 10)*2.174;
	}
	
	return fVolt;
}

/*ADC �¶ȼ��㺯��
	���룺ADֵ	 float�ͣ����㴦��ƽ��ֵ��
	���룺��Դ��ѹ uint08�� ��֧��3/5V����������ѹ����
	������¶�@�� float��
*/
/*********************************
ADC�¶ȼ��㺯�� 
���ܣ�����ADC�����¶�ֵ
����: ADCֵ����Դ��ѹ
���: �¶�ֵ
*********************************/
float ANAC_ADC_TemperatureCalc(float fADCData ,uint8_t Vdd)
{
	float fTestADC, fTestT, fFa;
	float fTemperature;
		
	if( const_temp_TestA == 0x1E )
	{
		//ʹ���¶ȶ�������
		fTestT = const_temp_TestA+(float)(const_temp_TestB/0x80)*0.5;
		if( Vdd == 3 )
		{
			fTestADC = const_adc_Test  - const_T_Offset3V*const_TmpsH;
		}
		else
		{			
			fTestADC = const_adc_Test  - const_T_Offset5V*const_TmpsH;
		}
	}
	else
	{
		//������ʱʹ��
		fTestT = 30;
		fTestADC = 1500;
	}
	
	if( fADCData > (fTestADC-25) )	//����
		fFa = const_TmpsH;
	else
		fFa = const_TmpsL;

	fTemperature = (fADCData - fTestADC)/fFa + fTestT;
	
	return fTemperature;
}


/*********************************
�Ƚ�����ʼ�����ú��� 
���ܣ����ñȽ�������
����: ANAC_COMPx_InitTypeDef* para  �Ƚ���1��2 �Ĵ����������롢�������롢�ж�ʹ�ܵȲ���
���: ��
*********************************/
void ANAC_COMPx_Init(ANAC_COMPx_InitTypeDef* para)
{
	if(para->COMPx == 1)//�Ƚ���1
	{
		ANAC_COMP1CR_V1PSEL_Set(para->VxPSEL);		//�Ƚ���x��������ѡ��
		ANAC_COMP1CR_V1NSEL_Set(para->VxNSEL);		//�Ƚ���x��������ѡ��
		ANAC_COMPICR_CMP1SEL_Set(para->CMPxSEL);	//�Ƚ���x�ж�Դѡ��
		ANAC_COMPICR_CMP1IE_Setable(para->CMPxIE);	//����x�ж�ʹ��
		ANAC_COMPICR_CMP1DF_Setable(para->CMPxDF);	//�Ƚ���x�����˲�ʹ��
		ANAC_COMP1CR_CMP1EN_Setable(para->CMPxEN);	//�Ƚ���xʹ��
	}
	else		//�Ƚ���2
	{
		ANAC_COMP2CR_V2PSEL_Set(para->VxPSEL);		//�Ƚ���x��������ѡ��
		ANAC_COMP2CR_V2NSEL_Set(para->VxNSEL);		//�Ƚ���x��������ѡ��
		ANAC_COMPICR_CMP2SEL_Set(para->CMPxSEL);	//�Ƚ���x�ж�Դѡ��
		ANAC_COMPICR_CMP2IE_Setable(para->CMPxIE);	//����x�ж�ʹ��
		ANAC_COMPICR_CMP2DF_Setable(para->CMPxDF);	//�Ƚ���x�����˲�ʹ��
		ANAC_COMP2CR_CMP2EN_Setable(para->CMPxEN);	//�Ƚ���xʹ��	
	}
}


/******END OF FILE****/



