#include"SysTick.h"
 

/*

    From the TRM of the microcontroller 
    By reset HSI(16MHz) will be selected as a System clock, and to Systick timer it is divided by 8 i.e (2MHz)
    refer the clock tree of the microcontroller 

*/
void ConfigureSystickInterrupt(uint16_t time_ms){

   /*

   SysTick Interrupt is system exception so no need of NVIC.
   By refering the TRM of microcontroller default priority is 6, but can be changed using System control reigsters in 
   processor 
    use SysTick peripheral register to configure the timer(1ms) and its interrupt

   */ 
    uint16_t no_of_ticks = (time_ms*2000);
    SYST_RVR = (no_of_ticks - 1); //for 1ms
    SYST_CVR = 0X00;
    /* enable interrupt and start the timer */
    SYST_CSR |= (1U<<0)|(1U<<1)|(1U<<2); 



}
