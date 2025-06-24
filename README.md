# STM32F411RE_Bare_Metal_Programming
Bare_metal_programming
# STM32F411RE Bare-Metal Programming

This repository contains a collection of **bare-metal embedded C projects** for the STM32F411RE microcontroller using direct register-level programming (no HAL/LL libraries). Each project focuses on understanding and configuring STM32 peripherals from scratch, aligning with ARM Cortex-M architecture and CMSIS standards.

---

## 📌 Objective

To strengthen embedded systems development skills by:
- Programming peripherals without any abstraction layer
- Understanding memory-mapped registers, NVIC, clock control, and interrupts
- Creating a clean, modular driver development workflow

---

## 📁 Project List

### 1. **LED Toggle using Address and Structure**
- Blinks an onboard LED using GPIO port configuration
- Implemented with both direct register access and `typedef` struct-style register mapping

### 2. **GPIO Output Project**
- Drives output pins using GPIO register configuration
- Demonstrates bit manipulation, `MODER`, `ODR` usage

---

## ⚙️ Tools Used

- **Microcontroller**: STM32F411RE (ARM Cortex-M4)
- **IDE**: STM32CubeIDE / VS Code (optional)
- **Language**: Embedded C
- **Toolchain**: ARM GCC
- **Debugger**: ST-Link / OpenOCD
- **Documentation Reference**: STM32F411RE Reference Manual & Datasheet

---

## 📚 Learning Focus

- Writing peripheral drivers manually (GPIO, UART, ADC, etc.)
- Understanding memory layout, vector table, and startup code
- Using CMSIS-style register maps
- Interrupt configuration with NVIC
- Linking, flashing, and debugging without HAL

