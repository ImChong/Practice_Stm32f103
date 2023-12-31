# 使用固件库操作的项目模板

使用固件库操作的项目模板

```shell
.
│  keilkill.bat
│  README.md
│
├─.vscode
│      c_cpp_properties.json
│      settings.json
│      tasks.json
│
├─Doc
│      README.md
│
├─Libraries
│  ├─CMSIS
│  │  │  core_cm3.c
│  │  │  core_cm3.h
│  │  │  stm32f10x.h
│  │  │  system_stm32f10x.c
│  │  │  system_stm32f10x.h
│  │  │
│  │  └─startup
│  │          startup_stm32f10x_cl.s
│  │          startup_stm32f10x_hd.s
│  │          startup_stm32f10x_hd_vl.s
│  │          startup_stm32f10x_ld.s
│  │          startup_stm32f10x_ld_vl.s
│  │          startup_stm32f10x_md.s
│  │          startup_stm32f10x_md_vl.s
│  │          startup_stm32f10x_xl.s
│  │
│  └─STM32F10x_StdPeriph_Driver
│      ├─inc
│      │      misc.h
│      │      stm32f10x_adc.h
│      │      stm32f10x_bkp.h
│      │      stm32f10x_can.h
│      │      stm32f10x_cec.h
│      │      stm32f10x_crc.h
│      │      stm32f10x_dac.h
│      │      stm32f10x_dbgmcu.h
│      │      stm32f10x_dma.h
│      │      stm32f10x_exti.h
│      │      stm32f10x_flash.h
│      │      stm32f10x_fsmc.h
│      │      stm32f10x_gpio.h
│      │      stm32f10x_i2c.h
│      │      stm32f10x_iwdg.h
│      │      stm32f10x_pwr.h
│      │      stm32f10x_rcc.h
│      │      stm32f10x_rtc.h
│      │      stm32f10x_sdio.h
│      │      stm32f10x_spi.h
│      │      stm32f10x_tim.h
│      │      stm32f10x_usart.h
│      │      stm32f10x_wwdg.h
│      │
│      └─src
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
├─Project
│  │  Embedfire_F103_Button.sct
│  │  Embedfire_F103_Fwlib_Template.uvguix.29142
│  │  Embedfire_F103_Fwlib_Template.uvoptx
│  │  Embedfire_F103_Fwlib_Template.uvprojx
│  │  EventRecorderStub.scvd
│  │
│  ├─.vscode
│  │      c_cpp_properties.json
│  │      keil-assistant.log
│  │      uv4.log
│  │      uv4.log.lock
│  │
│  ├─DebugConfig
│  │      Fwlib_GPIO_Button_BitBand_STM32F103VE_1.0.0.dbgconf
│  │      Fwlib_Template_STM32F103VE_1.0.0.dbgconf
│  │
│  ├─Listings
│  └─Objects
│          ArInp.Scr
│          Embedfire_F103_Button.bin
│          Embedfire_F103_Button.hex
│          Embedfire_F103_Button.sct
│
└─User
    │  main.c
    │  stm32f10x_conf.h
    │  stm32f10x_it.c
    │  stm32f10x_it.h
    │
    ├─Button
    │      bsp_key.c
    │      bsp_key.h
    │
    └─Led
            bsp_led.c
            bsp_led.h
```
