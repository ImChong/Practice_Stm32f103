/*
 * @FilePath     : \01_Keil_Fwlib_GPIO_Button\User\Button\bsp_key.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-02 17:39:04
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-04 11:52:39
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : BSP - Board Support Package：按键相关函数源文件
 */

#include "bsp_key.h"    /* 此头文件将添加 stm32f10x.h */

/**
 * @description: 按键的 GPIO 初始化
 * =================================================================================
 * @param {uint32_t} RCC_GPIO_Clock RCC外设的对应GPIO时钟寄存器
 * @param {GPIO_TypeDef} *GPIOx
 * @param {uint16_t} GPIO_Pin
 * @return {*}
 */
void KEY_GPIO_Config(uint32_t RCC_GPIO_Clock, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    GPIO_InitTypeDef GPIO_InitStructure;                                /* GPIO 端口初始化结构体 */
    RCC_APB2PeriphClockCmd(RCC_GPIO_Clock, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin;                             /* 选择要控制的GPIO 引脚*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;               /* 设置引脚的输出类型为浮空输入：硬件已外部下拉 */
    /* 输入无需设置速率 */
    GPIO_Init(GPIOx, &GPIO_InitStructure);
}

/**
 * @description: 按键松手检测
 * =================================================================================
 * @param {GPIO_TypeDef} *GPIOx
 * @param {uint16_t} GPIO_Pin
 * @return {uint8_t} KEY_ON 按键按下 / KEY_OFF 按键没按下
 */
uint8_t KEY_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    /* 检测是否有按键按下*/
    if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) {
        /* 等待按键释放*/
        while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);        /* 松手检测 */
        return KEY_ON;
    }
    return KEY_OFF;
}
