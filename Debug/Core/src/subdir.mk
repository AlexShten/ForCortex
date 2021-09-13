################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/src/main.c 

OBJS += \
./Core/src/main.o 

C_DEPS += \
./Core/src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/src/%.o: ../Core/src/%.c Core/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I/home/alex/STM32CubeIDE/workspace_1.7.0/GPIO/CMSIS/inc -I/home/alex/STM32CubeIDE/workspace_1.7.0/GPIO/Core/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

