################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../src/dsgl/dotFile/tokens/Tokens.cxx 

CXX_DEPS += \
./src/dsgl/dotFile/tokens/Tokens.d 

OBJS += \
./src/dsgl/dotFile/tokens/Tokens.o 


# Each subdirectory must supply rules for building sources it contributes
src/dsgl/dotFile/tokens/%.o: ../src/dsgl/dotFile/tokens/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -p -pg -ftest-coverage -fprofile-arcs -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


