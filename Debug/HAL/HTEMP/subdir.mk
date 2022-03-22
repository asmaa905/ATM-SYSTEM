################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/HTEMP/HTEMP_SENSOR_prg.c 

OBJS += \
./HAL/HTEMP/HTEMP_SENSOR_prg.o 

C_DEPS += \
./HAL/HTEMP/HTEMP_SENSOR_prg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/HTEMP/%.o: ../HAL/HTEMP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\1-NTI_course\New folder\RTOS_FinalProject\Free_RTOS" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\HAL\HKEYPAD" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\LIB" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\MCAL\DIO" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\MCAL\GPI" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\MCAL\MEXTI" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\MCAL\MTIMER0" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\HAL\HLCD" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\HAL\HLED" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\HAL\HSSD" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


