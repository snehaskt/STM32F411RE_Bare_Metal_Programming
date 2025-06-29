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

### 3. **GPIO Control using BSRR Register**
- This project demonstrates GPIO output pin control using the **BSRR (Bit Set/Reset Register)** on the STM32F411RE microcontroller.
- Instead of using the `ODR` register for setting or clearing output pins, this project utilizes `BSRR` for **atomic pin manipulation**.
- Helps avoid **read-modify-write hazards** in real-time embedded systems.
- Written using **bare-metal Embedded C** with direct register access, no HAL or LL libraries.

### 4. **GPIO Input (Button Read)**
- Configures GPIO pin as **input** to read external button state
- Demonstrates pull-down resistor config and input reading via IDR
- Toggles output based on input
- Fully written in **bare-metal C** using STM32 register definitions

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

