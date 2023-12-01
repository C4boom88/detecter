#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "wkup.h"

/*********************************************************************************
			  ___   _     _____  _____  _   _  _____  _____  _   __
			 / _ \ | |   |_   _||  ___|| \ | ||_   _||  ___|| | / /
			/ /_\ \| |     | |  | |__  |  \| |  | |  | |__  | |/ /
			|  _  || |     | |  |  __| | . ` |  | |  |  __| |    \
			| | | || |_____| |_ | |___ | |\  |  | |  | |___ | |\  \
			\_| |_/\_____/\___/ \____/ \_| \_/  \_/  \____/ \_| \_/

 *	******************************************************************************
 *	ALIENTEK Pandora STM32L475 IOT开发板	实验14
 *	待机唤醒实验		HAL库版本
 *	技术支持：www.openedv.com
 *	淘宝店铺：http://eboard.taobao.com
 *	关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 *	广州市星翼电子科技有限公司
 *	作者：正点原子 @ALIENTEK
 *	******************************************************************************/

int main(void)
{
    HAL_Init();
    SystemClock_Config();		//初始化系统时钟为80M
    delay_init(80); 			//初始化延时函数    80M系统时钟
    uart_init(115200);			//初始化串口，波特率为115200

    LED_Init();					//初始化LED

    WKUP_Init();				//初始化待机唤醒

    LCD_Init();					//初始化LCD

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


