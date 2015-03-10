#include "./TASK/task.h"

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif


/*
    需要包含
    lcd.c
    ili93.c
    touch.c
    */
//更新滑动条
void M1_S1(u16 x, u16 y)
{
    if (motostep == 0)
    {
        moto_maxspeed = PM1;
        motostep_set = PM2 - motostep_sum;
        motostep_sum += motostep_set;
        if (motostep_set < 0)
        {
            motostep_set = -motostep_set;
            Set_A1
            Clr_A0
        }
        else
        {
            Set_A0
            Clr_A1
        }
        motostep = motostep_set;
        mototime_set = 420;
    }
}
void Soft_PWM(void)
{
    static char i = 0;
    if (moto_runtime == 0 && motostep)
    {
        motostep--;
        if (motostep_set - motostep < 60)mototime_set -= (motostep - (motostep_set - 60)) / 4;
        else if (motostep < 60)mototime_set += (60 - motostep) / 4;
        if (i)
        {
            i = i >> 1;
            Set_C6;
        }
        else
        {
            i++;
            Clr_C6;
        }
    }//80//55
    if (moto_runtime++ > (mototime_set + moto_maxspeed + 70))
    {
        moto_runtime = 0;
    }
}
void Soft_PWM(void)
{
    static char i = 0;
    if (moto_runtime == 0 && motostep)
    {
        motostep--;
        if (motostep_set - motostep < 60)mototime_set -= (motostep - (motostep_set - 60)) / 4;
        else if (motostep < 60)mototime_set += (60 - motostep) / 4;
        if (i)
        {
            i = i >> 1;
            Set_C6;
        }
        else 
        {
            i++;
            Clr_C6;
        }
    }//80//55
    if (moto_runtime++ > (mototime_set + moto_maxspeed + 70))
    {
        moto_runtime = 0;
    }
}

int task_stepmotor(void)
{
    _SS
    WaitX(20);
    while (1)
    {
        WaitX(80);

    }
    _EE
}

