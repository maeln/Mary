################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../src/main.cxx \
../src/notes.cxx \
../src/notescounter.cxx \
../src/notesfactory.cxx \
../src/playbeat.cxx 

CXX_DEPS += \
./src/main.d \
./src/notes.d \
./src/notescounter.d \
./src/notesfactory.d \
./src/playbeat.d 

OBJS += \
./src/main.o \
./src/notes.o \
./src/notescounter.o \
./src/notesfactory.o \
./src/playbeat.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -p -pg -ftest-coverage -fprofile-arcs -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


