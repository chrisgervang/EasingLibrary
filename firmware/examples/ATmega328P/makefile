################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
EasingFunctionsTest.lss \

FLASH_IMAGE += \
EasingFunctionsTest.hex \

EEPROM_IMAGE += \
EasingFunctionsTest.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: EasingFunctionsTest.elf secondary-outputs

# Tool invocations
EasingFunctionsTest.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++  -lc -lm -Wl,-Map,EasingFunctionsTest.map,--cref -L"C:\Program Files (x86)\ArduinoLibrary0021\0021\lib" -L"C:\Users\Andy\Documents\andyworkshop\easing functions\EasingLibrary\MCUIndependent" -mmcu=atmega328p -o"EasingFunctionsTest.elf"  $(OBJS) $(USER_OBJS) $(LIBS)  -lc
	@echo 'Finished building target: $@'
	@echo ' '

EasingFunctionsTest.lss: EasingFunctionsTest.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S EasingFunctionsTest.elf  >"EasingFunctionsTest.lss"
	@echo 'Finished building: $@'
	@echo ' '

EasingFunctionsTest.hex: EasingFunctionsTest.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex EasingFunctionsTest.elf  "EasingFunctionsTest.hex"
	@echo 'Finished building: $@'
	@echo ' '

EasingFunctionsTest.eep: EasingFunctionsTest.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex EasingFunctionsTest.elf  "EasingFunctionsTest.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: EasingFunctionsTest.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t EasingFunctionsTest.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EEPROM_IMAGE)$(ELFS)$(FLASH_IMAGE)$(LSS)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(CPP_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) EasingFunctionsTest.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
