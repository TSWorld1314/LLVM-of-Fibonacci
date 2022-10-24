cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)
project(Fibonacci)

set(LLVM_DIR "D:/llvm-project-14.0.6.src/build/lib/cmake/llvm")

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")


include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${LLVM_BUILD})

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})

add_definitions(${LLVM_DEFINITIONS_LIST})

add_executable(Fibonacci fibonacci.cpp)

llvm_map_components_to_libnames(llvm_libs 
    Core
    ExecutionEngine
    Interpreter
    MC
    MCJIT
    Support
    nativecodegen
    irreader 
    executionengine
    interpreter 
    ipo 
    x86asmparser 
)

# add_custom_command(TARGET Fibonacci1
# 		    PRE_BUILD
# 		    COMMAND clang++ -O1 -emit-llvm ${CMAKE_CURRENT_SOURCE_DIR}/fibonacci_jit.cpp -c -o cfib.bc 
# 		    VERBATIM
# 		    )

message(${llvm_libs})
# Link against LLVM libraries
target_link_libraries(Fibonacci
    PUBLIC
    ${llvm_libs})