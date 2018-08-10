/**
  ******************************************************************************
  * @file    fm33a0xx_scu.c
  * @author  FM33a0xx Application Team
  * @version V2.0.2
  * @date    7-12-2017
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the system control unit (scu) peripheral:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33a0xx_scu.h" 

/** @addtogroup fm385_StdPeriph_Driver
  * @{
  */

/** @defgroup SCU 
  * @brief SCU driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup SCU_Private_Functions
  * @{
  */
	

//Code_Start
//2018-04-02-13-22-16
//FM33A0XX_Driver_Gen_V1.4

/********************************
Debug״̬��ET4ʹ�ܿ��ƺ���
����:Debug״̬��ET4ʹ��
����:ʹ��״̬
********************************/
void SCU_MCUDBGCR_DBG_ET4_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_ET4_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_ET4_STOP_Msk);
	}
}
/********************************
��ȡDebug״̬��ET4ʹ�ܿ��ƺ���
����:��ȡDebug״̬��ET4ʹ��״̬
���:ʹ��״̬
********************************/
FunState SCU_MCUDBGCR_DBG_ET4_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_ET4_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
Debug״̬��ET3ʹ�ܿ��ƺ���
����:Debug״̬��ET3ʹ��
����:ʹ��״̬
********************************/
void SCU_MCUDBGCR_DBG_ET3_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_ET3_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_ET3_STOP_Msk);
	}
}
/********************************
��ȡDebug״̬��ET3ʹ�ܿ��ƺ���
����:��ȡDebug״̬��ET3ʹ��״̬
���:ʹ��״̬
********************************/
FunState SCU_MCUDBGCR_DBG_ET3_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_ET3_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
Debug״̬��ET2ʹ�ܿ��ƺ���
����:Debug״̬��ET2ʹ��
����:ʹ��״̬
********************************/
void SCU_MCUDBGCR_DBG_ET2_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_ET2_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_ET2_STOP_Msk);
	}
}
/********************************
��ȡDebug״̬��ET2ʹ�ܿ��ƺ���
����:��ȡDebug״̬��ET2ʹ��״̬
���:ʹ��״̬
********************************/
FunState SCU_MCUDBGCR_DBG_ET2_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_ET2_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
Debug״̬��ET1ʹ�ܿ��ƺ���
����:Debug״̬��ET1ʹ��
����:ʹ��״̬
********************************/
void SCU_MCUDBGCR_DBG_ET1_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_ET1_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_ET1_STOP_Msk);
	}
}
/********************************
��ȡDebug״̬��ET1ʹ�ܿ��ƺ���
����:��ȡDebug״̬��ET1ʹ��״̬
���:ʹ��״̬
********************************/
FunState SCU_MCUDBGCR_DBG_ET1_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_ET1_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/********************************
Debug״̬��BT2ʹ�ܿ��ƺ���
����:Debug״̬��BT2ʹ��
����:ʹ��״̬
********************************/
void SCU_MCUDBGCR_DBG_BT2_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_BT2_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_BT2_STOP_Msk);
	}
}
/********************************
��ȡDebug״̬��BT2ʹ�ܿ��ƺ���
����:��ȡDebug״̬��BT2ʹ��״̬
���:ʹ��״̬
********************************/
FunState SCU_MCUDBGCR_DBG_BT2_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_BT2_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
Debug״̬��BT1ʹ�ܿ��ƺ���
����:Debug״̬��BT1ʹ��
����:ʹ��״̬
********************************/
void SCU_MCUDBGCR_DBG_BT1_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_BT1_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_BT1_STOP_Msk);
	}
}
/********************************
��ȡDebug״̬��BT1ʹ�ܿ��ƺ���
����:��ȡDebug״̬��BT1ʹ��״̬
���:ʹ��״̬
********************************/
FunState SCU_MCUDBGCR_DBG_BT1_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_BT1_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
Debug״̬��WWDTʹ�ܿ��ƺ���
����:Debug״̬��WWDTʹ��
����:ʹ��״̬
********************************/
void SCU_MCUDBGCR_DBG_WWDT_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_WWDT_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_WWDT_STOP_Msk);
	}
}
/********************************
��ȡDebug״̬��WWDTʹ�ܿ��ƺ���
����:��ȡDebug״̬��WWDTʹ��״̬
���:ʹ��״̬
********************************/
FunState SCU_MCUDBGCR_DBG_WWDT_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_WWDT_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
Debug״̬��IWDTʹ�ܿ��ƺ���
����:Debug״̬��IWDTʹ��
����:ʹ��״̬
********************************/
void SCU_MCUDBGCR_DBG_IWDT_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_IWDT_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_IWDT_STOP_Msk);
	}
}
/********************************
��ȡDebug״̬��IWDTʹ�ܿ��ƺ���
����:��ȡDebug״̬��IWDTʹ��״̬
���:ʹ��״̬
********************************/
FunState SCU_MCUDBGCR_DBG_IWDT_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_IWDT_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
���ַ�Ƕ�����ʴ����־����
����:���ַ�Ƕ�����ʴ����־
********************************/
void SCU_HDFFLAG_DABORT_ADDR_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_DABORT_ADDR_FLAG_Msk;
}

