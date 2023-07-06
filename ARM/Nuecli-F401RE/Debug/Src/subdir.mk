################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c 

OBJS += \
./Src/main.o 

C_DEPS += \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/Service" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL/RCC" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL/GPIO" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL/NVIC" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL/EXTI" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL/STK" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL/DMA" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su

.PHONY: clean-Src

