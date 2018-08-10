/**
  ******************************************************************************
  * @file    fm33a0xx_spi.c
  * @author  
  * @version V2.0.2
  * @date    
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of SPI:           
  *           
  ******************************************************************************  
  */ 

/* Includes ------------------------------------------------------------------*/ 

#include "fm33a0xx_spi.h" 
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/



//Code_Start
//2018-04-02-13-22-56
//FM33A0XX_Driver_Gen_V1.4

/********************************
Master��MISO�źŵĲ���λ�õ�������
����:Master��MISO�źŵĲ���λ�õ��������ڸ���ͨ��ʱ����PCB�����ӳ�
���룺����λ�õ������߼�ֵ
1���������ӳٰ��SCK����
0��������
********************************/
void SPIx_SPICR1_MSPA_Set(SPIx_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->SPICR1;
	tmpreg &= ~(SPIx_SPICR1_MSPA_Msk);
	tmpreg |= (SetValue & SPIx_SPICR1_MSPA_Msk);
	SPIx->SPICR1 = tmpreg;
}
/********************************
��ȡMaster��MISO�źŵĲ���λ�õ�������
����:��ȡ����λ�õ������߼�ֵ
���������λ�õ������߼�ֵ
1���������ӳٰ��SCK����
0��������
********************************/
uint32_t SPIx_SPICR1_MSPA_Get(SPIx_Type* SPIx)
{
	return (SPIx->SPICR1 & SPIx_SPICR1_MSPA_Msk);
}

/********************************
Slave MISO����λ�õ�������
����:Slave MISO����λ�õ���
���룺Slave MISO����λ�õ������߼�ֵ
1����ǰ���SCK���ڷ���
0��������
********************************/
void SPIx_SPICR1_SSPA_Set(SPIx_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->SPICR1;
	tmpreg &= ~(SPIx_SPICR1_SSPA_Msk);
	tmpreg |= (SetValue & SPIx_SPICR1_SSPA_Msk);
	SPIx->SPICR1 = tmpreg;
}
/********************************
��ȡSlave MISO����λ�õ�������
����:��ȡSlave MISO����λ�õ������߼�ֵ
�����Slave MISO����λ�õ������߼�ֵ
1����ǰ���SCK���ڷ���
0��������
********************************/
uint32_t SPIx_SPICR1_SSPA_Get(SPIx_Type* SPIx)
{
	return (SPIx->SPICR1 & SPIx_SPICR1_SSPA_Msk);
}

/********************************
 MASTER/SLAVEģʽѡ����
����: MASTER/SLAVEģʽѡ��
���룺 MASTER/SLAVEģʽѡ����߼�ֵ
1��Masterģʽ
0��Slaveģʽ
********************************/
void SPIx_SPICR1_MM_Set(SPIx_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->SPICR1;
	tmpreg &= ~(SPIx_SPICR1_MM_Msk);
	tmpreg |= (SetValue & SPIx_SPICR1_MM_Msk);
	SPIx->SPICR1 = tmpreg;
}
/********************************
 ��ȡMASTER/SLAVEģʽѡ����
����: ��ȡMASTER/SLAVEģʽ
����� MASTER/SLAVEģʽ���߼�ֵ
1��Masterģʽ
0��Slaveģʽ
********************************/
uint32_t SPIx_SPICR1_MM_Get(SPIx_Type* SPIx)
{
	return (SPIx->SPICR1 & SPIx_SPICR1_MM_Msk);
}
/********************************
 Masterģʽ�����ü���SCK cycle����ֵ����
����: ����SCK cycle��WAIT��ֵ
���룺  SCK cycle��WAIT��ֵ
********************************/
void SPIx_SPICR1_WAIT_Set(SPIx_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->SPICR1;
	tmpreg &= ~(SPIx_SPICR1_WAIT_Msk);
	tmpreg |= (SetValue & SPIx_SPICR1_WAIT_Msk);
	SPIx->SPICR1 = tmpreg;
}
/********************************
 ��ȡMasterģʽ�����ü���SCK cycle����ֵ����
����: ��ȡ���õ�SCK cycle��WAIT��ֵ
�����  SCK cycle��WAIT��ֵ
********************************/
uint32_t SPIx_SPICR1_WAIT_Get(SPIx_Type* SPIx)
{
	return (SPIx->SPICR1 & SPIx_SPICR1_WAIT_Msk);
}

