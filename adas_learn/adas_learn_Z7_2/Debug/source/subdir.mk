################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/BSDModule.c \
../source/BSDModulePort.c \
../source/SinSearchTable.c \
../source/TargetSelect.c \
../source/Trajectory.c \
../source/WarningAlg.c 

OBJS += \
./source/BSDModule.o \
./source/BSDModulePort.o \
./source/SinSearchTable.o \
./source/TargetSelect.o \
./source/Trajectory.o \
./source/WarningAlg.o 

C_DEPS += \
./source/BSDModule.d \
./source/BSDModulePort.d \
./source/SinSearchTable.d \
./source/TargetSelect.d \
./source/Trajectory.d \
./source/WarningAlg.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@source/BSDModule.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


