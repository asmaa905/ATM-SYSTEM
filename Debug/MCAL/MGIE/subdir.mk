################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MGIE/MGIE_Program.c 

OBJS += \
./MCAL/MGIE/MGIE_Program.o 

C_DEPS += \
./MCAL/MGIE/MGIE_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MGIE/%.o: ../MCAL/MGIE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\1-NTI_course\New folder\RTOS_FinalProject\Free_RTOS" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\HAL\HCLCD" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\HAL\HKPD" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\LIB" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\MCAL\MDIO" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\MCAL\MGIE" -I"D:\1-NTI_course\New folder\RTOS_FinalProject\MCAL\MUSART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


