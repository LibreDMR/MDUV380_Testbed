# MDUV380_Testbed


Project for anyone with a new RT-3S or UV380 to attempt to figure out why the CPU in these new radios does not run the OpenGD77 firmware.

To build this test project you need to download and install STM32CubeIDE from https://www.st.com/en/development-tools/stm32cubeide.html  then import the project


The project contains a minimal set of files necessary to write to demonstrate the problem, and to debug either by flashing the green / red, or writing messages to the screen or the radio or to write text to the USB Serial port.



From experiments done by VE2NCK, the crash seems to occur in FreeRTOS tasks.c  

https://github.com/LibreDMR/MDUV380_Testbed/blob/master/Middlewares/Third_Party/FreeRTOS/Source/tasks.c#L2090

vTaskStartScheduler


No more information is known about the crash at the moment, and I do not personally have a radio with a non-genuine CPU (STM32F407VTG) 
