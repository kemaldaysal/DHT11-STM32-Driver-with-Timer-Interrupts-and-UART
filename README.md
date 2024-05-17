**General Information and References**
-

* This project is created and tested with STM32F070RB. When implementing this code to other projects with different MCUs, the configurations of pins, DHT11, timer and UART, and also the timer's prescaler values based on MCU's frequency will need to be changed.
* Before starting, measuring period (default (min) 1150ms) can be changed by adjusting the period parameter in main start function (start_dht11_timer_and_uart), located in application_layer_driver.c.    

**Things to do before trying the project codes**
-

1) DHT11, timer and UART drivers' header files and source codes are located in /Drivers/Hardware_Drivers /Inc and /Src files. Because STM32CubeIDE doesn't have default paths to these folders, these folders should be added to project's path, in order to resolve the "header files and source codes can't be found" error. To do so, user should right-click to the project, then Properties -> C/C++ Build -> Settings -> MCU GCC Compiler -> Include Paths, then add the /Hardware_Drivers/Inc folder to the path.
2) To use UART's TX and console write functions without errors and to display the float variables succesfully on serial console, user should enable the "Use float with printf from newlib-nano (-u _print_float)" setting. To do so, user should right-click to the project, then Properties -> C/C++ Build -> Settings -> MCU Settings and then enable the tickbox for "Use float with printf from newlib-nano (-u _print_float)".

**Known Bugs and Limitations**
-

* Because of DHT11 having 1 Hz polling rate (meaning only one read per second) and the other codes taking some time (even in one of the shortest and time-efficient forms), when the waiting time between measurements goes below 1150ms, the dht11 starts to fail to reply to the MCU's start signals. For now, a preventation function is added if enters a measurement period parameter lower than 1150ms. To do this, the function basically fixes the period to 1150ms (lowest possible in my code and config, as far as i could found).
* Because of the majority of main functions working with timer interrupts (instead of blocking HAL delays and other delays) and the used timer is a 16-bit timer, the period between measurements parameters' max value is 65535 (2^16) milliseconds, which is 65.5 seconds, in this configuration functions. If a measurement period longer than 65.5 seconds is needed in some applications, a new timer function with a different timer prescaler approach is needed.       

**To Do List**
-
