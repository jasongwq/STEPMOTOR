#ifndef __USER_H
#define __USER_H

#ifdef __cplusplus
       extern "C" {
#endif
#include "sys.h"
#include "gpio.h"
#include "pid.h"
#include "usr_usart.h"
struct Parameter
{
    u16 up;//�趨����
    u16 down;//�趨����
    u16 powerd;//ʵ�ʹ���
    u16 powerf;//ʵ�ʹ���
    u16 setpower;//�趨����
    u16 speed;//ʵ���ٶ�
    u16 setspeed;//ʵ���ٶ�
    u16 flag;//��־λ
    u16 settemperature;//�趨�¶�1
    u16 settemperature2;//�趨�¶�2
    s16 fenshan;//����PWM
    s16 dianzu;//����PWM
    u16 time_flag;
    u16 last_flag;//ģʽ
};
extern struct Parameter parameter;
//struct PID
//{
//    s16 SetPoint; // �趨Ŀ�� Desired Value
//    s16 Proportion; // �������� Proportional Const
//    s16 Integral; // ���ֳ��� Integral Const
//    s16 Derivative; // ΢�ֳ��� Derivative Const
//    s32 LastError; // Error[-1]
//    s32 PrevError; // Error[-2]
//    s32 SumError; // Sums of Errors
//};

extern struct PID spid; // PID Control Structure
extern s8 FixedCurve[][210];
extern int mode2unm;
extern int Curve;
#ifdef __cplusplus
        }
#endif
#endif
