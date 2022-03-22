################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Free_RTOS/croutine.c \
../Free_RTOS/event_groups.c \
../Free_RTOS/heap_1.c \
../Free_RTOS/list.c \
../Free_RTOS/port.c \
../Free_RTOS/queue.c \
../Free_RTOS/stream_buffer.c \
../Free_RTOS/tasks.c \
../Free_RTOS/timers.c 

OBJS += \
./Free_RTOS/croutine.o \
./Free_RTOS/event_groups.o \
./Free_RTOS/heap_1.o \
./Free_RTOS/list.o \
./Free_RTOS/port.o \
./Free_RTOS/queue.o \
./Free_RTOS/stream_buffer.o \
./Free_RTOS/tasks.o \
./Free_RTOS/timers.o 

C_DEPS += \
./Free_RTOS/croutine.d \
./Free_RTOS/event_groups.d \
./Free_RTOS/heap_1.d \
./Free_RTOS/list.d \
./Free_RTOS/port.d \
./Free_RTOS/queue.d \
./Free_RTOS/stream_buffer.d \
./Free_RTOS/tasks.d \
./Free_RTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Free_RTOS/%.o: ../Free_RTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\Free_RTOS" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\HAL\HEEPROM" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\MCAL\MTWI" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\HAL\HKEYPAD" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\LIB" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\MCAL\DIO" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\MCAL\GPI" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\MCAL\MEXTI" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\MCAL\MTIMER0" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\HAL\HLCD" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\HAL\HLED" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\HAL\HSSD" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


