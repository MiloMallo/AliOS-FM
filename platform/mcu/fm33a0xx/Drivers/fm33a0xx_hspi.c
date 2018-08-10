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

#include "fm33a0xx_hspi.h"  



/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

//Code_Start
//2018-04-02-13-22-40
//FM33A0XX_Driver_Gen_V1.4

/********************************
HSPI ���ƺ���
����: ����Master���ӳٲ���ʱ���Slave����ǰ����ʱ��
���룺	HSPI_SPICR1_DELAY_CFG_MASTER_NO_DELAY		Masterģʽ�����ӳ� *
	HSPI_SPICR1_DELAY_CFG_SLAVE_NORMAL		Slaveģʽ���������� 
	HSPI_SPICR1_DELAY_CFG_MASTER_DLY_L1		Masterģʽ��1���ӳ� 
	HSPI_SPICR1_DELAY_CFG_SLAVE_PHASE_1		Slaveģʽ��������λ1
	HSPI_SPICR1_DELAY_CFG_MASTER_DLY_L2		Masterģʽ��2���ӳ� 
	HSPI_SPICR1_DELAY_CFG_SLAVE_PHASE_2		Slaveģʽ��������λ2
	HSPI_SPICR1_DELAY_CFG_MASTER_DLY_L3		Masterģʽ��3���ӳ� 
	HSPI_SPICR1_DELAY_CFG_SLAVE_PHASE_3		Slaveģʽ��������λ3
	HSPI_SPICR1_DELAY_CFG_MASTER_DLY_L4		Masterģʽ��4���ӳ� 
	HSPI_SPICR1_DELAY_CFG_SLAVE_PHASE_4		Slaveģʽ��������λ4 

���:��
********************************/
void HSPI_SPICR1_DELAY_CFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_DELAY_CFG_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_DELAY_CFG_Msk);
	HSPI->SPICR1 = tmpreg;
}
/********************************
HSPI ���ƺ���
����: ��ȡMaster���ӳٲ���ʱ���Slave����ǰ����ʱ��
���룺�� 
���:	HSPI_SPICR1_DELAY_CFG_MASTER_NO_DELAY		Masterģʽ�����ӳ� *
	HSPI_SPICR1_DELAY_CFG_SLAVE_NORMAL		Slaveģʽ���������� 
	HSPI_SPICR1_DELAY_CFG_MASTER_DLY_L1		Masterģʽ��1���ӳ� 
	HSPI_SPICR1_DELAY_CFG_SLAVE_PHASE_1		Slaveģʽ��������λ1
	HSPI_SPICR1_DELAY_CFG_MASTER_DLY_L2		Masterģʽ��2���ӳ� 
	HSPI_SPICR1_DELAY_CFG_SLAVE_PHASE_2		Slaveģʽ��������λ2
	HSPI_SPICR1_DELAY_CFG_MASTER_DLY_L3		Masterģʽ��3���ӳ� 
	HSPI_SPICR1_DELAY_CFG_SLAVE_PHASE_3		Slaveģʽ��������λ3
	HSPI_SPICR1_DELAY_CFG_MASTER_DLY_L4		Masterģʽ��4���ӳ� 
	HSPI_SPICR1_DELAY_CFG_SLAVE_PHASE_4		Slaveģʽ��������λ4
********************************/
uint32_t HSPI_SPICR1_DELAY_CFG_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_DELAY_CFG_Msk);
}


/********************************
HSPI ���ƺ���
����: ���ù���ģʽ
���룺	HSPI_SPICR1_MM_SLAVE		SLAVE
	HSPI_SPICR1_MM_MASTER		MASTER

���:��
********************************/
void HSPI_SPICR1_MM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_MM_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_MM_Msk);
	HSPI->SPICR1 = tmpreg;
}

