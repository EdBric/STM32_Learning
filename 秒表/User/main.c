#include "system.h"
#include "led.h"
#include "SysTick.h"
#include "beep.h"
#include "smg.h"
#include "key.h"
#include "exti.h"

u8 smgduan[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
//定义数组  0-F共阴码表
int count=9999;
int i;
int main()
{
	LED_Init();
	SysTick_Init(72);//72:系统时钟大小
	BEEP_Init();
	SMG_Init();
	KEY_Init();
	My_EXTI_Init();//外部中断函数
	
	while(1)
	{
		i=1;
		GPIO_Write(SMG_PORT,(u16)(~smgduan[count%10]));//~为取反
		delay_ms(999);
		beep=1;
		delay_us(1000);
		beep=0;
		delay_us(50);
		count--;
	}
}
 

