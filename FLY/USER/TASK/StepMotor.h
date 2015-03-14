#include "sys.h"
#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H
#include "gpio.h"
#include "usr_usart.h"
#define DEBUG_USART USART1
enum Mode {rect, trapezium, null};
typedef int (*pFunEvent)(char x); //声明一个函数指针
class StepMotor
{
private:
    char i,dir;
    char Enable;
    s32 motostep;
    s32 step;
    u16 mototime_set;
    u16 moto_minspeed;
    u16 moto_runtime;
    u16 rate;
    u16 angle;
    Mode mode;
    void (*pio)(char x,char y);
    void (*pdirH)(char x,char y);
    void (*pdirL)(char x,char y);
    char io,iodirH, iodirL;

public:
    StepMotor(void (*pfun)(char x,char y), char setio1, void (*pdH)(char x,char y), char setio2)
    {
			Enable=1;
        mode = rect;
        angle = 0;
        rate = 10;
        moto_runtime = 0;
        moto_minspeed = 0;
        mototime_set = 0;
        step = 0;
        motostep = 0;
        i = 0;
        pio = pfun;
        io = setio1;
			  pdirH = pdH;
        iodirH = setio2;
    }
    void Run() //这是成员函数
    {
			
        if (moto_runtime == 0 && motostep!=0&&Enable)
        {
            //if (motostep>0)
							motostep--;
            if (i)
            {
                i = i >> 1;
                (*pio)(io,1);
                //Sys_Printf(DEBUG_USART, (char *)"-");
            }
            else
            {
                i++;
                (*pio)(io,0);
                //Sys_Printf(DEBUG_USART, (char *)"_");
            }
        }
				
        if (moto_runtime++ > (mototime_set + moto_minspeed))
        {
            moto_runtime = 0;
        }
    }
		void Stop() //这是成员函数
    {
			//Enable=0;
      motostep=0;			
		}
		void Start() //这是成员函数
    {
			Enable=1;			
		}
    void SetDir(char setdir)
    {
			dir=setdir;
			if(setdir==1){
			(*pdirH)(iodirH,1);
			}
			else{
			(*pdirH)(iodirH,0);		
     }
		}
    void SetMode(Mode setmode)
    {
        mode = setmode;
    }
    void SetStep(s32 setstep)
    {
        step = setstep;
        motostep = step;
    }
    void SetRate(u16 setrate)
    {
        rate = 100000/setrate;
        mototime_set = rate;
    }
    void SetAngle(u16 setangle)
    {
        angle = setangle;
        motostep = angle;
    }
		u8 GetState()
		{
			if(motostep==0)
		     return 0;
			else
				 return 1;
		}
};

#endif