/********************************
 MASTERģʽ���������ú���
����: MASTERģʽ�����ʵ�����
���룺   MASTERģʽ�����ʵ�������ֵ��fAHBCLK�ķ�Ƶ��
********************************/
void SPIx_SPICR1_BAUD_Set(SPIx_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->SPICR1;
	tmpreg &= ~(SPIx_SPICR1_BAUD_Msk);
	tmpreg |= (SetValue & SPIx_SPICR1_BAUD_Msk);
	SPIx->SPICR1 = tmpreg;
}
/********************************
 ��ȡMASTERģʽ���������õ���ֵ����
����: ��ȡMASTERģʽ�����ʵ�����
�����  ģʽ�����ʵ����ã�fAHBCLK�ķ�Ƶ��
********************************/
uint32_t SPIx_SPICR1_BAUD_Get(SPIx_Type* SPIx)
{
	return (SPIx->SPICR1 & SPIx_SPICR1_BAUD_Msk);
}

/********************************
 ֡��ʽ���ú���
����: ֡��ʽ������
���룺֡��ʽ������
0���ȷ���MSB
1���ȷ���LSB 
********************************/
void SPIx_SPICR1_LSBF_Set(SPIx_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->SPICR1;
	tmpreg &= ~(SPIx_SPICR1_LSBF_Msk);
	tmpreg |= (SetValue & SPIx_SPICR1_LSBF_Msk);
	SPIx->SPICR1 = tmpreg;
}
/********************************
 ��ȡ֡��ʽ�����õĺ���
����: ���ö�ȡ֡��ʽ������
�����  ֡��ʽ������
0���ȷ���MSB
1���ȷ���LSB
********************************/
uint32_t SPIx_SPICR1_LSBF_Get(SPIx_Type* SPIx)
{
	return (SPIx->SPICR1 & SPIx_SPICR1_LSBF_Msk);
}

/********************************
 ʱ�Ӽ���ѡ����
����: ����ʱ�Ӽ���
���룺ʱ�Ӽ��Ե�����
1������ʱ��ֹͣ�ڸߵ�ƽ
0������ʱ��ֹͣ�ڵ͵�ƽ
********************************/
void SPIx_SPICR1_CPHOL_Set(SPIx_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->SPICR1;
	tmpreg &= ~(SPIx_SPICR1_CPHOL_Msk);
	tmpreg |= (SetValue & SPIx_SPICR1_CPHOL_Msk);
	SPIx->SPICR1 = tmpreg;
}
/********************************
 ��ȡʱ�Ӽ���ѡ��ĺ���
����: ��ȡ����ʱ�Ӽ���
�������ȡʱ�Ӽ��Ե�����
1������ʱ��ֹͣ�ڸߵ�ƽ
0������ʱ��ֹͣ�ڵ͵�ƽ
********************************/
uint32_t SPIx_SPICR1_CPHOL_Get(SPIx_Type* SPIx)
{
	return (SPIx->SPICR1 & SPIx_SPICR1_CPHOL_Msk);
}

/********************************/
/* ʱ����λѡ�� ��غ��� */
void SPIx_SPICR1_CPHA_Set(SPIx_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->SPICR1;
	tmpreg &= ~(SPIx_SPICR1_CPHA_Msk);
	tmpreg |= (SetValue & SPIx_SPICR1_CPHA_Msk);
	SPIx->SPICR1 = tmpreg;
}
/********************************
 ��ȡʱ����λѡ����
����: ��ȡʱ����λѡ��
�����ȡʱ����λѡ��
1���ڶ���ʱ�ӱ����ǵ�һ����׽����
0����һ��ʱ�ӱ����ǵ�һ����׽����
********************************/
uint32_t SPIx_SPICR1_CPHA_Get(SPIx_Type* SPIx)
{
	return (SPIx->SPICR1 & SPIx_SPICR1_CPHA_Msk);
}


