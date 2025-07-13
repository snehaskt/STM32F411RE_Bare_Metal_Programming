# 8_UART_RX_TX_modular – UART Transmit & Receive Driver (STM32 Bare-Metal)

This project demonstrates a **modular UART driver** for both **transmit (TX)** and **receive (RX)** functionality using STM32F411RE. The goal is to abstract UART operations into reusable functions using register-level programming.

## 🔧 Features

- Transmits and receives characters using USART2
- Polling-based RX and TX (uses TXE and RXNE flags)
- Modular driver architecture with reusable functions
- No HAL/LL used — all code is register-based and CMSIS-compliant

## 📁 Folder Structure

