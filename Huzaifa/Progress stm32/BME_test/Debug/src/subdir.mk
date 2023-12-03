################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bme280.c \
../src/clocks.c \
../src/gpio.c \
../src/i2c.c \
../src/main.c \
../src/stm32f1xx_it.c \
../src/syscalls.c \
../src/system.c \
../src/system_stm32f1xx.c 

OBJS += \
./src/bme280.o \
./src/clocks.o \
./src/gpio.o \
./src/i2c.o \
./src/main.o \
./src/stm32f1xx_it.o \
./src/syscalls.o \
./src/system.o \
./src/system_stm32f1xx.o 

C_DEPS += \
./src/bme280.d \
./src/clocks.d \
./src/gpio.d \
./src/i2c.d \
./src/main.d \
./src/stm32f1xx_it.d \
./src/syscalls.d \
./src/system.d \
./src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -DSTM32F103xB -DUSE_HAL_DRIVER -I"D:/STM32/BME_test/HAL_Driver/Inc/Legacy" -I"D:/STM32/BME_test/inc" -I"D:/STM32/BME_test/CMSIS/device" -I"D:/STM32/BME_test/CMSIS/core" -I"D:/STM32/BME_test/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