FlagStatus SCU_HDFFLAG_DABORT_ADDR_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_DABORT_ADDR_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/********************************
��ȡ��ַ�Ƕ�����ʴ����־����
����:��ȡ��ַ�Ƕ�����ʴ����־
���:��ַ�Ƕ�����ʴ����־
********************************/
void SCU_HDFFLAG_DABORT_RESP_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_DABORT_RESP_FLAG_Msk;
}

/********************************
��Ƿ���ַ���ʴ����־����
����:��Ƿ���ַ���ʴ����־
********************************/
FlagStatus SCU_HDFFLAG_DABORT_RESP_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_DABORT_RESP_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
��ȡ�Ƿ���ַ���ʴ����־����
����:��ȡ�Ƿ���ַ���ʴ����־��־
���:�Ƿ���ַ���ʴ����־��־
********************************/
void SCU_HDFFLAG_SVCUNDEF_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_SVCUNDEF_FLAG_Msk;
}
/********************************
��ȡSVC instructionsδ�����־����
����:��ȡSVC instructionsδ�����־
���:SVC instructionsδ�����־
********************************/
FlagStatus SCU_HDFFLAG_SVCUNDEF_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_SVCUNDEF_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
��ִ��BKPTָ���־����
����:��ִ��BKPTָ���־
********************************/
void SCU_HDFFLAG_BKPT_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_BKPT_FLAG_Msk;
}
/********************************
��ȡִ��BKPTָ���־����
����:��ȡִ��BKPTָ���־
���:ִ��BKPTָ��ı�־
********************************/
FlagStatus SCU_HDFFLAG_BKPT_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_BKPT_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
��Thumb-State��־����
����:��Thumb-State��־
********************************/
void SCU_HDFFLAG_TBIT_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_TBIT_FLAG_Msk;
}

/********************************
��ȡThumb-State��־����
����:��ȡThumb-State��־
���:Thumb-State�ı�־
********************************/
FlagStatus SCU_HDFFLAG_TBIT_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_TBIT_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
������ָ���־����
����:������ָ���־
********************************/
void SCU_HDFFLAG_SPECIAL_OP_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_SPECIAL_OP_FLAG_Msk;
}
/********************************
��ȡ����ָ���־����
����:��ȡ����ָ���־
���:����ָ��ı�־
********************************/
FlagStatus SCU_HDFFLAG_SPECIAL_OP_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_SPECIAL_OP_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
��hardfault��־λ����
����:��hardfault�ı�־λ
********************************/
void SCU_HDFFLAG_HDF_REQUEST_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_HDF_REQUEST_FLAG_Msk;
}
/********************************
��ȡhardfault��־λ����
����:��ȡhardfault��־λ
���:hardfault�ı�־λ
********************************/
FlagStatus SCU_HDFFLAG_HDF_REQUEST_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_HDF_REQUEST_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/********************************
SCU��ʼ��ȱʡ����
����:SCU��ʼ��ȱʡ����
********************************/
void SCU_Deinit(void)
{
	SCU->MCUDBGCR = 0x00003F03;
	SCU->HDFFLAG = 0x00000000;
}
//Code_End


/******END OF FILE****/



