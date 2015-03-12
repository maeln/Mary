################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../src/dsgl/Graph.cxx \
../src/dsgl/Node.cxx 

CXX_DEPS += \
./src/dsgl/Graph.d \
./src/dsgl/Node.d 

OBJS += \
./src/dsgl/Graph.o \
./src/dsgl/Node.o 


# Each subdirectory must supply rules for building sources it contributes
src/dsgl/%.o: ../src/dsgl/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -p -pg -ftest-coverage -fprofile-arcs -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


