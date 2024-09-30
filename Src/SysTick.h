#ifndef __SYS_TICK__
#define __SYS_TICK__
#include<stdint.h>

#define SYST_CSR (*(volatile uint32_t *)0xE000E010) 
#define SYST_RVR (*(volatile uint32_t *)0xE000E014)
#define SYST_CVR (*(volatile uint32_t *)0xE000E018)

void ConfigureSystickInterrupt(uint16_t time_ms);

#endif