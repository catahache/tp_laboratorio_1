################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/menuOpciones.c \
../src/operaciones.c \
../src/tp1CalculadoraTerminado.c 

OBJS += \
./src/menuOpciones.o \
./src/operaciones.o \
./src/tp1CalculadoraTerminado.o 

C_DEPS += \
./src/menuOpciones.d \
./src/operaciones.d \
./src/tp1CalculadoraTerminado.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


