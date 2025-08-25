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

### 5. **UART Transmission using Polling**
- Configures USART2 to send data using polling-based method
- Uses TXE flag to ensure data register is ready before sending
- Written in bare-metal C using register definitions (no HAL)

### 7. **UART TX Modular Driver**
- Implements UART transmission using a modular driver architecture
- Separates initialization and transmit functions into reusable components
- Written in pure Embedded C using STM32 register-level access (no HAL)

### 8. **UART TX/RX Modular Driver**
- Implements UART transmit and receive using polling (TXE and RXNE)
- Fully modular: separates config, send, and receive functions
- Register-level firmware (no HAL) using CMSIS headers


### 9. **ADC - Single Conversion Mode**
- Demonstrates single conversion of analog input using ADC
- Uses PA1 as analog input pin
- Basic bare-metal ADC configuration and reading

### 9.0 **ADC - Continuous Conversion Mode**
- Demonstrates continuous ADC conversion without software trigger
- ADC continuously updates data register with latest analog value
- Helps in real-time sensor tracking applications

### 9.1. **ADC - LDR Sensor Interfacing**
- Reads analog light level from an LDR sensor
- Displays "Light is ON" or "Light is OFF" via UART based on threshold
- Shows practical use-case of sensor and ADC integration


---


### 10. **System Tick Timer (SysTick)**

- Implements the **Cortex-M4's internal SysTick timer** to create precise time delays  
- Configured using registers: `CTRL`, `LOAD`, and `VAL`  
- No HAL/LL used — purely **bare-metal register-level programming**
- Useful in:
  - Creating time delays
  - Task scheduling in RTOS
  - Generating periodic interrupts
- Demonstrates how to:
  - Enable the SysTick timer
  - Generate delay using polling
  - Understand internal system timer operation of ARM Cortex-M cores

---


### 11. **TIM2 General Purpose Timer**
- Demonstrates configuration of TIM2 as a 32-bit up/down counter
- Uses 16-bit prescaler to generate periodic events
- Compared with SysTick Timer to highlight differences
- Implemented in bare-metal C (no HAL/LL)
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


