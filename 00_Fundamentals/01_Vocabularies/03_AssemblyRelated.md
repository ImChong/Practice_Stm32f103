# 1. 汇编术语

- [1. 汇编术语](#1-汇编术语)
  - [1.1. 启动文件](#11-启动文件)
  - [1.2. 常用的汇编指令](#12-常用的汇编指令)

## 1.1. 启动文件
> 在嵌入式系统中，启动文件（通常也叫启动代码、启动程序或启动例程）有着非常重要的作用。这些文件通常是汇编语言或低级C语言编写的，它们作为整个嵌入式软件的入点，并负责初始化硬件以及准备软件环境，以便主程序（通常是一个C语言的 `main()` 函数）能正常运行。
>
> 下面列举了启动文件通常需要完成的一些任务：
>
> ### 1.1.1. 复位向量和中断向量的设
> 启动文件通常包含一个向量表，该表定义了各种中断和异常的处理程序入口点。最重要的通常是复位向量，它指向系统复位后应执行的第一条指令。
>
> ### 1.1.2. 初始化数据段和BSS段
> 全局和静态变量可能需要在RAM中进行初始化。对于初值不为零的变量，启动代码会把这些变量的初值从Flash或其他非易失存储器复制到RAM中。对于初值为零或未初始化变> 量（通常位于BSS段），启动代码通常会将这些变量的内存区域清零。
>
> ### 1.1.3. 设置堆和栈
> 启动文件通常负责设置栈指针，以及在需要的情况下初始化堆。
>
> ### 1.1.4. 初始化硬件
> 一些嵌入式系统可能需要在主程序运行之前进行特定的硬件初始化，如配置时钟、初始化内存控制器、设置GPIO模式等。
>
> ### 1.1.5. 跳转到主程序
> 最后，启动文件将控制权转交给主程序，通常是C语言的 `main()` 函数。
>
> ### 1.1.6. 附加功能
> 在一些复杂的系统中，启动文件还可能涉及更多的任务，比如执行一些自检（self-test）、加载操作系统、设置多核CPU环境等。
>
> 总体来说，启动文件在嵌入式系统中起到“铺路”的作用，确保硬件和软件环境都准备就绪，以便应用程序能够正确、有效地运行。
>
> ### 1.1.7. 异常服务例程（ESR）
> 异常服务例程（ESR: Exception Service Routine）是一种在嵌入式系统中用于处理异常的代码段。当系统发生异常时，处理器会跳转到相应的异常处理程序，然后执行相应的 ESR。ESR 可以用于处理各种异常，例如中断、系统调用、页错误等。在 ARM 处理器中，ESR 通常由操作系统内核提供，并且可以根据需要进行自定义。ESR 可以访问 CPU 寄存器和内存，因此可以执行各种操作，例如保存 CPU 状态、记录日志、发送信号等。ESR 的实现需要考虑到多线程和多核心的情况，以确保系统的稳定性和可靠性。
>
> ### 1.1.8. 中断处理程序（Interrupt Handler）& 中断服务例程（ISR: Interrupt Service Routine）
> 在嵌入式系统中，中断处理程序（Interrupt Handler），也常被称为中断服务程序（Interrupt Service Routine, ISR）或中断处理子程序，是一段特定的代码，用于响应和处理来自外部或内部源的中断请求。
>
> 中断是一个重要的机制，允许硬件设备或内部系统事件通知处理器需要采取某些行动。当一个中断事件发生时，当前正在执行的代码被暂停，处理器保存当前的执行上下文，然后跳转到与该中断相关联的中断处理程序进行处理。完成中断处理后，处理器将恢复被打断的执行上下文，并继续执行被中断的代码。
>
> 以下是中断处理程序的一些关键特点和作用：
>
> 1. **响应事件**：中断处理程序允许处理器迅速响应外部事件，如按钮按下、定时器溢出或串行通信中的数据到达。
>
> 2. **实时性**：在许多实时系统中，中断提供了满足实时约束的机制，确保系统能够及时响应关键事件。
>
> 3. **上下文保存和恢复**：当中断发生时，处理器保存当前任务的状态或上下文，以便在中断处理结束后恢复。这通常涉及保存一些或所有的处理器寄存器。
>
> 4. **短暂**：为了不过度延迟其他活动，ISRs 通常需要尽快执行并结束。因此，推荐的做法是让 ISR 尽可能短，并避免在其中执行长时间的操作。
>
> 5. **优先级**：多个中断源可能具有不同的优先级。有的中断处理程序可能被设计为可以被更高优先级的中断所打断，而某些中断可能被设置为不可被打断的。
>
> 6. **嵌入式系统的典型应用**：在嵌入式系统中，ISRs 常用于处理如按键输入、传感器数据读取、通信接口的数据传输等任务。
>
> 为了正确使用中断和避免潜在的问题（如资源竞争、嵌套中断等），设计和实现中断处理程序时需要谨慎。确保中断逻辑简单明了，并尽量减少 ISR 的执行时间，是良好中断处理设计的关键要素。

>
> ### 1.1.9. NMI（Non-Maskable Interrupt）中断
>NMI 是 "Non-Maskable Interrupt" 的缩写，中文常称为“不可屏蔽中断”。与常规可屏蔽（maskable）中断不同，NMI 是一种特殊类型的中断，通常用于处理紧急或高优先级的任务。一旦 NMI 被触发，它不能被其他中断或程序代码屏蔽或禁用，从而确保即时的响应。
>
> 在嵌入式系统和微控制器，如 STM32 系列中，NMI 通常用于处理一些非常重要的硬件错误或特殊事件，例如：
>
> - 系统复位或低电压检测
> - 外部硬件错误或失败
> - 内存错误或校验失败
> - 其他需要立即处理的紧急情况
>
> 由于 NMI 是不可屏蔽的，因此在编程时需要特别小心，确保 NMI 中断处理程序（Interrupt Handler）能够尽快返回，避免影响系统的其他部分。
>
> NMI 的具体用途和行为取决于特定的硬件和应用需求。在使用 NMI 之前，建议详细阅读相应微控制器或嵌入式系统的数据手册和参考手册，以了解其行为和限制。
>
> ### 1.1.10. PC 指针: 程序计数器（Program Counter）
> 在嵌入式软件中，PC 指针通常指的是 **程序计数器**（Program Counter），它是一种用于存储下一条指令地址的寄存器。在 CPU 执行指令时，它会从 PC 指针所指向的地址处读取下一条指令，并将 PC 指针自动递增，以指向下一条指令的地址。因此，PC 指针在程序执行过程中起着非常重要的作用，它可以控制程序的执行流程，使程序按照预期的顺序执行。
>
> 在嵌入式系统中，PC 指针通常由编译器和调试器自动管理，因此程序员不需要手动操作 PC 指针。但是，在某些情况下，程序员可能需要手动修改 PC 指针的值，例如在实现跳转指令、异常处理等方面。此时，程序员需要非常小心地操作 PC 指针，以确保程序的正确性和稳定性。
>

## 1.2. 常用的汇编指令
> 汇编指令的种类和具体格式取决于目标处理器架构。以下是一些在各种处理器架构中常见的汇编指令类型，以及它们大致的功能描述：
>
> ### 1.2.1. x86/x86-64架构
> x86 架构的 CPU 采用复杂指令集（CISC），指令集非常复杂，每个指令的执行时间都比较长。x86 指令集中的指令通常有不同的长度，包括 8 位、16 位、32 位和 64 位等。x86 指令集中还包括一些特殊用途的指令，例如浮点运算和字符串操作等。
> - `MOV`: 数据传输
> - `ADD` / `SUB`: 加法和减法
> - `MUL` / `DIV`: 乘法和除法
> - `AND` / `OR` / `XOR` / `NOT`: 位运算
> - `PUSH` / `POP`: 压栈和出栈
> - `JMP`: 无条件跳转
> - `JE` / `JNE` / `JZ` / `JNZ` 等：条件跳转
> - `CALL`: 函数调用
> - `RET`: 函数返回
>
> ### 1.2.2. ARM架构
> ARM 架构的 CPU 采用精简指令集（RISC），指令集非常简单，每个指令的执行时间都很短，因此可以提高 CPU 的运行速度。ARM 指令集中的指令通常只有 32 位，而且大多数指令都是条件执行的，这意味着它们只在满足某些条件时才会被执行。ARM 指令集还包括一些专门用于处理向量数据的指令，这些指令可以同时处理多个数据元素。
> - `EQU`: 宏定义的伪指令，相当于等于，类似与C 中的define。The EQU directive gives a symbolic name to a numeric constant, a register-relative value or a PC-relative value.
> - `AREA`: 告诉汇编器汇编一个新的代码段或者数据段。`STACK` 表示段名，这个可以任意命名；`NOINIT` 表示不初始化；`READWRITE` 表示可读可写，`ALIGN=3`，表示按照2^3 对齐，即 8 字节对齐。
> - `SPACE`: 用于分配一定大小的内存空间，单位为字节。这里指定大小等于Stack_Size。
> - `PRESERVE8`: 指定当前文件的堆栈按照8 字节对齐。
> - `THUMB`: 表示后面指令兼容THUMB 指令。`THUBM` 是 ARM 以前的指令集，16bit，现在 Cortex-M 系列的都使用 `THUMB-2` 指令集，`THUMB-2` 是 32 位的，兼容 16 位 32 位的指令，是 `THUMB` 的超集。
> - `EXPORT`: 声明一个标号可被外部的文件使用，使标号具有全局属性。如果是 `IAR` 编译器，则使用的是 `GLOBAL` 这个指令。
> - `DCD`: 以字为单位分配内存，要求4字节对齐，并要求初始化这些内存。
> - `PROC`: 定义子程序，与 `ENDP` 成对使用，表示子程序结束
> - *`WEAK`: 弱定义，如果外部文件声明了一个标号，则优先使用外部文件定义的标号，如果外部文件没有定义也不出错。要注意的是：这个不是 ARM 的指令，是编译器的，这里放在一起只是为了方便。*
> - `IMPORT`: 声明标号来自外部文件，跟C语言中的 `EXTERN` 关键字类似。
> - `B`: 跳转到一个标号。
> - *`ALIGN`: 编译器对指令或者数据的存放地址进行对齐，一般需要跟一个立即数，缺省表示4字节对齐。要注意的是：这个不是 ARM 的指令，是编译器的，这里放在一起只是为了方便。*
> - `END`: 到达文件的末尾，文件结束。
> - `IF` / `ELSE` / `ENDIF`: 汇编条件分支语句，跟C语言的if else类似。
> - `LDR` / `STR`: 加载 - 从存储器中加载字到一个寄存器中 / 存储
> - `BL`: 跳转到由寄存器 / 标号给出的地址，并把跳转前的下条指令地址保存到LR
> - `BLX`: 跳转到指定寄存器，执行相关函数并返回。跳转到由寄存器给出的地址，并根据寄存器的 `LSE` 确定处理器的状态，还要把跳转前的下条指令地址保存到 `LR`。
> - `BX`: 跳转到指定寄存器，执行相关函数不用返回。跳转到由寄存器 / 标号给出的地址，不用返回。
> - `ADD` / `SUB`: 加法和减法
> - `MUL` / `MLA`: 乘法和乘法-累加
> - `AND` / `ORR` / `EOR` / `BIC`: 位运算
> - `PUSH` / `POP`: 压栈和出栈
> - `B` / `BL`: 分支和分支链接（函数调用）
> - `CMP`: 比较
> - `BEQ` / `BNE` / `BGT` / `BLT` 等：条件分支
>
> ### 1.2.3. MIPS架构
>
> - `LW` / `SW`: 加载字和存储字
> - `ADD` / `ADDI` / `SUB`: 加法和减法
> - `AND` / `OR` / `XOR` / `NOR`: 位运算
> - `J` / `JR` / `JAL`: 跳转和跳转并链接
> - `BEQ` / `BNE`: 条件分支
> - `SLT` / `SLTI`: 设置小于
>
> ### 1.2.4. RISC-V架构
>
> - `LUI` / `AUIPC`: 装载上位立即数
> - `ADD` / `ADDI`: 加法和加法立即数
> - `AND` / `OR` / `XOR`: 位运算
> - `JAL` / `JALR`: 跳转和链接
> - `BEQ` / `BNE` / `BLT` / `BGE`: 条件分支
> - `SW` / `LW`: 存储和加载
>
> 这只是一个非常粗略的概览，各个架构有自己独特的指令集，还有许多其他专用的或者高级的汇编指令。了解具体的汇编指令集通常需要参考该处理器架构的相关文档或手册。
