/*
 * @FilePath     : \00_Keil_Fwlib_RCC\User\RCC\bsp_rccClkCfg.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-06 23:12:51
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-08 22:14:54
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : BSP - Board Support Package: RCC 相关函数头文件
 */
#ifndef __BSP_RCCCLKCFG_H
#define __BSP_RCCCLKCFG_H

#include "stm32f10x.h"

void HSE_SetSysClk(uint32_t RCC_PLLMul_x);

#endif  /* __BSP_RCCCLKCFG_H */