/**
  ******************************************************************************
  * @file    fm33a0xx_i2c.c
  * @author  FM33a0xx Application Team
  * @version V2.0.2
  * @date    18-1-2018
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/
/* Includes ------------------------------------------------------------------*/

#include "fm33a0xx_i2c.h" 
#include <string.h>
/** @addtogroup fm33a0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup I2C 
  * @brief I2C driver modules
  * @{
  */ 

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

 //Code_Start
//2018-04-02-13-21-22
//FM33A0XX_Driver_Gen_V1.4

/********************************
 I2Cģ���ֹʱ��SCL�̶�Ϊ�ߵ͵�ƽ����λ����
���ܣ�I2Cģ���ֹʱ������SCL�̶�Ϊ�ߵ͵�ƽ����λ
���룺����SCL�̶�Ϊ�ߵ͵�ƽ����λ
1 = ��SCL�ź�ת��Ϊ�ߵ�ƽ����Ǳ�Ҫ�����鳣̬��Ϊ1
0 = ��SCL�ź�ת��Ϊ�͵�ƽ
********************************/
void I2C_I2CCTRL_SCLHL_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->I2CCTRL |= (I2C_I2CCTRL_SCLHL_Msk);
	}
	else
	{
		I2C->I2CCTRL &= ~(I2C_I2CCTRL_SCLHL_Msk);
	}
}
/********************************
��ȡSCL�̶�Ϊ�ߵ͵�ƽ����λ����
���ܣ���ȡSCL�̶�Ϊ�ߵ͵�ƽ����λ������
�����SCL�̶�Ϊ�ߵ͵�ƽ����λ������
1 = ��SCL�ź�ת��Ϊ�ߵ�ƽ����Ǳ�Ҫ�����鳣̬��Ϊ1
0 = ��SCL�ź�ת��Ϊ�͵�ƽ
********************************/
FunState I2C_I2CCTRL_SCLHL_Getable(void)
{
	if (I2C->I2CCTRL & (I2C_I2CCTRL_SCLHL_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
 I2Cģ���ֹʱ��SDA�̶�Ϊ�ߵ͵�ƽ����λ����
���ܣ�I2Cģ���ֹʱ������SDA�̶�Ϊ�ߵ͵�ƽ����λ
���룺����SDA�̶�Ϊ�ߵ͵�ƽ����λ
1 = ��SDA�ź�ת��Ϊ�ߵ�ƽ����Ǳ�Ҫ�����鳣̬��Ϊ1
0 = ��SDA�ź�ת��Ϊ�͵�ƽ
********************************/
void I2C_I2CCTRL_SDAHL_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->I2CCTRL |= (I2C_I2CCTRL_SDAHL_Msk);
	}
	else
	{
		I2C->I2CCTRL &= ~(I2C_I2CCTRL_SDAHL_Msk);
	}
}
/********************************
��ȡSDA�̶�Ϊ�ߵ͵�ƽ����λ����
���ܣ���ȡSDA�̶�Ϊ�ߵ͵�ƽ����λ������
�����SDA�̶�Ϊ�ߵ͵�ƽ����λ������
1 = ��SDA�ź�ת��Ϊ�ߵ�ƽ����Ǳ�Ҫ�����鳣̬��Ϊ1
0 = ��SDA�ź�ת��Ϊ�͵�ƽ
********************************/
FunState I2C_I2CCTRL_SDAHL_Getable(void)
{
	if (I2C->I2CCTRL & (I2C_I2CCTRL_SDAHL_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
 ���ؽ���ģʽ�£��������ӻ���Ӧʹ��λ����
���ܣ����ؽ���ģʽ�£��������ӻ���Ӧʹ��λ
���룺�������ӻ���Ӧʹ��λ
1 = �������ͻ�ӦACKDT���ӻ�
0 = ��������Ӧ�ӻ�
********************************/
void I2C_I2CCTRL_ACKEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->I2CCTRL |= (I2C_I2CCTRL_ACKEN_Msk);
	}
	else
	{
		I2C->I2CCTRL &= ~(I2C_I2CCTRL_ACKEN_Msk);
	}
}
/********************************
 ���ؽ���ģʽ�£���ȡ�������ӻ���Ӧʹ��λ�ĺ���
���ܣ����ؽ���ģʽ�£���ȡ�������ӻ���Ӧʹ��λ
������������ӻ���Ӧʹ��λ
1 = �������ͻ�ӦACKDT���ӻ�
0 = ��������Ӧ�ӻ�
********************************/
FunState I2C_I2CCTRL_ACKEN_Getable(void)
{
	if (I2C->I2CCTRL & (I2C_I2CCTRL_ACKEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
 ���ؽ���ģʽ�£�����ʹ��λ���ú���
���ܣ����ؽ���ģʽ�£�����ʹ��λ���ú���
���룺����ʹ��λ����
1 = ��������ʹ��
0 = ���ս�ֹ
********************************/
void I2C_I2CCTRL_RCEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->I2CCTRL |= (I2C_I2CCTRL_RCEN_Msk);
	}
	else
	{
		I2C->I2CCTRL &= ~(I2C_I2CCTRL_RCEN_Msk);
	}
}
/********************************
 ���ؽ���ģʽ�£���ȡ����ʹ��λ���ú���
���ܣ����ؽ���ģʽ�£���ȡ����ʹ��λ���ú���
�������ȡ����ʹ��λ����
1 = ��������ʹ��
0 = ���ս�ֹ
********************************/
FunState I2C_I2CCTRL_RCEN_Getable(void)
{
	if (I2C->I2CCTRL & (I2C_I2CCTRL_RCEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
 STOPʱ�����ʹ�ܿ���λ���ú���
���ܣ�STOPʱ�����ʹ�ܿ���λ���ú���
���룺STOPʱ�����ʹ�ܿ���λ������
1 = STOPʱ�����ʹ��
0 = STOPʱ�������ֹ
********************************/
void I2C_I2CCTRL_PEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->I2CCTRL |= (I2C_I2CCTRL_PEN_Msk);
	}
	else
	{
		I2C->I2CCTRL &= ~(I2C_I2CCTRL_PEN_Msk);
	}
}
/********************************
 Repeated STARTʱ�����ʹ�ܿ���λ���ú���
���ܣ�Repeated STARTʱ�����ʹ�ܿ���λ���ú���
���룺Repeated STARTʱ�����ʹ�ܿ���λ������
1 = Repeated STARTʱ�����ʹ��
0 = Repeated STARTʱ�������ֹ
********************************/
void I2C_I2CCTRL_RSEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->I2CCTRL |= (I2C_I2CCTRL_RSEN_Msk);
	}
	else
	{
		I2C->I2CCTRL &= ~(I2C_I2CCTRL_RSEN_Msk);
	}
}

/********************************
 STARTʱ�����ʹ�ܿ���λ���ú���
���ܣ�STARTʱ�����ʹ�ܿ���λ���ú���
���룺STARTʱ�����ʹ�ܿ���λ������
1 = STARTʱ�����ʹ��
0 = STARTʱ�������ֹ
********************************/
void I2C_I2CCTRL_SEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->I2CCTRL |= (I2C_I2CCTRL_SEN_Msk);
	}
	else
	{
		I2C->I2CCTRL &= ~(I2C_I2CCTRL_SEN_Msk);
	}
}

