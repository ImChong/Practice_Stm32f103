# 使用固件库操作的项目模板

使用固件库操作的项目模板

```shell
.                                           # 项目根目录
│  keilkill.bat                                 # 清除 keil 生成的中间文件
│  README.md                                    # 本说明文件
│
├─.vscode                                   # VSCode 配置文件夹
│      c_cpp_properties.json                    # VSCode C/C++ 配置文件
│      keil-assistant.log                       # Keil Assistant 日志文件
│      uv4.log                                  # Keil 编译日志文件
│      uv4.log.lock                             # Keil 编译日志文件锁
│
├─Doc                                       # 文档
│      README.md                                # 项目文档
│
├─Libraries
│  ├─CMSIS                                  # CMSIS 标准库
│  │  │  core_cm3.c                             # CMSIS 核心库
│  │  │  core_cm3.h                             # CMSIS 核心库头文件
│  │  │  stm32f10x.h                            # stm32f103 的头文件：包含各寄存器的地址
│  │  │  system_stm32f10x.c                     # 系统初始化文件
│  │  │  system_stm32f10x.h                     # 系统初始化文件头文件
│  │  │
│  │  └─startup                             # 启动文件
│  │          startup_stm32f10x_cl.s
│  │          startup_stm32f10x_hd.s            # 本项目使用
│  │          startup_stm32f10x_hd_vl.s
│  │          startup_stm32f10x_ld.s
│  │          startup_stm32f10x_ld_vl.s
│  │          startup_stm32f10x_md.s
│  │          startup_stm32f10x_md_vl.s
│  │          startup_stm32f10x_xl.s
│  │
│  └─STM32F10x_StdPeriph_Driver             # STM32F10x 标准外设库
│      ├─inc                                    # 头文件
│      │      misc.h                                # 杂项
│      │      stm32f10x_adc.h                       # ADC (Analog-to-Digital Converter)：将模拟信号转换为数字信号
│      │      stm32f10x_bkp.h                       # BKP (Backup Registers)：备份寄存器 - 提供备份寄存器和备份电源
│      │      stm32f10x_can.h                       # CAN (Controller Area Network)：CAN 控制器
│      │      stm32f10x_cec.h                       # CEC (Consumer Electronics Control)：消费电子控制
│      │      stm32f10x_crc.h                       # CRC (Cyclic Redundancy Check)：循环冗余校验
│      │      stm32f10x_dac.h                       # DAC (Digital-to-Analog Converter)：数模转换器
│      │      stm32f10x_dbgmcu.h                    # 调试
│      │      stm32f10x_dma.h                       # DMA (Direct Memory Access)：直接存储器访问控制器
│      │      stm32f10x_exti.h                      # 外部中断
│      │      stm32f10x_flash.h                     # FLASH：内部 FLASH
│      │      stm32f10x_fsmc.h                      # FSMC (Flexible Static Memory Controller)：外部 SRAM/NOR FLASH
│      │      stm32f10x_gpio.h                      # GPIO (General Purpose Input/Output)：通用输入输出
│      │      stm32f10x_i2c.h                       # I2C (Inter-Integrated Circuit)：一种串行通信协议 - I2C协议使用两根信号线（时钟线SCL和数据线SDA）进行通信
│      │      stm32f10x_iwdg.h                      # 独立看门狗 (Independent Watchdog)：定时计数器
│      │      stm32f10x_pwr.h                       # 电源
│      │      stm32f10x_rcc.h                       # RCC (Reset and Clock Control)：时钟树 - 控制系统时钟和复位
│      │      stm32f10x_rtc.h                       # RTC (Real-Time Clock)：实时时钟
│      │      stm32f10x_sdio.h                      # SDIO (Secure Digital Input/Output)：一种基于SD卡的扩展接口
│      │      stm32f10x_spi.h                       # SPI (Serial Peripheral Interface)：一种串行通信协议 - SPI协议使用四根信号线（时钟线SCK、数据线MOSI、数据线MISO和片选线CS）进行通信
│      │      stm32f10x_tim.h                       # TIM (Timer)：定时器
│      │      stm32f10x_usart.h                     # USART (Universal Synchronous/Asynchronous Receiver/Transmitter)：一种串行通信协议 - 通用同步/异步串行接收/发送器 - USART协议使用两根或四根信号线进行通信
│      │      stm32f10x_wwdg.h                      # 窗口看门狗 (Window Watchdog)：时间窗口
│      │
│      └─src                                    # 源文件
│              misc.c
│              stm32f10x_adc.c
│              stm32f10x_bkp.c
│              stm32f10x_can.c
│              stm32f10x_cec.c
│              stm32f10x_crc.c
│              stm32f10x_dac.c
│              stm32f10x_dbgmcu.c
│              stm32f10x_dma.c
│              stm32f10x_exti.c
│              stm32f10x_flash.c
│              stm32f10x_fsmc.c
│              stm32f10x_gpio.c
│              stm32f10x_i2c.c
│              stm32f10x_iwdg.c
│              stm32f10x_pwr.c
│              stm32f10x_rcc.c
│              stm32f10x_rtc.c
│              stm32f10x_sdio.c
│              stm32f10x_spi.c
│              stm32f10x_tim.c
│              stm32f10x_usart.c
│              stm32f10x_wwdg.c
│
├─Project                                       # Keil 工程文件夹
│  │  Embedfire_F103_Fwlib_Template.uvoptx          # Keil 工程文件选项
│  │  Embedfire_F103_Fwlib_Template.uvprojx         # Keil 工程文件
│  │
│  ├─DebugConfig
│  │      Fwlib_Template_Rcc_Overclock_STM32F103VE_1.0.0.dbgconf
│  │      Fwlib_Template_STM32F103VE_1.0.0.dbgconf
│  │
│  ├─Listings                                       # Keil 编译生成的中间文件
│  └─Objects                                        # Keil 编译生成的中间文件
│          Embedfire_F103_Fwlib_Template.hex            # Keil 编译生成的烧录文件
│
└─User                                          # 用户代码
    │  main.c                                       # 主函数
    │  stm32f10x_conf.h                             # 用户配置文件
    │  stm32f10x_it.c                               # 中断服务函数
    │  stm32f10x_it.h                               # 中断服务函数头文件
    │
    ├─Led                                           # LED 应用
    │      bsp_led.c                                    # Board Support Package - LED 应用
    │      bsp_led.h                                    # Board Support Package - LED 应用头文件
    │
    └─RCC                                           # RCC 应用
            bsp_rccClkCfg.c                             # Board Support Package - RCC 应用
            bsp_rccClkCfg.h                             # Board Support Package - RCC 应用头文件
```