/********************************
Slave����ܽ��˲�ʹ�ܣ�SSN/SCK/MOSI������
����: Slave����ܽ��˲�ʹ�ܣ�SSN/SCK/MOSI���Ŀ���رչ���
���룺 Slave����ܽ��˲�ʹ��
1��ʹ��4ns�˲�
0�����˲�
********************************/
void SPIx_SPICR2_FLTEN_Setable(SPIx_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->SPICR2 |= (SPIx_SPICR2_FLTEN_Msk);
	}
	else
	{
		SPIx->SPICR2 &= ~(SPIx_SPICR2_FLTEN_Msk);
	}
}
/********************************
��ȡSlave����ܽ��˲�ʹ�ܣ�SSN/SCK/MOSI������
����: ��ȡSlave����ܽ��˲�ʹ�ܣ�SSN/SCK/MOSI��״̬
����� Slave����ܽ��˲�ʹ�ܵ�״̬
1��ʹ��4ns�˲�
0�����˲�
********************************/
FunState SPIx_SPICR2_FLTEN_Getable(SPIx_Type* SPIx)
{
	if (SPIx->SPICR2 & (SPIx_SPICR2_FLTEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/********************************
Masterģʽ��SSN����ģʽѡ����
����: Masterģʽ��SSN����ģʽ��ѡ��
���룺 Masterģʽ��SSN����ģʽ��ѡ��
1��ÿ������8bit��Master����SSN��ά�ָߵ�ƽʱ����WAIT�Ĵ�������
0��ÿ������8bit��Master����SSNΪ��
********************************/
void SPIx_SPICR2_SSNM_Set(SPIx_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->SPICR2;
	tmpreg &= ~(SPIx_SPICR2_SSNM_Msk);
	tmpreg |= (SetValue & SPIx_SPICR2_SSNM_Msk);
	SPIx->SPICR2 = tmpreg;
}
/********************************
��ȡMasterģʽ��SSN����ģʽѡ����
����: Masterģʽ��SSN����ģʽ��ѡ��
���룺 Masterģʽ��SSN����ģʽ��ѡ��
1��ÿ������8bit��Master����SSN��ά�ָߵ�ƽʱ����WAIT�Ĵ�������
0��ÿ������8bit��Master����SSNΪ��
********************************/
uint32_t SPIx_SPICR2_SSNM_Get(SPIx_Type* SPIx)
{
	return (SPIx->SPICR2 & SPIx_SPICR2_SSNM_Msk);
}

/********************************
TXONLYӲ���Զ���յ�ʹ�ܺ���
����: TXONLYӲ���Զ���յ�ʹ�ܿ���ر�
���룺 TXONLYӲ���Զ���յ�ʹ��״̬
1��TXONLYӲ���Զ�������Ч�����ʹ��TXO�󣬵ȴ�������Ϻ�Ӳ������
0���ر�TXONLYӲ���Զ�����
********************************/
void SPIx_SPICR2_TXO_AC_Set(SPIx_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->SPICR2;
	tmpreg &= ~(SPIx_SPICR2_TXO_AC_Msk);
	tmpreg |= (SetValue & SPIx_SPICR2_TXO_AC_Msk);
	SPIx->SPICR2 = tmpreg;
}
/********************************
��ȡTXONLYӲ���Զ���յ�ʹ��״̬�ĺ���
����: ��ȡTXONLYӲ���Զ���յ�ʹ��״̬
����� ��ȡTXONLYӲ���Զ���յ�ʹ��״̬
1��TXONLYӲ���Զ�������Ч�����ʹ��TXO�󣬵ȴ�������Ϻ�Ӳ������
0���ر�TXONLYӲ���Զ�����
********************************/
uint32_t SPIx_SPICR2_TXO_AC_Get(SPIx_Type* SPIx)
{
	return (SPIx->SPICR2 & SPIx_SPICR2_TXO_AC_Msk);
}

/********************************
TTXONLY����λ���ú���
����: TTXONLY����λ������
���룺 TTXONLY����λ������
1����Master�ĵ�����ģʽ
0���رյ�����ģʽ
********************************/
void SPIx_SPICR2_TXO_Setable(SPIx_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->SPICR2 |= (SPIx_SPICR2_TXO_Msk);
	}
	else
	{
		SPIx->SPICR2 &= ~(SPIx_SPICR2_TXO_Msk);
	}
}
/********************************
��ȡTTXONLY����λ���ú���
����: ��ȡTTXONLY����λ������
����� TTXONLY����λ������
1����Master�ĵ�����ģʽ
0���رյ�����ģʽ
********************************/
FunState SPIx_SPICR2_TXO_Getable(SPIx_Type* SPIx)
{
	if (SPIx->SPICR2 & (SPIx_SPICR2_TXO_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
Masterģʽ���������SSN�����ƽ����
����: ����SSN�����ƽ������
���룺 ����SSN�����ƽ
1��SSN����ߵ�ƽ
0��SSN����͵�ƽ
********************************/
void SPIx_SPICR2_SSN_Set(SPIx_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->SPICR2;
	tmpreg &= ~(SPIx_SPICR2_SSN_Msk);
	tmpreg |= (SetValue & SPIx_SPICR2_SSN_Msk);
	SPIx->SPICR2 = tmpreg;
}
/********************************
��ȡMasterģʽ���������SSN�����ƽ����
����: ��ȡ����SSN�����ƽ������
���룺 ����SSN�����ƽ
1��SSN����ߵ�ƽ
0��SSN����͵�ƽ
********************************/
uint32_t SPIx_SPICR2_SSN_Get(SPIx_Type* SPIx)
{
	return (SPIx->SPICR2 & SPIx_SPICR2_SSN_Msk);
}

/********************************
Masterģʽ��SSN�Ŀ��Ʒ�ʽ����
����: SSN�Ŀ��Ʒ�ʽ������
���룺 SSN�Ŀ��Ʒ�ʽ
1��Masterģʽ��SSN������������
0��Masterģʽ��SSN�����Ӳ���Զ�����
********************************/
void SPIx_SPICR2_SSNSEN_Set(SPIx_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->SPICR2;
	tmpreg &= ~(SPIx_SPICR2_SSNSEN_Msk);
	tmpreg |= (SetValue & SPIx_SPICR2_SSNSEN_Msk);
	SPIx->SPICR2 = tmpreg;
}
/********************************
��ȡMasterģʽ��SSN�Ŀ��Ʒ�ʽ����
����: ��ȡSSN�Ŀ��Ʒ�ʽ������
����� SSN�Ŀ��Ʒ�ʽ
1��Masterģʽ��SSN������������
0��Masterģʽ��SSN�����Ӳ���Զ�����
********************************/
uint32_t SPIx_SPICR2_SSNSEN_Get(SPIx_Type* SPIx)
{
	return (SPIx->SPICR2 & SPIx_SPICR2_SSNSEN_Msk);
}

/********************************
SPIʹ�ܺ���
����: SPIʹ�ܵ�����
���룺 SPIʹ������
1��ʹ��SPI
0���ر�SPI����շ��ͽ��ջ���
********************************/
void SPIx_SPICR2_SPIEN_Setable(SPIx_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->SPICR2 |= (SPIx_SPICR2_SPIEN_Msk);
	}
	else
	{
		SPIx->SPICR2 &= ~(SPIx_SPICR2_SPIEN_Msk);
	}
}
/********************************
��ȡSPIʹ�ܺ���
����: ��ȡSPIʹ�ܵ�����
����� SPIʹ������
1��ʹ��SPI
0���ر�SPI����շ��ͽ��ջ���
********************************/
FunState SPIx_SPICR2_SPIEN_Getable(SPIx_Type* SPIx)
{
	if (SPIx->SPICR2 & (SPIx_SPICR2_SPIEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/********************************
�������BUFFER����
����: �������BUFFER
********************************/
void SPIx_SPICR3_TXBFC_Clr(SPIx_Type* SPIx)
{
	SPIx->SPICR3 = SPIx_SPICR3_TXBFC_Msk;
}
/********************************
�������BUFFER����
����: �������BUFFER
********************************/
void SPIx_SPICR3_RXBFC_Clr(SPIx_Type* SPIx)
{
	SPIx->SPICR3 = SPIx_SPICR3_RXBFC_Msk;
}
/********************************
�����ģʽ����ĺ���
����: �����ģʽ����
********************************/
void SPIx_SPICR3_MERRC_Clr(SPIx_Type* SPIx)
{
	SPIx->SPICR3 = SPIx_SPICR3_MERRC_Msk;
}

/********************************
�����ģʽ����ĺ���
����: �����ģʽ����
********************************/
void SPIx_SPICR3_SERRC_Clr(SPIx_Type* SPIx)
{
	SPIx->SPICR3 = SPIx_SPICR3_SERRC_Msk;
}
/********************************
HSPI�����ж�ʹ�ܺ���
����: HSPI�����ж�ʹ�ܵ�����
���룺 HSPI�����ж�ʹ������
********************************/
void SPIx_SPIIE_ERRIE_Setable(SPIx_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->SPIIE |= (SPIx_SPIIE_ERRIE_Msk);
	}
	else
	{
		SPIx->SPIIE &= ~(SPIx_SPIIE_ERRIE_Msk);
	}
}
/********************************
��ȡHSPI�����ж�ʹ�ܺ���
����: ��ȡHSPI�����ж�ʹ�ܵ�����
����� ��ȡHSPI�����ж�ʹ������
********************************/
FunState SPIx_SPIIE_ERRIE_Getable(SPIx_Type* SPIx)
{
	if (SPIx->SPIIE & (SPIx_SPIIE_ERRIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/********************************
�����ж�ʹ�ܺ���
����: �����ж�ʹ�ܵ�����
���룺 �����ж�ʹ������
********************************/
void SPIx_SPIIE_TXIE_Setable(SPIx_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->SPIIE |= (SPIx_SPIIE_TXIE_Msk);
	}
	else
	{
		SPIx->SPIIE &= ~(SPIx_SPIIE_TXIE_Msk);
	}
}
/********************************
��ȡ�����ж�ʹ�ܺ���
����: ��ȡ�����ж�ʹ�ܵ�����
����� �����ж�ʹ������
********************************/
FunState SPIx_SPIIE_TXIE_Getable(SPIx_Type* SPIx)
{
	if (SPIx->SPIIE & (SPIx_SPIIE_TXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
�����ж�ʹ�ܺ���
����: �����ж�ʹ�ܵ�����
���룺 �����ж�ʹ������
********************************/
void SPIx_SPIIE_RXIE_Setable(SPIx_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->SPIIE |= (SPIx_SPIIE_RXIE_Msk);
	}
	else
	{
		SPIx->SPIIE &= ~(SPIx_SPIIE_RXIE_Msk);
	}
}

/********************************
��ȡ�����ж�ʹ�ܺ���
����: ��ȡ�����ж�ʹ�ܵ�����
����� �����ж�ʹ������
********************************/
FunState SPIx_SPIIE_RXIE_Getable(SPIx_Type* SPIx)
{
	if (SPIx->SPIIE & (SPIx_SPIIE_RXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
Master Error��־����
����: ��ȡMaster Error��־
����� Master Error��־
********************************/
FlagStatus SPIx_SPIIF_MERR_Chk(SPIx_Type* SPIx)
{
	if (SPIx->SPIIF & SPIx_SPIIF_MERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/********************************
Slave Error��־����
����: ��ȡSlave Error��־
����� Slave Error��־
********************************/
FlagStatus SPIx_SPIIF_SERR_Chk(SPIx_Type* SPIx)
{
	if (SPIx->SPIIF & SPIx_SPIIF_SERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
������ջ��������־����
����: ������ջ��������־
���룺 ������ջ��������־
********************************/
void SPIx_SPIIF_RXCOL_Clr(SPIx_Type* SPIx)
{
	SPIx->SPIIF = SPIx_SPIIF_RXCOL_Msk;
}
/********************************
��ȡ���ջ��������־����
����: ��ȡ���ջ��������־
����� ���ջ��������־
********************************/
FlagStatus SPIx_SPIIF_RXCOL_Chk(SPIx_Type* SPIx)
{
	if (SPIx->SPIIF & SPIx_SPIIF_RXCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
������ͻ��������־����
����: ������ͻ��������־
���룺 ������ͻ��������־
********************************/
void SPIx_SPIIF_TXCOL_Clr(SPIx_Type* SPIx)
{
	SPIx->SPIIF = SPIx_SPIIF_TXCOL_Msk;
}
/********************************
��ȡ���ͻ��������־����
����: ��ȡ���ͻ��������־
����� ���ͻ��������־
********************************/
FlagStatus SPIx_SPIIF_TXCOL_Chk(SPIx_Type* SPIx)
{
	if (SPIx->SPIIF & SPIx_SPIIF_TXCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
��ȡSPI���б�־����
����: ��ȡSPI���б�־
����� SPI���б�־
********************************/
FlagStatus SPIx_SPIIF_BUSY_Chk(SPIx_Type* SPIx)
{
	if (SPIx->SPIIF & SPIx_SPIIF_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
��ȡTX Buffer Empty��־λ����
����: ��ȡTX Buffer Empty��־λ
����� TX Buffer Empty��־λ
********************************/
FlagStatus SPIx_SPIIF_TXBE_Chk(SPIx_Type* SPIx)
{
	if (SPIx->SPIIF & SPIx_SPIIF_TXBE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


/********************************
��ȡRX Buffer Full��־λ����
����: ��ȡRX Buffer Full��־λ
����� RX Buffer Full��־λ
********************************/
FlagStatus SPIx_SPIIF_RXBF_Chk(SPIx_Type* SPIx)
{
	if (SPIx->SPIIF & SPIx_SPIIF_RXBF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
SPI���ͻ��溯��
����: дSPI���ͻ���
���룺 SPI���ͻ���
********************************/
void SPIx_SPITXBUF_Write(SPIx_Type* SPIx, uint32_t SetValue)
{
	SPIx->SPITXBUF = (SetValue & SPIx_SPITXBUF_TXBUF_Msk);
}
/********************************
��ȡSPI���ͻ��溯��
����: ��ȡSPI���ͻ����ֵ
����� SPI���ͻ����ֵ
********************************/
uint32_t SPIx_SPITXBUF_Read(SPIx_Type* SPIx)
{
	return (SPIx->SPITXBUF & SPIx_SPITXBUF_TXBUF_Msk);
}

/********************************
SPI���ջ��溯��
����: дSPI���ջ���
���룺 SPI���ջ���
********************************/
void SPIx_SPIRXBUF_Write(SPIx_Type* SPIx, uint32_t SetValue)
{
	SPIx->SPIRXBUF = (SetValue & SPIx_SPIRXBUF_RXBUF_Msk);
}
/********************************
��ȡSPI���ջ��溯��
����: ��ȡSPI���ջ����ֵ
����� SPI���ջ����ֵ
********************************/
uint32_t SPIx_SPIRXBUF_Read(SPIx_Type* SPIx)
{
	return (SPIx->SPIRXBUF & SPIx_SPIRXBUF_RXBUF_Msk);
}
/********************************
SPIȱʡ���ú���
����:SPIȱʡ����
********************************/
void SPIx_Deinit(SPIx_Type* SPIx)
{
	SPIx->SPICR1 = 0x00000108;
	SPIx->SPICR2 = 0x00000054;
	SPIx->SPICR3 = 0x00000000;
	SPIx->SPIIE = 0x00000000;
	//SPIx->SPIIF = 0x00000002;
	//SPIx->SPITXBUF = 0x00000000;
	//SPIx->SPIRXBUF = 0x00000000;
}
//Code_End



/********************************
 SPI��ģʽ��ʼ������
����:  SPI��ģʽ��ʼ��
���룺 SPI��ģʽ�ĳ�ʼ������
********************************/
void SPI_Master_Init(SPIx_Type* SPIx, SPI_Master_SInitTypeDef* para)
{
	SPI_Master_InitTypeDef init_para;

	SPIx_Deinit(SPIx);

	init_para.MSPA = SPIx_SPICR1_MSPA_NORMAL;
	init_para.WAIT = SPIx_SPICR1_WAIT_WAIT_1;
	init_para.BAUD_RATE = para->BAUD_RATE;
	init_para.LSBF = para->LSBF;
	init_para.CPHOL = para->CPHOL;
	init_para.CPHA = para->CPHA;
	init_para.SSNM = para->SSNM;
	init_para.TXO = DISABLE;
	init_para.TXO_AC = SPIx_SPICR2_TXO_AC_CLR_AT_CLOSE;
	init_para.SSNSEN = para->SSNSEN;

	init_para.SPIEN = DISABLE;
	init_para.ERRIE = DISABLE;
	init_para.TXIE = DISABLE;
	init_para.RXIE = DISABLE;
	
	SPIx_SPICR1_MSPA_Set(SPIx, init_para.MSPA);
	SPIx_SPICR1_WAIT_Set(SPIx, init_para.WAIT);
	SPIx_SPICR1_BAUD_Set(SPIx, init_para.BAUD_RATE);
	SPIx_SPICR1_LSBF_Set(SPIx, init_para.LSBF);
	SPIx_SPICR1_CPHOL_Set(SPIx, init_para.CPHOL);
	SPIx_SPICR1_CPHA_Set(SPIx, init_para.CPHA);
	SPIx_SPICR2_SSNM_Set(SPIx, init_para.SSNM);
	SPIx_SPICR2_TXO_Setable(SPIx, init_para.TXO);
	SPIx_SPICR2_TXO_AC_Set(SPIx, init_para.TXO_AC);
	SPIx_SPICR2_SSNSEN_Set(SPIx, init_para.SSNSEN);

	SPIx_SPICR1_MM_Set(SPIx, SPIx_SPICR1_MM_MASTER);//���ó���ģʽ
}

/********************************
 SPI��ģʽ��ʼ������
����:  SPI��ģʽ��ʼ��
���룺 SPI��ģʽ�ĳ�ʼ������
********************************/
void SPI_Slave_Init(SPIx_Type* SPIx, SPI_Slave_SInitTypeDef* para)
{
	SPI_Slave_InitTypeDef init_para;

	SPIx_Deinit(SPIx);

	init_para.SSPA = SPIx_SPICR1_SSPA_NORMAL;
	init_para.FLTEN = ENABLE;
	init_para.LSBF = para->LSBF;
	init_para.CPHOL = para->CPHOL;
	init_para.CPHA = para->CPHA;
	init_para.TXO = DISABLE;
	init_para.TXO_AC = SPIx_SPICR2_TXO_AC_CLR_AT_CLOSE;

	init_para.SPIEN = DISABLE;
	init_para.ERRIE = DISABLE;
	init_para.TXIE = DISABLE;
	init_para.RXIE = DISABLE;
	
	SPIx_SPICR1_SSPA_Set(SPIx, init_para.SSPA);
	SPIx_SPICR2_FLTEN_Setable(SPIx, init_para.FLTEN);
	SPIx_SPICR1_LSBF_Set(SPIx, init_para.LSBF);
	SPIx_SPICR1_CPHOL_Set(SPIx, init_para.CPHOL);
	SPIx_SPICR1_CPHA_Set(SPIx, init_para.CPHA);
	SPIx_SPICR2_TXO_Setable(SPIx, init_para.TXO);
	SPIx_SPICR2_TXO_AC_Set(SPIx, init_para.TXO_AC);

	SPIx_SPICR1_MM_Set(SPIx, SPIx_SPICR1_MM_SLAVE);//���óɴ�ģʽ
}


/********************************
 SPI��SSN���õ�ƽ�͵ĺ���
********************************/
void SPI_SSN_Set_Low(SPIx_Type* SPIx)//������
{
	SPIx_SPICR2_SSN_Set(SPIx, SPIx_SPICR2_SSN_LOW);//����SSN�ź�
}
/********************************
 SPI��SSN���õ�ƽ�ߵĺ���
********************************/
void SPI_SSN_Set_High(SPIx_Type* SPIx)//������
{
	SPIx_SPICR2_SSN_Set(SPIx, SPIx_SPICR2_SSN_HIGH);//����SSN�ź�
}
/********************************
 SPI����һ���ֽڵĺ���
���ܣ�SPI����һ���ֽ�
�����SPI�����ֽ�
********************************/
unsigned char SPI_Recv_Byte(SPIx_Type* SPIx)//SPI����һ�ֽ�
{
	return SPIx_SPIRXBUF_Read(SPIx);
}
/********************************
 SPI����һ���ֽڵĺ���
���ܣ�SPI����һ���ֽ�
���룺SPIҪ���͵��ֽ�
********************************/
void SPI_Send_Byte(SPIx_Type* SPIx, unsigned char data)//SPI����һ�ֽ�
{
	SPIx_SPITXBUF_Write(SPIx, data);
}
/********************************
 SPI���Ͳ�����һ���ֽڵĺ���
���ܣ�SPI���ͺͽ���һ���ֽ�
���룺SPIҪ���͵��ֽڣ������SPI�����ֽ�
********************************/
unsigned char SPI_RW_Byte(SPIx_Type* SPIx, unsigned char data)//SPI���Ͳ�����һ�ֽ�
{
    unsigned char rx_data;

    while(1)
    {
    	if (SPIx_SPIIF_TXBE_Chk(SPIx) == SET)
		{
			break;
		}		
    }
    SPI_Send_Byte(SPIx, data);

    while(1)
    {
    	if (SPIx_SPIIF_RXBF_Chk(SPIx) == SET)
        {
            break;
        }
    }
    rx_data = SPI_Recv_Byte(SPIx);
    return rx_data;
}

//Code_End

/******END OF FILE****/

