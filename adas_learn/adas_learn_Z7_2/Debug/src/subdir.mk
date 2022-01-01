################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../src/intc_sw_handlers.S 

C_SRCS += \
../src/S32R274__Interrupt_Init.c \
../src/Vector.c \
../src/intc_SW_mode_isr_vectors_S32R274.c \
../src/main_Z7_2.c 

OBJS += \
./src/S32R274__Interrupt_Init.o \
./src/Vector.o \
./src/intc_SW_mode_isr_vectors_S32R274.o \
./src/intc_sw_handlers.o \
./src/main_Z7_2.o 

C_DEPS += \
./src/S32R274__Interrupt_Init.d \
./src/Vector.d \
./src/intc_SW_mode_isr_vectors_S32R274.d \
./src/main_Z7_2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/S32R274__Interrupt_Init.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS Assembler'
	powerpc-eabivle-gcc "@src/intc_sw_handlers.args" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


