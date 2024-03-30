################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KPD/subdir.mk
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
INT0_INT1_Periority.lss \

FLASH_IMAGE += \
INT0_INT1_Periority.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: INT0_INT1_Periority.elf secondary-outputs

# Tool invocations
INT0_INT1_Periority.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,INT0_INT1_Periority.map -mmcu=atmega32 -o "INT0_INT1_Periority.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

INT0_INT1_Periority.lss: INT0_INT1_Periority.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S INT0_INT1_Periority.elf  >"INT0_INT1_Periority.lss"
	@echo 'Finished building: $@'
	@echo ' '

INT0_INT1_Periority.hex: INT0_INT1_Periority.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex INT0_INT1_Periority.elf  "INT0_INT1_Periority.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: INT0_INT1_Periority.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 INT0_INT1_Periority.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) INT0_INT1_Periority.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
