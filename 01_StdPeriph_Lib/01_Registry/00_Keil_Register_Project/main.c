/*
 * @FilePath     : \Practice_Embedfire_Stm32f103\01_StdPeriph_Lib\01_Registry\00_Keil_Register_Project\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-01 20:07:07
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-12 09:20:52
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 主函数源文件
 */
// #include "stm32f10x.h"          /* 实现寄存器定义 */
#include "stm32f10x_gpio.h"     /* 自定义 gpio 函数 */

#define SECTION_ADDRESS_EN 0                    /* 用地址直接操作 GPIO PB0 */
#define SECTION_MACRO_EN 0                      /* 用寄存器宏操作 GPIO PB0 */
#define SECTION_STRUCT_EN 0                     /* 用结构体操作 GPIO PB0 */
#define SECTION_FUNCTION_EN 0                   /* 用函数操作 GPIO PB0 */
#define SECTION_GPIO_INIT_STRUCTURE_EN 0        /* 用结构体初始化 GPIO PB0 */
#define SECTION_LED_MACRO_EN 1                  /* 用 LED 宏提高可读性 */

#define LED_G_CLK_ENABLE    (RCC->APB2ENR |= (1 << (1 * 3)))    /* 使能GPIOB时钟 */
#define LED_GPIO            GPIOB                               /* 设置LED的GPIO */
#define LED_R_PIN           GPIO_Pin_5                          /* 红灯引脚 */
#define LED_G_PIN           GPIO_Pin_0                          /* 绿灯引脚 */
#define LED_B_PIN           GPIO_Pin_1                          /* 蓝灯引脚 */

/**
 * @description: 系统初始化函数
 * [野火]STM32库开发实战指南, ——基于野火指南者开发板
 * =================================================================================
 * @return {*}
 */
void SystemInit(void) {
    /* 函数为空，为了让编译器不报错 */
}

/**
 * @description: 延迟函数
 * [野火]STM32库开发实战指南, ——基于野火指南者开发板
 * =================================================================================
 * @param {__IO uint32_t} nCount
 * @return {*}
 */
void Delay(__IO uint32_t nCount) {
    for (; nCount != 0; nCount--);
}

/**
 * @description: 主程序入口
 * [野火]STM32库开发实战指南, ——基于野火指南者开发板
 * =================================================================================
 * @return {*}
 */
