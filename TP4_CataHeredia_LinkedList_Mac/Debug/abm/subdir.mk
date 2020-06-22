################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../abm/Controller.c \
../abm/abmBooks.c \
../abm/book.c \
../abm/menu.c \
../abm/parser.c \
../abm/utn.c 

OBJS += \
./abm/Controller.o \
./abm/abmBooks.o \
./abm/book.o \
./abm/menu.o \
./abm/parser.o \
./abm/utn.o 

C_DEPS += \
./abm/Controller.d \
./abm/abmBooks.d \
./abm/book.d \
./abm/menu.d \
./abm/parser.d \
./abm/utn.d 


# Each subdirectory must supply rules for building sources it contributes
abm/%.o: ../abm/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