/********************************
HSPI ���ƺ���
����: ��ȡ����ģʽ
���룺�� 
���:	HSPI_SPICR1_MM_SLAVE		SLAVE
	HSPI_SPICR1_MM_MASTER		MASTER
********************************/
uint32_t HSPI_SPICR1_MM_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_MM_Msk);
}
/********************************
HSPI ���ƺ���
����: ���÷�����ÿ��byte֮��ĵȴ�ʱ��
���룺	HSPI_SPICR1_WAIT_WAIT_1		ÿ����8bit���ټ���1��sck���ڵȴ�ʱ���ٴ�����һ��8Bit����		
	HSPI_SPICR1_WAIT_WAIT_2		ÿ����8bit���ټ���2��sck���ڵȴ�ʱ���ٴ�����һ��8Bit����
	HSPI_SPICR1_WAIT_WAIT_3		ÿ����8bit���ټ���3��sck���ڵȴ�ʱ���ٴ�����һ��8Bit����
	HSPI_SPICR1_WAIT_WAIT_4		ÿ����8bit���ټ���4��sck���ڵȴ�ʱ���ٴ�����һ��8Bit����
���:��
********************************/
void HSPI_SPICR1_WAIT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_WAIT_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_WAIT_Msk);
	HSPI->SPICR1 = tmpreg;
}
/********************************
HSPI ���ƺ���
����: ��ȡ������ÿ��byte֮��ĵȴ�ʱ��
���룺�� 
���:	HSPI_SPICR1_WAIT_WAIT_1		ÿ����8bit���ټ���1��sck���ڵȴ�ʱ���ٴ�����һ��8Bit����		
			HSPI_SPICR1_WAIT_WAIT_2		ÿ����8bit���ټ���2��sck���ڵȴ�ʱ���ٴ�����һ��8Bit����
			HSPI_SPICR1_WAIT_WAIT_3		ÿ����8bit���ټ���3��sck���ڵȴ�ʱ���ٴ�����һ��8Bit����
			HSPI_SPICR1_WAIT_WAIT_4		ÿ����8bit���ټ���4��sck���ڵȴ�ʱ���ٴ�����һ��8Bit����
********************************/
uint32_t HSPI_SPICR1_WAIT_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_WAIT_Msk);
}

/********************************
HSPI ���ƺ���
����: ����MASTERģʽ�µĲ�����
���룺HSPI_SPICR1_BAUD_PCLK					����ʱ�Ӳ���Ƶ
			HSPI_SPICR1_BAUD_PCLK_2				����ʱ��2��Ƶ
			HSPI_SPICR1_BAUD_PCLK_4				����ʱ��4��Ƶ
			HSPI_SPICR1_BAUD_PCLK_8				����ʱ��8��Ƶ
			HSPI_SPICR1_BAUD_PCLK_16			����ʱ��16��Ƶ
			HSPI_SPICR1_BAUD_PCLK_32			����ʱ��32��Ƶ
			HSPI_SPICR1_BAUD_PCLK_64			����ʱ��64��Ƶ
			HSPI_SPICR1_BAUD_PCLK_128			����ʱ��128��Ƶ
���:��
********************************/
void HSPI_SPICR1_BAUD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_BAUD_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_BAUD_Msk);
	HSPI->SPICR1 = tmpreg;
}
/********************************
HSPI ���ƺ���
����: ��ȡMASTERģʽ�µĲ�����
���룺�� 
���:	HSPI_SPICR1_BAUD_PCLK					����ʱ�Ӳ���Ƶ
			HSPI_SPICR1_BAUD_PCLK_2				����ʱ��2��Ƶ
			HSPI_SPICR1_BAUD_PCLK_4				����ʱ��4��Ƶ
			HSPI_SPICR1_BAUD_PCLK_8				����ʱ��8��Ƶ
			HSPI_SPICR1_BAUD_PCLK_16			����ʱ��16��Ƶ
			HSPI_SPICR1_BAUD_PCLK_32			����ʱ��32��Ƶ
			HSPI_SPICR1_BAUD_PCLK_64			����ʱ��64��Ƶ
			HSPI_SPICR1_BAUD_PCLK_128			����ʱ��128��Ƶ
********************************/
uint32_t HSPI_SPICR1_BAUD_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_BAUD_Msk);
}

