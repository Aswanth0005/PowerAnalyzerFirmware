################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/iocontrol/subdir.mk
-include Drivers/calculations/subdir.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include Drivers/Low\ pass\ filter/subdir.mk
-include Drivers/ADCdrivers/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := FIrmware_Mileston1_v1
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
FIrmware_Mileston1_v1.elf \

MAP_FILES += \
FIrmware_Mileston1_v1.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
FIrmware_Mileston1_v1.list \


# All Target
all: main-build

# Main-build Target
main-build: FIrmware_Mileston1_v1.elf secondary-outputs

# Tool invocations
FIrmware_Mileston1_v1.elf FIrmware_Mileston1_v1.map: $(OBJS) $(USER_OBJS) D:\Projects\Power_Analyzer_ProDucT\git\PowerAnalyzerFirmware\FIrmware_Mileston1_v1\STM32H743ZITX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "FIrmware_Mileston1_v1.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"D:\Projects\Power_Analyzer_ProDucT\git\PowerAnalyzerFirmware\FIrmware_Mileston1_v1\STM32H743ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="FIrmware_Mileston1_v1.map" -Wl,--gc-sections -static -L"D:\Projects\Power_Analyzer_ProDucT\git\PowerAnalyzerFirmware\FIrmware_Mileston1_v1\lib" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -u _printf_float -u _scanf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

FIrmware_Mileston1_v1.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "FIrmware_Mileston1_v1.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) FIrmware_Mileston1_v1.elf FIrmware_Mileston1_v1.list FIrmware_Mileston1_v1.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