int main(void) {
#if SECTION_ADDRESS_EN
    /* NOTE: 用地址直接操作 GPIO PB0 */
    /* RCC_APB2ENR 打开 GPIOB 端口的时钟 */
    /* IOPBEN：设置为 1 */
    *(unsigned int *)0x40021018 |= (1 << (1 * 3));          /* 设置为1，1位为一组，向左移动3位 */

    /* GPIOB_CRL 配置 PB0 清零 */
    *(unsigned int *)0x40010C00 &= ~(0x0f << (4 * 0));      /* 设置为0x0f，4位为一组，向左移动0位 */
    /* GPIOx_CRL 配置 PB0 口为输出 */
    /* 5 = 0101 - CNF0：01：通用开漏输出模式 - MODE0：01：输出模式，最大速度10MHz */
    /* 1 = 0001 - CNF0：00：通用推挽输出模式 - MODE0：01：输出模式，最大速度10MHz */
    *(unsigned int *)0x40010C00 |= (5 << (4 * 0));          /* 设置为1，4位为一组，向左移动0位 */

    /* GPIOx_ODR 控制 ODR 寄存器 */
    /* ODR0：设置为 0 */
    *(unsigned int *)0x40010C0C &= ~(1 << (1 * 0));         /* 设置为0，1位为一组，向左移动0位 */

    return 0;

#elif SECTION_MACRO_EN
    /* NOTE: 用寄存器宏操作 GPIO PB0 */
    /* RCC_APB2ENR 打开 GPIOB 端口的时钟 */
    /* IOPBEN：设置为 1 */
    RCC_APB2ENR |= (1 << (1 * 3));          /* 设置为1，1位为一组，向左移动3位 */

    /* GPIOB_CRL 配置 PB0 清零 */
    GPIOB_CRL &= ~(0x0f << (4 * 0));        /* 设置为0x0f，4位为一组，向左移动0位 */
    /* GPIOx_CRL 配置 PB0 口为输出 */
    /* 5 = 0101 - CNF0：01：通用开漏输出模式 - MODE0：01：输出模式，最大速度10MHz */
    /* 1 = 0001 - CNF0：00：通用推挽输出模式 - MODE0：01：输出模式，最大速度10MHz */
    GPIOB_CRL |= (1 << (4 * 0));            /* 设置为1，4位为一组，向左移动0位 */

    /* GPIOx_ODR 控制 ODR 寄存器 */
    /* ODR0：设置为 0 */
    GPIOB_ODR &= ~(1 << (1 * 0));           /* 设置为0，1位为一组，向左移动0位 */   /* 取决与硬件原理图：输出 0 点亮 LED 灯*/
    GPIOB_ODR |= (1 << (1 * 0));            /* 设置为1，1位为一组，向左移动0位 */

    return 0;

#elif SECTION_STRUCT_EN
    /* NOTE: 用结构体操作 GPIO PB0 */
    /* RCC_APB2ENR 打开 GPIOB 端口的时钟 */
    /* IOPBEN：设置为 1 */
    RCC->APB2ENR |= (1 << (1 * 3));          /* 设置为1，1位为一组，向左移动3位 */

    /* GPIOB_CRL 配置 PB0 清零 */
    GPIOB->CRL &= ~(0x0f << (4 * 0));        /* 设置为0x0f，4位为一组，向左移动0位 */
    /* GPIOx_CRL 配置 PB0 口为输出 */
    /* 5 = 0101 - CNF0：01：通用开漏输出模式 - MODE0：01：输出模式，最大速度10MHz */
    /* 1 = 0001 - CNF0：00：通用推挽输出模式 - MODE0：01：输出模式，最大速度10MHz */
    GPIOB->CRL |= (1 << (4 * 0));            /* 设置为1，4位为一组，向左移动0位 */

    /* GPIOx_ODR 控制 ODR 寄存器 */
    /* ODR0：设置为 0 */
    GPIOB->ODR &= ~(1 << (1 * 0));           /* 设置为0，1位为一组，向左移动0位 */   /* 取决与硬件原理图：输出 0 点亮 LED 灯*/
    GPIOB->ODR |= (1 << (1 * 0));            /* 设置为1，1位为一组，向左移动0位 */

    return 0;

#elif SECTION_FUNCTION_EN
    /* NOTE: 用函数操作 GPIO PB0 */
    /* RCC_APB2ENR 打开 GPIOB 端口的时钟 */
    /* IOPBEN：设置为 1 */
    RCC->APB2ENR |= (1 << (1 * 3));          /* 设置为1，1位为一组，向左移动3位 */

    /* GPIOB_CRL 配置 PB0 清零 */
    GPIOB->CRL &= ~(0x0f << (4 * 0));        /* 设置为0x0f，4位为一组，向左移动0位 */
    /* GPIOx_CRL 配置 PB0 口为输出 */
    /* 5 = 0101 - CNF0：01：通用开漏输出模式 - MODE0：01：输出模式，最大速度10MHz */
    /* 1 = 0001 - CNF0：00：通用推挽输出模式 - MODE0：01：输出模式，最大速度10MHz */
    GPIOB->CRL |= (1 << (4 * 0));            /* 设置为1，4位为一组，向左移动0位 */

    /* GPIOx_ODR 控制 ODR 寄存器 */
    /* ODR0：设置为 0 */
    GPIO_SetBits(GPIOB, GPIO_Pin_0);
    GPIO_ResetBits(GPIOB, GPIO_Pin_0);

    return 0;

#elif SECTION_GPIO_INIT_STRUCTURE_EN
    /* NOTE: 用结构体初始化 GPIO PB0 */
    /* GPIO 端口初始化j结构体 */
    GPIO_InitTypeDef GPIO_InitStructure;

    /* RCC_APB2ENR 打开 GPIOB 端口的时钟 */
    /* IOPBEN：设置为 1 */
    RCC->APB2ENR |= (1 << (1 * 3));          /* 设置为1，1位为一组，向左移动3位 */

    /* 选择要控制的GPIO 引脚*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    /* 设置引脚的输出类型为推挽输出*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    /* 设置输出速率为 50MHZ */
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    /* 调用库函数，初始化 GPIO 引脚 */
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    /* 使引脚输出低电平, 点亮 LED1 */
    GPIO_ResetBits(GPIOB, GPIO_Pin_0);

    while (1) {
        /* 使引脚输出低电平, 点亮 LED */
        GPIO_ResetBits(GPIOB, GPIO_Pin_0);

        /* 延时一段时间 */
        Delay(0xFFFFF);

        /* 使引脚输出高电平，关闭 LED1*/
        GPIO_SetBits(GPIOB, GPIO_Pin_0);

        /* 延时一段时间 */
        Delay(0xFFFFF);
    }

#elif SECTION_LED_MACRO_EN
    /* NOTE: 用 LED 宏提高可读性 */
    /* GPIO 端口初始化结构体 */
    GPIO_InitTypeDef GPIO_InitStructure;

    /* RCC_APB2ENR 打开 GPIOB 端口的时钟 */
    LED_G_CLK_ENABLE;          /* 初始化 GPIOB 时钟 */

    /* 选择要控制的GPIO 引脚*/
    GPIO_InitStructure.GPIO_Pin = LED_R_PIN | LED_G_PIN | LED_B_PIN;
    /* 设置引脚的输出类型为推挽输出*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    /* 设置输出速率为 50MHZ */
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    /* 调用库函数，初始化 GPIO 引脚 */
    GPIO_Init(LED_GPIO, &GPIO_InitStructure);

    /* 使引脚输出高电平，关闭 LED */
    GPIO_SetBits(LED_GPIO, LED_R_PIN | LED_G_PIN | LED_B_PIN);

    while (1) {
        /* 使引脚输出低电平, 点亮 LED Green */
        GPIO_ResetBits(LED_GPIO, LED_G_PIN);
        /* 延时一段时间 */
        Delay(0xFFFFF);
        /* 使引脚输出高电平，关闭 LED Green */
        GPIO_SetBits(LED_GPIO, LED_G_PIN);
        /* 延时一段时间 */
        Delay(0xFFFFF);

        /* 使引脚输出低电平, 点亮 LED Blue */
        GPIO_ResetBits(LED_GPIO, LED_B_PIN);
        /* 延时一段时间 */
        Delay(0xFFFFF);
        /* 使引脚输出高电平，关闭 LED Blue */
        GPIO_SetBits(LED_GPIO, LED_B_PIN);
        /* 延时一段时间 */
        Delay(0xFFFFF);

        /* 使引脚输出低电平, 点亮 LED Red */
        GPIO_ResetBits(LED_GPIO, LED_R_PIN);
        /* 延时一段时间 */
        Delay(0xFFFFF);
        /* 使引脚输出高电平，关闭 LED Red */
        GPIO_SetBits(LED_GPIO, LED_R_PIN);
        /* 延时一段时间 */
        Delay(0xFFFFF);
    }

#endif
}
