#include"Mutex.h"
#include"Tasks.h"
#include"CriticalSection.h"
extern uint8_t current_task;

void CriticalSection(void){

        if(MutexAvailable()){

                IncreasePriority(current_task);  /*To avoid priority Inversion*/
                TakeMutex();
                /* Write Critical Section code here */
                BlockTask(50);
                ReleaseMutex();


        }

}
