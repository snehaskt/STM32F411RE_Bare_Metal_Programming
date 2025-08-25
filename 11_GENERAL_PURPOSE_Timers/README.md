# 11. TIM2 General Purpose Timer

### Overview
This project demonstrates the configuration and usage of **TIM2**, a general-purpose timer on the STM32F411RE microcontroller.

### Key Features
- **32-bit up/down counter** with a **16-bit prescaler**
- Configured to generate periodic time events
- Compared with **SysTick Timer** to understand differences
- Implemented in **bare-metal C** 

### Learning Highlights
- How to enable TIM2 clock
- Setting prescaler and auto-reload register
- Polling update flag to detect overflow
- Understanding difference between SysTick and general-purpose timers

### Real-time Applications
- Event counters
- Periodic interrupts
- Generating precise delays
- PWM generation (with further configuration)
