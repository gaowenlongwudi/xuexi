################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
adas_learn_Z4_0.siz \


# All Target
all: adas_learn_Z4_0.elf secondary-outputs

dependents:
	-cd J:/CX/adas/adas_learn/adas_learn_Z7_1/Debug && $(MAKE) all
	-cd J:/CX/adas/adas_learn/adas_learn_Z7_2/Debug && $(MAKE) all

# Tool invocations
adas_learn_Z4_0.elf: $(OBJS) J:/CX/adas/adas_learn/adas_learn_Z4_0/Project_Settings/Linker_Files/S32R274_flash.ld $(OSPT) $(USER_OBJS) J:/CX/adas/adas_learn/adas_learn_Z7_1/Debug/adas_learn_Z7_1.elf J:/CX/adas/adas_learn/adas_learn_Z7_2/Debug/adas_learn_Z7_2.elf
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	powerpc-eabivle-gcc -o "adas_learn_Z4_0.elf" "@adas_learn_Z4_0.args"  $(USER_OBJS) $(LIBS) $(OSPT)
	@echo 'Finished building target: $@'
	@echo ' '

adas_learn_Z4_0.siz: adas_learn_Z4_0.elf
	@echo 'Invoking: Standard S32DS Print Size'
	powerpc-eabivle-size --format=berkeley adas_learn_Z4_0.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents
J:/CX/adas/adas_learn/adas_learn_Z7_1/Debug/adas_learn_Z7_1.elf:
J:/CX/adas/adas_learn/adas_learn_Z7_2/Debug/adas_learn_Z7_2.elf:

-include ../makefile.targets
