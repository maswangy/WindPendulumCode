#include "ADC.h"
#if __ADC_ENABLE
/***************************************************************************
�������ƣ�ADCKey_Init
�������ܣ�ADC���ܳ�ʼ��
������ע��
***************************************************************************/
void ADCKey_Init(void)
{
  GPIO_InitTypeDef      GPIO_InitStructure;
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	ADC_InitTypeDef       ADC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin     = GPIO_Pin_0;        //ͨ��10
	GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AN;      //ģ������
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_NOPULL;  //����
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC1,ENABLE);  //ADC1��λ
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC1,DISABLE); //��λ����
	
	ADC_TempSensorVrefintCmd(ENABLE);                    //ʹ���ڲ��¶ȴ�����
	
	ADC_CommonInitStructure.ADC_Mode             = ADC_Mode_Independent;         //����ģʽ
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles; //���������׶�����
	ADC_CommonInitStructure.ADC_DMAAccessMode    = ADC_DMAAccessMode_Disabled;   //DMAʧ��
	ADC_CommonInitStructure.ADC_Prescaler        = ADC_Prescaler_Div4;           //4��Ƶ��36MHz
	ADC_CommonInit(&ADC_CommonInitStructure);
	
	ADC_InitStructure.ADC_Resolution           = ADC_Resolution_12b;             //12Bģʽ
	ADC_InitStructure.ADC_ScanConvMode         = ENABLE;                         //ɨ�裺��
	ADC_InitStructure.ADC_ContinuousConvMode   = ENABLE;                         //����ת������
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;  //������⣺��
	ADC_InitStructure.ADC_DataAlign            = ADC_DataAlign_Right;            //���룺��
	ADC_InitStructure.ADC_NbrOfConversion      = 2;                              //1��ת���ڹ���������
	ADC_Init(ADC1,&ADC_InitStructure);
	
	/* ADC1 regular channel10 configuration ------------------------------------*/
	ADC_RegularChannelConfig(ADC1,ADC_Channel_10,1,ADC_SampleTime_480Cycles);	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_16, 2, ADC_SampleTime_480Cycles );	//ADC16,ADCͨ��,480������,��߲���ʱ�������߾�ȷ��	
	
	
	ADC_DMARequestAfterLastTransferCmd(ADC1,ENABLE);                             //Դ���ݱ仯ʱ����DMA����
	
	ADC_DMACmd(ADC1,ENABLE);
	
	ADC_Cmd(ADC1,ENABLE);
}

/***************************************************************************
�������ƣ�ADCKey_Init
�������ܣ�ADC���ܳ�ʼ��
������ע��
***************************************************************************/
void ADCTem_Init(void)
{
  GPIO_InitTypeDef      GPIO_InitStructure;
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	ADC_InitTypeDef       ADC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin     = GPIO_Pin_6;        //ͨ��6
	GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AN;      //ģ������
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_NOPULL;  //����
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC1,ENABLE);  //ADC1��λ
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC1,DISABLE); //��λ����
	
  ADC_TempSensorVrefintCmd(ENABLE);                    //ʹ���ڲ��¶ȴ�����
	
	ADC_CommonInitStructure.ADC_Mode             = ADC_Mode_Independent;         //����ģʽ
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles; //���������׶�����
	ADC_CommonInitStructure.ADC_DMAAccessMode    = ADC_DMAAccessMode_Disabled;   //DMAʧ��
	ADC_CommonInitStructure.ADC_Prescaler        = ADC_Prescaler_Div4;           //4��Ƶ��36MHz
	ADC_CommonInit(&ADC_CommonInitStructure);
	
	ADC_InitStructure.ADC_Resolution           = ADC_Resolution_12b;             //12Bģʽ
	ADC_InitStructure.ADC_ScanConvMode         = DISABLE;                        //ɨ�裺��
	ADC_InitStructure.ADC_ContinuousConvMode   = DISABLE;                        //����ת������
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;  //������⣺��
	ADC_InitStructure.ADC_DataAlign            = ADC_DataAlign_Right;            //���룺��
	ADC_InitStructure.ADC_NbrOfConversion      = 2;                              //2��ת���ڹ���������
	ADC_Init(ADC1,&ADC_InitStructure);
	
	/* ADC1 regular channel10 configuration ------------------------------------*/
	ADC_RegularChannelConfig(ADC1,ADC_Channel_6,1,ADC_SampleTime_480Cycles);
	
	ADC_Cmd(ADC1,ENABLE);
}
/***************************************************************************
�������ƣ�
�������ܣ�
������ע��
***************************************************************************/









#endif  //__ADC_ENABLE
