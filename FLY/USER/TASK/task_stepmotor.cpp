#include "./TASK/task.h"

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif

#include "gpio.h"
#include "exti.h"
#include "StepMotor.h"
#include "DataTransferConfig.h"

StepMotor motorA(PAOUT, 1, PCOUT, 1); //脉冲信号,方向控制信号io
StepMotor motorB(PAOUT, 0, PCOUT, 0);
StepMotor motorC(PAOUT, 2, PCOUT, 2);

#define MOTORD_INIT PA5_OUT;PA7_OUT;
#define MOTORD_OUT PAout(5)=0;delay_ms(500);PAout(7)=1;
#define MOTORD_IN  PAout(7)=0;delay_ms(500);PAout(5)=1;


//StepMotor motorD(PAOUT,3,PAOUT,3);
void MotorIQR(void)
{
    motorA.Run();
    motorB.Run();
    motorC.Run();
}
u8 iqr1 = 0;
int task_stepmotor_test0(void)
{
    _SS
    WaitX(20);
    TIM7_Int_Init(36, 10); //200k
    PC1_OUT;
    PA1_OUT;
    PC0_OUT;
    PA0_OUT;
    PC2_OUT;
    PA2_OUT;
    *fangle1 = 30110;
    *fRate1 = 1000;
    while (1)
    {
        WaitX(500);
        iqr1 = 0;
        motorA.SetStep((s32)(300000));
        motorA.SetRate((u16)(*fRate1));
        motorA.SetDir(0);
        while (iqr1 == 0)
        {
            WaitX(1);
        };
        motorA.Stop();
        motorA.SetDir(1);
        motorA.SetStep((s32)(20000));
        while (motorA.GetState() == 1)
        {
            WaitX(1);
        };
    }
    _EE
}
int task_stepmotor_test1(void)
{
    _SS
    WaitX(20);
    TIM7_Int_Init(36, 10); //200k
    PC0_OUT;
    PA0_OUT;
    PC2_OUT;
    PA2_OUT;
    *fangle1 = 30110;
    *fRate2 = 1100;
    *fRate3 = 300;
    motorB.SetStep((s32)(-1));
    motorB.SetRate((u16)(*fRate2));
    motorC.SetStep((s32)(-1));
    motorC.SetRate((u16)(*fRate3));
    while (1)
    {
        WaitX(500);
    }
    _EE
}
int task_stepmotor(void)
{
    _SS
    WaitX(20);
    TIM7_Int_Init(36, 10); //200k
    PA5_OUT;
    PA7_OUT;

    PC1_OUT;
    PA1_OUT;
    //motorA
    PC0_OUT;
    PA0_OUT;
    //motorB
    PC2_OUT;
    PA2_OUT;
    //motorC
    *fangle1 = 10000;

    *fangle2 = 18500;
    *fangle3 = 5000;
    *fangle4 = 6000;
    *fangle5 = 20000;
    *fRate1 = 1100;
    *fRate2 = 1100;
    *fRate3 = 300;
    while (1)
    {
        WaitX(500);
        motorB.SetRate((u16)(*fRate1));
        motorB.SetStep((s32)(*fangle1));
        while (motorB.GetState() == 1)
        {
            WaitX(1);
        };
        iqr1 = 0;
        motorA.SetDir(0);
        motorA.SetRate((u16)(*fRate1));
        motorA.SetStep((s32)(-1));
        while (iqr1 == 0)
        {
            WaitX(1);
        };
        motorA.Stop();
        //加紧
        motorB.SetStep((s32)(*fangle2));
        motorB.SetRate((u16)(*fRate2));
        motorC.SetStep((s32)(*fangle3));
        motorC.SetRate((u16)(*fRate3));
        //转动
        while (motorB.GetState() == 1)
        {
            WaitX(1);
        };
        while (motorC.GetState() == 1)
        {
            WaitX(1);
        };

        PAout(5) = 0;
        PAout(7) = 0;
        PAout(5) = 1;
        WaitX(1000);
        PAout(5) = 0;
        WaitX(500);
        PAout(7) = 1;
        //切断

        motorC.SetStep((s32)(fangle4));
        motorC.SetRate((u16)(*fRate3));
        //包紧
        while (motorC.GetState() == 1)
        {
            WaitX(1);
        };

        motorA.SetDir(1);
        motorA.SetStep((s32)(fangle5));
        while (motorA.GetState() == 1)
        {
            WaitX(1);
        };
    }
    _EE
}
int task_stepmotor_test3(void)
{
    _SS
    WaitX(20);
    PA5_OUT;
    PA7_OUT;

    while (1)
    {
        WaitX(500);
        PAout(7) = 0;
        WaitX(5);
        PAout(5) = 1;
        WaitX(1000);
        PAout(5) = 0;
        WaitX(5);
        PAout(7) = 1;
        //切断

    }
    _EE
}
