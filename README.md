# Time Clock Project

**** system description: ****

Simple clock project that simulate real time usind 
- green led represents second
- 2_Seven segment represents minutes
- 2_Seven segment represents houres

**** What are the components to make that system? ****

    • 1 Green LED.
    • 4 Seven Segment.
    • Microcontroller (we use ATMEGA32).

**** system design: ****

Time starts from 00:00 to 23:59 then repeats itself

So, it consists of 4 parts:

    • HAL  
    • MCAL 
    • LIB
    • Application
  
Each level of them contains some of driver which control the whole system.

     • HAL ➔ Seven Segment driver.
     • MCAL ➔ DIO driver.
     • LIB ➔ Memory Map & Standerd Macros & Standerd Types.
     • Application ➔ final level of the system.
  
So, when the system starts it will loop forever for changing the state of Clock
