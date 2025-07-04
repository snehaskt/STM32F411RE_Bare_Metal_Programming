# 5_UART_TX – UART Transmission using Polling (STM32 Bare-Metal)

This project demonstrates how to transmit data over UART using **polling method** on the STM32F411RE microcontroller. It is written in pure embedded C using **register-level access**, with no HAL or library dependencies.

## Features

- Configures USART2 peripheral for data transmission
- Sends a static string continuously via UART
- Uses polling method (TXE flag) to load data into data register
- Clock and pin setup configured via RCC and GPIO registers

## Tools Used

- STM32F411RE Nucleo board
- STM32CubeIDE or custom Makefile
- UART terminal (TeraTerm, PuTTY) for serial monitoring
- Baud rate: 9600 bps

##  Learning Objectives

- Understanding USART registers (BRR, CR1, DR, SR)
- Using polling method to check TXE and TC flags
- Register-level peripheral initialization (RCC, GPIO, AF)

##  Note

Written without HAL/LL libraries for better understanding of low-level microcontroller architecture.
