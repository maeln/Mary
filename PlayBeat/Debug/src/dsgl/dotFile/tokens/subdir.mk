################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../src/dsgl/dotFile/tokens/Tokens.cxx 

OBJS += \
./src/dsgl/dotFile/tokens/Tokens.o 

CXX_DEPS += \
./src/dsgl/dotFile/tokens/Tokens.d 


# Each subdirectory must supply rules for building sources it contributes
src/dsgl/dotFile/tokens/%.o: ../src/dsgl/dotFile/tokens/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -p -pg -Wall -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


