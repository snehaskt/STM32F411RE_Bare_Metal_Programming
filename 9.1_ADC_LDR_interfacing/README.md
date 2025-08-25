
# 9.1 - ADC LDR Sensor Interfacing (STM32F411RE)

### Description
This project demonstrates interfacing an **LDR (Light Dependent Resistor)** with STM32F411RE using the ADC peripheral. The system monitors ambient light levels and displays messages via UART based on brightness.

### Key Features
- Reads analog voltage from LDR using ADC (PA1)
- Converts voltage to digital value using 12-bit ADC
- Compares value to a light threshold
- Displays "Light is ON" or "Light is OFF" via UART

### Technical Highlights
- ADC Channel: PA1 (ADC1_IN1)
- Threshold Value: Defined in code (e.g., 2000 out of 4095)
- Communication: UART2 TX using polling (printf or uart2_write_string)
- Bare-metal register-level coding, no HAL

###  Hardware Setup
- LDR connected to PA1 (via A0 pin from sensor)
- Power: 3.3V VCC from STM32 board
- Common GND shared between STM32 and sensor
- LED indicators can optionally show light/dark status
