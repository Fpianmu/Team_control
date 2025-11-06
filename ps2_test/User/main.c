#include "stm32f10x.h"                  // Device header
#include "pstwo.h"
#include "delay.h"
#include "LED.h"
#include "sys.h"
#include "usart.h"	
#include <stdio.h>
uint8_t KeyNum = 0;

int main(void)
{
	Stm32_Clock_Init(9); //系统时钟设置
	PS2_Init();    //手柄初始化
	delay_init(72);  
	uart_init(72,9600);  //串口1初始化 
	LED_Init();   //GPIOA初始化
	
	while (1)
	{
		KeyNum = PS2_DataKey();
		if (KeyNum != 0)
		{
			delay_ms(10);
			KeyNum = PS2_DataKey();
			if (KeyNum == 0)  continue;
			if (KeyNum == 5)  //PSB_PAD_UP
			{
				GPIO_Write(GPIOA,~0x0001);
				delay_ms(500);
				KeyNum = 0;
			}
			if (KeyNum == 6)  //PSB_PAD_RIGHT
			{
				GPIO_Write(GPIOA,~0x0002);
				delay_ms(500);
				KeyNum = 0;
			}
			if (KeyNum == 7)  //PSB_PAD_DOWN
			{	
				GPIO_Write(GPIOA,~0x0004);
				delay_ms(500);
				KeyNum = 0;
			}
			if (KeyNum == 8)  //PSB_PAD_LEFT
			{
				GPIO_Write(GPIOA,~0x0008);
				delay_ms(500);
				KeyNum = 0;
			}
			if (KeyNum == 9)  //PSB_L2
			{
				GPIO_Write(GPIOA, ~0x0001);	
				delay_ms(100);
				GPIO_Write(GPIOA, ~0x0002);	
				delay_ms(100);
				GPIO_Write(GPIOA, ~0x0004);	
				delay_ms(100);
				GPIO_Write(GPIOA, ~0x0008);	
				delay_ms(100);
				KeyNum = 0;
			}
			if (KeyNum == 10)  //PSB_R2 
			{
				GPIO_Write(GPIOA, ~0x0010);	
				delay_ms(100);
				GPIO_Write(GPIOA, ~0x0020);	
				delay_ms(100);
				GPIO_Write(GPIOA, ~0x0040);	
				delay_ms(100);
				GPIO_Write(GPIOA, ~0x0080);	
				delay_ms(100);
				KeyNum = 0;
			}
			if (KeyNum == 11)  //PSB_L1 
			{
				GPIO_Write(GPIOA, ~0x0008);	
				delay_ms(100);
				GPIO_Write(GPIOA, ~0x0004);	
				delay_ms(100);
				GPIO_Write(GPIOA, ~0x0002);	
				delay_ms(100);
				GPIO_Write(GPIOA, ~0x0001);	
				delay_ms(100);
				KeyNum = 0;
			}
			if (KeyNum == 12)  //PSB_R1
			{
				GPIO_Write(GPIOA, ~0x0080);	
				delay_ms(100);
				GPIO_Write(GPIOA, ~0x0040);	
				delay_ms(100);
				GPIO_Write(GPIOA, ~0x0020);	
				delay_ms(100);
				GPIO_Write(GPIOA, ~0x0010);	
				delay_ms(100);
				KeyNum = 0;
			}
			if (KeyNum == 13)  //PSB_TRIANGLE 
			{
				GPIO_Write(GPIOA,~0x0010);
				delay_ms(500);
				KeyNum = 0;
			}
			if (KeyNum == 14)  //PSB_CIRCLE
			{
				GPIO_Write(GPIOA,~0x0020);
				delay_ms(500);
				KeyNum = 0;
			}
			if (KeyNum == 15)  //PSB_CROSS 
			{
				GPIO_Write(GPIOA,~0x0040);
				delay_ms(500);
				KeyNum = 0;
			}
			if (KeyNum == 26)  //
			{
				GPIO_Write(GPIOA,~0x0080);
				delay_ms(500);
				KeyNum = 0;
			}
				
			//printf("  \r\n   %d  is  pressed  \r\n",KeyNum);
		}
		//printf("  \r\n   %d  is  pressed  \r\n",KeyNum);
	}
	
}
