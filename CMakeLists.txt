cmake_minimum_required(VERSION 3.17)
project(dia_sample)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(dia_sample
        src/stdafx.h
        src/stdafx.cpp
        src/DIA2Dump.h
        src/DIA2Dump.cpp
        src/Callback.h
        src/regs.h
        src/regs.cpp
        src/PrintSymbol.h
        src/PrintSymbol.cpp
        src/main.cpp)