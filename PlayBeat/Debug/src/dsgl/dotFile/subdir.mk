################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../src/dsgl/dotFile/DotFileLoader.cxx \
../src/dsgl/dotFile/Lexer.cxx \
../src/dsgl/dotFile/Parser.cxx 

CXX_DEPS += \
./src/dsgl/dotFile/DotFileLoader.d \
./src/dsgl/dotFile/Lexer.d \
./src/dsgl/dotFile/Parser.d 

OBJS += \
./src/dsgl/dotFile/DotFileLoader.o \
./src/dsgl/dotFile/Lexer.o \
./src/dsgl/dotFile/Parser.o 


# Each subdirectory must supply rules for building sources it contributes
src/dsgl/dotFile/%.o: ../src/dsgl/dotFile/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -p -pg -ftest-coverage -fprofile-arcs -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


