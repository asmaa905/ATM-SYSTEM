################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MTWI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/HLCD/subdir.mk
-include HAL/HKEYPAD/subdir.mk
-include HAL/HEEPROM/subdir.mk
-include Free_RTOS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
RTOS_FinalProject.lss \

FLASH_IMAGE += \
RTOS_FinalProject.hex \

EEPROM_IMAGE += \
RTOS_FinalProject.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: RTOS_FinalProject.elf secondary-outputs

# Tool invocations
RTOS_FinalProject.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,RTOS_FinalProject.map -mmcu=atmega32 -o "RTOS_FinalProject.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

RTOS_FinalProject.lss: RTOS_FinalProject.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S RTOS_FinalProject.elf  >"RTOS_FinalProject.lss"
	@echo 'Finished building: $@'
	@echo ' '

RTOS_FinalProject.hex: RTOS_FinalProject.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex RTOS_FinalProject.elf  "RTOS_FinalProject.hex"
	@echo 'Finished building: $@'
	@echo ' '

RTOS_FinalProject.eep: RTOS_FinalProject.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex RTOS_FinalProject.elf  "RTOS_FinalProject.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: RTOS_FinalProject.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 RTOS_FinalProject.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) RTOS_FinalProject.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
