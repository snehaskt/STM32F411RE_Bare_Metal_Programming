# 9.1 - ADC Continuous Conversion Mode (STM32F411RE)

### Description
This project demonstrates **continuous analog-to-digital conversion** using the ADC peripheral of STM32F411RE. Unlike single conversion mode, the ADC continuously samples an analog voltage from a pin without needing software to start every conversion.

### Key Concepts
- Continuous conversion mode of ADC
- PA1 (ADC Channel 1) is used as analog input
-  fully bare-metal register-level development
- Polling-based method used to read ADC values in a loop

### Configuration Highlights
- ADC Channel: ADC1_IN1 (connected to PA1)
- Mode: Continuous Conversion (CONT bit enabled)
- Resolution: 12-bit
- Conversion status monitored with EOC flag
- Output printed via `printf()` using semihosting or UART

### Use Case
Useful when continuous analog monitoring is required, like:
- Battery voltage tracking
- Temperature sensor feedback loop
- LDR or potentiometer analog value tracking

### Tools Used
- STM32CubeIDE
- STM32F411RE Nucleo Board
- No HAL libraries (bare-metal C)

---

✅ Developed as part of STM32 bare-metal peripheral driver learning.
