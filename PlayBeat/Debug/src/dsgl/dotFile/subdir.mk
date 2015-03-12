################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../src/dsgl/dotFile/DotFileLoader.cxx \
../src/dsgl/dotFile/Lexer.cxx \
../src/dsgl/dotFile/Parser.cxx 

OBJS += \
./src/dsgl/dotFile/DotFileLoader.o \
./src/dsgl/dotFile/Lexer.o \
./src/dsgl/dotFile/Parser.o 

CXX_DEPS += \
./src/dsgl/dotFile/DotFileLoader.d \
./src/dsgl/dotFile/Lexer.d \
./src/dsgl/dotFile/Parser.d 


# Each subdirectory must supply rules for building sources it contributes
src/dsgl/dotFile/%.o: ../src/dsgl/dotFile/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -p -pg -Wall -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


