#include "stm32f10x.h"                  // Device header
#include "pstwo.h"
#include "delay.h"
#include "LED.h"
#include "sys.h"
#include "usart.h"	
#include <stdio.h>
#include "OLED.h"

uint8_t KeyNum = 0;

int main(void)
{
	Stm32_Clock_Init(9); //系统时钟设置
	OLED_Init();		//OLED屏初始化  显示手柄数据
	PS2_Init();    //手柄初始化
	delay_init(72);  
	uart_init(72,9600);  //串口1初始化 
	LED_Init();   //GPIOA初始化
	
	while (1)
	{
		OLED_ShowString(1,1,"Button");
		KeyNum = PS2_DataKey();
		OLED_ShowNum(2,1,KeyNum,5);
		delay_ms(1000);
		OLED_Clear();
		/*  
		PS2手柄的返回值(绿灯模式)详见工程根目录下的图片！
		*/
	}
	
}
