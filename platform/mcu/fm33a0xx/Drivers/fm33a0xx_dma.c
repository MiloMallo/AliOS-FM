/**
  ******************************************************************************
  * @file    fm33a0xx_dma.c
  * @author  FM385 Application Team
  * @version V2.0.2
  * @date    27-3-2018
  * @brief   This file provides firmware functions to manage the following 
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33a0xx_dma.h" 

/** @addtogroup fm33a0_StdPeriph_Driver
  * @{
  */

/** @defgroup DMA 
  * @brief DMA driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup DMA_Private_Functions
  * @{
  */ 

//Code_Start
//2018-03-02-15-19-03
//FM33A0XX_Driver_Gen_V1.3

/********************************
DMA���ܿ��ƺ���
����: ����DMA����ȫ��ʹ��
���룺ENABLE/DISABLE	DMAʹ��/DMA�ر�	
���: ��
********************************/
void DMA_GLOBALCTRL_DMAEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DMA->GLOBALCTRL |= (DMA_GLOBALCTRL_DMAEN_Msk);
	}
	else
	{
		DMA->GLOBALCTRL &= ~(DMA_GLOBALCTRL_DMAEN_Msk);
	}
}
/********************************
DMA���ܿ��ƺ���
����: ��ȡDMA����ȫ��ʹ������
���룺��
���: ENABLE/DISABLE	DMAʹ��/DMA�ر�	
********************************/
FunState DMA_GLOBALCTRL_DMAEN_Getable(void)
{
	if (DMA->GLOBALCTRL & (DMA_GLOBALCTRL_DMAEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/********************************
DMA���ܿ��ƺ���
����: ����Channelx ���䳤��
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
			SetValue: 0-1fff(���䳤��ΪSetValue+1)
���: ��
********************************/
void DMA_CHxCTRL_TSIZE_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	uint32_t *pREG;
	uint32_t tmpreg;    
	
	pREG = (uint32_t *)(0x40000404 + CHx*8);//DMA->CH0CTRL;
	
    SetValue <<= DMA_CHxCTRL_TSIZE_Pos;//�ֹ����
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHxCTRL_TSIZE_Msk);
	tmpreg |= (SetValue&DMA_CHxCTRL_TSIZE_Msk);
	*pREG = tmpreg;
}
/********************************
DMA���ܿ��ƺ���
����: ��ȡChannelx ���䳤��
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
���: tmpsize: 0-1fff(���䳤��Ϊtmpsize+1)
********************************/
uint32_t DMA_CHxCTRL_TSIZE_Get(DMA_CH_Type CHx)
{
	uint32_t *pREG;
    uint32_t tmpsize;
	
	pREG = (uint32_t *)(0x40000404 + CHx*8);
	
    tmpsize = (*pREG & DMA_CHxCTRL_TSIZE_Msk);
    tmpsize >>= DMA_CHxCTRL_TSIZE_Pos;
	return tmpsize;
}

/********************************
DMA���ܿ��ƺ���
����: ����Channelx ���ȼ�
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
			DMA_CHxCTRL_PRI_LOW				�����ȼ�
			/DMA_CHxCTRL_PRI_MEDIUM		�����ȼ�
			/DMA_CHxCTRL_PRI_HIGH			�����ȼ�
			/DMA_CHxCTRL_PRI_VERY_HIGH	������ȼ�
���: ��
********************************/
void DMA_CHxCTRL_PRI_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	uint32_t *pREG;
	uint32_t tmpreg;
	
	pREG = (uint32_t *)(0x40000404 + CHx*8);
	
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHxCTRL_PRI_Msk);
	tmpreg |= (SetValue&DMA_CHxCTRL_PRI_Msk);
	*pREG = tmpreg;
}
/********************************
DMA���ܿ��ƺ���
����: ��ȡChannelx ���ȼ�
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
���: DMA_CHxCTRL_PRI_LOW				�����ȼ�
			/DMA_CHxCTRL_PRI_MEDIUM		�����ȼ�
			/DMA_CHxCTRL_PRI_HIGH			�����ȼ�
			/DMA_CHxCTRL_PRI_VERY_HIGH	������ȼ�
********************************/
uint32_t DMA_CHxCTRL_PRI_Get(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(0x40000404 + CHx*8);
	return (*pREG & DMA_CHxCTRL_PRI_Msk);
}

