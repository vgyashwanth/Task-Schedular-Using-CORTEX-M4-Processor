#ifndef __MUTEX__
#define __MUTEX__
#include<stdint.h>

uint8_t  MutexAvailable(void);
void TakeMutex();
void ReleaseMutex();
void IncreasePriority(uint8_t task);

#endif