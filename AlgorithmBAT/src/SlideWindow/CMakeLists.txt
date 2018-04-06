cmake_minimum_required(VERSION 3.9)
project(SlideWindow)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SlideWindow.h)
add_executable(SlideWindow ${SOURCE_FILES})