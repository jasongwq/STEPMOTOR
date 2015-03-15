/***SYS***/
#include "sys.h"
#include "gpio.h"
#include <string.h>
#include "usr_usart.h"
#include "minos_delay.h"
#include "sys_os.h"
#include "gpio.h"
#include "stm32_config.h"
#include "G32_timer.h"
/***C***/
#include "string.h"
/***Other***/
#include "./TASK/tasks.h"
#include "exti.h"	
void SYS_INIT(void)
{
    /***延时初始化***/
    delay_init();
    /***中断初始化***/
    NVIC_Configuration();
    uart_init (115200);
    //uart_init (115200);
    //uart3_init(115200);
    Sys_Printf(Printf_USART, (char *)"\r\nPrintf_USART ok");
	  Sys_Printf(Printf_USART, (char *)"1");
	  Sys_Printf(Printf_USART, (char *)"2");
	  Sys_Printf(Printf_USART, (char *)"3");
//	PA5_OUT
//	PAout(5)=1;
		EXTI_Configuration(GPIOB,GPIO_Pin_0,0);
	  EXTI_NVIC_Configuration(0,2,1,1);
}
void stepmotot(void)
{
	
}
int main(void)
{
    SYS_INIT();
    /***总循环***/
    while (1)
    {
      RunTaskA(task_stepmotor,0);
			RunTaskA(task_pwm_ex1,1);
			
        RunTaskA(task_display,2);
      RunTaskA(task_led,3);
    }
}
