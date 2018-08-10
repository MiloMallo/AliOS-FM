/**
  ******************************************************************************
  * @file    fm33a0xx_crc.c
  * @author  FM33a0xx Application Team
  * @version V2.0.2
  * @date    8-1-2018
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33a0xx_crc.h" 


/** @addtogroup fm33a0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup CRC
  * @brief CRC driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

//Code_Start
//2018-04-02-13-20-31
//FM33A0XX_Driver_Gen_V1.4

/********************************
CRC ���ܿ��ƺ���
����: ���CRC��������(����16λ��Ч)
���룺CRC����
���: ��
********************************/
void CRC_CRCDR_Write(uint32_t SetValue)
{
	CRC->CRCDR = (SetValue & CRC_CRCDR_CRCDR_Msk);
}
/********************************
CRC ���ܿ��ƺ���
����: ��ȡCRC��������(����16λ��Ч)
���룺��
���: CRC����
********************************/
uint32_t CRC_CRCDR_Read(void)
{
	return (CRC->CRCDR & CRC_CRCDR_CRCDR_Msk);
}

/********************************
CRC ���ܿ��ƺ���
����: ����CRC���뷴ת
���룺ENABLE/DISABLE			���밴�ֽڷ�ת/���벻��ת
���: ��
********************************/
void CRC_CRCCR_RFLTIN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->CRCCR |= (CRC_CRCCR_RFLTIN_Msk);
	}
	else
	{
		CRC->CRCCR &= ~(CRC_CRCCR_RFLTIN_Msk);
	}
}
/********************************
CRC ���ܿ��ƺ���
����: ��ȡCRC���뷴ת����
���룺��
���: ENABLE/DISABLE			���밴�ֽڷ�ת/���벻��ת
********************************/
FunState CRC_CRCCR_RFLTIN_Getable(void)
{
	if (CRC->CRCCR & (CRC_CRCCR_RFLTIN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
CRC ���ܿ��ƺ���
����: ����CRC�����ת
���룺ENABLE/DISABLE			������ֽڷ�ת/�������ת
���: ��
********************************/
void CRC_CRCCR_RFLTO_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->CRCCR |= (CRC_CRCCR_RFLTO_Msk);
	}
	else
	{
		CRC->CRCCR &= ~(CRC_CRCCR_RFLTO_Msk);
	}
}
/********************************
CRC ���ܿ��ƺ���
����: ��ȡCRC�����ת����
���룺��
���: ENABLE/DISABLE			������ֽڷ�ת/�������ת
********************************/
FunState CRC_CRCCR_RFLTO_Getable(void)
{
	if (CRC->CRCCR & (CRC_CRCCR_RFLTO_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/********************************
CRC ���ܿ��ƺ���
����: ��ȡCRC�����־λ
���룺��
���:	SET/RESET		CRC�����ȫ0/CRC���ȫ0
********************************/
FlagStatus CRC_CRCCR_RES_Chk(void)
{
	if (CRC->CRCCR & CRC_CRCCR_RES_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
CRC ���ܿ��ƺ���
����: ��ȡCRC�����־λ
���룺��
���:	SET/RESET		CRC���������/CRC�������
********************************/
FlagStatus CRC_CRCCR_BUSY_Chk(void)
{
	if (CRC->CRCCR & CRC_CRCCR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
CRC ���ܿ��ƺ���
����: ����CRC������ʹ��
���룺ENABLE/DISABLE			������CRC_XOR/��������CRC_XOR
���: ��
********************************/
void CRC_CRCCR_XOR_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->CRCCR |= (CRC_CRCCR_XOR_Msk);
	}
	else
	{
		CRC->CRCCR &= ~(CRC_CRCCR_XOR_Msk);
	}
}
/********************************
CRC ���ܿ��ƺ���
����: ��ȡCRC����������
���룺��
���: ENABLE/DISABLE			������CRC_XOR/��������CRC_XOR
********************************/
FunState CRC_CRCCR_XOR_Getable(void)
{
	if (CRC->CRCCR & (CRC_CRCCR_XOR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
CRC ���ܿ��ƺ���
����: ����CRCУ�����ʽѡ��
���룺CRC_CRCCR_CRCSEL_CRC16			00��CRC16
			CRC_CRCCR_CRCSEL_CRC8				01��CRC8
			CRC_CRCCR_CRCSEL_CCITT			10/11��CCITT
���: ��
********************************/
void CRC_CRCCR_CRCSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CRC->CRCCR;
	tmpreg &= ~(CRC_CRCCR_CRCSEL_Msk);
	tmpreg |= (SetValue & CRC_CRCCR_CRCSEL_Msk);
	CRC->CRCCR = tmpreg;
}
/********************************
CRC ���ܿ��ƺ���
����: ��ȡCRCУ�����ʽѡ��
���룺��
���: CRC_CRCCR_CRCSEL_CRC16			00��CRC16
			CRC_CRCCR_CRCSEL_CRC8				01��CRC8
			CRC_CRCCR_CRCSEL_CCITT			10/11��CCITT
********************************/
uint32_t CRC_CRCCR_CRCSEL_Get(void)
{
	return (CRC->CRCCR & CRC_CRCCR_CRCSEL_Msk);
}

/********************************
CRC ���ܿ��ƺ���
����: ����CRC�����ֵ(����ǰ������)
���룺0x00000000-0x0000ffff
���: ��
********************************/
void CRC_CRCLFSR_Write(uint32_t SetValue)
{
	CRC->CRCLFSR = (SetValue & CRC_CRCLFSR_LFSR_Msk);
}
/********************************
CRC ���ܿ��ƺ���
����: ��ȡCRC�����ֵ
���룺��
���: CRC�����ֵ
********************************/
uint32_t CRC_CRCLFSR_Read(void)
{
	return (CRC->CRCLFSR & CRC_CRCLFSR_LFSR_Msk);
}

/********************************
CRC ���ܿ��ƺ���
����: ����CRC������ֵ
���룺0x00000000-0x0000ffff
���: ��
********************************/
void CRC_CRCXOR_Write(uint32_t SetValue)
{
	CRC->CRCXOR = (SetValue & CRC_CRCXOR_CRC_XOR_Msk);
}
/********************************
CRC ���ܿ��ƺ���
����: ��ȡCRC������ֵ
���룺��
���: 0x00000000-0x0000ffff
********************************/
uint32_t CRC_CRCXOR_Read(void)
{
	return (CRC->CRCXOR & CRC_CRCXOR_CRC_XOR_Msk);
}

/********************************
CRC ���ܿ��ƺ���
����: ����CRCУ��ʹ��
���룺ENABLE/DISABLE		��Flash CRCУ��/��ʹ��Flash CRCУ��
���: ��
********************************/
void CRC_CRCFLSEN_FLSCRCEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->CRCFLSEN |= (CRC_CRCFLSEN_FLSCRCEN_Msk);
	}
	else
	{
		CRC->CRCFLSEN &= ~(CRC_CRCFLSEN_FLSCRCEN_Msk);
	}
}
/********************************
CRC ���ܿ��ƺ���
����: ��ȡCRCУ��ʹ������
���룺��
���: ENABLE/DISABLE		��Flash CRCУ��/��ʹ��Flash CRCУ��
********************************/
FunState CRC_CRCFLSEN_FLSCRCEN_Getable(void)
{
	if (CRC->CRCFLSEN & (CRC_CRCFLSEN_FLSCRCEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
CRC ���ܿ��ƺ���
����: ����FLASH CRCУ����ʼ��ַ
���룺17λFlash��ַ(word��ַ)
���: ��
********************************/
void CRC_CRCFLSAD_Write(uint32_t SetValue)
{
	CRC->CRCFLSAD = (SetValue & CRC_CRCFLSAD_FLSAD_Msk);
}
/********************************
CRC ���ܿ��ƺ���
����: ��ȡFLASH CRCУ����ʼ��ַ
���룺��
���: 17λFlash��ַ(word��ַ)
********************************/
uint32_t CRC_CRCFLSAD_Read(void)
{
	return (CRC->CRCFLSAD & CRC_CRCFLSAD_FLSAD_Msk);
}

/********************************
CRC ���ܿ��ƺ���
����: ����FLASH CRCУ�鳤��
���룺17λ���ݳ���(word��ַ,ʵ�����㳤��Ϊ(FLSS+1)*4�ֽ�)
���: ��
********************************/
void CRC_CRCFLSSIZE_Write(uint32_t SetValue)
{
	CRC->CRCFLSSIZE = (SetValue & CRC_CRCFLSSIZE_FLSS_Msk);
}
/********************************
CRC ���ܿ��ƺ���
����: ��ȡFLASH CRCУ�鳤��
���룺��
���: 17λ���ݳ���(word��ַ,ʵ�����㳤��Ϊ(FLSS+1)*4�ֽ�)
********************************/
uint32_t CRC_CRCFLSSIZE_Read(void)
{
	return (CRC->CRCFLSSIZE & CRC_CRCFLSSIZE_FLSS_Msk);
}

/********************************
CRC ���ܿ��ƺ���
����: CRC ȱʡ����
���룺��
���: ��
********************************/
void CRC_Deinit(void)
{
	//CRC->CRCDR = ;
	CRC->CRCCR = 0x00000000;
	CRC->CRCLFSR = 0x0000FFFF;
	CRC->CRCXOR = 0x00000000;
	CRC->CRCFLSEN = 0x00000000;
	CRC->CRCFLSAD = 0x00000000;
	CRC->CRCFLSSIZE = 0x00000000;
}
//Code_End

/* CRC��ʼ�����ú���*/
void CRC_Init(CRC_InitTypeDef* para)
{
	CRC_CRCCR_CRCSEL_Set(para->CRCSEL);			/*!<CRCУ�����ʽѡ��*/
	CRC_CRCCR_RFLTIN_Setable(para->RFLTIN);		/*!<CRC���뷴ת����*/
	CRC_CRCCR_RFLTO_Setable(para->RFLTO);		/*!<CRC�����ת����*/
	CRC_CRCCR_XOR_Setable(para->XOR);			/*!<������ʹ��*/
	CRC_CRCXOR_Write(para->CRC_XOR);			/*!<���������Ĵ���*/
}

/******END OF FILE****/



