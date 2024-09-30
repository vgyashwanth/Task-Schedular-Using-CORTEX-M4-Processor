#ifndef __TASK__
#define __TASK__

#include"StackAddressing.h"
#include<stdint.h>
#define TASK_PRIVATE_STACK_SIZE  (1024U)
#define TASK_BLOCK_STATE 0x00U
#define TASK_READY_STATE 0xFFU
/* the size of the private stack depends on the task size and how many function calls present in the task
    as of now 1KB but can be changed in future
 */

#define T1_STACK_START (SRAM_END)
#define T2_STACK_START ( (SRAM_END-(1*TASK_PRIVATE_STACK_SIZE)) )
#define T3_STACK_START ( (SRAM_END-(2*TASK_PRIVATE_STACK_SIZE)) )
#define T4_STACK_START ( (SRAM_END-(3*TASK_PRIVATE_STACK_SIZE)) )
#define IDLE_STACK_START ( (SRAM_END-(4*TASK_PRIVATE_STACK_SIZE)) )

typedef struct 
{
    /* data */
    uint32_t CurrentPSP;
    uint32_t block_tick;
    uint8_t  Task_state;
    void (*TasksBaseAddress)(void);

}TCB;

/*Stores the no of user tasks*/
#define MAX_TASKS 5U



/* Tasks declaration */
void Task1(void);
void Task2(void);
void Task3(void);
void Task4(void);
/*we need to run the idle task when all other tasks are blocked*/
void IdleTask(void);
void BlockTask(uint32_t ticks);
void UpdateTask(void);
void UpdateTaskState(void);

#endif