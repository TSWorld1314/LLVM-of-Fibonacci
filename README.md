# LLVM_Fibonacci

This is a simple project from llvm example,it is aim to learn llvm on Windows.

LLVM version is 14.0.6.


# Build Project

First you should set LLVM_DIR as your llvm project of build folder of lib folder of cmake folder.like this:
    set(LLVM_DIR "D:/llvm-project-14.0.6.src/build/lib/cmake/llvm")
in your CMakeLists.txt.
Second you should build this project:
```
    cd Fibonacci
    mkdir build
    cd build
    cmake ..
    cmake --build .
```
This will output the executable Fibonacci.exe in build folder.
