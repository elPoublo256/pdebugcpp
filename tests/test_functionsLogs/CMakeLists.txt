cmake_minimum_required(VERSION 3.1)

project(test_cpp_loging_debug)

enable_testing()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(run_test test.cpp)

add_library(libresultprinterlib ../../resultprinterlib/resultprinter.h
   	../../resultprinterlib/resultprinter.cpp) 

include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(run_test ${Boost_LIBRARIES} libresultprinterlib)

add_test(NAME test1 COMMAND run_test)
