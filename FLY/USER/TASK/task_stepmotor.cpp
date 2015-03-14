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

StepMotor motorA(PAOUT,1,PCOUT,1);//脉冲信号,方向控制信号io
StepMotor motorB(PAOUT,0,PCOUT,0);
StepMotor motorC(PAOUT,2,PCOUT,2);

#define MOTORD_INIT PA5_OUT;PA7_OUT;
#define MOTORD_OUT PAout(5)=0;delay_ms(500);PAout(7)=1;
#define MOTORD_IN  PAout(7)=0;delay_ms(500);PAout(5)=1;


//StepMotor motorD(PAOUT,3,PAOUT,3);
void MotorIQR(void){
  //motorA.Run();
	motorB.Run();
	motorC.Run();
//	motorD.Run();
}
u8 iqr1=0;
int task_stepmotor_test0(void)
{
    _SS
    WaitX(20);
		TIM7_Int_Init(36,10);//200k
	MOTORD_INIT;
	  PC1_OUT;
	  PA1_OUT;
  	PC0_OUT;
	  PA0_OUT;
	  PC2_OUT;  
	  PA2_OUT;
	  *fangle1=30110;
	  *fRate1=1000;
    while (1)
    {
			WaitX(500);
			iqr1=0;
			motorA.SetStep((s32)(300000));
			motorA.SetRate((u16)(*fRate1));
			motorA.SetDir(0);
			while(iqr1==0){WaitX(1);};
			motorA.Stop();
			motorA.SetDir(1);
			motorA.SetStep((s32)(20000));
			while(motorA.GetState()==1){WaitX(1);};
    }
    _EE
}
int task_stepmotor_test2(void)
{
    _SS
    WaitX(20);
		TIM7_Int_Init(36,10);//200k
  	PC0_OUT;
	  PA0_OUT;
	  PC2_OUT;  
	  PA2_OUT;
	  *fangle1=30110;
	  *fRate2=1100;
	  *fRate3=300;
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
		TIM7_Int_Init(36,10);//200k
		PC1_OUT;
	  PA1_OUT;
	//motorA
  	PC0_OUT;
	  PA0_OUT;
	//motorB
	  PC2_OUT;
	  PA2_OUT;
	//motorC
	  *fangle1=30110;
	  *fRate2=1100;
	  *fRate3=300;
    
	  while (1)
    {
			WaitX(500);
			motorB.SetStep((s32)(4500));
		  motorB.SetRate((u16)(*fRate2));
			iqr1=0;
			motorA.SetDir(0);
			motorA.SetRate((u16)(*fRate1));
			motorA.SetStep((s32)(300000));
			while(iqr1==0){WaitX(1);};
			motorA.Stop();
			//加紧
			motorB.SetStep((s32)(11000));
		  motorB.SetRate((u16)(*fRate2));
		  motorC.SetStep((s32)(3000));
		  motorC.SetRate((u16)(*fRate3));
			//转动
			while(motorB.GetState()==1){WaitX(1);};
			while(motorC.GetState()==1){WaitX(1);};
			
			PAout(5)=0;
			WaitX(500);
			PAout(7)=1;
			WaitX(1000);
			PAout(7)=0;
			WaitX(500);
			PAout(5)=1;
			//切断
			
			motorB.SetStep((s32)(11000));
		  motorB.SetRate((u16)(*fRate2));
		  motorC.SetStep((s32)(3000));
		  motorC.SetRate((u16)(*fRate3));
			//包紧
			while(motorB.GetState()==1){WaitX(1);};
			while(motorC.GetState()==1){WaitX(1);};
			
			motorA.SetDir(1);
			motorA.SetStep((s32)(20000));
			while(motorA.GetState()==1){WaitX(1);};
    }
    _EE
}
	
	
	


///*
//    需要包含
//    lcd.c
//    ili93.c
//    touch.c
//    */
////更新滑动条
//void M1_S1(u16 x, u16 y)
//{
//    if (motostep == 0)
//    {
//        moto_maxspeed = PM1;
//        motostep_set = PM2 - motostep_sum;
//        motostep_sum += motostep_set;
//        if (motostep_set < 0)
//        {
//            motostep_set = -motostep_set;
//            Set_A1
//            Clr_A0
//        }
//        else
//        {
//            Set_A0
//            Clr_A1
//        }
//        motostep = motostep_set;
//        mototime_set = 420;
//    }
//}
//void Soft_PWM(void)
//{
//    static char i = 0;
//    if (moto_runtime == 0 && motostep)
//    {
//        motostep--;
//        if (motostep_set - motostep < 60)mototime_set -= (motostep - (motostep_set - 60)) / 4;
//        else if (motostep < 60)mototime_set += (60 - motostep) / 4;
//        if (i)
//        {
//            i = i >> 1;
//            Set_C6;
//        }
//        else
//        {
//            i++;
//            Clr_C6;
//        }
//    }//80//55
//    if (moto_runtime++ > (mototime_set + moto_maxspeed + 70))
//    {
//        moto_runtime = 0;
//    }
//}
//void Soft_PWM(void)
//{
//    static char i = 0;
//    if (moto_runtime == 0 && motostep)
//    {
//        motostep--;
//        if (motostep_set - motostep < 60)mototime_set -= (motostep - (motostep_set - 60)) / 4;
//        else if (motostep < 60)mototime_set += (60 - motostep) / 4;
//        if (i)
//        {
//            i = i >> 1;
//            Set_C6;
//        }
//        else 
//        {
//            i++;
//            Clr_C6;
//        }
//    }//80//55
//    if (moto_runtime++ > (mototime_set + moto_maxspeed + 70))
//    {
//        moto_runtime = 0;
//    }
//}


