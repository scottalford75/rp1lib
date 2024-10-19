# rp1lib

User space memory mapped peripheral library for the Raspberry Pi RP1 chip.

This library utilises:

1. gpiochip_rp1 library for GPIO control
2. spi-dw library, based on spi-dw-core kernel library, for SPI

This library can hopefully form the base for a fully functional RP1 library to include the other hardware features of the RP1 chip. I2C, PWM etc.

The example program used Code::Block IDE and was written on the RPI5 for testing.

