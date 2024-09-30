#include"IntExc.h"
__attribute__((naked))void EnableExc(void){

    __asm volatile("MOV R0,#0x00");
    __asm volatile("MSR PRIMASK,R0");
    __asm volatile("BX LR");

}
__attribute__((naked))void DisableExc(void){

    __asm volatile("MOV R0,#0x01");
    __asm volatile("MSR PRIMASK,R0");
    __asm volatile("BX LR");

}