/********************************
HSPI ���ƺ���
����: ����֡��ʽ
���룺HSPI_SPICR1_LSBF_MSB		�ȷ���MSB
			HSPI_SPICR1_LSBF_LSB		�ȷ���LSB
���:��
********************************/
void HSPI_SPICR1_LSBF_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_LSBF_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_LSBF_Msk);
	HSPI->SPICR1 = tmpreg;
}
/********************************
HSPI ���ƺ���
����: ��ȡ֡��ʽ
���룺�� 
���:	HSPI_SPICR1_LSBF_MSB		�ȷ���MSB
			HSPI_SPICR1_LSBF_LSB		�ȷ���LSB
********************************/
uint32_t HSPI_SPICR1_LSBF_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_LSBF_Msk);
}

/********************************
HSPI ���ƺ���
����: ����ʱ�Ӽ���
���룺HSPI_SPICR1_CPHOL_LOW		����ʱ��ֹͣ�ڵ͵�ƽ
			HSPI_SPICR1_CPHOL_HIGH	����ʱ��ֹͣ�ڸߵ�ƽ
���:��
********************************/
void HSPI_SPICR1_CPHOL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_CPHOL_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_CPHOL_Msk);
	HSPI->SPICR1 = tmpreg;
}
/********************************
HSPI ���ƺ���
����: ��ȡʱ�Ӽ���
���룺�� 
���:	HSPI_SPICR1_CPHOL_LOW		����ʱ��ֹͣ�ڵ͵�ƽ
			HSPI_SPICR1_CPHOL_HIGH	����ʱ��ֹͣ�ڸߵ�ƽ
********************************/
uint32_t HSPI_SPICR1_CPHOL_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_CPHOL_Msk);
}

/********************************
HSPI ���ƺ���
����: ����ʱ����λ
���룺HSPI_SPICR1_CPHA_FIRST			��һ��ʱ�ӱ����ǵ�һ����׽����
	    HSPI_SPICR1_CPHA_SECOND			�ڶ���ʱ�ӱ����ǵ�һ����׽����
���:��
********************************/
void HSPI_SPICR1_CPHA_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_CPHA_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_CPHA_Msk);
	HSPI->SPICR1 = tmpreg;
}
/********************************
HSPI ���ƺ���
����: ��ȡʱ����λ
���룺�� 
���:	HSPI_SPICR1_CPHA_FIRST			��һ��ʱ�ӱ����ǵ�һ����׽����
	    HSPI_SPICR1_CPHA_SECOND			�ڶ���ʱ�ӱ����ǵ�һ����׽����
********************************/
uint32_t HSPI_SPICR1_CPHA_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_CPHA_Msk);
}

