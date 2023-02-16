# MDUV380_Testbed


Project for anyone with a new RT-3S or UV380 to attempt to figure out why the CPU in these new radios does not run the OpenGD77 firmware.

The crash seems to occur in FreeRTOS tasks.c  

https://github.com/LibreDMR/MDUV380_Testbed/blob/master/Middlewares/Third_Party/FreeRTOS/Source/tasks.c#L2090

vTaskStartScheduler
