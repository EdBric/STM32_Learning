

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "adc_temp.h"


/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
int main()
{
	u8 i=0;
	int temp=0;
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //中断优先级分组 分2组
	LED_Init();
	USART1_Init(9600);
	ADC_Temp_Init();
	
	while(1)
	{
		i++;
		if(i%20==0)
		{
			led1=!led1;
		}
		
		if(i%50==0)
		{
			temp=Get_Temperture();
			if(temp<0)
			{
				temp=-temp;
				printf("内部温度检测值为：-");
			}
			else
			{
				printf("内部温度检测值为：+");
			}
			printf("%.2f°C\r\n",(float)temp/100);
		}
		delay_ms(10);	
	}
}
