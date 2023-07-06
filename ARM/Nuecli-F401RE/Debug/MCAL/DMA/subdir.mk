################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DMA/DMA_Program.c 

OBJS += \
./MCAL/DMA/DMA_Program.o 

C_DEPS += \
./MCAL/DMA/DMA_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/DMA/%.o MCAL/DMA/%.su MCAL/DMA/%.cyclo: ../MCAL/DMA/%.c MCAL/DMA/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/Service" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL/RCC" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL/GPIO" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL/NVIC" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL/EXTI" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL/STK" -I"E:/NTI_4Month/Interfacing/ARM/Nuecli-F401RE/MCAL/DMA" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL-2f-DMA

clean-MCAL-2f-DMA:
	-$(RM) ./MCAL/DMA/DMA_Program.cyclo ./MCAL/DMA/DMA_Program.d ./MCAL/DMA/DMA_Program.o ./MCAL/DMA/DMA_Program.su

.PHONY: clean-MCAL-2f-DMA

