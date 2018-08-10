/**
  ******************************************************************************
  * @file    fm33a0xx_flash.c
  * @author  FM33a0xx Application Team
  * @version V2.0.2
  * @date    3-1-2018
  * @brief   This file provides firmware functions to manage the following 
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33a0xx_flash.h" 

/** @addtogroup fm33a0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup FLASH 
  * @brief FLASH driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup FLASH_Private_Functions
  * @{
  */ 
	
//Code_Start
//2018-04-02-13-21-07
//FM33A0XX_Driver_Gen_V1.4

/********************************
FLASH���ȴ��������ú���
����:FLASH���ȴ��������ã���CPUʱ�ӳ���24M����Ҫ��wait1 cycle
���룺�����µ縴λ��ѹ��bit1:0��
      00/11��0 wait cycle
      01��1 wait cycle
      10��2 wait cycles
���:��
********************************/
void FLASH_FLSRDCON_WAIT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLASH->FLSRDCON;
	tmpreg &= ~(FLASH_FLSRDCON_WAIT_Msk);
	tmpreg |= (SetValue & FLASH_FLSRDCON_WAIT_Msk);
	FLASH->FLSRDCON = tmpreg;
}

/********************************
FLASH���ȴ�����״̬����
����: ��ȡFLASH���ȴ�����
���룺��
���: 00/11��0 wait cycle
      01��1 wait cycle
      10��2 wait cycles
********************************/
uint32_t FLASH_FLSRDCON_WAIT_Get(void)
{
	return (FLASH->FLSRDCON & FLASH_FLSRDCON_WAIT_Msk);
}

