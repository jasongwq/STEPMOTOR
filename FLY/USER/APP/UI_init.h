#include "lcd.h"

void UI_Init(void)
{
    //����
    but[0].s = 320 - 165;
    but[0].x = 320 - 5;
    but[0].z = 5;
    but[0].y = 240 - 25;
    LCD_DrawRectangle(but[0].z, but[0].s, but[0].y, but[0].x);
    /////////////////////////////////////////////////////////////////////////
#define Button_num 1
    //���� ��ɫ
    but[1].s = 320 - 75        ;
    but[1].x = 320 - 60        ;
    but[1].z = 240 - 20        ;
    but[1].y = 240 - 5         ;
    LCD_Fill(         but[1].z, but[1].s, but[1].y, but[1].x, BLACK);
    LCD_ShowString(but[1].z, but[1].x - 16, 12 * 16, 16, 16, "R"); //��ʾһ���ַ���,12/16����
#undef Button_num
    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////
#define Button_num 2
    //���� ��ɫ
    but[Button_num].s = 320 - 95        ;
    but[Button_num].x = 320 - 80        ;
    but[Button_num].z = 240 - 20        ;
    but[Button_num].y = 240 - 5         ;
    LCD_Fill(      but[Button_num].z, but[Button_num].s, but[Button_num].y, but[Button_num].x, RED);
    LCD_ShowString(but[Button_num].z, but[Button_num].x - 16, 12 * 16, 16, 16, "S"); //��ʾһ���ַ���,12/16����
#undef Button_num
    /////////////////////////////////////////////////////////////////////////
#define Button_num 3
    //����
    but[3].s = 80       ;
    but[3].x = 110      ;
    but[3].z = 160      ;
    but[3].y = 200      ;

    LCD_DrawRectangle(but[3].y, but[3].s, but[3].y + 30, but[3].x);
    LCD_DrawRectangle(but[Button_num].z, but[Button_num].s, but[Button_num].y, but[Button_num].x);
    LCD_ShowString(but[3].z, but[3].s, 5 * 8, 16, 16, "Power"); //��ʾһ���ַ���,12/16����
    LCD_ShowString(but[3].z, but[3].s + 16, 5 * 8, 16, 16, "( w )"); //��ʾһ���ַ���,12/16����

#undef Button_num
    /////////////////////////////////////////////////////////////////////////
#define Button_num 4
    //ת��
    but[4].s = 120      ;
    but[4].x = 150      ;
    but[4].z = 160 ;
    but[4].y = 200 ;
    LCD_ShowString(but[4].z, but[4].s, 5 * 8, 16, 16, "Speed"); //��ʾһ���ַ���,12/16����
    LCD_ShowString(but[4].z, but[4].s + 16, 5 * 8, 16, 16, "(r/s)"); //��ʾһ���ַ���,12/16����

    LCD_DrawRectangle(but[4].y, but[4].s, but[4].y + 30, but[4].x);
    LCD_DrawRectangle(but[Button_num].z, but[Button_num].s, but[Button_num].y, but[Button_num].x);
#undef Button_num
    /////////////////////////////////////////////////////////////////////////
#define Button_num 5
    //����
    but[5].s = 80       ;
    but[5].x = 110      ;
    but[5].z = 80       ;
    but[5].y = 120      ;
    LCD_ShowString(but[5].z, but[5].s, 5 * 8, 16, 16, "Up"); //��ʾһ���ַ���,12/16����
    LCD_ShowString(but[Button_num].z, but[Button_num].s + 16, 5 * 8, 16, 16, "( C ))"); //��ʾһ���ַ���,12/16����

    LCD_DrawRectangle(but[5].y, but[5].s, but[5].y + 30, but[5].x);
    LCD_DrawRectangle(but[5].z, but[5].s, but[5].y, but[5].x);
#undef Button_num
    /////////////////////////////////////////////////////////////////////////
#define Button_num 6
    //����
    but[Button_num].s = 120     ;
    but[Button_num].x = 150     ;
    but[Button_num].z = 80      ;
    but[Button_num].y = 120     ;
    LCD_ShowString(but[Button_num].z, but[Button_num].s, 5 * 8, 16, 16, "Down"); //��ʾһ���ַ���,12/16����
    LCD_ShowString(but[Button_num].z, but[Button_num].s + 16, 5 * 8, 16, 16, "( C ))"); //��ʾһ���ַ���,12/16����

    LCD_DrawRectangle(but[Button_num].y, but[Button_num].s, but[Button_num].y + 30, but[Button_num].x);
    LCD_DrawRectangle(but[Button_num].z, but[Button_num].s, but[Button_num].y, but[Button_num].x);
#undef Button_num
    /////////////////////////////////////////////////////////////////////////
#define Button_num 7
    //��
    but[Button_num].s = 5     ;
    but[Button_num].x = 75    ;
    but[Button_num].z = 180   ;
    but[Button_num].y = 235   ;
    //LCD_ShowString(but[Button_num].z,but[Button_num].s,5*8,16,16,"Down");   //��ʾһ���ַ���,12/16����
    LCD_DrawRectangle(but[Button_num].z, but[Button_num].s, but[Button_num].y, but[Button_num].x);
    LCD_DrawLine(but[Button_num].z + 5, but[Button_num].s + 5, but[Button_num].y - 5, but[Button_num].s + 5); //�ϲ�
    LCD_DrawLine(but[Button_num].z + 5, but[Button_num].s + 5, but[Button_num].y - 27, but[Button_num].x - 5); //���
    LCD_DrawLine(but[Button_num].y - 5, but[Button_num].s - 5, but[Button_num].y - 27, but[Button_num].x - 5); //�Ҳ�

#undef Button_num
    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////
#define Button_num 8
    //��
    but[Button_num].s = 5     ;
    but[Button_num].x = 75    ;
    but[Button_num].z = 120   ;
    but[Button_num].y = 175   ;
    //LCD_ShowString(but[Button_num].z,but[Button_num].s,5*8,16,16,"Down");   //��ʾһ���ַ���,12/16����
    LCD_DrawRectangle(but[Button_num].z, but[Button_num].s, but[Button_num].y, but[Button_num].x);
    LCD_DrawLine(but[Button_num].z + 5, but[Button_num].x - 5, but[Button_num].y - 5, but[Button_num].x - 5); //�²�
    LCD_DrawLine(but[Button_num].z + 5, but[Button_num].x - 5, but[Button_num].y - 27, but[Button_num].s + 5); //���
    LCD_DrawLine(but[Button_num].y - 5, but[Button_num].x - 5, but[Button_num].y - 27, but[Button_num].s + 5); //�Ҳ�
#undef Button_num
    /////////////////////////////////////////////////////////////////////////
#define Button_num 9
    //ģʽ��
    but[Button_num].s = 5     ;
    but[Button_num].x = 75    ;
    but[Button_num].z = 60    ;
    but[Button_num].y = 115   ;
    LCD_ShowString(but[Button_num].z, but[Button_num].s, 6 * 8, 16, 16, "Mode 2"); //��ʾһ���ַ���,12/16����
    LCD_DrawRectangle(but[Button_num].z, but[Button_num].s, but[Button_num].y, but[Button_num].x);
#undef Button_num
    /////////////////////////////////////////////////////////////////////////
#define Button_num 10
    //ģʽһ
    but[Button_num].s = 5     ;
    but[Button_num].x = 75    ;
    but[Button_num].z = 5     ;
    but[Button_num].y = 55    ;
    LCD_ShowString(but[Button_num].z, but[Button_num].s, 6 * 8, 16, 16, "Mode 1"); //��ʾһ���ַ���,12/16����
    LCD_DrawRectangle(but[Button_num].z, but[Button_num].s, but[Button_num].y, but[Button_num].x);
#undef Button_num
    /////////////////////////////////////////////////////////////////////////
#define Button_num 11
    //���� ��ɫ
    but[Button_num].s = 320 - 55        ;
    but[Button_num].x = 320 - 40        ;
    but[Button_num].z = 240 - 20        ;
    but[Button_num].y = 240 - 5         ;
    LCD_Fill(      but[Button_num].z, but[Button_num].s, but[Button_num].y, but[Button_num].x, BLUE);
    LCD_ShowString(but[Button_num].z, but[Button_num].x - 16, 12 * 16, 16, 16, "R"); //��ʾһ���ַ���,12/16����
#undef Button_num
    {
        //��������
        LCD_ShowChar(but[0].z + 8, but[0].s - 16, '.', 16, 0);
        LCD_ShowChar(but[0].z + 24, but[0].s - 16, 'C', 16, 0);
        LCD_ShowNum( but[0].z , but[0].s + - 16, 0, 1, 16); //��ʾ��������
        LCD_ShowNum( but[0].z + 16, but[0].s + - 16, 5, 1, 16); //��ʾ��������
    }
}

