################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/RCC_Program.c 

OBJS += \
./MCAL/RCC_Program.o 

C_DEPS += \
./MCAL/RCC_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o MCAL/%.su MCAL/%.cyclo: ../MCAL/%.c MCAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/Service" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL

clean-MCAL:
	-$(RM) ./MCAL/RCC_Program.cyclo ./MCAL/RCC_Program.d ./MCAL/RCC_Program.o ./MCAL/RCC_Program.su

.PHONY: clean-MCAL

