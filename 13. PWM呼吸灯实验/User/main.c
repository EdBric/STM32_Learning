

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "pwm.h"

int main()
{
	u16 i=0;  
	u8 fx=0;
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	TIM3_CH1_PWM_Init(500,72-1); //Ƶ����2Kh
	
	while(1)
	{
		
		if(fx==0)
		{
			i++;
			if(i==300)
			{
				fx=1;
			}
		}
		else
		{
			i--;
			if(i==0)
			{
				fx=0;
			}
		}
		TIM_SetCompare1(TIM3,i);  //iֵ������ȡ499����ΪARR���ֵ��499.
		delay_ms(10);	
	}
}
