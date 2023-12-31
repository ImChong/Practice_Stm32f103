# 1. 嵌入式术语

- [1. 嵌入式术语](#1-嵌入式术语)
  - [1.1. 数据手册（Data Sheet）](#11-数据手册data-sheet)
  - [1.2. 参考手册（Reference Manual）](#12-参考手册reference-manual)
  - [1.3. ISP（In-System Programming）](#13-ispin-system-programming)
  - [1.4. NRST（Negative Reset）](#14-nrstnegative-reset)
  - [1.5. RST（Reset）](#15-rstreset)
  - [1.6. RTS（Request to Send）](#16-rtsrequest-to-send)
  - [1.7. DTR（Data Terminal Ready）](#17-dtrdata-terminal-ready)
  - [1.8. SWD（Serial Wire Debug）](#18-swdserial-wire-debug)
  - [1.9. 内部 FLASH](#19-内部-flash)
  - [1.10. 系统存储器（System Memory）](#110-系统存储器system-memory)
  - [1.11. 内部 SRAM（Static Random Access Memory）](#111-内部-sramstatic-random-access-memory)
  - [1.12. CMSIS-DAP（Cortex Microcontroller Software Interface Standard - Debug Access Port）](#112-cmsis-dapcortex-microcontroller-software-interface-standard---debug-access-port)
  - [1.13. 最低有效位（LSB）](#113-最低有效位lsb)
  - [1.14. 小端模式（Little Endian）](#114-小端模式little-endian)
  - [1.15. 大端模式（Big Endian）](#115-大端模式big-endian)
  - [1.16. IROM 和 IRAM](#116-irom-和-iram)
  - [1.17. SRAM (Static Random-Access Memory)](#117-sram-static-random-access-memory)
  - [1.18. SDRAM (Synchronous Dynamic Random-Access Memory)](#118-sdram-synchronous-dynamic-random-access-memory)
  - [1.19. CCMRAM (Core Coupled Memory RAM)](#119-ccmram-core-coupled-memory-ram)

## 1.1. 数据手册（Data Sheet）

> 基础规格：数据手册主要提供微控制器的基础规格，例如工作电压、频率范围、尺寸、引脚配置等。
> 硬件概述：数据手册通常会概述微控制器的硬件结构，包括各种外设、内存大小和种类。
> 引脚信息：具体的引脚分配、电气特性（如输入电压、输出电流等）。
> 电气参数：各种电气特性，包括最大/最小电压、电流、功耗等。
> 简单应用案例：可能会包括一些基础的应用电路图。
> 订购信息：不同型号和包装形式的订购代码。
> 数据手册通常更短，更侧重于硬件和电气参数。

## 1.2. 参考手册（Reference Manual）

> 外设详解：参考手册提供了详细的信息关于微控制器内部的各种外设（如GPIO、USART、ADC等）的工作原理。
> 寄存器映射：详细列出各种外设的寄存器映射和位定义。
> 功能描述：对各个功能模块（例如，电源管理、时钟系统等）有深入的描述。
> 编程指导：包括一些编程的实例和流程，以及与硬件交互时需要注意的事项。
> 系统配置：如何配置微控制器的各种硬件和软件选项。
> 参考手册通常更长，更详细，更侧重于软件开发和硬件配置。
> 简而言之，如果你想了解微控制器的电气特性和基础规格，你应该查阅数据手册。如果你正在进行编程和开发工作，那么参考手册会是一个更有用的资源。在实际开发过程中，这两种文档通常都是必要的。

## 1.3. ISP（In-System Programming）

> ISP（In-System Programming）是一种通过连接到目标设备的外部接口，在设备内部编程或修改程序代码和数据的技术。这种技术通常用于更新固件、修改配置、烧录Bootloader等操作，而无需将芯片从电路板上取下来，使得在生产和维护阶段都能更加便捷地进行。

## 1.4. NRST（Negative Reset）

> NRST 通常代表 "nRST"，其中 "n" 代表 "not"，意思是反相。它在电子和嵌入式系统领域中常用来表示 "Negative Reset"，即负向复位信号。这个信号用于将一个设备或电路恢复到初始状态，通常是通过将设备的内部状态清零或将其重新启动来实现。

## 1.5. RST（Reset）

> "RST" 通常是 "Reset"（复位）的缩写。它表示一种操作或信号，用于将设备、系统或电路恢复到初始状态，以便进行初始化或排除故障。复位操作通常会清除设备的内部状态，将其返回到一个可控的状态，以便重新启动或重新配置。

## 1.6. RTS（Request to Send）

> "RTS" 通常是 "Request to Send" 的缩写，它是一种用于串行通信的信号，用于控制数据的发送。在串行通信中，数据的发送和接收需要一定的协调，以确保数据能够正确地传输。

## 1.7. DTR（Data Terminal Ready）

> "DTR" 通常是 "Data Terminal Ready" 的缩写，它是一种用于串行通信的信号，用于指示数据终端设备（通常是计算机或控制器）是否已准备好进行通信。"DTR" 信号与串行通信中的数据流控制和设备连接状态有关。

## 1.8. SWD（Serial Wire Debug）

> SWD（Serial Wire Debug）是一种用于嵌入式系统调试和编程的接口协议，其简单的硬件连接和高效的数据传输使其成为了嵌入式开发中常用的调试工具接口。

## 1.9. 内部 FLASH

> 内部闪存（Flash）是一种非易失性存储器，通常用于存储程序代码和常量数据。它具有以下特点：
>
> - 非易失性：Flash 存储器在断电情况下可以保留存储的数据，适用于存储长期不变的程序代码。
> - 可擦写和可编程：Flash 存储器可以通过特定的操作擦除并重新编程，允许更新固件或程序。
> - 相对较大容量：Flash 存储器通常具有较大的容量，足以存储整个操作系统和应用程序代码。
> - 擦写次数有限：每个 Flash 存储单元的擦写次数是有限的，需要谨慎设计以避免过度使用。

## 1.10. 系统存储器（System Memory）

> 系统存储器通常指的是存储启动引导程序、系统配置数据、引导加载程序等重要信息的存储区域。这个区域可以是内部闪存的一部分，也可以是专门的存储芯片。它具有以下特点：
>
> - 存储重要数据：系统存储器通常用于存储启动引导程序、配置信息等，以确保系统在启动时能够正常工作。
> - 可靠性要求高：系统存储器中的数据需要高可靠性，因为它们与系统启动和操作相关。

## 1.11. 内部 SRAM（Static Random Access Memory）

> SRAM（Static Random Access Memory，静态随机存取存储器）是一种类型的计算机存储器，用于临时存储数据和变量。与动态随机存取存储器（DRAM）相比，SRAM具有更快的读写速度和较低的访问延迟，但通常也更昂贵且需要更多的电力。
> 内部静态随机存储器（SRAM）是一种用于存储临时数据和变量的存储器，它具有以下特点：
>
> - 高速读写：SRAM 存储器的读写速度很快，适用于临时存储数据和变量。
> - 临时性：SRAM 存储器中的数据在断电后会丢失，适用于存储程序执行期间的中间结果和变量。
> - 相对较小容量：SRAM 存储器通常比 Flash 存储器小，因此主要用于存储短期数据。

## 1.12. CMSIS-DAP（Cortex Microcontroller Software Interface Standard - Debug Access Port）

> CMSIS-DAP（Cortex Microcontroller Software Interface Standard - Debug Access Port）是一种用于嵌入式系统调试的标准接口协议。它是由ARM（现在的ARM Limited）提出并定义的，旨在提供一种通用的调试和编程接口，以便开发者可以使用统一的方式对不同的Cortex-M微控制器进行调试和编程操作。
> CMSIS-DAP通常用于创建支持JTAG和SWD（Serial Wire Debug）等调试接口的工具，如调试器、编程器和仿真器。通过CMSIS-DAP，开发者可以实现以下功能：
>
> - 调试操作：允许开发者在目标微控制器上运行、暂停、单步执行、查看寄存器和内存等操作，以进行代码调试和故障排除。
> - 程序烧录：可以通过CMSIS-DAP接口将编译后的固件程序加载到目标微控制器的内部Flash中。
> - 芯片复位：支持对目标微控制器进行软件复位或硬件复位操作。
> - 性能分析：一些CMSIS-DAP实现还支持性能分析功能，如跟踪和性能计数器。
> - 通用性：CMSIS-DAP标准化了接口协议，使得兼容不同厂家和型号的Cortex-M微控制器变得更加容易。

## 1.13. 最低有效位（LSB）

> 在嵌入式系统（以及计算机科学和电子工程中）中，LSB 是 "Least Significant Bit"（最低有效位）的缩写。在一个二进制数中，最低有效位是右边的那一位，也就是2的0次方位。与之对应的是 MSB（"Most Significant Bit"，最高有效位），这是二进制数中左边的那一位。
>
> 例如，在8位二进制数 `1101 0101` 中，最右边的位（即 '1'）是 LSB，而最左边的位（即第一个 '1'）是 MSB。
>
> ### 1.13.1. LSB的重要性
>
> - **数据存储和传输**：在某些系统或协议中，需要明确数据是以 "Little-endian" 还是 "Big-endian" 的格式来存储或传输。这里的 "endian" 指的就是 LSB 和 MSB 的存放顺序。
>
> - **位操作**：在进行位操作（如位掩码、位字段设置等）时，了解 LSB 的位置是非常重要的。
>
> - **模数转换和数据压缩**：在一些特定的应用场景中，可能只关心数据的某几个最低有效位。
>
> - **硬件接口和通信协议**：在一些硬件通信协议（如 SPI、I2C 等）中，数据传输的 LSB/MSB 顺序可能会被明确规定。
>
> 了解 LSB 和 MSB 的概念是进行低级编程（包括嵌入式系统编程）和硬件设计的基础。这些概念对于正确地解释数据和实现数据通信有至关重要的作用。

## 1.14. 小端模式（Little Endian）

> 小端模式（Little Endian）是指数据的低字节保存在内存的低地址中，而数据的高字节保存在内存的高地址中。
>
> 假设有一个 32 位整数，值为 (高字节)0x12345678(低字节)，在小端模式下，该整数在内存中的存储方式如下：
>
> ```c
> 地址  |  数据
> ----  | -----
> 低地址 | 低字节
> 0x00  | 0x78
> 0x01  | 0x56
> 0x02  | 0x34
> 0x03  | 0x12
> 高地址 | 高字节
> ```

## 1.15. 大端模式（Big Endian）

> 大端模式（Big Endian）是指数据的高字节保存在内存的低地址中，而数据的低字节保存在内存的高地址中。
>
> 假设有一个 32 位整数，值为 (高字节)0x12345678(低字节)，在大端模式下，该整数在内存中的存储方式如下：
>
> ```c
> 地址  |  数据
> ----  | -----
> 低地址 | 高字节
> 0x00  | 0x12
> 0x01  | 0x34
> 0x02  | 0x56
> 0x03  | 0x78
> 高地址 | 低字节
> ```

## 1.16. IROM 和 IRAM

> IROM 和 IRAM 的全称通常为：
>
> - **IROM**: Instruction Read-Only Memory。这通常指的是存储程序代码的只读存储器区域，如固件或其他不经常更改的程序数据。
>
> - **IRAM**: Instruction Random Access Memory。这通常指的是为程序的运行时数据提供空间的内存，如堆栈、局部变量和全局变量。
>
> 在许多嵌入式系统和微控制器的上下文中，IROM（通常表示指令ROM或内部ROM）和IRAM（通常表示指令RAM或内部RAM）是区分不同类型存储器的常见术语。以下是它们之间的基本区别：
>
> 1. **存储介质**:
>    - **IROM**: IROM通常是非易失性的，它保留其内容，即使在断电后。这是存储固定程序代码的地方，该代码在上电或复位时被执行。
>    - **IRAM**: IRAM是易失性的，这意味着它会在断电后丢失其内容。这是为程序运行时数据（如堆栈、局部变量和全局变量）提供空间的地方。
>
> 2. **访问速度**:
>    - **IROM**: 通常访问速度较慢，因为它是基于闪存或其他非易失性技术。
>    - **IRAM**: 由于基于SRAM技术，访问速度通常较快。
>
> 3. **用途**:
>    - **IROM**: 主要用于存储程序代码，特别是那些不需要频繁修改的代码。
>    - **IRAM**: 用于存储运行时数据，如堆、栈和其他动态数据。
>
> 4. **写入周期**:
>    - **IROM**: 由于通常基于闪存，写入周期可能有限，而且比RAM慢得多。
>    - **IRAM**: 可以被快速写入，并且写入周期是无限的。
>
> 5. **大小**:
>    - **IROM**: 在很多微控制器上，IROM的大小比IRAM大，因为代码通常需要更多的空间。
>    - **IRAM**: 通常比IROM小，因为RAM技术在单位面积上更昂贵。
>
> 6. **电源消耗**:
>    - **IROM**: 在读取时消耗较少的电力。
>    - **IRAM**: 由于基于动态RAM技术，可能需要持续的刷新来保持其内容，从而消耗更多的电力。

值得注意的是，不同的架构和微控制器可能有其自己的定义和约定。因此，当在特定平台或文档上看到这些术语时，最好是查阅相关文档来确定其确切意义。

## 1.17. SRAM (Static Random-Access Memory)

> - **全称**: 静态随机访问存储器（Static Random-Access Memory）。
> - **工作原理**: SRAM 使用晶体管来存储每一位的数据，并且不需要定期刷新来保持其内容。
> - **优点**:
>   - 访问速度快。
>   - 没有刷新周期。
> - **缺点**:
>   - 更昂贵，因为每一位都需要多个晶体管（通常是6个）。
>   - 相对于其它类型的 RAM，它的密度较低。
> - **应用**: 由于其速度，SRAM 通常用作 CPU 的高速缓存。

## 1.18. SDRAM (Synchronous Dynamic Random-Access Memory)

> - **全称**: 同步动态随机访问存储器（Synchronous Dynamic Random-Access Memory）。
> - **工作原理**: SDRAM 存储数据在容量电荷的微小电容上，并需要定期刷新来保持其内容。
> - **优点**:
>   - 相比于 SRAM，每位数据只需要一个晶体管和一个电容，这使得 SDRAM 在相同的面积内可以实现更高的密度。
>   - 由于制造成本较低，因此更便宜。
> - **缺点**:
>   - 需要定期刷新，这会导致额外的延迟。
>   - 访问速度较 SRAM 慢。
> - **应用**: 由于其成本和密度的优势，SDRAM 通常用作主存储器（例如，在计算机和许多嵌入式系统中的主 RAM）。

## 1.19. CCMRAM (Core Coupled Memory RAM)

> CCMRAM(Core Coupled Memory RAM)是Arm Cortex-M系列MCU中的一种特殊的高速内存。
>
> 其主要特征是:
>
> - 与核心(Core)通过总线紧密相连(Coupled),速度很快
> - 容量较小,通常几十KB到几百KB
> - 用于存放关键程序和数据,提高访问速度
>
> CCMRAM的优点包括:
>
> - 零等待状态访问,速度快,通常与CPU同频运行
> - 提高实时性和确定性,用于存放实时任务
> - 降低功耗,内核可以直接访问CCMRAM,无需通过总线
>
> CCMRAM常见的使用场景:
>
> - 存放实时操作系统的核心代码和关键数据结构
> - 频繁访问的程序代码,如中断服务例程
> - 需要低延迟存取的变量,如PID控制的中间变量
> - 缓存CPU与其他内存之间的高速数据交换
>
> 总而言之,CCMRAM是MCU中一块关键的高速内存,通过与内核紧密集成提升实时性和性能。正确利用CCMRAM可以优化系统的性能指标。