/********************************
HSPI ���ƺ���
����: ����SLAVE������ܽ��˲�ʹ��
���룺ENABLE/DISABLE		����ܽ����˲�/����ܽ����˲�
���:��
********************************/
void HSPI_SPICR2_FLTEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		HSPI->SPICR2 |= (HSPI_SPICR2_FLTEN_Msk);
	}
	else
	{
		HSPI->SPICR2 &= ~(HSPI_SPICR2_FLTEN_Msk);
	}
}
/********************************
HSPI ���ƺ���
����: ��ȡSLAVE������ܽ��˲��Ƿ�ʹ��
���룺��
���: ENABLE/DISABLE		����ܽ����˲�/����ܽ����˲�
********************************/
FunState HSPI_SPICR2_FLTEN_Getable(void)
{
	if (HSPI->SPICR2 & (HSPI_SPICR2_FLTEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
HSPI ���ƺ���
����: ����MASTERģʽ��SSN�Ŀ���ģʽ
���룺HSPI_SPICR2_SSNM_LOW			ÿ������8bit��Master����SSNΪ��
      HSPI_SPICR2_SSNM_HIGH			ÿ������8bit��Master����SSN��ά�ָߵ�ƽʱ����WAIT�Ĵ�������
���:��
********************************/
void HSPI_SPICR2_SSNM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR2;
	tmpreg &= ~(HSPI_SPICR2_SSNM_Msk);
	tmpreg |= (SetValue & HSPI_SPICR2_SSNM_Msk);
	HSPI->SPICR2 = tmpreg;
}

/********************************
HSPI ���ƺ���
����: ��ȡMASTERģʽ��SSN�Ŀ���ģʽ
���룺��
���: HSPI_SPICR2_SSNM_LOW			ÿ������8bit��Master����SSNΪ��
      HSPI_SPICR2_SSNM_HIGH			ÿ������8bit��Master����SSN��ά�ָߵ�ƽʱ����WAIT�Ĵ�������
********************************/
uint32_t HSPI_SPICR2_SSNM_Get(void)
{
	return (HSPI->SPICR2 & HSPI_SPICR2_SSNM_Msk);
}

/********************************
HSPI ���ƺ���
����: ����TXONLYӲ���Զ���յ�ʹ��
���룺HSPI_SPICR2_TXO_AC_CLR_AT_CLOSE			�ر�TXONLYӲ���Զ�����
	    HSPI_SPICR2_TXO_AC_CLR_AT_TX				TXONLYӲ���Զ�������Ч�����ʹ��TXO�󣬵ȴ�������Ϻ�Ӳ������
���:��
********************************/
void HSPI_SPICR2_TXO_AC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR2;
	tmpreg &= ~(HSPI_SPICR2_TXO_AC_Msk);
	tmpreg |= (SetValue & HSPI_SPICR2_TXO_AC_Msk);
	HSPI->SPICR2 = tmpreg;
}
/********************************
HSPI ���ƺ���
����: ��ȡTXONLYӲ���Զ���յ�ʹ������
���룺��
���: HSPI_SPICR2_TXO_AC_CLR_AT_CLOSE			�ر�TXONLYӲ���Զ�����
	    HSPI_SPICR2_TXO_AC_CLR_AT_TX				TXONLYӲ���Զ�������Ч�����ʹ��TXO�󣬵ȴ�������Ϻ�Ӳ������
********************************/
uint32_t HSPI_SPICR2_TXO_AC_Get(void)
{
	return (HSPI->SPICR2 & HSPI_SPICR2_TXO_AC_Msk);
}

/********************************
HSPI ���ƺ���
����: ����TXONLYʹ��(MASTER�µ���ģʽ����)
���룺ENABLE/DISABLE		��Master�ĵ�����ģʽ/�رյ�����ģʽ
���:��
********************************/
void HSPI_SPICR2_TXO_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		HSPI->SPICR2 |= (HSPI_SPICR2_TXO_Msk);
	}
	else
	{
		HSPI->SPICR2 &= ~(HSPI_SPICR2_TXO_Msk);
	}
}
/********************************
HSPI ���ƺ���
����: ��ȡTXONLYʹ��״̬(MASTER�µ���ģʽ����)
���룺��
���: ENABLE/DISABLE		��Master�ĵ�����ģʽ/�رյ�����ģʽ
********************************/
FunState HSPI_SPICR2_TXO_Getable(void)
{
	if (HSPI->SPICR2 & (HSPI_SPICR2_TXO_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
HSPI ���ƺ���
����: ����MASTER��SSN�������ƽ
���룺HSPI_SPICR2_SSN_LOW 	SSN����͵�ƽ
	    HSPI_SPICR2_SSN_HIGH	SSN����ߵ�ƽ
���:��
********************************/
void HSPI_SPICR2_SSN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR2;
	tmpreg &= ~(HSPI_SPICR2_SSN_Msk);
	tmpreg |= (SetValue & HSPI_SPICR2_SSN_Msk);
	HSPI->SPICR2 = tmpreg;
}
/********************************
HSPI ���ƺ���
����: ��ȡMASTER��SSN�������ƽ����
���룺��
���: HSPI_SPICR2_SSN_LOW 	SSN����͵�ƽ
	    HSPI_SPICR2_SSN_HIGH	SSN����ߵ�ƽ
********************************/
uint32_t HSPI_SPICR2_SSN_Get(void)
{
	return (HSPI->SPICR2 & HSPI_SPICR2_SSN_Msk);
}

/********************************
HSPI ���ƺ���
����: ����MASTER��SSN�Ŀ��Ʒ�ʽ
���룺HSPI_SPICR2_SSNSEN_HARD		Masterģʽ��SSN�����Ӳ���Զ�����
	    HSPI_SPICR2_SSNSEN_SOFT		Masterģʽ��SSN������������
���:��
********************************/
void HSPI_SPICR2_SSNSEN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR2;
	tmpreg &= ~(HSPI_SPICR2_SSNSEN_Msk);
	tmpreg |= (SetValue & HSPI_SPICR2_SSNSEN_Msk);
	HSPI->SPICR2 = tmpreg;
}
/********************************
HSPI ���ƺ���
����: ��ȡMASTER��SSN�Ŀ��Ʒ�ʽ����
���룺��
���: HSPI_SPICR2_SSNSEN_HARD		Masterģʽ��SSN�����Ӳ���Զ�����
	    HSPI_SPICR2_SSNSEN_SOFT		Masterģʽ��SSN������������
********************************/
uint32_t HSPI_SPICR2_SSNSEN_Get(void)
{
	return (HSPI->SPICR2 & HSPI_SPICR2_SSNSEN_Msk);
}

/********************************
HSPI ���ƺ���
����: HSPIʹ�ܿ���
���룺ENABLE/DISABLE	HSPIʹ��/HSPI��ֹ
���:��
********************************/
void HSPI_SPICR2_HSPIEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		HSPI->SPICR2 |= (HSPI_SPICR2_HSPIEN_Msk);
	}
	else
	{
		HSPI->SPICR2 &= ~(HSPI_SPICR2_HSPIEN_Msk);
	}
}
/********************************
HSPI ���ƺ���
����: ��ȡHSPIʹ�ܿ���״̬
���룺��
���: ENABLE/DISABLE	HSPIʹ��/HSPI��ֹ
********************************/
FunState HSPI_SPICR2_HSPIEN_Getable(void)
{
	if (HSPI->SPICR2 & (HSPI_SPICR2_HSPIEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/********************************
HSPI ���ƺ���
����: ������ͻ���
���룺��
���: ��
********************************/
void HSPI_SPICR3_TXBFC_Clr(void)
{
	HSPI->SPICR3 = HSPI_SPICR3_TXBFC_Msk;
}
/********************************
HSPI ���ƺ���
����: ������ջ���
���룺��
���: ��
********************************/
void HSPI_SPICR3_RXBFC_Clr(void)
{
	HSPI->SPICR3 = HSPI_SPICR3_RXBFC_Msk;
}
/********************************
HSPI ���ƺ���
����: ���MASTER ERR��־(HSPISTA.MERR)
���룺��
���: ��
********************************/
void HSPI_SPICR3_MERRC_Clr(void)
{
	HSPI->SPICR3 = HSPI_SPICR3_MERRC_Msk;
}
/********************************
HSPI ���ƺ���
����: ���SLAVE ERR��־(HSPISTA.SERR)
���룺HSPI_SPICR3_SERRC_Msk
���:��
********************************/
void HSPI_SPICR3_SERRC_Clr(void)
{
	HSPI->SPICR3 = HSPI_SPICR3_SERRC_Msk;
}
/********************************
HSPI ���ƺ���
����: ����HSPI�����ж�ʹ��
���룺ENABLE/DISABLE			�����ж�ʹ��/�����жϽ�ֹ
���:��
********************************/
void HSPI_SPIIE_ERRIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		HSPI->SPIIE |= (HSPI_SPIIE_ERRIE_Msk);
	}
	else
	{
		HSPI->SPIIE &= ~(HSPI_SPIIE_ERRIE_Msk);
	}
}
/********************************
HSPI ���ƺ���
����: ��ȡHSPI�����ж�ʹ��״̬
���룺��
���: ENABLE/DISABLE			�����ж�ʹ��/�����жϽ�ֹ
********************************/
FunState HSPI_SPIIE_ERRIE_Getable(void)
{
	if (HSPI->SPIIE & (HSPI_SPIIE_ERRIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/********************************
HSPI ���ƺ���
����: ����HSPI�����ж�ʹ��
���룺ENABLE/DISABLE			�����ж�ʹ��/�����жϽ�ֹ
���:��
********************************/
void HSPI_SPIIE_TXIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		HSPI->SPIIE |= (HSPI_SPIIE_TXIE_Msk);
	}
	else
	{
		HSPI->SPIIE &= ~(HSPI_SPIIE_TXIE_Msk);
	}
}
/********************************
HSPI ���ƺ���
����: ��ȡHSPI�����ж�ʹ��״̬
���룺��
���: ENABLE/DISABLE			�����ж�ʹ��/�����жϽ�ֹ
********************************/
FunState HSPI_SPIIE_TXIE_Getable(void)
{
	if (HSPI->SPIIE & (HSPI_SPIIE_TXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/********************************
HSPI ���ƺ���
����: ����HSPI�����ж�ʹ��
���룺ENABLE/DISABLE			�����ж�ʹ��/�����жϽ�ֹ
���:��
********************************/
void HSPI_SPIIE_RXIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		HSPI->SPIIE |= (HSPI_SPIIE_RXIE_Msk);
	}
	else
	{
		HSPI->SPIIE &= ~(HSPI_SPIIE_RXIE_Msk);
	}
}
/********************************
HSPI ���ƺ���
����: ��ȡHSPI�����ж�ʹ��״̬
���룺��
���: ENABLE/DISABLE			�����ж�ʹ��/�����жϽ�ֹ
********************************/
FunState HSPI_SPIIE_RXIE_Getable(void)
{
	if (HSPI->SPIIE & (HSPI_SPIIE_RXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
HSPI ���ƺ���
����: ��ȡHSPI MASTER�����жϱ�־
���룺��
���: SET/RESET					HSPI����MASTER�жϷ���/HSPI MASTER�����ж�δ����
********************************/
FlagStatus HSPI_SPIIF_MERR_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_MERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
HSPI ���ƺ���
����: ��ȡHSPI SLAVE�����жϱ�־
���룺��
���: SET/RESET					HSPI SLAVE�����жϷ���/HSPI SLAVE�����ж�δ����
********************************/
FlagStatus HSPI_SPIIF_SERR_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_SERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/********************************
HSPI ���ƺ���
����: ����ջ������
���룺��
���: ��
********************************/
void HSPI_SPIIF_RXCOL_Clr(void)
{
	HSPI->SPIIF = HSPI_SPIIF_RXCOL_Msk;
}
/********************************
HSPI ���ƺ���
����: ��ȡ���ջ��������־
���룺��
���: SET/RESET			�������ջ������/δ�������ջ������
********************************/
FlagStatus HSPI_SPIIF_RXCOL_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_RXCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
HSPI ���ƺ���
����: �巢�ͻ������
���룺��
���: ��
********************************/
void HSPI_SPIIF_TXCOL_Clr(void)
{
	HSPI->SPIIF = HSPI_SPIIF_TXCOL_Msk;
}
/********************************
HSPI ���ƺ���
����: ��ȡ���ͻ��������־
���룺��
���: SET/RESET	�������ͻ������/δ�������ͻ������
********************************/
FlagStatus HSPI_SPIIF_TXCOL_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_TXCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
HSPI ���ƺ���
����: ��ȡHSPI���б�־
���룺��
���: SET/RESET	HSPI������/HSPI����
********************************/
FlagStatus HSPI_SPIIF_BUSY_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
HSPI ���ƺ���
����: ��ȡ���ͻ���TX buffer�ձ�־
���룺��
���: SET/RESET	TX buffer ��/TX buffer ��
********************************/
FlagStatus HSPI_SPIIF_TXBE_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_TXBE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
HSPI ���ƺ���
����: ��ȡ���ջ���RX buffer����־
���룺��
���: SET/RESET	RX buffer ��/RX buffer ��
********************************/
FlagStatus HSPI_SPIIF_RXBF_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_RXBF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
HSPI ���ƺ���
����: д���ͻ���
���룺0x00000000-0x000000ff(��Ҫ���͵�data)
���: ��
********************************/
void HSPI_SPITXBUF_Write(uint32_t SetValue)
{
	HSPI->SPITXBUF = (SetValue & HSPI_SPITXBUF_TXBUF_Msk);
}
/********************************
HSPI ���ƺ���
����: �����ͻ���
���룺��
���: 0x00000000-0x000000ff(��Ҫ���͵�data)
********************************/
uint32_t HSPI_SPITXBUF_Read(void)
{
	return (HSPI->SPITXBUF & HSPI_SPITXBUF_TXBUF_Msk);
}

/********************************
HSPI ���ƺ���
����: д���ջ���
���룺0x00000000-0x000000ff
���: ��
********************************/
void HSPI_SPIRXBUF_Write(uint32_t SetValue)
{
	HSPI->SPIRXBUF = (SetValue & HSPI_SPIRXBUF_RXBUF_Msk);
}
/********************************
HSPI ���ƺ���
����: �����ջ���
���룺��
���: 0x00000000-0x000000ff(���յ���data)
********************************/
uint32_t HSPI_SPIRXBUF_Read(void)
{
	return (HSPI->SPIRXBUF & HSPI_SPIRXBUF_RXBUF_Msk);
}

/********************************
HSPI ���ƺ���
����: HSPIȱʡ����
���룺��
���: ��
********************************/
void HSPI_Deinit(void)
{
	HSPI->SPICR1 = 0x00000108;
	HSPI->SPICR2 = 0x00000054;
	HSPI->SPICR3 = 0x00000000;
	HSPI->SPIIE = 0x00000000;
	//HSPI->SPIIF = 0x00000002;
	//HSPI->SPITXBUF = 0x00000000;
	//HSPI->SPIRXBUF = 0x00000000;
}
//Code_End

/********************************
HSPI ���ƺ���
����: HSPI MASTER��ʼ��
���룺
���: ��
********************************/
void HSPI_Master_Init(HSPI_Master_SInitTypeDef* para)
{
	HSPI_Master_InitTypeDef init_para;
	HSPI_Deinit();

	init_para.DELAY_CFG = HSPI_SPICR1_DELAY_CFG_MASTER_NO_DELAY;
	init_para.WAIT = HSPI_SPICR1_WAIT_WAIT_1;
	init_para.BAUD_RATE = para->BAUD_RATE;
	init_para.LSBF = para->LSBF;
	init_para.CPHOL = para->CPHOL;
	init_para.CPHA = para->CPHA;
	init_para.SSNM = para->SSNM;
	init_para.TXO = DISABLE;
	init_para.TXO_AC = HSPI_SPICR2_TXO_AC_CLR_AT_CLOSE;
	init_para.SSNSEN = para->SSNSEN;

	init_para.HSPIEN = DISABLE;
	init_para.ERRIE = DISABLE;
	init_para.TXIE = DISABLE;
	init_para.RXIE = DISABLE;

	HSPI_SPICR1_DELAY_CFG_Set(init_para.DELAY_CFG);
	HSPI_SPICR1_WAIT_Set(init_para.WAIT);
	HSPI_SPICR1_BAUD_Set(init_para.BAUD_RATE);
	HSPI_SPICR1_LSBF_Set(init_para.LSBF);
	HSPI_SPICR1_CPHOL_Set(init_para.CPHOL);
	HSPI_SPICR1_CPHA_Set(init_para.CPHA);
	HSPI_SPICR2_SSNM_Set(init_para.SSNM);
	HSPI_SPICR2_TXO_Setable(init_para.TXO);
	HSPI_SPICR2_TXO_AC_Set(init_para.TXO_AC);
	HSPI_SPICR2_SSNSEN_Set(init_para.SSNSEN);

	HSPI_SPICR1_MM_Set(HSPI_SPICR1_MM_MASTER);//���ó���ģʽ
}

/********************************
HSPI ���ƺ���
����: HSPI SLAVER ��ʼ��
���룺
���: ��
********************************/
void HSPI_Slave_Init(HSPI_Slave_SInitTypeDef* para)
{
	HSPI_Slave_InitTypeDef init_para;
	HSPI_Deinit();

	init_para.DELAY_CFG = HSPI_SPICR1_DELAY_CFG_SLAVE_NORMAL;
	init_para.FLTEN = ENABLE;
	init_para.LSBF = para->LSBF;
	init_para.CPHOL = para->CPHOL;
	init_para.CPHA = para->CPHA;
	init_para.TXO = DISABLE;
	init_para.TXO_AC = HSPI_SPICR2_TXO_AC_CLR_AT_CLOSE;

	init_para.HSPIEN = DISABLE;
	init_para.ERRIE = DISABLE;
	init_para.TXIE = DISABLE;
	init_para.RXIE = DISABLE;

	HSPI_SPICR1_DELAY_CFG_Set(init_para.DELAY_CFG);
	HSPI_SPICR2_FLTEN_Setable(init_para.FLTEN);
	HSPI_SPICR1_LSBF_Set(init_para.LSBF);
	HSPI_SPICR1_CPHOL_Set(init_para.CPHOL);
	HSPI_SPICR1_CPHA_Set(init_para.CPHA);
	HSPI_SPICR2_TXO_Setable(init_para.TXO);
	HSPI_SPICR2_TXO_AC_Set(init_para.TXO_AC);
	
	HSPI_SPICR1_MM_Set(HSPI_SPICR1_MM_SLAVE);//���óɴ�ģʽ
}

void HSPI_SSN_Set_Low(void)//������
{
	HSPI_SPICR2_SSN_Set(HSPI_SPICR2_SSN_LOW);//����SSN�ź�
}

void HSPI_SSN_Set_High(void)//������
{
	HSPI_SPICR2_SSN_Set(HSPI_SPICR2_SSN_HIGH);//����SSN�ź�
}

unsigned char HSPI_Recv_Byte(void)//HSPI����һ�ֽ�
{
	return HSPI_SPIRXBUF_Read();
}
void HSPI_Send_Byte(unsigned char data)//HSPI����һ�ֽ�
{
	HSPI_SPITXBUF_Write(data);
}

unsigned char HSPI_RW_Byte(unsigned char data)//SPI���Ͳ�����һ�ֽ�
{
    unsigned char rx_data;

    while(1)
    {
    	if (HSPI_SPIIF_TXBE_Chk() == SET)
		{
			break;
		}		
    }
    HSPI_Send_Byte(data);

    while(1)
    {
    	if (HSPI_SPIIF_RXBF_Chk() == SET)
        {
            break;
        }
    }
    rx_data = HSPI_Recv_Byte();
    return rx_data;
}



/******END OF FILE****/