/********************************
DMA���ܿ��ƺ���
����: ����Channelx RAM��ַ��������
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
			DMA_CHxCTRL_INC_DEC			��ַ�ݼ�
			/DMA_CHxCTRL_INC_INC		��ַ����
���: ��
********************************/
void DMA_CHxCTRL_INC_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	uint32_t *pREG;
	uint32_t tmpreg;
	
	pREG = (uint32_t *)(0x40000404 + CHx*8);
	
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHxCTRL_INC_Msk);
	tmpreg |= (SetValue&DMA_CHxCTRL_INC_Msk);
	*pREG = tmpreg;
}
/********************************
DMA���ܿ��ƺ���
����: ��ȡChannelx RAM��ַ��������
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
���: DMA_CHxCTRL_INC_DEC			��ַ�ݼ�
			/DMA_CHxCTRL_INC_INC		��ַ����
********************************/
uint32_t DMA_CHxCTRL_INC_Get(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(0x40000404 + CHx*8);
	return (*pREG & DMA_CHxCTRL_INC_Msk);
}

/********************************
DMA���ܿ��ƺ���
����: ����Channelx ����ͨ��ѡ��
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
			DMA_CH0CTRL_CH0SSEL_ET4_CAP				ET4����ͨ��
			/DMA_CH0CTRL_CH0SSEL_ET2_CAP			ET2����ͨ��
			/DMA_CH0CTRL_CH0SSEL_BT2_CAP			BT2����ͨ��
			/DMA_CH0CTRL_CH0SSEL_ET3_CAP			ET3����ͨ��
			/DMA_CH0CTRL_CH0SSEL_BT1_CAP			BT1����ͨ��
			/DMA_CH0CTRL_CH0SSEL_CRC_OUT			CRC���ͨ��
			/DMA_CH0CTRL_CH0SSEL_AES_IN				AES����ͨ��
			/DMA_CH0CTRL_CH0SSEL_ADC_OUT			ADC���ͨ��
���: ��
********************************/
void DMA_CHxCTRL_SSEL_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	uint32_t *pREG;
	uint32_t tmpreg;
	
	pREG = (uint32_t *)(0x40000404 + CHx*8);
	
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHxCTRL_SSEL_Msk);
	tmpreg |= (SetValue&DMA_CHxCTRL_SSEL_Msk);
	*pREG = tmpreg;
}
/********************************
DMA���ܿ��ƺ���
����: ��ȡChannelx ����ͨ��ѡ��
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
���: DMA_CH0CTRL_CH0SSEL_ET4_CAP				ET4����ͨ��
			/DMA_CH0CTRL_CH0SSEL_ET2_CAP			ET2����ͨ��
			/DMA_CH0CTRL_CH0SSEL_BT2_CAP			BT2����ͨ��
			/DMA_CH0CTRL_CH0SSEL_ET3_CAP			ET3����ͨ��
			/DMA_CH0CTRL_CH0SSEL_BT1_CAP			BT1����ͨ��
			/DMA_CH0CTRL_CH0SSEL_CRC_OUT			CRC���ͨ��
			/DMA_CH0CTRL_CH0SSEL_AES_IN				AES����ͨ��
			/DMA_CH0CTRL_CH0SSEL_ADC_OUT			ADC���ͨ��
********************************/
uint32_t DMA_CHxCTRL_SSEL_Get(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(0x40000404 + CHx*8);
	return (*pREG & DMA_CHxCTRL_SSEL_Msk);
}

