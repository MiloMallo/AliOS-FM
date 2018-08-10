/**
  ******************************************************************************
  * @file    fm33a00xx_lcd.c
  * @author  FM33a0xx Application Team
  * @version V2.0.2
  * @date    11-1-2018
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/
#include "fm33a0xx_lcd.h" 

//Code_Start
//2018-04-02-13-21-29
//FM33A0XX_Driver_Gen_V1.4

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�SEG/COM��LCD�ر�����½ӵؿ��ƣ�������
����: ENABLE/DISABLE	COM��SEG��LCD�ر��½ӵ�/����
���: ��
*********************************/
void LCD_DISPCTRL_ANTIPOLAR_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->DISPCTRL |= (LCD_DISPCTRL_ANTIPOLAR_Msk);
	}
	else
	{
		LCD->DISPCTRL &= ~(LCD_DISPCTRL_ANTIPOLAR_Msk);
	}
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡSEG/COM��LCD�ر�����½ӵ�״̬
����: ��
���: ENABLE/DISABLE	COM��SEG��LCD�ر��½ӵ�/����
*********************************/
FunState LCD_DISPCTRL_ANTIPOLAR_Getable(void)
{
	if (LCD->DISPCTRL & (LCD_DISPCTRL_ANTIPOLAR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�LCD��ʾ����ʹ�ܿ���
����: ENABLE/DISABLE	LCD��ʾʹ��/LCD��ʾ��ֹ
���: ��
*********************************/
void LCD_DISPCTRL_LCDEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->DISPCTRL |= (LCD_DISPCTRL_LCDEN_Msk);
	}
	else
	{
		LCD->DISPCTRL &= ~(LCD_DISPCTRL_LCDEN_Msk);
	}
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD��ʾ����ʹ�ܿ���
����: ��
���: ENABLE/DISABLE	LCD��ʾʹ��/LCD��ʾ��ֹ
*********************************/
FunState LCD_DISPCTRL_LCDEN_Getable(void)
{
	if (LCD->DISPCTRL & (LCD_DISPCTRL_LCDEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�LCD��ʾ��˸ʹ�ܿ���
����: ENABLE/DISABLE	LCD��ʾ��˸ʹ��/LCD��ʾ��˸��ֹ
���: ��
*********************************/
void LCD_DISPCTRL_FLICK_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->DISPCTRL |= (LCD_DISPCTRL_FLICK_Msk);
	}
	else
	{
		LCD->DISPCTRL &= ~(LCD_DISPCTRL_FLICK_Msk);
	}
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD��ʾ��˸����ʹ�ܿ���
����: ��
���: ENABLE/DISABLE	LCD��ʾ��˸ʹ��/LCD��ʾ��˸��ֹ
*********************************/
FunState LCD_DISPCTRL_FLICK_Getable(void)
{
	if (LCD->DISPCTRL & (LCD_DISPCTRL_FLICK_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�LCD����ģʽ����ʾ����(����DISPMD=1���������Ч)
����: ENABLE/DISABLE	LCD����ģʽ��ȫ��/LCD����ģʽ��ȫ��
���: ��
*********************************/
void LCD_DISPCTRL_TEST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->DISPCTRL |= (LCD_DISPCTRL_TEST_Msk);
	}
	else
	{
		LCD->DISPCTRL &= ~(LCD_DISPCTRL_TEST_Msk);
	}
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD����ģʽ����ʾ����(����DISPMD=1���������Ч)
����: ��
���: ENABLE/DISABLE	LCD����ģʽ��ȫ��/LCD����ģʽ��ȫ��
*********************************/
FunState LCD_DISPCTRL_TEST_Getable(void)
{
	if (LCD->DISPCTRL & (LCD_DISPCTRL_TEST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�LCDģʽѡ��
����: ENABLE/DISABLE	����ģʽ/����ģʽ
���: ��
*********************************/
void LCD_DISPCTRL_DISPMD_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->DISPCTRL |= (LCD_DISPCTRL_DISPMD_Msk);
	}
	else
	{
		LCD->DISPCTRL &= ~(LCD_DISPCTRL_DISPMD_Msk);
	}
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�LCDģʽѡ��
����: ��
���: ENABLE/DISABLE	����ģʽ/����ģʽ
*********************************/
FunState LCD_DISPCTRL_DISPMD_Getable(void)
{
	if (LCD->DISPCTRL & (LCD_DISPCTRL_DISPMD_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�LCD���Կ���λ(����DISPMD=1���������Ч)
����: LCD_LCDTEST_LCCTRL_0/LCD_LCDTEST_LCCTRL_1 LCD��ƽ�������Ĵ�������/LCD��ƽ�ɲ��ԼĴ�������
���: ��
*********************************/
void LCD_LCDTEST_LCCTRL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->LCDTEST;
	tmpreg &= ~(LCD_LCDTEST_LCCTRL_Msk);
	tmpreg |= (SetValue & LCD_LCDTEST_LCCTRL_Msk);
	LCD->LCDTEST = tmpreg;
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD���Կ���λ(����DISPMD=1���������Ч)
����: ��
���: LCD_LCDTEST_LCCTRL_0/LCD_LCDTEST_LCCTRL_1 LCD��ƽ�������Ĵ�������/LCD��ƽ�ɲ��ԼĴ�������
*********************************/
uint32_t LCD_LCDTEST_LCCTRL_Get(void)
{
	return (LCD->LCDTEST & LCD_LCDTEST_LCCTRL_Msk);
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�LCD����ģʽʹ�ܿ���(����DISPMD=1���������Ч)
����: ENABLE/DISABLE 	LCD����ģʽʹ��/LCD����ģʽ��ֹ
���: ��
*********************************/
void LCD_LCDTEST_TESTEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->LCDTEST |= (LCD_LCDTEST_TESTEN_Msk);
	}
	else
	{
		LCD->LCDTEST &= ~(LCD_LCDTEST_TESTEN_Msk);
	}
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�LCD����ģʽʹ�ܿ���(����DISPMD=1���������Ч)
����: ��
���: ENABLE/DISABLE 	LCD����ģʽʹ��/LCD����ģʽ��ֹ
*********************************/
FunState LCD_LCDTEST_TESTEN_Getable(void)
{
	if (LCD->LCDTEST & (LCD_LCDTEST_TESTEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD��ʾƵ��
����: 00-FF
���: ��
*********************************/
void LCD_DF_Write(uint32_t SetValue)
{
	LCD->DF = (SetValue & LCD_DF_DF_Msk);
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD��ʾƵ��
����: ��
���: 00-FF
*********************************/
uint32_t LCD_DF_Read(void)
{
	return (LCD->DF & LCD_DF_DF_Msk);
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD��ʾ����ʱ��
����: 00-FF  ton*0.25s
���: ��
*********************************/
void LCD_TON_Write(uint32_t SetValue)
{
	LCD->TON = (SetValue & LCD_TON_TON_Msk);
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD��ʾ����ʱ��
����: ��
���: 00-FF ton*0.25s
*********************************/
uint32_t LCD_TON_Read(void)
{
	return (LCD->TON & LCD_TON_TON_Msk);
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD��ʾϨ��ʱ��
����: 00-FF  toff*0.25s
���: ��
*********************************/
void LCD_TOFF_Write(uint32_t SetValue)
{
	LCD->TOFF = (SetValue & LCD_TOFF_TOFF_Msk);
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD��ʾϨ��ʱ��
����: ��
���: 00-FF toff*0.25s
*********************************/
uint32_t LCD_TOFF_Read(void)
{
	return (LCD->TOFF & LCD_TOFF_TOFF_Msk);
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD�����ж�ʹ��
����: ENABLE/DISABLE	�����ж�ʹ��/��ֹ
���: ��
*********************************/
void LCD_DISPIE_DONIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->DISPIE |= (LCD_DISPIE_DONIE_Msk);
	}
	else
	{
		LCD->DISPIE &= ~(LCD_DISPIE_DONIE_Msk);
	}
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD�����ж�ʹ��
����: ��
���: ENABLE/DISABLE	�����ж�ʹ��/��ֹ
*********************************/
FunState LCD_DISPIE_DONIE_Getable(void)
{
	if (LCD->DISPIE & (LCD_DISPIE_DONIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCDϨ���ж�ʹ��
����: ENABLE/DISABLE	Ϩ���ж�ʹ��/��ֹ
���: ��
*********************************/
void LCD_DISPIE_DOFFIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->DISPIE |= (LCD_DISPIE_DOFFIE_Msk);
	}
	else
	{
		LCD->DISPIE &= ~(LCD_DISPIE_DOFFIE_Msk);
	}
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCDϨ���ж�ʹ��
����: ��
���: ENABLE/DISABLE	Ϩ���ж�ʹ��/��ֹ
*********************************/
FunState LCD_DISPIE_DOFFIE_Getable(void)
{
	if (LCD->DISPIE & (LCD_DISPIE_DOFFIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���LCD�����жϱ�־
����: ��
���: ��
*********************************/
void LCD_DISPIF_DONIF_Clr(void)
{
	LCD->DISPIF = LCD_DISPIF_DONIF_Msk;
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD�����жϱ�־
����: ��
���: SET/RESET		LCD�����ж��ѷ���/δ����
*********************************/
FlagStatus LCD_DISPIF_DONIF_Chk(void)
{
	if (LCD->DISPIF & LCD_DISPIF_DONIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���LCDϨ���жϱ�־
����: ��
���: ��
*********************************/
void LCD_DISPIF_DOFFIF_Clr(void)
{
	LCD->DISPIF = LCD_DISPIF_DOFFIF_Msk;
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCDϨ���жϱ�־
����: ��
���: SET/RESET		LCDϨ���ж��ѷ���/δ����
*********************************/
FlagStatus LCD_DISPIF_DOFFIF_Chk(void)
{
	if (LCD->DISPIF & LCD_DISPIF_DOFFIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCDƫ��
����: LCD_LCDSET_BIASMD_4BIAS/LCD_LCDSET_BIASMD_3BIAS	1/4bias / 1/3bias
���: ��
*********************************/
void LCD_LCDSET_BIASMD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->LCDSET;
	tmpreg &= ~(LCD_LCDSET_BIASMD_Msk);
	tmpreg |= (SetValue & LCD_LCDSET_BIASMD_Msk);
	LCD->LCDSET = tmpreg;
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCDƫ��
����: ��
���: LCD_LCDSET_BIASMD_4BIAS/LCD_LCDSET_BIASMD_3BIAS	1/4bias / 1/3bias
*********************************/
uint32_t LCD_LCDSET_BIASMD_Get(void)
{
	return (LCD->LCDSET & LCD_LCDSET_BIASMD_Msk);
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD��������
����: LCD_LCDSET_WFT_ATYPE/LCD_LCDSET_WFT_BTYPE		A�ನ�� / B�ನ��
���: ��
*********************************/
void LCD_LCDSET_WFT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->LCDSET;
	tmpreg &= ~(LCD_LCDSET_WFT_Msk);
	tmpreg |= (SetValue & LCD_LCDSET_WFT_Msk);
	LCD->LCDSET = tmpreg;
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD��������
����: ��
���: LCD_LCDSET_WFT_ATYPE/LCD_LCDSET_WFT_BTYPE		A�ನ�� / B�ನ��
*********************************/
uint32_t LCD_LCDSET_WFT_Get(void)
{
	return (LCD->LCDSET & LCD_LCDSET_WFT_Msk);
}


/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD dutyֵ
����: LCD_LCDSET_LMUX_4COM/LCD_LCDSET_LMUX_6COM/LCD_LCDSET_LMUX_8COM	4com/6com/8com
���: ��
*********************************/
void LCD_LCDSET_LMUX_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->LCDSET;
	tmpreg &= ~(LCD_LCDSET_LMUX_Msk);
	tmpreg |= (SetValue & LCD_LCDSET_LMUX_Msk);
	LCD->LCDSET = tmpreg;
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD dutyֵ
����: ��
���: LCD_LCDSET_LMUX_4COM/LCD_LCDSET_LMUX_6COM/LCD_LCDSET_LMUX_8COM	4com/6com/8com
*********************************/
uint32_t LCD_LCDSET_LMUX_Get(void)
{
	return (LCD->LCDSET & LCD_LCDSET_LMUX_Msk);
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD SCƵ��ֵ
����: 	LCD_LCDDRV_SCFSEL_X1		Ƶ��Ϊdisp_clk/1
	LCD_LCDDRV_SCFSEL_X8		Ƶ��Ϊdisp_clk/8
	LCD_LCDDRV_SCFSEL_X16		Ƶ��Ϊdisp_clk/16
	LCD_LCDDRV_SCFSEL_X32		Ƶ��Ϊdisp_clk/32
	LCD_LCDDRV_SCFSEL_X64		Ƶ��Ϊdisp_clk/64
	LCD_LCDDRV_SCFSEL_X128		Ƶ��Ϊdisp_clk/128
	LCD_LCDDRV_SCFSEL_X256		Ƶ��Ϊdisp_clk/256
	LCD_LCDDRV_SCFSEL_X512		Ƶ��Ϊdisp_clk/512
���: ��
*********************************/
void LCD_LCDDRV_SCFSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->LCDDRV;
	tmpreg &= ~(LCD_LCDDRV_SCFSEL_Msk);
	tmpreg |= (SetValue & LCD_LCDDRV_SCFSEL_Msk);
	LCD->LCDDRV = tmpreg;
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD SCƵ��ֵ
����: ��
���: 	LCD_LCDDRV_SCFSEL_X1		Ƶ��Ϊdisp_clk/1
	LCD_LCDDRV_SCFSEL_X8		Ƶ��Ϊdisp_clk/8
	LCD_LCDDRV_SCFSEL_X16		Ƶ��Ϊdisp_clk/16
	LCD_LCDDRV_SCFSEL_X32		Ƶ��Ϊdisp_clk/32
	LCD_LCDDRV_SCFSEL_X64		Ƶ��Ϊdisp_clk/64
	LCD_LCDDRV_SCFSEL_X128		Ƶ��Ϊdisp_clk/128
	LCD_LCDDRV_SCFSEL_X256		Ƶ��Ϊdisp_clk/256
	LCD_LCDDRV_SCFSEL_X512		Ƶ��Ϊdisp_clk/512
*********************************/
uint32_t LCD_LCDDRV_SCFSEL_Get(void)
{
	return (LCD->LCDDRV & LCD_LCDDRV_SCFSEL_Msk);
}


/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD ������ʽ����(Ƭ���������ģʽ��)
����: 	LCD_LCDDRV_SC_CTRL_ONE		��������
	LCD_LCDDRV_SC_CTRL_TWO		������������
	LCD_LCDDRV_SC_CTRL_FOUR		���������Ĵ�(��SC>4HKzʱ����ѡ��ҲΪ��������)
	LCD_LCDDRV_SC_CTRL_CONTINUE	��������
���: ��
*********************************/
void LCD_LCDDRV_SC_CTRL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->LCDDRV;
	tmpreg &= ~(LCD_LCDDRV_SC_CTRL_Msk);
	tmpreg |= (SetValue & LCD_LCDDRV_SC_CTRL_Msk);
	LCD->LCDDRV = tmpreg;
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD ������ʽ����(Ƭ���������ģʽ��)
����: ��
���: 	LCD_LCDDRV_SC_CTRL_ONE		��������
	LCD_LCDDRV_SC_CTRL_TWO		������������
	LCD_LCDDRV_SC_CTRL_FOUR		���������Ĵ�(��SC>4HKzʱ����ѡ��ҲΪ��������)
	LCD_LCDDRV_SC_CTRL_CONTINUE	��������
*********************************/
uint32_t LCD_LCDDRV_SC_CTRL_Get(void)
{
	return (LCD->LCDDRV & LCD_LCDDRV_SC_CTRL_Msk);
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD ��������
����: 	LCD_LCDDRV_IC_CTRL_L3		�����������
	LCD_LCDDRV_IC_CTRL_L2		���������δ�
	LCD_LCDDRV_IC_CTRL_L1		����������С
	LCD_LCDDRV_IC_CTRL_L0		����������С
���: ��
*********************************/
void LCD_LCDDRV_IC_CTRL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->LCDDRV;
	tmpreg &= ~(LCD_LCDDRV_IC_CTRL_Msk);
	tmpreg |= (SetValue & LCD_LCDDRV_IC_CTRL_Msk);
	LCD->LCDDRV = tmpreg;
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD ��������
����: ��
���: 	LCD_LCDDRV_IC_CTRL_L3		�����������
	LCD_LCDDRV_IC_CTRL_L2		���������δ�
	LCD_LCDDRV_IC_CTRL_L1		����������С
	LCD_LCDDRV_IC_CTRL_L0		����������С
*********************************/
uint32_t LCD_LCDDRV_IC_CTRL_Get(void)
{
	return (LCD->LCDDRV & LCD_LCDDRV_IC_CTRL_Msk);
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD ����ģʽ
����: 	LCD_LCDDRV_ENMODE_EXTERNALCAP		Ƭ���������
	LCD_LCDDRV_ENMODE_INNERRESISTER		Ƭ�ڵ�������
���: ��
*********************************/
void LCD_LCDDRV_ENMODE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->LCDDRV;
	tmpreg &= ~(LCD_LCDDRV_ENMODE_Msk);
	tmpreg |= (SetValue & LCD_LCDDRV_ENMODE_Msk);
	LCD->LCDDRV = tmpreg;
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD ����ģʽ
����: ��
���: 	LCD_LCDDRV_ENMODE_EXTERNALCAP		Ƭ���������
	LCD_LCDDRV_ENMODE_INNERRESISTER		Ƭ�ڵ�������
*********************************/
uint32_t LCD_LCDDRV_ENMODE_Get(void)
{
	return (LCD->LCDDRV & LCD_LCDDRV_ENMODE_Msk);
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD ƫ�õ�ƽѡ��(�Ҷ�)
����: 	00-0F
���: ��
*********************************/
void LCD_LCDBIAS_Write(uint32_t SetValue)
{
	LCD->LCDBIAS = (SetValue & LCD_LCDBIAS_LCDBIAS_Msk);
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD ƫ�õ�ƽѡ��(�Ҷ�)
����: ��
���: 	00-0F
*********************************/
uint32_t LCD_LCDBIAS_Read(void)
{
	return (LCD->LCDBIAS & LCD_LCDBIAS_LCDBIAS_Msk);
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD BOOST����Ƶ�������ź�
����: 	LCD_LCDBSTCON_OSC_CFG_GRADE0		0�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE1		1�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE2		2�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE3		3�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE4		4�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE5		5�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE6		6�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE7		7�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE8		8�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	
���: ��
*********************************/
void LCD_LCDBSTCON_OSC_CFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->LCDBSTCON;
	tmpreg &= ~(LCD_LCDBSTCON_OSC_CFG_Msk);
	tmpreg |= (SetValue & LCD_LCDBSTCON_OSC_CFG_Msk);
	LCD->LCDBSTCON = tmpreg;
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD BOOST����Ƶ�������ź�
����: ��
���: 	LCD_LCDBSTCON_OSC_CFG_GRADE0		0�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE1		1�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE2		2�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE3		3�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE4		4�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE5		5�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE6		6�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE7		7�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
	LCD_LCDBSTCON_OSC_CFG_GRADE8		8�� ֵԽ��Ƶ��Խ�ߣ�����Խǿ������Խ��
*********************************/
uint32_t LCD_LCDBSTCON_OSC_CFG_Get(void)
{
	return (LCD->LCDBSTCON & LCD_LCDBSTCON_OSC_CFG_Msk);
}


/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD ��׼ԴBufferʹ�ܿ���
����: ENABLE/DISABLE	ʹ�ܻ�׼Դ/��ֹ
���: ��
*********************************/
void LCD_LCDBSTCON_BUFENB_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->LCDBSTCON &= ~(LCD_LCDBSTCON_BUFENB_Msk);
	}
	else
	{
		LCD->LCDBSTCON |= (LCD_LCDBSTCON_BUFENB_Msk);
	}
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD ��׼ԴBufferʹ�ܿ���
����: ��
���: ENABLE/DISABLE	ʹ�ܻ�׼Դ/��ֹ
*********************************/
FunState LCD_LCDBSTCON_BUFENB_Getable(void)
{
	if (LCD->LCDBSTCON & (LCD_LCDBSTCON_BUFENB_Msk))
	{
		return DISABLE;
	}
	else
	{
		return ENABLE;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD ��׼ԴBuffer��·����
����: ENABLE/DISABLE	ʹ�ܻ�׼Դ��·/��ֹ
���: ��
*********************************/
void LCD_LCDBSTCON_BUFBYP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->LCDBSTCON |= (LCD_LCDBSTCON_BUFBYP_Msk);
	}
	else
	{
		LCD->LCDBSTCON &= ~(LCD_LCDBSTCON_BUFBYP_Msk);
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD ��׼ԴBuffer��·����
����: ��
���: ENABLE/DISABLE	ʹ�ܻ�׼Դ��·/��ֹ
*********************************/
FunState LCD_LCDBSTCON_BUFBYP_Getable(void)
{
	if (LCD->LCDBSTCON & (LCD_LCDBSTCON_BUFBYP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD VLCD����
����: ENABLE/DISABLE	ʹ��VLCD����/��ֹ
���: ��
*********************************/
void LCD_LCDBSTCON_VLCDPD_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->LCDBSTCON |= (LCD_LCDBSTCON_VLCDPD_Msk);
	}
	else
	{
		LCD->LCDBSTCON &= ~(LCD_LCDBSTCON_VLCDPD_Msk);
	}
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD VLCD����״̬
����: ��
���: ENABLE/DISABLE	ʹ��VLCD����/��ֹ
*********************************/
FunState LCD_LCDBSTCON_VLCDPD_Getable(void)
{
	if (LCD->LCDBSTCON & (LCD_LCDBSTCON_VLCDPD_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD VLCD�����ѹ
����: 	LCD_LCDBSTCON_VLCDCFG_2P5V		VLCD = 2.5V
	LCD_LCDBSTCON_VLCDCFG_3P0V		VLCD = 3.0V
	LCD_LCDBSTCON_VLCDCFG_3P5V		VLCD = 3.5V
	LCD_LCDBSTCON_VLCDCFG_4P0V		VLCD = 4.0V
	LCD_LCDBSTCON_VLCDCFG_4P5V		VLCD = 4.5V
	LCD_LCDBSTCON_VLCDCFG_5P0V		VLCD = 5.0V
	LCD_LCDBSTCON_VLCDCFG_5P5V		VLCD = 5.5V
	
���: ��
*********************************/
void LCD_LCDBSTCON_VLCDCFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->LCDBSTCON;
	tmpreg &= ~(LCD_LCDBSTCON_VLCDCFG_Msk);
	tmpreg |= (SetValue & LCD_LCDBSTCON_VLCDCFG_Msk);
	LCD->LCDBSTCON = tmpreg;
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD VLCD�����ѹ
����: ��
���: 	LCD_LCDBSTCON_VLCDCFG_2P5V		VLCD = 2.5V
	LCD_LCDBSTCON_VLCDCFG_3P0V		VLCD = 3.0V
	LCD_LCDBSTCON_VLCDCFG_3P5V		VLCD = 3.5V
	LCD_LCDBSTCON_VLCDCFG_4P0V		VLCD = 4.0V
	LCD_LCDBSTCON_VLCDCFG_4P5V		VLCD = 4.5V
	LCD_LCDBSTCON_VLCDCFG_5P0V		VLCD = 5.0V
	LCD_LCDBSTCON_VLCDCFG_5P5V		VLCD = 5.5V	
*********************************/
uint32_t LCD_LCDBSTCON_VLCDCFG_Get(void)
{
	return (LCD->LCDBSTCON & LCD_LCDBSTCON_VLCDCFG_Msk);
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD Booster�����ź�
����: ENABLE/DISABLE	Booster�����ź�ʹ��/��ֹ
���: ��
*********************************/
void LCD_LCDBSTCON_BOOST_TEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->LCDBSTCON |= (LCD_LCDBSTCON_BOOST_TEN_Msk);
	}
	else
	{
		LCD->LCDBSTCON &= ~(LCD_LCDBSTCON_BOOST_TEN_Msk);
	}
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD Booster�����ź�״̬
����: ��
���:  ENABLE/DISABLE	Booster�����ź�ʹ��/��ֹ
*********************************/
FunState LCD_LCDBSTCON_BOOST_TEN_Getable(void)
{
	if (LCD->LCDBSTCON & (LCD_LCDBSTCON_BOOST_TEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD Boosterʹ�ܿ���
����: ENABLE/DISABLE	Boosterʹ��/��ֹ
���: ��
*********************************/
void LCD_LCDBSTCON_BOOST_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->LCDBSTCON |= (LCD_LCDBSTCON_BOOST_EN_Msk);
	}
	else
	{
		LCD->LCDBSTCON &= ~(LCD_LCDBSTCON_BOOST_EN_Msk);
	}
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD Boosterʹ��״̬
����: ��
���:  ENABLE/DISABLE	Boosterʹ��/��ֹ
*********************************/
FunState LCD_LCDBSTCON_BOOST_EN_Getable(void)
{
	if (LCD->LCDBSTCON & (LCD_LCDBSTCON_BOOST_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD COM0~3���ʹ�ܿ���
����: 00-0F COM0-COM3
���: ��
*********************************/
void LCD_COM_EN_Write(uint32_t SetValue)
{
	LCD->COM_EN = (SetValue & LCD_COM_EN_COMEN_Msk);
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD COM0~3���ʹ��״̬
����: ��
���: 00-0F COM0-COM3
*********************************/
uint32_t LCD_COM_EN_Read(void)
{
	return (LCD->COM_EN & LCD_COM_EN_COMEN_Msk);
}


/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD SEG0-31���ʹ�ܿ���
����: 00000000-ffffffff	SEG0-SEG31
���: ��
*********************************/
void LCD_SEG_EN0_Write(uint32_t SetValue)
{
	LCD->SEG_EN0 = (SetValue);
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD SEG0-31���ʹ��״̬
����: ��
���: 00000000-ffffffff	SEG0-SEG31
*********************************/
uint32_t LCD_SEG_EN0_Read(void)
{
	return (LCD->SEG_EN0);
}

/*********************************
LCD ��ʾ���ƺ��� 
���ܣ�����LCD SEG32~43(COM4-7)���ʹ�ܿ���
����: 00000000-00000fff	SEG32~43(COM4-7)
���: ��
*********************************/
void LCD_SEG_EN1_Write(uint32_t SetValue)
{
	LCD->SEG_EN1 = (SetValue & LCD_SEG_EN1_SEGENx_Msk);
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ���ȡLCD SEG32~43(COM4-7)���ʹ��״̬
����: ��
���: 00000000-00000fff	SEG32~43(COM4-7)
*********************************/
uint32_t LCD_SEG_EN1_Read(void)
{
	return (LCD->SEG_EN1 & LCD_SEG_EN1_SEGENx_Msk);
}
/*********************************
LCD ��ʾ���ƺ��� 
���ܣ��ر�����LCD(ȱʡ)
����: ��
���: ��
*********************************/
void LCD_Deinit(void)
{
	LCD->DISPCTRL = 0x00000000;
	LCD->LCDTEST = 0x00000000;
	LCD->DF = 0x00000000;
	LCD->TON = 0x00000000;
	LCD->TOFF = 0x00000000;
	LCD->DISPIE = 0x00000000;
	LCD->DISPIF = 0x00000000;
	LCD->LCDSET = 0x00000000;
	LCD->LCDDRV = 0x00000002;
	LCD->LCDBIAS = 0x0000000E;
	LCD->LCDBSTCON = 0x00000000;
	LCD->COM_EN = 0x00000000;
	LCD->SEG_EN0 = 0x00000000;
	LCD->SEG_EN1 = 0x00000000;
}
//Code_End

/*DISPDATAx��ʾ���ݼĴ���ˢ��*/
void LCD_DISPDATAx_Refresh(uint32_t* DispBuf)
{
    LCD->DISPDATA0 = DispBuf[0];
    LCD->DISPDATA1 = DispBuf[1];
    LCD->DISPDATA2 = DispBuf[2];
    LCD->DISPDATA3 = DispBuf[3];
    LCD->DISPDATA4 = DispBuf[4];
    LCD->DISPDATA5 = DispBuf[5];
    LCD->DISPDATA6 = DispBuf[6];
    LCD->DISPDATA7 = DispBuf[7];
    LCD->DISPDATA8 = DispBuf[8];
    LCD->DISPDATA9 = DispBuf[9];
}

/*lcd boost��������*/
void LCD_Boost_Init(LCD_Boost_InitTypeDef* para)
{
	LCD_LCDBSTCON_OSC_CFG_Set(para->OSC_CFG);
	LCD_LCDBSTCON_VLCDCFG_Set(para->VLCDCFG);
	LCD_LCDBSTCON_BUFENB_Setable(para->BUFENB);
	LCD_LCDBSTCON_BUFBYP_Setable(para->BUFBYP);
	LCD_LCDBSTCON_VLCDPD_Setable(para->VLCDPD);	
	LCD_LCDBSTCON_BOOST_TEN_Setable(para->BOOST_TEN);
	LCD_LCDBSTCON_BOOST_EN_Setable(para->BOOST_EN);
}

/*LCD��ʾ��������*/
void LCD_Init(LCD_InitTypeDef* para)
{
	LCD_LCDSET_LMUX_Set(para->LMUX);
	LCD_LCDDRV_ENMODE_Set(para->ENMODE);
	LCD_LCDSET_WFT_Set(para->WFT);
	LCD_DF_Write(para->DF);
	LCD_LCDSET_BIASMD_Set(para->BIASMD);
	LCD_LCDDRV_SCFSEL_Set(para->SCFSEL);
	LCD_LCDDRV_SC_CTRL_Set(para->SC_CTRL);
	LCD_LCDDRV_IC_CTRL_Set(para->IC_CTRL);	
	LCD_LCDBIAS_Write(para->LCDBIAS);
	LCD_DISPCTRL_ANTIPOLAR_Setable(para->ANTIPOLAR);
	
	LCD_DISPCTRL_TEST_Setable(para->TEST);
	LCD_DISPCTRL_DISPMD_Setable(para->DISPMD);

	LCD_LCDTEST_LCCTRL_Set(para->LCCTRL);
	LCD_LCDTEST_TESTEN_Setable(para->TESTEN);
	
	LCD_DISPCTRL_FLICK_Setable(para->FLICK);	
	LCD_TON_Write(para->TON);
	LCD_TOFF_Write(para->TOFF);
	LCD_DISPIE_DONIE_Setable(para->DONIE);
	LCD_DISPIE_DOFFIE_Setable(para->DOFFIE);
	LCD_DISPIF_DONIF_Clr();
	LCD_DISPIF_DOFFIF_Clr();
	
	LCD_DISPCTRL_LCDEN_Setable(para->LCDEN);	
}


