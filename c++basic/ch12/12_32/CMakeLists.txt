cmake_minimum_required(VERSION 3.9)
project(12_32)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp my_QueryResult.h my_StrBlob.h my_TextQuery.h my_TextQuery.cpp)
add_executable(12_32 ${SOURCE_FILES})