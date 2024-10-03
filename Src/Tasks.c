#include"StackAddressing.h"
#include"Tasks.h"
#include"IntExc.h"
extern uint8_t current_task;
extern TCB UserTasks[MAX_TASKS];
/* this value will get updated when Systick exception happens */
uint32_t global_tick = 0;
/* as of now  the tasks never terminate and never return once they called but can be changed in future */
void Task1(void){
    while(1){

        /* write the application here */
        int a = 10;
        BlockTask(10);
    }
}
void Task2(void){
    while(1){

        /* write the application here */
        int a = 10;
        BlockTask(2);
    }
}
void Task3(void){
    while(1){

        /* write the application here */
        int a = 10;
        BlockTask(4);
    }
}
void Task4(void){
    while(1){

        /* write the application here */
       int a = 10; 
        BlockTask(6);
    }
}
void IdleTask(void){

    while(1);

}

void ScheduleTask(void){
    /*

    round robin scheduling algorithm
    checking for the ready tasks and updating the current_task var accordingly, 
    if all tasks are blocked then run idle task
    
    */
    DisableExc();
 
    uint8_t state = TASK_BLOCK_STATE;
    uint8_t previous_task_priority = UserTasks[current_task].Task_priority;
    /* Edge case when current_task is highest priority but present in TASK_BLOCK_STATE */

    if(UserTasks[current_task].Task_state == TASK_BLOCK_STATE){
        /* Choose one task which is in Ready state then later compare the priorites */
        for(uint8_t i=1; i<MAX_TASKS; i++){

            if( UserTasks[i].Task_state == TASK_READY_STATE){

                previous_task_priority = UserTasks[i].Task_priority;
                break;

            }

        }

    }
    for(uint8_t i =1;i<MAX_TASKS;i++){

    state = UserTasks[i].Task_state;
    /*Iterating through all user Tasks and finding the Taks which is ready and low priority */
    if( state == TASK_READY_STATE && UserTasks[i].Task_priority <= previous_task_priority )
    {
        current_task = i;
        previous_task_priority = UserTasks[current_task].Task_priority;

    }
          
    }
    if(state == TASK_BLOCK_STATE)
        current_task = 0;
    
    EnableExc();

}

void BlockTask(uint32_t ticks){
    /*we should not block the idle task*/

      /*Disable all exceptions*/
        DisableExc();

    if(current_task != 0){ /* For avoiding blocking of IDLE Task */

    UserTasks[current_task].block_tick = (global_tick + ticks);
    UserTasks[current_task].Task_state = TASK_BLOCK_STATE;

    }
      /* Enable all Exceptions */
        EnableExc();


}

void UpdateTaskState(void){

    /*Disable all exceptions*/
        DisableExc();

    /*iterating all tasks except Idle one*/
    for(int i = 1;i<MAX_TASKS;i++){
        /*if the task in blocked state*/
        if(UserTasks[i].Task_state == TASK_BLOCK_STATE ){

                /* if the requried block time is elapsed */
                if(UserTasks[i].block_tick == global_tick){

                    UserTasks[i].Task_state  = TASK_READY_STATE;

                }

        }

    }

     /* Enable all Exceptions */
        EnableExc();

      
}