/********************************
FLASH DBG���ƼĴ���״̬����
����: ��ȡFLASH DBG���ƼĴ���״̬
���룺��
���: SET   ����MCUDBGCR�Ĵ�������
      RESET  MCUDBGCR�Ĵ���ʹ��
********************************/
FlagStatus FLASH_OPTBR_DBGCFGEN_Chk(void)
{
	if (FLASH->OPTBR & FLASH_OPTBR_DBGCFGEN_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/********************************
FLASH RAM����ʹ��״̬����
����: ��ȡFLASH DBG���ƼĴ���״̬
���룺��
���: SET   ����оƬ��ʱ��RAM����
      RESET  ��ֹоƬ��RAM����
********************************/
FlagStatus FLASH_OPTBR_RAMBOOT_Chk(void)
{
	if (FLASH->OPTBR & FLASH_OPTBR_RAMBOOT_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/********************************
FLASH Ӧ�ô���Ȩ������ʹ��״̬����
����: ��ȡFLASH Ӧ�ô���Ȩ������ʹ��״̬
���룺��
���: 00/01/11��ACLOCK��ʹ��
      10��ACLOCKʹ��
********************************/
FlagStatus FLASH_OPTBR_ACLOCKEN_Chk(void)
{
	if (FLASH->OPTBR & FLASH_OPTBR_ACLOCKEN_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/********************************
FLASH Debug Port��ȡ����ʹ��״̬����
����: ��ȡFLASH Debug Port��ȡ����ʹ��״̬
���룺��
���: 00/01/11��DBRDP��ʹ��
      10��DBRDPʹ��
********************************/
FlagStatus FLASH_OPTBR_DBRDPEN_Chk(void)
{
	if (FLASH->OPTBR & FLASH_OPTBR_DBRDPEN_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
FLASH ACLOCK1���ú���
����: �ֱ����ڿ���Block31~Block0��Ӧ�ô����д����
���룺1����ȡ�Ͳ�дȨ������
      0����ȡ�Ͳ�дȨ�޷ſ�
���: ��
********************************/
void FLASH_ACLOCK1_Write(uint32_t SetValue)
{
	FLASH->ACLOCK1 = (SetValue);
}

uint32_t FLASH_ACLOCK1_Read(void)
{
	return (FLASH->ACLOCK1);
}

/********************************
FLASH ACLOCK2���ú���
����: �ֱ����ڿ���Block63~Block32��Ӧ�ô����д����
���룺1����ȡ�Ͳ�дȨ������
      0����ȡ�Ͳ�дȨ�޷ſ�
���: ��
********************************/
void FLASH_ACLOCK2_Write(uint32_t SetValue)
{
	FLASH->ACLOCK2 = (SetValue);
}
/********************************
FLASH ACLOCK2����״̬��ȡ����
����:��ȡ ACLOCK1����״̬
���룺��
���: 1����ȡ�Ͳ�дȨ������
      0����ȡ�Ͳ�дȨ�޷ſ�
********************************/
uint32_t FLASH_ACLOCK2_Read(void)
{
	return (FLASH->ACLOCK2);
}

/********************************
FLASH ����������ʽ���ú���
����:FLASH ����������ʽ
���룺00/11��Sector Erase �Ȳ���
      01��Block Erase �����
      10����ֹ
���: ��
********************************/
void FLASH_EPCON_ERTYPE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLASH->EPCON;
	tmpreg &= ~(FLASH_EPCON_ERTYPE_Msk);
	tmpreg |= (SetValue & FLASH_EPCON_ERTYPE_Msk);
	FLASH->EPCON = tmpreg;
}
/********************************
FLASH ����������ʽ״̬��ȡ����
����:��ȡ ������ʽ״̬
���룺��
���: 00/11��Sector Erase �Ȳ���
      01��Block Erase �����
      10����ֹ
********************************/
uint32_t FLASH_EPCON_ERTYPE_Get(void)
{
	return (FLASH->EPCON & FLASH_EPCON_ERTYPE_Msk);
}
/********************************
���������
����:�������
���룺�����λ��Ӳ����ɱ�̺��Զ�����
���: ��
********************************/
void FLASH_EPCON_PREQ_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLASH->EPCON;
	tmpreg &= ~(FLASH_EPCON_PREQ_Msk);
	tmpreg |= (SetValue & FLASH_EPCON_PREQ_Msk);
	FLASH->EPCON = tmpreg;
}
/********************************
�������״̬��ȡ����
����:��ȡ �������״̬
���룺��
���: �����ɺ���0
********************************/
uint32_t FLASH_EPCON_PREQ_Get(void)
{
	return (FLASH->EPCON & FLASH_EPCON_PREQ_Msk);
}
/********************************
����������
����:��������
���룺�����λ��Ӳ����ɱ�̺��Զ�����
���: ��
********************************/
void FLASH_EPCON_EREQ_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLASH->EPCON;
	tmpreg &= ~(FLASH_EPCON_EREQ_Msk);
	tmpreg |= (SetValue & FLASH_EPCON_EREQ_Msk);
	FLASH->EPCON = tmpreg;
}
/********************************
��������״̬��ȡ����
����:��ȡ��������״̬
���룺��
���: �����ɺ���0
********************************/
uint32_t FLASH_EPCON_EREQ_Get(void)
{
	return (FLASH->EPCON & FLASH_EPCON_EREQ_Msk);
}

/* Flash��дKey����Ĵ������������SWD�����дǰ������ȷ����˵�ַд��Ϸ�KEY���С��յ�ַ���������޼Ĵ���ʵ�֡� ��غ��� */
void FLASH_FLSKEY_Write(uint32_t SetValue)
{
	FLASH->FLSKEY = (SetValue);
}

/********************************
Flash��дKey����Ĵ������ú���
����:Flash��дKey����ʹ��
���룺ENABLE   ����Flash��дKey
      DISABLE  �ر�Flash��дKey
���: ��
********************************/
void FLASH_FLSIE_AUTHIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLASH->FLSIE |= (FLASH_FLSIE_AUTHIE_Msk);
	}
	else
	{
		FLASH->FLSIE &= ~(FLASH_FLSIE_AUTHIE_Msk);
	}
}
/********************************
Flash��дKey����Ĵ���״̬��ȡ����
����:��ȡFlash��дKey����Ĵ���״̬
���룺��
���: ENABLE   ����Flash��дKey
      DISABLE  �ر�Flash��дKey
********************************/
FunState FLASH_FLSIE_AUTHIE_Getable(void)
{
	if (FLASH->FLSIE & (FLASH_FLSIE_AUTHIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/********************************
Flash KEY�����ж�ʹ�ܿ��ƺ���
����:Flash KEY�����ж�ʹ��
���룺ENABLE   ����Flash KEY�����ж�
      DISABLE  �ر�Flash KEY�����ж�
���: ��
********************************/
void FLASH_FLSIE_KEYIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLASH->FLSIE |= (FLASH_FLSIE_KEYIE_Msk);
	}
	else
	{
		FLASH->FLSIE &= ~(FLASH_FLSIE_KEYIE_Msk);
	}
}
/********************************
Flash KEY�����жϻ�ȡ����
����:��ȡFlash KEY�����ж�״̬
���룺��
���: ENABLE   Flash��дKey�жϲ���
      DISABLE  Flash��дKey�ж�δ����
********************************/
FunState FLASH_FLSIE_KEYIE_Getable(void)
{
	if (FLASH->FLSIE & (FLASH_FLSIE_KEYIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/********************************
��д��ʱʱ�Ӵ����ж�ʹ�ܿ��ƺ���
����:��д��ʱʱ�Ӵ����ж�ʹ��
���룺ENABLE   �����д��ʱʱ�Ӵ����ж�ʹ��
      DISABLE  �رղ�д��ʱʱ�Ӵ����ж�ʹ��
���: ��
********************************/
void FLASH_FLSIE_CKIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLASH->FLSIE |= (FLASH_FLSIE_CKIE_Msk);
	}
	else
	{
		FLASH->FLSIE &= ~(FLASH_FLSIE_CKIE_Msk);
	}
}
/********************************
��д��ʱʱ�Ӵ����ж�״̬��ȡ����
����:��д��ʱʱ�Ӵ����ж�ʹ��״̬
���룺��
���: ENABLE   ��д��ʱʱ�Ӵ����жϲ���
      DISABLE  ��д��ʱʱ�Ӵ����ж�δ����
********************************/
FunState FLASH_FLSIE_CKIE_Getable(void)
{
	if (FLASH->FLSIE & (FLASH_FLSIE_CKIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/********************************
�����ɱ�־�ж�ʹ�ܿ��ƺ���
����:�����ɱ�־�ж�ʹ��
���룺ENABLE   ��������ɱ�־�ж�ʹ��
      DISABLE  �رձ����ɱ�־�ж�ʹ��
���: ��
********************************/
void FLASH_FLSIE_PRDIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLASH->FLSIE |= (FLASH_FLSIE_PRDIE_Msk);
	}
	else
	{
		FLASH->FLSIE &= ~(FLASH_FLSIE_PRDIE_Msk);
	}
}
/********************************
�����ɱ�־�ж�ʹ��״̬��ȡ����
����:�����ɱ�־�ж�ʹ��
���룺��
���: ENABLE   �����ɱ�־�ж�ʹ���жϲ���
      DISABLE  �����ɱ�־�ж�ʹ���ж�δ����
********************************/
FunState FLASH_FLSIE_PRDIE_Getable(void)
{
	if (FLASH->FLSIE & (FLASH_FLSIE_PRDIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/********************************
��д��ɱ�־�ж�ʹ�ܿ��ƺ���
����:��д��ɱ�־�ж�ʹ��
���룺ENABLE   �����д��ɱ�־�ж�ʹ��
      DISABLE  �رղ�д��ɱ�־�ж�ʹ��
���: ��
********************************/
void FLASH_FLSIE_ERDIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLASH->FLSIE |= (FLASH_FLSIE_ERDIE_Msk);
	}
	else
	{
		FLASH->FLSIE &= ~(FLASH_FLSIE_ERDIE_Msk);
	}
}
/********************************
��д��ɱ�־�ж�ʹ��״̬��ȡ����
����:��д��ɱ�־�ж�ʹ��
���룺��
���: ENABLE   ��д��ɱ�־�ж�ʹ���жϲ���
      DISABLE  ��д��ɱ�־�ж�ʹ���ж�δ����
********************************/
FunState FLASH_FLSIE_ERDIE_Getable(void)
{
	if (FLASH->FLSIE & (FLASH_FLSIE_ERDIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
Flash��дȨ�޴�����
����:��ȡLOCK�����ݻ��LOCK���дʱ��λ�����д1���㡣
���룺���д1���㡣
���: ��
********************************/
void FLASH_FLSIF_AUTHIF_Clr(void)
{
	FLASH->FLSIF = FLASH_FLSIF_AUTHIF_Msk;
}
/********************************
Flash��дȨ�޴���״̬��ȡ����
����:��ȡFlash��дȨ�޴���
���룺��
���: SET    Flash��дȨ�޴����жϲ���
      RESET  Flash��дȨ�޴����ж�δ����
********************************/
FlagStatus FLASH_FLSIF_AUTHIF_Chk(void)
{
	if (FLASH->FLSIF & FLASH_FLSIF_AUTHIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/********************************
Flash KEY������
����: ��Flash KEY����
���룺Ӳ����λ�����д1���㡣
���: ��
********************************/
void FLASH_FLSIF_KEYIF_Clr(void)
{
	FLASH->FLSIF = FLASH_FLSIF_KEYIF_Msk;
}
/********************************
Flash KEY����״̬��ȡ����
����:��ȡFlash KEY����
���룺��
���: SET    Flash KEY�����жϲ���
      RESET  Flash KEY�����ж�δ����
********************************/
FlagStatus FLASH_FLSIF_KEYIF_Chk(void)
{
	if (FLASH->FLSIF & FLASH_FLSIF_KEYIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/********************************
��д��ʱʱ�Ӵ�����
����: NVMIF��дFlashʱAHBCLKֻ��ʹ��RCHF 8M��16M��ʹ������ʱ�Ӳ�д���ᴥ��CKERR�����д1���㡣
���룺��Flash CK����
���: ��
********************************/
void FLASH_FLSIF_CKIF_Clr(void)
{
	FLASH->FLSIF = FLASH_FLSIF_CKIF_Msk;
}
/********************************
��д��ʱʱ�Ӵ���״̬��ȡ����
����:��ȡFlash ��д��ʱʱ�Ӵ�״̬
���룺��
���: SET    Flash ��д��ʱʱ�Ӵ����жϲ���
      RESET  Flash ��д��ʱʱ�Ӵ����ж�δ����
********************************/
FlagStatus FLASH_FLSIF_CKIF_Chk(void)
{
	if (FLASH->FLSIF & FLASH_FLSIF_CKIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/********************************
�����ɱ�־����
����: Program Done�������ɱ�־��Ӳ����λ�����д1���㡣
���룺������ɱ�־��
���: ��
********************************/
void FLASH_FLSIF_PRDIF_Clr(void)
{
	FLASH->FLSIF = FLASH_FLSIF_PRDIF_Msk;
}
/********************************
�����ɱ�־����״̬��ȡ����
����:��ȡ�����ɱ�־״̬
���룺��
���: SET    �������жϲ���
      RESET �������ж�δ����
********************************/
FlagStatus FLASH_FLSIF_PRDIF_Chk(void)
{
	if (FLASH->FLSIF & FLASH_FLSIF_PRDIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/********************************
��д��ɱ�־����
����: Erase Done����д��ɱ�־��Ӳ����λ�����д1����
���룺���д��ɱ�־��
���: ��
********************************/
void FLASH_FLSIF_ERDIF_Clr(void)
{
	FLASH->FLSIF = FLASH_FLSIF_ERDIF_Msk;
}
/********************************
��д��ɱ�־����״̬��ȡ����
����:��ȡ��д��ɱ�־״̬
���룺��
���: SET    ��д����жϲ���
      RESET ��д����ж�δ����
********************************/
FlagStatus FLASH_FLSIF_ERDIF_Chk(void)
{
	if (FLASH->FLSIF & FLASH_FLSIF_ERDIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void FLASH_Deinit(void)
{
	FLASH->FLSRDCON = 0x00000000;
	FLASH->PRFTCON = 0x00000000;
	//FLASH->OPTBR = 0x00000005;
	//FLASH->ACLOCK1 = ;
	//FLASH->ACLOCK2 = ;
	FLASH->EPCON = 0x00000000;
	//FLASH->FLSKEY = 0x00000000;//key����  
	FLASH->FLSIE = 0x00000000;
	//FLASH->FLSIF = 0x00000000;
}
//Code_End


/********************************
������ú���
����:�������
���룺������ַ
���: ��
********************************/
void FLASH_Erase_Sector(uint32_t erase_addr)
{
    //set to sector erase
    FLASH_EPCON_ERTYPE_Set(FLASH_EPCON_ERTYPE_SECTOR);
	
    //SET EREQ
    FLASH_EPCON_EREQ_Set(FLASH_EPCON_EREQ_ERASE);
	
    //write flash key
    FLASH_FLSKEY_Write(flash_sector_erase_key0);
    FLASH_FLSKEY_Write(flash_sector_erase_key1);
	
    //����Ҫ�����������������ַд��������0x1234_ABCD
    *(uint32_t*)erase_addr = flash_erase_data;
	
	//wait for finish
	while(SET != FLASH_FLSIF_ERDIF_Chk()){__NOP();}
	FLASH_FLSIF_ERDIF_Clr();
	
    FLASH_FLSKEY_Write(0x00000000);
}

/********************************
����дflash����
����:����дflash
���룺д���ַ��д������
���: ��
********************************/
void FLASH_Prog_SingleByte(uint32_t prog_addr,uint8_t prog_data)
{
	//set PREQ
    FLASH_EPCON_PREQ_Set(FLASH_EPCON_PREQ_PROG);
	
	//write flash key
    FLASH_FLSKEY_Write(flash_PROG_key0);
    FLASH_FLSKEY_Write(flash_PROG_key1);
	
    *(uint8_t*)prog_addr = prog_data;	

    while(RESET == FLASH_FLSIF_PRDIF_Chk()){__NOP();}
	FLASH_FLSIF_PRDIF_Clr();
	
    FLASH_FLSKEY_Write(0x00000000);
}

/********************************
����дflash����
����:����дflash
���룺д���ַ��д�����ݺͳ���
���: ��
********************************/
void FLASH_Prog_ByteString(uint32_t prog_addr,uint8_t* prog_data, uint16_t Len)
{
	uint16_t i;
	//set PREQ
	FLASH_EPCON_PREQ_Set(FLASH_EPCON_PREQ_PROG);
	
	//write flash key
	FLASH_FLSKEY_Write(flash_PROG_key0);
	FLASH_FLSKEY_Write(flash_PROG_key1);
	
	for(i=0; i<Len; i++)
	{
		FLASH_EPCON_PREQ_Set(FLASH_EPCON_PREQ_PROG);	//set PREQ
		*(uint8_t*)prog_addr = prog_data[i];						//дһ���ֽ�
		prog_addr++;
		while(RESET == FLASH_FLSIF_PRDIF_Chk()){__NOP();}//�ȴ�д�������
		FLASH_FLSIF_PRDIF_Clr();						//���д����жϱ�־
	//	delay_50(1);
	}
	
    FLASH_FLSKEY_Write(0x00000000);
}

/******END OF FILE****/






