################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Ili9341Lib/ColorImg.c \
../Core/Ili9341Lib/FontBig.c \
../Core/Ili9341Lib/FontLitll.c \
../Core/Ili9341Lib/Ili9341Lib.c \
../Core/Ili9341Lib/Ili9341LibTouch.c \
../Core/Ili9341Lib/monochromImg.c 

OBJS += \
./Core/Ili9341Lib/ColorImg.o \
./Core/Ili9341Lib/FontBig.o \
./Core/Ili9341Lib/FontLitll.o \
./Core/Ili9341Lib/Ili9341Lib.o \
./Core/Ili9341Lib/Ili9341LibTouch.o \
./Core/Ili9341Lib/monochromImg.o 

C_DEPS += \
./Core/Ili9341Lib/ColorImg.d \
./Core/Ili9341Lib/FontBig.d \
./Core/Ili9341Lib/FontLitll.d \
./Core/Ili9341Lib/Ili9341Lib.d \
./Core/Ili9341Lib/Ili9341LibTouch.d \
./Core/Ili9341Lib/monochromImg.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Ili9341Lib/%.o Core/Ili9341Lib/%.su: ../Core/Ili9341Lib/%.c Core/Ili9341Lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/Users/Solov/STM32CubeIDE/workspace_1.11.0/PulseGeneratorILI9341/Core/Ili9341Lib" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Ili9341Lib

clean-Core-2f-Ili9341Lib:
	-$(RM) ./Core/Ili9341Lib/ColorImg.d ./Core/Ili9341Lib/ColorImg.o ./Core/Ili9341Lib/ColorImg.su ./Core/Ili9341Lib/FontBig.d ./Core/Ili9341Lib/FontBig.o ./Core/Ili9341Lib/FontBig.su ./Core/Ili9341Lib/FontLitll.d ./Core/Ili9341Lib/FontLitll.o ./Core/Ili9341Lib/FontLitll.su ./Core/Ili9341Lib/Ili9341Lib.d ./Core/Ili9341Lib/Ili9341Lib.o ./Core/Ili9341Lib/Ili9341Lib.su ./Core/Ili9341Lib/Ili9341LibTouch.d ./Core/Ili9341Lib/Ili9341LibTouch.o ./Core/Ili9341Lib/Ili9341LibTouch.su ./Core/Ili9341Lib/monochromImg.d ./Core/Ili9341Lib/monochromImg.o ./Core/Ili9341Lib/monochromImg.su

.PHONY: clean-Core-2f-Ili9341Lib

