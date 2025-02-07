# Blinky LED Example
This is a simple example program that demonstrates how to toggle two LEDs on and off using the Zephyr RTOS. The program is written in C and is intended to run on a microcontroller supported by Zephyr.


## Description
The program toggles two LEDs (led0 and led1) on and off at a specified interval (500 milliseconds). The state of each LED is printed to the console every time it changes.

## Requirements
Zephyr RTOS supported microcontroller board with at least two LEDs to toggle them.
A Hardware Setup ensure that your development board has two LEDs defined in the device tree as led0 and led1. If your board does not have these aliases, you may need to modify the device tree or use different GPIO pins.

## Software Setup
Install Zephyr RTOS and set up your development environment by following the [Zephyr Getting Started Guide](https://docs.zephyrproject.org/latest/develop/getting_started/index.html).

Clone this repository or copy the provided code into your Zephyr project directory.
```
    git clone blinky
```

Install OpenOCD and set up your debugger ans flash tool by following the [Flash and debug host tools](https://docs.zephyrproject.org/latest/develop/flash_debug/host-tools.html#flash-debug-host-tools)


Build and flash the program to your development board and replace board name with your board.
```
    build_flash.bat
```
