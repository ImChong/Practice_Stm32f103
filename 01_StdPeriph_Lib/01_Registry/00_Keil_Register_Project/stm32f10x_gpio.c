#include "stm32f10x_gpio.h"

/* GPIO_SetBits()
 *  Functionality: 为GPIO引脚设置高电平
 *  Arguments: GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin
 *  Return: void
 *  References:
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    GPIOx->BSRR |= GPIO_Pin;
}

/* GPIO_ResetBits()
 *  Functionality: 为GPIO引脚设置低电平
 *  Arguments: GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin
 *  Return: void
 *  References:
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    GPIOx->BRR |= GPIO_Pin;
}