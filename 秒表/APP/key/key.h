#ifndef _KEY_H
#define _KEY_H

#include "system.h"


#define KEY_UP_PIN    	  GPIO_Pin_0
#define KEY_UP_PORT	   		(GPIOA)

#define KEY_LEFT_PIN      GPIO_Pin_2
#define KEY_DOWN_PIN      GPIO_Pin_3
#define KEY_RIGHT_PIN     GPIO_Pin_4

#define KEY_PORT	  	 		(GPIOE)

//位带操作
//#define K_UP              PAin(0)
//#define K_DOWN            PEin(3)
//#define K_LEFT            PEin(2)
//#define K_RIGHT           PEin(4)

//库函数
#define K_UP              GPIO_ReadInputDataBit(KEY_UP_PORT,KEY_UP_PIN)
#define K_DOWN            GPIO_ReadInputDataBit(KEY_PORT,KEY_DOWN_PIN)
#define K_LEFT            GPIO_ReadInputDataBit(KEY_PORT,KEY_LEFT_PIN)
#define K_RIGHT           GPIO_ReadInputDataBit(KEY_PORT,KEY_RIGHT_PIN)


#define KEY_UP            1
#define KEY_DOWN          2  
#define KEY_LEFT          3  
#define KEY_RIGHT         4   

void KEY_Init(void);
u8 KEY_Scan(u8 mode);

#endif
