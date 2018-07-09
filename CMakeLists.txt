cmake_minimum_required(VERSION 3.1)
project(pdebugcpp)
set_target_properties(run_my_stl PROPERTIES
 CXX_STANDART 14
 CMAKE_CXX_STANDART_REQUIRED ON
 COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

