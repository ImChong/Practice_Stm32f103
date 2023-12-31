# SystemInit 函数分析

```c
/**
  * @brief  Sets System clock frequency to 72MHz and configure HCLK, PCLK2
  *         and PCLK1 prescalers.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockTo72(void)
{
  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

  /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
  /* Enable | 使能 HSE */
  RCC->CR |= ((uint32_t)RCC_CR_HSEON);             /* 外部高速时钟使能 (External high-speed clock enable) */

  /* Wait till HSE is ready and if Time out is reached exit | 等待 HSE 就绪并做超时处理 */
  do
  {
    HSEStatus = RCC->CR & RCC_CR_HSERDY;
    StartUpCounter++;
  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

  if ((RCC->CR & RCC_CR_HSERDY) != RESET)           /* RESET = 0 */
  {
    HSEStatus = (uint32_t)0x01;                     /* HSE 启动正常 */
  }
  else
  {
    HSEStatus = (uint32_t)0x00;                     /* HSE 启动异常 */
  }

  if (HSEStatus == (uint32_t)0x01)                  /* 如果 HSE 启动成功，程序则继续往下执行 */
  {
    /* Enable Prefetch Buffer | 使能预取址缓冲区 */
    FLASH->ACR |= FLASH_ACR_PRFTBE;                /* 0x4002 2000 闪存存储器接口 */

    /* Flash 2 wait state */                        /* 两个等待状态，当 48MHz < SYSCLK ≤ 72MHz | 国产GD32声称无需等待时间 */
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;

    /* AHB (Advanced High performance Bus) */
    /* HCLK = SYSCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;      /* AHB prescaler: AHB 最大时钟等于系统时钟 72 MHz */

    /* APB2 (Advanced Peripheral Bus 2) */
    /* PCLK2 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;     /* APB high-speed prescaler (APB2): APB2 最大时钟等于系统时钟 72 MHz */

    /* APB1 (Advanced Peripheral Bus 1) */
    /* PCLK1 = HCLK / 2 */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2;     /* APB low-speed prescaler (APB1): APB1 最大时钟等于系统时钟的1/2 36 MHz */

    /* PLL (Phase-Locked Loop) */
    /* PLL configuration: PLLCLK = HSE * 9 = 72 MHz */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE |
                                        RCC_CFGR_PLLMULL));   /* 清空 RCC_CFGR 的 PLLSRC，PLLXTPRE 和 PLLMULL 位 */
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL9);

    /* Enable PLL */
    RCC->CR |= RCC_CR_PLLON;                                  /* PLL 使能 */

    /* Wait till PLL is ready */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)                     /* 等待 PLL 时钟就绪标志 (PLL clock ready flag) */
    {
    }

    /* Select PLL as system clock source */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));        /* 清空 RCC_CFGR 的 SW 位 */
    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;                   /* PLL 作为系统时钟源 */

    /* Wait till PLL is used as system clock source */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)      /* 等待 PLL 作为系统时钟源标志。系统时钟切换状态 (System clock switch status) */
    {
    }
  }
  else                                      /* 如果 HSE 启动失败，用户可以在这里添加处理错误的代码 */
  { /* If HSE fails to start-up, the application will have wrong clock
         configuration. User can add here some code to deal with this error */
  }
}

/* ============================================================================== */
/* ============================================================================== */

/**
  * @brief  Configures the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers.
  * @param  None
  * @retval None
  */
static void SetSysClock(void)
{
#ifdef SYSCLK_FREQ_HSE
  SetSysClockToHSE();
#elif defined SYSCLK_FREQ_24MHz
  SetSysClockTo24();
#elif defined SYSCLK_FREQ_36MHz
  SetSysClockTo36();
#elif defined SYSCLK_FREQ_48MHz
  SetSysClockTo48();
#elif defined SYSCLK_FREQ_56MHz
  SetSysClockTo56();
#if defined SYSCLK_FREQ_72MHz
  SetSysClockTo72();
#endif

 /* If none of the define above is enabled, the HSI is used as System clock
    source (default after reset) */
}

/* ============================================================================== */
/* ============================================================================== */

/**
  * @brief  Setup the microcontroller system
  *         Initialize the Embedded Flash Interface, the PLL and update the
  *         SystemCoreClock variable.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
void SystemInit (void)
{
  /* Reset the RCC clock configuration to the default reset state(for debug purpose) */
  /* Set HSION bit */
  RCC->CR |= (uint32_t)0x00000001;          /* 使能内部高速时钟 (Internal high-speed clock enable) */

  /* Reset SW, HPRE, PPRE1, PPRE2, ADCPRE and MCO bits */
  RCC->CFGR &= (uint32_t)0xF0FF0000;        /* 清空 RCC_CFGR 的 SW，HPRE，PPRE1，PPRE2，ADCPRE 和 MCO 位 */

  /* Reset HSEON, CSSON and PLLON bits */
  RCC->CR &= (uint32_t)0xFEF6FFFF;          /* 清空 RCC_CR 的 HSEON，CSSON 和 PLLON 位 */

  /* Reset HSEBYP bit */
  RCC->CR &= (uint32_t)0xFFFBFFFF;          /* 清空 RCC_CR 的 HSEBYP 位 */

  /* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits */
  RCC->CFGR &= (uint32_t)0xFF80FFFF;        /* 清空 RCC_CFGR 的 PLLSRC，PLLXTPRE，PLLMUL 和 USBPRE/OTGFSPRE 位 */

  /* Disable all interrupts and clear pending bits  */
  RCC->CIR = 0x009F0000;                    /* 禁止所有中断并清空挂起位 (Disable all interrupts and clear pending bits) */

#if defined (STM32F10X_HD) || (defined STM32F10X_XL) || (defined STM32F10X_HD_VL)
  #ifdef DATA_IN_ExtSRAM
    SystemInit_ExtMemCtl();                 /* 外部存储器控制器初始化 (External Memory Controller) */
  #endif /* DATA_IN_ExtSRAM */
#endif

  /* Configure the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers */
  /* Configure the Flash Latency cycles and enable prefetch buffer */
  SetSysClock();                            /* 设置系统时钟频率，HCLK，PCLK2 和 PCLK1 预分频器。设置闪存延迟周期并使能预取缓冲区 */

#ifdef VECT_TAB_SRAM
  SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM. */  /* 向量表重定位到内部 SRAM */
#else
  SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH. */  /* 向量表重定位到内部 FLASH */
#endif
}
```
