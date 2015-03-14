#include "./TASK/task.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "data_transfer.h"
#include "control.h"
#include "pwm.h"
#include "DataTransferConfig.h"
#define EX_BaudRate 8
u16 in(u32 x)
{
    u32 y2 = 0;
    u32 y1;
    do
    {
        y2 += 2;
        y1 = 72000000 / x / y2;
    }
    while (y1 > 65536);
    return y2;
}
int task_pwm_ex(void)
{
    u16 x = 0;
    _SS
    Ex_Init();
    x = in(400);
    TIM2_PWM_Init(x, 72000000 / x / 400);
    TIM_SetCompare2(TIM2, x / 2);
    *fRate1 = 200;
    while (1)
    {

        static u16 temp = 0;
        if (temp != (u16)(*fRate1))
        {
            temp = (u16)(*fRate1);
            x = in((u16)(temp));
            TIM2_PWM_Init(x, 72000000 / x / (u16)(temp));
            TIM_SetCompare2(TIM2, x / 2);
        }

        WaitX(EX_BaudRate);
        Data_Exchange();
    }
    _EE
}
int task_pwm_ex1(void)
{
    _SS
    Ex_Init();
    while (1)
    {

        WaitX(EX_BaudRate);
        Data_Exchange();
    }
    _EE
}
//#undef EX_BaudRate
#ifdef __cplusplus
}
#endif
