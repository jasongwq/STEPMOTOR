#include "./TASK/task.h"

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif


/*
    ��Ҫ����
    lcd.c
    ili93.c
    touch.c
    */
//���»�����
class StepMotor
{
public:
    StepMotor(arguments);
    ~StepMotor();

    /* data */
};
enum Event {press, click, release, null};
class Point
{
public:
    u16 x;
    u16 y;
};
class Size
{
public:
    u16 w;
    u16 h;
};
//����
class Rect //��class��ͷ
{
private:
public:
    u16 BackColor;
    u8 *BackgroundImage;
    Point Bounds;//������������
    Size size;
    Rect()
    {
        Bounds.x = 0;
        Bounds.y = 0;
        size.w = 240;
        size.h = 320;
        BackColor = BLUE;
    }
    void draw() //���ǳ�Ա����
    {
        LCD_Fill(Bounds.x, Bounds.y, Bounds.x + size.w, Bounds.y + size.h, BackColor);
    }
    void SetBackColor(u16 color)
    {
        BackColor = color;
    }
    void SetRect(u16 x, u16 y, u16 w, u16 h)
    {
        Bounds.x = x;
        Bounds.y = y;
        size.w = w;
        size.h = h;
    }
};
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

