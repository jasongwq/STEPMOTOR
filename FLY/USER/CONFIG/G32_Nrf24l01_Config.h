#ifndef _NRF24L01_CONFIG_H_
#define _NRF24L01_CONFIG_H_

/***24L01����***/
/*ʹ��Ӳ��SPI 1 or 2*/
//#define NRF24L01_SPI1
#define NRF24L01_SPI2
/*ʹ�����SPI*/
//#define NRF24L01_SPISOFT

/*����SPI_NRF_SPI��CE����*/
#define NRF24l01_CE_RCC  RCC_APB2Periph_GPIOB
#define NRF24l01_CE_GPIO GPIOB
#define NRF24l01_CE_PIN  GPIO_Pin_11
/*����SPI_NRF_SPI�� CSN ����*/
#define NRF24l01_CSN_RCC  RCC_APB2Periph_GPIOC
#define NRF24l01_CSN_GPIO GPIOC
#define NRF24l01_CSN_PIN  GPIO_Pin_6
/*����SPI_NRF_SPI��IRQ����*/
#define NRF24l01_IQR_RCC  RCC_APB2Periph_GPIOC
#define NRF24l01_IQR_GPIO GPIOC
#define NRF24l01_IQR_PIN  GPIO_Pin_7

#ifdef NRF24L01_SPISOFT
	/*����SPI_NRF_SPI�� MOSI ����*/
	#define NRF24l01_MOSI_RCC  RCC_APB2Periph_GPIOB
	#define NRF24l01_MOSI_GPIO GPIOB
	#define NRF24l01_MOSI_PIN  GPIO_Pin_15
	/*����SPI_NRF_SPI�� SIMO ����*/
	#define NRF24l01_SIMO_RCC  RCC_APB2Periph_GPIOB
	#define NRF24l01_SIMO_GPIO GPIOB
	#define NRF24l01_SIMO_PIN  GPIO_Pin_14
	/*����SPI_NRF_SPI�� SCL(SCK) ����*/
	#define NRF24l01_SCL_RCC   RCC_APB2Periph_GPIOB
	#define NRF24l01_SCL_GPIO  GPIOB
	#define NRF24l01_SCL_PIN   GPIO_Pin_13
#endif
/***24L01����***/

#endif
/*
�ڰ� �ư�
CE  PB11
CSN PC6
IRQ PC7
*/
