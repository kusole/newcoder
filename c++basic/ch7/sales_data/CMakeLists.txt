cmake_minimum_required(VERSION 3.9)
project(sales_data)

set(CMAKE_CXX_STANDARD 11)

add_executable(sales_data main.cpp Sales_data.h Sales_data.cpp Screen.h WindowMgr.h)