#ifndef __OURSTM400240_H_
#define __OURSTM400240_H_
//�������ʾ��
/****************************************/
/*** LCD ***/
#define LCD_CONGIG
//RST
#define RCC_LCD_RST     RCC_APB2Periph_GPIOE
#define LCD_RST_GPIO    GPIOE
#define LCD_RST_Pin     GPIO_Pin_6
//LIGHT
#define RCC_LCD_LIGHT   RCC_APB2Periph_GPIOC
#define LCD_LIGHT_GPIO  GPIOC
#define LCD_LIGHT_Pin   GPIO_Pin_0
#define LCD_LED_1       GPIO_SetBits(  LCD_LIGHT_GPIO,LCD_LIGHT_Pin);//������PCout(13) //LCD����             PD13 
#define LCD_LED_0       GPIO_ResetBits(LCD_LIGHT_GPIO,LCD_LIGHT_Pin);//

//RD
#define RCC_LCD_RD  RCC_APB2Periph_GPIOD
#define LCD_RD_GPIO GPIOD
#define LCD_RD_Pin  GPIO_Pin_4
//WR
#define RCC_LCD_WR  RCC_APB2Periph_GPIOD
#define LCD_WR_GPIO GPIOD
#define LCD_WR_Pin  GPIO_Pin_5
//CS
#define RCC_LCD_CS  RCC_APB2Periph_GPIOD
#define LCD_CS_GPIO GPIOD
#define LCD_CS_Pin  GPIO_Pin_7
//RS
#define RCC_LCD_RS  RCC_APB2Periph_GPIOD
#define LCD_RS_GPIO GPIOD
#define LCD_RS_Pin  GPIO_Pin_11
/*** LCD ***/
/****************************************/
/***TOUCH***/
#define LCD_TOUCH_SPI_SOFT 1
#define LCD_TOUCH_SPI_1    0
#define LCD_TOUCH_SPI_2    0

#define RCC_LCD_TOUCH_PEN  RCC_APB2Periph_GPIOC
#define LCD_TOUCH_PEN_GPIO GPIOC
#define LCD_TOUCH_PEN_Pin  GPIO_Pin_2

#define RCC_LCD_TOUCH_TCS  RCC_APB2Periph_GPIOC
#define LCD_TOUCH_TCS_GPIO GPIOC
#define LCD_TOUCH_TCS_Pin  GPIO_Pin_3
//�봥����оƬ��������
#define PEN     PCin(2)      //PF10 INT
#define TCS     PCout(3)     //PB2  CS

#if LCD_TOUCH_SPI_SOFT
#define RCC_LCD_TOUCH_MISO RCC_APB2Periph_GPIOB
#define LCD_TOUCH_MISO_GPIO GPIOB
#define LCD_TOUCH_MISO_Pin  GPIO_Pin_4

#define RCC_LCD_TOUCH_MOSI RCC_APB2Periph_GPIOB
#define LCD_TOUCH_MOSI_GPIO GPIOB
#define LCD_TOUCH_MOSI_Pin  GPIO_Pin_5

#define RCC_LCD_TOUCH_SCK RCC_APB2Periph_GPIOB
#define LCD_TOUCH_SCK_GPIO GPIOB
#define LCD_TOUCH_SCK_Pin  GPIO_Pin_3

//ģ��SPI����
#define DOUT    PBin (4)//PAin(6)     //PF8  MISO
#define TDIN    PBout(5)//PAout(7)    //PF9  MOSI
#define TCLK    PBout(3)//PAout(5)    //PB1  SCLK

#endif
#define LCD_TP_CONGIG
#define LCD_TP_xfac 0.065768
#define LCD_TP_yfac 0.089917
#define LCD_TP_xoff (-18)
#define LCD_TP_yoff (-10)
//Ĭ��Ϊtouchtype=0������.
#define LCD_TP_TOUCHTYPE 0
//�����Ĳ���,��������������������ȫ�ߵ�ʱ��Ҫ�õ�.
//touchtype=0��ʱ��,�ʺ�����ΪX����,����ΪY�����TP.
//touchtype=1��ʱ��,�ʺ�����ΪY����,����ΪX�����TP.
#if LCD_TP_TOUCHTYPE
#define LCD_TP_DEFCMD_RDX 0X90;
#define LCD_TP_DEFCMD_RDY 0XD0;
#else
#define LCD_TP_DEFCMD_RDX 0XD0;
#define LCD_TP_DEFCMD_RDY 0X90;
#endif

/***TOUCH***/
/****************************************/

#endif
