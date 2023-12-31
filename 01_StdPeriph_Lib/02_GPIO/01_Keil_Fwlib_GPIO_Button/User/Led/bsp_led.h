/*
 * @FilePath     : \01_Keil_Fwlib_GPIO_Button\User\Led\bsp_led.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-02 17:29:59
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-04 23:05:22
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : BSP - Board Support Package: LED 相关函数头文件
 */
#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"      /* 此头文件将添加 stm32f10x_conf.h - 管理所有外设的头文件 */

#define LED_GPIO_CLK            RCC_APB2Periph_GPIOB        /* 设置LED的GPIO的时钟使能寄存器地址 */
#define LED_GPIO                GPIOB                       /* 设置LED的GPIO寄存器地址 */
#define LED_R_PIN_MSK           GPIO_Pin_5                  /* 红灯引脚寄存器地址 */
#define LED_G_PIN_MSK           GPIO_Pin_0                  /* 绿灯引脚寄存器地址 */
#define LED_B_PIN_MSK           GPIO_Pin_1                  /* 蓝灯引脚寄存器地址 */
#define LED_R_PIN_BIT_NUM       5                           /* 红灯引脚编号 */
#define LED_G_PIN_BIT_NUM       0                           /* 绿灯引脚编号 */
#define LED_B_PIN_BIT_NUM       1                           /* 蓝灯引脚编号 */

#define LED_ON      1
#define LED_OFF     0
#define PIN_HIGH    1
#define PIN_LOW     0

/* LED的开关 */
#define LED_SWITCH(ledPin, option)      if(option) \
                                            GPIO_ResetBits(LED_GPIO, ledPin); \
                                        else \
                                            GPIO_SetBits(LED_GPIO, ledPin);

/* LED状态切换：^ 异或 */
#define LED_TOGGLE(ledPin)              (LED_GPIO->ODR ^= ledPin);

void LED_GPIO_Config(void);

#endif  /* __BSP_LED_H */
