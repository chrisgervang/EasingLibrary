################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LiquidCrystal.cpp \
../Tester.cpp \
../main.cpp 

OBJS += \
./LiquidCrystal.o \
./Tester.o \
./main.o 

CPP_DEPS += \
./LiquidCrystal.d \
./Tester.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"C:\Users\Andy\Documents\andyworkshop\easing functions\EasingLibrary" -I"C:\Program Files (x86)\ArduinoLibrary0021\0021\include" -Wall -Werror -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


