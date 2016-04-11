# GestureRecog
Simple gesture recognition software for the ARM STM32-F4 Discovery Board and it's Accelerometer. 

Author: Eason Smith  

Requires the ARM toolchain, STM32-F4 Discovery and uses the Standard Peripheral Library.

A basic example is provided in main.c and detects a gesture of holding the board flat for 1 second, 
tilting the board up for 1 second, then holding the board flat for 1 second again. A basic message 
confirming the gesture is then printed to the screen.

To compile:
Run "make clean && make" in the main directory from the command line.

To debug/run using openocd and GDB:

1. Open a new terminal window and run the command:
"openocd -f board/stm32f4discovery.cfg"

2. Then in your main window run:
"arm-none-eabi-gdb STM32_Gesture_example.elf"

To Flash:
Run "st-flash write STM32_Gesture_example.elf 0x8000000" at the command line.
