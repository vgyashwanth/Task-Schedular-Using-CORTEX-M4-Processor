#include"Mutex.h"
extern uint8_t current_task;
void CriticalSection(void);
void CriticalSection(void){

        if(MutexAvailable()){

                IncreasePriority(current_task);
                TakeMutex();
                /* Write Critical Section code here */
                ReleaseMutex();


        }

}