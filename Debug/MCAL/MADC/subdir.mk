################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MADC/MADC_program.c 

OBJS += \
./MCAL/MADC/MADC_program.o 

C_DEPS += \
./MCAL/MADC/MADC_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MADC/%.o: ../MCAL/MADC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\Free_RTOS" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\HAL\HEEPROM" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\MCAL\MTWI" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\HAL\HKEYPAD" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\LIB" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\MCAL\DIO" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\MCAL\GPI" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\MCAL\MEXTI" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\MCAL\MTIMER0" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\HAL\HLCD" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\HAL\HLED" -I"C:\Users\PC\Desktop\project\RTOS_FinalProject\HAL\HSSD" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


