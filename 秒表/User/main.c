#include "system.h"
#include "led.h"
#include "SysTick.h"
#include "beep.h"
#include "smg.h"
#include "key.h"
#include "exti.h"

u8 smgduan[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
//��������  0-F�������
int count=9999;
int i;
int main()
{
	LED_Init();
	SysTick_Init(72);//72:ϵͳʱ�Ӵ�С
	BEEP_Init();
	SMG_Init();
	KEY_Init();
	My_EXTI_Init();//�ⲿ�жϺ���
	
	while(1)
	{
		i=1;
		GPIO_Write(SMG_PORT,(u16)(~smgduan[count%10]));//~Ϊȡ��
		delay_ms(999);
		beep=1;
		delay_us(1000);
		beep=0;
		delay_us(50);
		count--;
	}
}
 

