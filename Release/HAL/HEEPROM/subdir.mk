################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/HEEPROM/EEPROM_I2C.c 

OBJS += \
./HAL/HEEPROM/EEPROM_I2C.o 

C_DEPS += \
./HAL/HEEPROM/EEPROM_I2C.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/HEEPROM/%.o: ../HAL/HEEPROM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\1-NTI_course\New folder\RTOS_FinalProject\HAL\HEEPROM" -I"D:\1-NTI_course\New folder\RTOS_FinalProject" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\Free_RTOS" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\MCAL\MTWI" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\HAL\HKEYPAD" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\LIB" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\MCAL\DIO" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\HAL\HLCD" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


