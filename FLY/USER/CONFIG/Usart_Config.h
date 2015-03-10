#ifndef __USART_CONFIG_
#define __USART_CONFIG_
/****************************************/
/***USART***/
/********************************************
REMAP |  00      |   01         | 11        |
      |  TX  RX  |   TX  RX     | TX  RX    |
******|**********|**************|*******    |
USART1|  A9  A10 |   B6  B7     |           |
******|**********|**************|*******    |
USART2|  A2  A3  |   (D5  D6)   |           |
      |          |  (100)(144)  |           |
******|**********|**************|*******    |
USART3|  B10 B11 |   (C10 C11)  | (D8  D9)  |
      |          | (64 100 144) | (100 144) |
*********************************************/
//#define DEBUG_USART USART1

#define EN_USART_  (1)       //Enable(1)/Disable(0)
#define EN_USART2_ (0)       //Enable(1)/Disable(0)
#define EN_USART3_ (0)       //Enable(1)/Disable(0)
#define EN_USART_RX             1       //ʹ�ܣ�1��/��ֹ��0������1����
#define EN_USART2_RX            1       //ʹ�ܣ�1��/��ֹ��0������2����
#define EN_USART3_RX            1       //ʹ�ܣ�1��/��ֹ��0������3����

#define AF_USART1_ (0)
#define AF_USART2_ (0)
#define AF_USART3_ (0)
#define EN_USART1_IQR_T  (1)       //Enable(1)/Disable(0)
#define EN_USART1_IQR_R  (1)       //Enable(1)/Disable(0)
#define EN_USART2_IQR_T  (1)       //Enable(1)/Disable(0)
#define EN_USART2_IQR_R  (1)       //Enable(1)/Disable(0)
#define EN_USART3_IQR_T  (1)       //Enable(1)/Disable(0)
#define EN_USART3_IQR_R  (1)       //Enable(1)/Disable(0)

#define EN_USART1_DMA_T  (0)       //Enable(1)/Disable(0)
#define EN_USART1_DMA_R  (0)       //Enable(1)/Disable(0)
#define EN_USART2_DMA_T  (1)       //Enable(1)/Disable(0)
#define EN_USART2_DMA_R  (1)       //Enable(1)/Disable(0)
#define EN_USART3_DMA_T  (1)       //Enable(1)/Disable(0)
#define EN_USART3_DMA_R  (1)       //Enable(1)/Disable(0)

/***USART***/
      //����
/****************************************/
#endif
