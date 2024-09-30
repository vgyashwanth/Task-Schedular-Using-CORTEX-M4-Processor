#ifndef __STACK__
#define __STACK__
#include<stdint.h>
#define SRAM_START  (0x20000000U)
#define SRAM_SIZE   (128*1024U)
/*beforing entering into main startup function will get call ri8, so during calling main from startup MSP value 
is getting updated to 8 bytes less so -8 for storing the return address may be 
anyways once control entered into main it will stuck in while(1) so 8 bytes can be overwritten, no need to subtract 
8 bytes from SRAM_END
After running the code it concluded that we have to subtract 0x8u or else Bus_fault exception is encountring
it's because of stack mis allignment (not exactly known) so we have to subtract number multiple of 4 i.e 4,8,12,....
*/
#define SRAM_END    (SRAM_START + SRAM_SIZE-0x8U) 

#define MSP_START   ( (SRAM_END-(MAX_TASKS*TASK_PRIVATE_STACK_SIZE)) )   

#define DUMMY_XPSR  (0x01000000U)
#define LR_VAL      (0xFFFFFFFDU) 
__attribute__((naked))void SetMSP(void);
__attribute__((naked))void ChangeSPtoPSP(void);
uint32_t GetCurrentPSP(void);
void InitializeTasksPrivateStack(void);
void StoreCurrentPSP(uint32_t current_psp_val);

#endif