/********************************
 I2Cģ��ʹ�ܿ���λ���ú���
���ܣ�I2Cģ��ʹ�ܿ���λ���ú���
���룺I2Cģ��ʹ�ܿ���λ������
1 = I2Cʹ��
0 = I2C��ֹ
********************************/
void I2C_I2CCTRL_I2CEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->I2CCTRL |= (I2C_I2CCTRL_I2CEN_Msk);
	}
	else
	{
		I2C->I2CCTRL &= ~(I2C_I2CCTRL_I2CEN_Msk);
	}
}
/********************************
 ��ȡI2Cģ��ʹ�ܿ���λ���ú���
���ܣ���ȡI2Cģ��ʹ�ܿ���λ���ú���
�����I2Cģ��ʹ�ܿ���λ������
1 = I2Cʹ��
0 = I2C��ֹ
********************************/
FunState I2C_I2CCTRL_I2CEN_Getable(void)
{
	if (I2C->I2CCTRL & (I2C_I2CCTRL_I2CEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
 ���д��ͻ���λ�ĺ���
���ܣ����д��ͻ���λ
********************************/
void I2C_I2CSTA_WCOL_Clr(void)
{
	I2C->I2CSTA = I2C_I2CSTA_WCOL_Msk;
}

/********************************
 ��ȡд��ͻ���λ�ĺ���
���ܣ���ȡд��ͻ���λ
�����д��ͻ���λ
1 = ����д��ͻ
0 = δ������ͻ��
********************************/
FlagStatus I2C_I2CSTA_WCOL_Chk(void)
{
	if (I2C->I2CSTA & I2C_I2CSTA_WCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
 ��ȡI2C�ӿ�״̬λ�ĺ���
���ܣ���ȡI2C�ӿ�״̬
�����I2C�ӿ�״̬
1 = �ӿڴ��ڶ�д״̬�����ڽ������ݴ��䣬
0 = ��������ݴ���
********************************/
FlagStatus I2C_I2CSTA_RW_Chk(void)
{
	if (I2C->I2CSTA & I2C_I2CSTA_RW_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
 ��ȡ STOP��־λ�ĺ���
���ܣ���ȡ STOP��־λ
�����STOP��־λ
1 = ��⵽STOPʱ��
0 = δ��⵽STOPʱ��
********************************/
FlagStatus I2C_I2CSTA_P_Chk(void)
{
	if (I2C->I2CSTA & I2C_I2CSTA_P_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


/********************************
 ��ȡ START��־λ�ĺ���
���ܣ���ȡ START��־λ
�����START��־λ
1 = ��⵽STARTʱ��
0 = δ��⵽STARTʱ��
********************************/
FlagStatus I2C_I2CSTA_S_Chk(void)
{
	if (I2C->I2CSTA & I2C_I2CSTA_S_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
 ��ȡ ��������״̬λ�ĺ���
���ܣ���ȡ ��������״̬λ
�������������״̬λ
���գ�
1 = ������ɣ�SSPBUF��
0 = ����δ��ɣ�SSPBUF��
���ͣ�
1 = ���ڷ��ͣ�SSPBUF��
0 = ������ɣ�SSPBUF��
********************************/
FlagStatus I2C_I2CSTA_BF_Chk(void)
{
	if (I2C->I2CSTA & I2C_I2CSTA_BF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
 ������Դӻ��Ļ�Ӧ�źŵĺ���
���ܣ�������Դӻ��Ļ�Ӧ�ź�
********************************/
void I2C_I2CSTA_ACKSTA_Clr(void)
{
	I2C->I2CSTA = I2C_I2CSTA_ACKSTA_Msk;
}
/********************************
 ��ȡ ���Դӻ��Ļ�Ӧ�źŵĺ���
���ܣ���ȡ ���Դӻ��Ļ�Ӧ�ź�
��������Դӻ��Ļ�Ӧ�ź�
1 = �ӻ��޻�Ӧ
0 = ���յ��ӻ��Ļ�Ӧ0
********************************/
FlagStatus I2C_I2CSTA_ACKSTA_Chk(void)
{
	if (I2C->I2CSTA & I2C_I2CSTA_ACKSTA_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
 ������Ӧ�źŵ�״̬���ú���
���ܣ�������Ӧ�źŵ�״̬���ú���
���룺������Ӧ�źŵ�״̬������
1 = �����������ӻ���Ӧ
0 = ���������ӻ��Ļ�ӦΪ0
********************************/
void I2C_I2CSTA_ACKDT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = I2C->I2CSTA;
	tmpreg &= ~(I2C_I2CSTA_ACKDT_Msk);
	tmpreg |= (SetValue & I2C_I2CSTA_ACKDT_Msk);
	I2C->I2CSTA = tmpreg;
}
/********************************
 ��ȡ������Ӧ�źŵ�״̬���ú���
���ܣ���ȡ������Ӧ�źŵ�״̬���ú���
�����������Ӧ�źŵ�״̬������
1 = �����������ӻ���Ӧ
0 = ���������ӻ��Ļ�ӦΪ0
********************************/
uint32_t I2C_I2CSTA_ACKDT_Get(void)
{
	return (I2C->I2CSTA & I2C_I2CSTA_ACKDT_Msk);
}

/********************************
 ���������ú���
���ܣ����������ú���
���룺�����ʵ�����
SCL�����ʷ�Ƶ����
********************************/
void I2C_I2CBRG_Write(uint32_t SetValue)
{
	I2C->I2CBRG = (SetValue & I2C_I2CBRG_SSPBRG_Msk);
}
/********************************
 ��ȡ�����ʺ���
���ܣ���ȡ�����ʺ���
�����������
********************************/
uint32_t I2C_I2CBRG_Read(void)
{
	return (I2C->I2CBRG & I2C_I2CBRG_SSPBRG_Msk);
}

/********************************
 д�շ�����Ĵ�������
���ܣ� д�շ�����Ĵ���
���룺 Ҫд�շ�����Ĵ�����ֵ
********************************/
void I2C_I2CBUF_Write(uint32_t SetValue)
{
	I2C->I2CBUF = (SetValue & I2C_I2CBUF_SSPBUF_Msk);
}
/********************************
 ���շ�����Ĵ�������
���ܣ� ���շ�����Ĵ���
����� �շ�����Ĵ�����ֵ
********************************/
uint32_t I2C_I2CBUF_Read(void)
{
	return (I2C->I2CBUF & I2C_I2CBUF_SSPBUF_Msk);
}

/********************************
 I2C�ж�ʹ�ܿ���λ���ú���
���ܣ�I2C�ж�ʹ�ܿ���λ����
���룺I2C�ж�ʹ�ܿ���λ
1 = I2C�ж�ʹ��
0 = I2C�жϽ�ֹ
********************************/
void I2C_I2CIR_I2CIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->I2CIR |= (I2C_I2CIR_I2CIE_Msk);
	}
	else
	{
		I2C->I2CIR &= ~(I2C_I2CIR_I2CIE_Msk);
	}
}
/********************************
 ��ȡI2C�ж�ʹ�ܿ���λ���ú���
���ܣ���ȡI2C�ж�ʹ�ܿ���λ����
�����I2C�ж�ʹ�ܿ���λ
1 = I2C�ж�ʹ��
0 = I2C�жϽ�ֹ
********************************/
FunState I2C_I2CIR_I2CIE_Getable(void)
{
	if (I2C->I2CIR & (I2C_I2CIR_I2CIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/********************************
 ���I2C�жϱ�־λ�ĺ���
���ܣ����I2C�жϱ�־λ
********************************/
void I2C_I2CIR_I2CIF_Clr(void)
{
	if (I2C->I2CIR & (I2C_I2CIR_I2CIE_Msk))
	{
		I2C->I2CIR = (I2C_I2CIR_I2CIE_Msk|I2C_I2CIR_I2CIF_Msk);
	}
	else
	{
		I2C->I2CIR = I2C_I2CIR_I2CIF_Msk;
	}
}
/********************************
 ��ȡI2C�жϱ�־λ�ĺ���
���ܣ���ȡI2C�жϱ�־λ
�����I2C�жϱ�־λ
1 = ����I2C�ж�
0 = δ����I2C�ж�
********************************/
FlagStatus I2C_I2CIR_I2CIF_Chk(void)
{
	if (I2C->I2CIR & I2C_I2CIR_I2CIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
 ��ȡI2C��״̬������ĺ���
���ܣ���ȡI2C��״̬������
�����I2C��״̬������
********************************/
uint32_t I2C_I2CFSM_I2CFSM_Get(void)
{
	return (I2C->I2CFSM & I2C_I2CFSM_I2CFSM_Msk);
}

/********************************
 �����־�ж�ʹ�����ú���
���ܣ������־�ж�ʹ������
���룺�����־�ж�ʹ��
1 = I2C�ж�ʹ��
0 = I2C�жϽ�ֹ
********************************/
void I2C_I2CERR_ERRIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->I2CERR |= (I2C_I2CERR_ERRIE_Msk);
	}
	else
	{
		I2C->I2CERR &= ~(I2C_I2CERR_ERRIE_Msk);
	}
}
/********************************
 ��ȡ�����־�ж�ʹ�����ú���
���ܣ���ȡ�����־�ж�ʹ������
����������־�ж�ʹ��
1 = I2C�ж�ʹ��
0 = I2C�жϽ�ֹ
********************************/
FunState I2C_I2CERR_ERRIE_Getable(void)
{
	if (I2C->I2CERR & (I2C_I2CERR_ERRIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/********************************
 ���OP_IDLE״̬�´����־λ�ĺ���
���ܣ����OP_IDLE״̬�´����־λ
********************************/
void I2C_I2CERR_OIERR_Clr(void)
{
	if (I2C->I2CERR & (I2C_I2CERR_ERRIE_Msk))
	{
		I2C->I2CERR = (I2C_I2CERR_ERRIE_Msk|I2C_I2CERR_OIERR_Msk);
	}
	else
	{
		I2C->I2CERR = I2C_I2CERR_OIERR_Msk;
	}
}
/********************************
 ��ȡOP_IDLE״̬�´����־λ�ĺ���
���ܣ���ȡOP_IDLE״̬�´����־λ
�����OP_IDLE״̬�´����־λ
********************************/
FlagStatus I2C_I2CERR_OIERR_Chk(void)
{
	if (I2C->I2CERR & I2C_I2CERR_OIERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
 ���START_DONE״̬�´����־λ�ĺ���
���ܣ����START_DONE״̬�´����־λ
********************************/
void I2C_I2CERR_SDERR_Clr(void)
{
	if (I2C->I2CERR & (I2C_I2CERR_ERRIE_Msk))
	{
		I2C->I2CERR = (I2C_I2CERR_ERRIE_Msk|I2C_I2CERR_SDERR_Msk);
	}
	else
	{
		I2C->I2CERR = I2C_I2CERR_SDERR_Msk;
	}
}
/********************************
 ��ȡSTART_DONE״̬�´����־λ�ĺ���
���ܣ���ȡSTART_DONE״̬�´����־λ
�����START_DONE״̬�´����־λ
********************************/
FlagStatus I2C_I2CERR_SDERR_Chk(void)
{
	if (I2C->I2CERR & I2C_I2CERR_SDERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
 ���IDLE״̬�´����־λ�ĺ���
���ܣ����IDLE״̬�´����־λ
********************************/
void I2C_I2CERR_IERR_Clr(void)
{
	if (I2C->I2CERR & (I2C_I2CERR_ERRIE_Msk))
	{
		I2C->I2CERR = (I2C_I2CERR_ERRIE_Msk|I2C_I2CERR_IERR_Msk);
	}
	else
	{
		I2C->I2CERR = I2C_I2CERR_IERR_Msk;
	}
}

/********************************
 ��ȡIDLE״̬�´����־λ�ĺ���
���ܣ���ȡIDLE״̬�´����־λ
�����IDLE״̬�´����־λ
********************************/
FlagStatus I2C_I2CERR_IERR_Chk(void)
{
	if (I2C->I2CERR & I2C_I2CERR_IERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
 I2Cȱʡ���õĺ���
���ܣ�I2Cȱʡ����
********************************/
void I2C_Deinit(void)
{
	I2C->I2CCTRL = 0x00006000;
	I2C->I2CSTA = 0x00000000;
	I2C->I2CBRG = 0x00000013;
	//I2C->I2CBUF = ;
	I2C->I2CIR = 0x00000000;
	//I2C->I2CFSM = ;
	I2C->I2CERR = 0x00000000;
}
//Code_End

/********************************
 I2C�����ʼĴ���ֵ���㺯��
���ܣ�I2C�����ʼĴ���ֵ����
���룺����������@Hz�� APBClk @Hz
�����I2CBRG��Ӧ���������ʵ�����ֵ
********************************/
uint32_t I2C_BaudREG_Calc(uint32_t I2CClk, uint32_t APBClk)
{
	uint32_t TempREG;
	
	TempREG = APBClk/(4*I2CClk);
	if( TempREG >= 1 ) TempREG = TempREG - 1;
	
	return TempREG;
}


/******END OF FILE****/
