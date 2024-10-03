#include"IntExc.h"
__attribute__((naked))void EnableExc(void){

    __asm volatile("MOV R1,#0x00");
    __asm volatile("MSR PRIMASK,R1");
    __asm volatile("BX LR");

}
__attribute__((naked))void DisableExc(void){

    __asm volatile("MOV R1,#0x01");
    __asm volatile("MSR PRIMASK,R1");
     __asm volatile("BX LR");

}