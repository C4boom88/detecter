#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "wkup.h"


int main(void)
{
    HAL_Init();
    SystemClock_Config();		//��ʼ��ϵͳʱ��Ϊ80M
    delay_init(80); 			//��ʼ����ʱ����    80Mϵͳʱ��
    uart_init(115200);			//��ʼ�����ڣ�������Ϊ115200

    LED_Init();					//��ʼ��LED

    WKUP_Init();				//��ʼ����������

    LCD_Init();					//��ʼ��LCD

    Display_ALIENTEK_LOGO(0, 0);
	POINT_COLOR = RED;
    LCD_ShowString(30, 100, 200, 16, 16, "Pandora STM32L4 IOT");
    LCD_ShowString(30, 120, 200, 16, 16, "WKUP TEST");
    LCD_ShowString(30, 140, 200, 16, 16, "ATOM@ALIENTEK");
    LCD_ShowString(30, 160, 200, 16, 16, "2018/10/27");

    while(1)
    {
        LED_B_TogglePin;
        delay_ms(500);
    }
}