/********************************
DMA���ܿ��ƺ���
����: ����Channelx �����ж����ʹ��
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
			ENABLE/DISABLE	ʹ�ܴ�������ж�/�رմ�������ж�		
���: ��
********************************/
void DMA_CHxCTRL_FTIE_Setable(DMA_CH_Type CHx, FunState NewState)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(0x40000404 + CHx*8);
	if (NewState == ENABLE)
	{
		*pREG |= (DMA_CHxCTRL_FTIE_Msk);
	}
	else
	{
		*pREG &= ~(DMA_CHxCTRL_FTIE_Msk);
	}
}
/********************************
DMA���ܿ��ƺ���
����: ��ȡChannelx �����ж����ʹ��
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
���: ENABLE/DISABLE	ʹ�ܴ�������ж�/�رմ�������ж�	
********************************/
FunState DMA_CHxCTRL_FTIE_Getable(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(0x40000404 + CHx*8);
	if (*pREG & (DMA_CHxCTRL_FTIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
DMA���ܿ��ƺ���
����: ����Channelx ��̴�������ж�ʹ��
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
			ENABLE/DISABLE	ʹ�ܰ���ж�/�رհ���ж�		
���: ��
********************************/
void DMA_CHxCTRL_HTIE_Setable(DMA_CH_Type CHx, FunState NewState)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(0x40000404 + CHx*8);
	if (NewState == ENABLE)
	{
		*pREG |= (DMA_CHxCTRL_HTIE_Msk);
	}
	else
	{
		*pREG &= ~(DMA_CHxCTRL_HTIE_Msk);
	}
}
/********************************
DMA���ܿ��ƺ���
����: ����Channelx ��̴�������ж�ʹ��
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
���: ENABLE/DISABLE	ʹ�ܰ���ж�/�رհ���ж�
********************************/
FunState DMA_CHxCTRL_HTIE_Getable(DMA_CH_Type CHx)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(0x40000404 + CHx*8);
	if (*pREG & (DMA_CHxCTRL_HTIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
DMA���ܿ��ƺ���
����: ����Channelx ��
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
			ENABLE/DISABLE	CHx DMA������/CHx DMA���ܹر�
���: ��
********************************/
void DMA_CHxCTRL_EN_Setable(DMA_CH_Type CHx, FunState NewState)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(0x40000404 + CHx*8);
	if (NewState == ENABLE)
	{
		*pREG |= (DMA_CHxCTRL_EN_Msk);
	}
	else
	{
		*pREG &= ~(DMA_CHxCTRL_EN_Msk);
	}
}

/********************************
DMA���ܿ��ƺ���
����: ����Channelx RAMָ���ַ(DMA������ǰ�����˼Ĵ���д��RAMĿ���ַ��DMA���˼Ĵ�����DMA�����������Լ�)
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6)
SetValue:16bit ��ַ
���: ��
********************************/
void DMA_CHxRAMAD_Write(DMA_CH_Type CHx, uint32_t SetValue)
{
	uint32_t *pREG;
	
	pREG = (uint32_t *)(0x40000404 + 4 + CHx*8);
	*pREG = SetValue;
}

//uint32_t DMA_CHxRAMAD_Read(DMA_CH_Type CHx)
//{
//	uint32_t *pREG;
//	
//	pREG = (uint32_t *)(0x40000404 + 4 + CHx*8);
//	return (*pREG);
//}



/* Channel7FLASHָ���ַ ��غ��� */
/********************************
DMA���ܿ��ƺ���
����: ����Channel7 FLASHָ���ַ(DMA������ǰ�����˼Ĵ���д��FlashĿ���ַ��DMA���˼Ĵ�����DMA�����������Լ�)
���룺CHx(DMA_CH7 = 7)
SetValue:17bit ��ַ
���: ��
********************************/
void DMA_CH7FLSAD_Write(uint32_t SetValue)
{
//	DMA->CH7FLSAD = SetValue;
	DMA->CH7FLSAD = SetValue>>2;//CH7��flash��ַ���ֵ�ַ���˴���������2bit�����Ա�ʹ��ʱ����ʹ����ͨ��ַ
}

//uint32_t DMA_CH7FLSAD_Read(void)
//{
//	return (DMA->CH7FLSAD);
//}


/********************************
DMA���ܿ��ƺ���
����: ����Channel7 RAMָ���ַ(DMA������ǰ�����˼Ĵ���д��RAMĿ���ַ��DMA���˼Ĵ�����DMA�����������Լ�)
���룺CHx(DMA_CH7 = 7)
SetValue:14bit ��ַ
���: ��
********************************/
void DMA_CH7RAMAD_Write(uint32_t SetValue)
{
//	DMA->CH7RAMAD = SetValue;
	DMA->CH7RAMAD = SetValue>>2;//CH7��RAM��ַ���ֵ�ַ���˴���������2bit�����Ա�ʹ��ʱ����ʹ����ͨ��ַ
}

//uint32_t DMA_CH7RAMAD_Read(void)
//{
//	return (DMA->CH7RAMAD);
//}


/********************************
DMA���ܿ��ƺ���
����: ��Channelx �����̱�־
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
���: ��
********************************/
void DMA_CHSTATUS_DMACHxHT_Clr(DMA_CH_Type CHx)
{
	DMA->CHSTATUS = (0x1U<<CHx);
}
/********************************
DMA���ܿ��ƺ���
����: ��ȡChannelx �����̱�־
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
���: SET/RESET		��Ӧͨ����̴������/��Ӧͨ����̴���δ���
********************************/
FlagStatus DMA_CHSTATUS_DMACHxHT_Chk(DMA_CH_Type CHx)
{
	if (DMA->CHSTATUS & (0x1U<<CHx))
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
DMA���ܿ��ƺ���
����: ��Channelx ������ɱ�־
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
���: ��
********************************/
void DMA_CHSTATUS_DMACHxFT_Clr(DMA_CH_Type CHx)
{
	DMA->CHSTATUS = (0x100U<<CHx);
}
/********************************
DMA���ܿ��ƺ���
����: ��ȡChannelx ������ɱ�־
���룺CHx(DMA_CH0 = 0, DMA_CH1 = 1, DMA_CH2 = 2, DMA_CH3 = 3, DMA_CH4 = 4, DMA_CH5 = 5, DMA_CH6 = 6, DMA_CH7 = 7)
���: SET/RESET		��Ӧͨ���������/��Ӧͨ������δ���
********************************/
FlagStatus DMA_CHSTATUS_DMACHxFT_Chk(DMA_CH_Type CHx)
{
	if (DMA->CHSTATUS & (0x100U<<CHx))
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/********************************
DMA���ܿ��ƺ���
����: DMA���ܳ�ʼ��ȱʡ����
���룺��
���: ��
********************************/
void DMA_Deinit(void)
{
	DMA->GLOBALCTRL = 0x00000000;
	DMA->CH0CTRL = 0x00000000;
	DMA->CH0RAMAD = 0x00000000;
	DMA->CH1CTRL = 0x00000000;
	DMA->CH1RAMAD = 0x00000000;
	DMA->CH2CTRL = 0x00000000;
	DMA->CH2RAMAD = 0x00000000;
	DMA->CH3CTRL = 0x00000000;
	DMA->CH3RAMAD = 0x00000000;
	DMA->CH4CTRL = 0x00000000;
	DMA->CH4RAMAD = 0x00000000;
	DMA->CH5CTRL = 0x00000000;
	DMA->CH5RAMAD = 0x00000000;
	DMA->CH6CTRL = 0x00000000;
	DMA->CH6RAMAD = 0x00000000;
	DMA->CH7CTRL = 0x00000000;
	DMA->CH7FLSAD = 0x00000000;
	DMA->CH7RAMAD = 0x00000000;
	DMA->CHSTATUS = 0x00000000;
}
//Code_End
          

void DMA_Init(DMA_InitTypeDef* para)
{
	if( DMA_CH7 == para->CHx )
	{
		DMA_CH7RAMAD_Write(para->CHxRAMAD);//CH0~CH7ͨ��RAMָ���ַ
		DMA_CH7FLSAD_Write(para->CH7FLSAD);//ͨ��FLASHָ���ַ�������ͨ��7������
	}
	else
	{
		DMA_CHxRAMAD_Write(para->CHx, para->CHxRAMAD);//CH0~CH7ͨ��RAMָ���ַ
	}
	
	DMA_CHxCTRL_TSIZE_Set(para->CHx, para->CHxTSIZE);	//ͨ�����䳤��
	DMA_CHxCTRL_PRI_Set(para->CHx, para->CHxPRI);		//ͨ�����ȼ�
	DMA_CHxCTRL_INC_Set(para->CHx, para->CHxINC);		//ͨ����ַ��������
	DMA_CHxCTRL_SSEL_Set(para->CHx, para->CHxSSEL);		//CH0~CH6����ͨ��ѡ��,CH7���䷽ʽѡ��
	DMA_CHxCTRL_FTIE_Setable(para->CHx, para->CHxFTIE);	//ͨ����������ж�ʹ��
	DMA_CHxCTRL_HTIE_Setable(para->CHx, para->CHxHTIE);	//ͨ���������ж�ʹ��
	DMA_CHxCTRL_EN_Setable(para->CHx, para->CHxEN);		//ͨ��ʹ��
}

/******END OF FILE****/



