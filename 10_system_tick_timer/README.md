# System Tick Timer (SysTick) - STM32F411RE

This project demonstrates how to configure and use the **SysTick timer** in STM32F411RE microcontroller to generate accurate delays in milliseconds using **bare-metal programming**.

---

## Features

- Configures SysTick for a 1ms time base (based on 16 MHz system clock).
- Implements `systick_delay_ms()` function for precise delays.
- Uses ARM Cortex-M core registers directly
- Demonstrates periodic LED toggling using SysTick delay.

---

## What You’ll Learn

- How the **SysTick** timer works in ARM Cortex-M cores.
- Calculating reload values for desired delay intervals.
- Difference between **SysTick** and peripheral timers.
- Advantages of using SysTick for delay generation and task scheduling.

---

## 📌 Applications

- LED blinking
- Debouncing buttons
- Timing communication intervals
- Cooperative scheduling (basic RTOS concepts)

---
