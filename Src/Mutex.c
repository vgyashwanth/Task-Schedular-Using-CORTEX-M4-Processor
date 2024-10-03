#include"Mutex.h"
#include"Tasks.h"
extern int current_task;
extern TCB UserTasks[MAX_TASKS];
uint8_t Mutex = 1;

uint8_t  MutexAvailable(void){

        return Mutex;
}
void TakeMutex(){

    if( Mutex==1 )
         Mutex--;
   
}
void ReleaseMutex(){
    
    if(Mutex==0)
        Mutex++;
    
}
void IncreasePriority(uint8_t task){

    UserTasks[task].Task_priority = 0x00;
    
}
