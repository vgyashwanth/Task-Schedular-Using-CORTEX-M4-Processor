#include"StackAddressing.h"
#include"Tasks.h"
#include<stdint.h>
#include"IntExc.h"
/* to keep the track on tasks */
uint8_t current_task = 1;

/* Creating the TCB for user Tasks */
TCB UserTasks[MAX_TASKS];

__attribute__((naked))void SetMSP(void){
    /* __attribute__((naked)) to avoid the prolog and epilog code which modefied the MSP */
    /* to access the MSP use inline assembly */
    __asm volatile("MOV R0,%0":/*output operands*/:"r"(MSP_START):);
    __asm volatile("MSR MSP,R0");
    __asm volatile("BX LR");
    


}
void InitializeTasksPrivateStack(void){
        /*Disable all exceptions*/
        DisableExc();

        UserTasks[0].CurrentPSP = IDLE_STACK_START;
        UserTasks[0].Task_state = TASK_READY_STATE;
        UserTasks[0].Task_priority = 255; /*Lowest priority*/
        UserTasks[0].TasksBaseAddress = IdleTask;

        UserTasks[1].CurrentPSP = T1_STACK_START;
        UserTasks[1].Task_state = TASK_READY_STATE;
        UserTasks[1].Task_priority = 1; /*Static priority*/
        UserTasks[1].TasksBaseAddress = Task1;

        UserTasks[2].CurrentPSP = T2_STACK_START;
        UserTasks[2].Task_state = TASK_READY_STATE;
        UserTasks[2].Task_priority = 2; /*Static priority*/
        UserTasks[2].TasksBaseAddress = Task2;

        UserTasks[3].CurrentPSP = T3_STACK_START;
        UserTasks[3].Task_state = TASK_READY_STATE;
        UserTasks[3].Task_priority = 3; /*Static priority*/
        UserTasks[3].TasksBaseAddress = Task3;

        UserTasks[4].CurrentPSP = T4_STACK_START;
        UserTasks[4].Task_state = TASK_READY_STATE;
        UserTasks[4].Task_priority = 4; /*Static priority*/
        UserTasks[4].TasksBaseAddress = Task4;


        for(uint8_t i = 0;i<MAX_TASKS;i++){

            uint32_t * ptr = (uint32_t*)UserTasks[i].CurrentPSP;

            /*storing xpsr with thumb bit = 1*/
            *ptr = (uint32_t)DUMMY_XPSR;
            ptr --;
            /*storing PC but this will get updated by task schedular*/
            *ptr = (uint32_t)UserTasks[i].TasksBaseAddress;
            ptr--;
            /*storing LR with exec_return value we are storing 0xFFFFFFFD*/
            *ptr = (uint32_t)LR_VAL;
          
            /*storing remaining general purpose registers with zero*/
            for(uint8_t reg = 0;reg<13;reg++)
                {    
                     ptr--;
                    *ptr = 0x00;
                  
                }

                UserTasks[i].CurrentPSP = (uint32_t)ptr; /*storing the PSP val*/


        }
        /* Enable all Exceptions */
        EnableExc();


}

uint32_t GetCurrentPSP(void){

        return UserTasks[current_task].CurrentPSP;

}
__attribute__((naked))void ChangeSPtoPSP(void){
      
	__asm volatile("PUSH {LR}");
        __asm volatile("BL GetCurrentPSP");
        /*If we write __asm volatile("POP {LR}"); at bottom then cpu refer to PSP which is invalid HardFault()*/
         __asm volatile("POP {LR}");
        __asm volatile("MSR PSP,R0"); /* the return value of the function just called above will store in R0 as per AAPCS*/
        __asm volatile("MOV R0,#0X02");
        __asm volatile("MSR CONTROL,R0"); /* change to SP to PSP*/
       
        __asm volatile("BX LR");




}
void StoreCurrentPSP(uint32_t current_psp_val){

     DisableExc();
    UserTasks[current_task].CurrentPSP = current_psp_val;
     EnableExc();
     
}
