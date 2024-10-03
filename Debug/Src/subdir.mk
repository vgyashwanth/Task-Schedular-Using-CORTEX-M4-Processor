################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/CriticalSection.c \
../Src/IntExc.c \
../Src/Mutex.c \
../Src/StackAddressing.c \
../Src/SysTick.c \
../Src/Tasks.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/CriticalSection.o \
./Src/IntExc.o \
./Src/Mutex.o \
./Src/StackAddressing.o \
./Src/SysTick.o \
./Src/Tasks.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/CriticalSection.d \
./Src/IntExc.d \
./Src/Mutex.d \
./Src/StackAddressing.d \
./Src/SysTick.d \
./Src/Tasks.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411CEUx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/CriticalSection.cyclo ./Src/CriticalSection.d ./Src/CriticalSection.o ./Src/CriticalSection.su ./Src/IntExc.cyclo ./Src/IntExc.d ./Src/IntExc.o ./Src/IntExc.su ./Src/Mutex.cyclo ./Src/Mutex.d ./Src/Mutex.o ./Src/Mutex.su ./Src/StackAddressing.cyclo ./Src/StackAddressing.d ./Src/StackAddressing.o ./Src/StackAddressing.su ./Src/SysTick.cyclo ./Src/SysTick.d ./Src/SysTick.o ./Src/SysTick.su ./Src/Tasks.cyclo ./Src/Tasks.d ./Src/Tasks.o ./Src/Tasks.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

