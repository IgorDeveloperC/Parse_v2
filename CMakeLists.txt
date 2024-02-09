cmake_minimum_required(VERSION 3.10)

project(Parser_v2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_EXE src/Parser_v2.cpp src/TargetMessage.cpp src/TargetMessage.h )


add_executable(Parser_v2 ${SOURCE_EXE})



