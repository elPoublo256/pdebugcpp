cmake_minimum_required(VERSION 2.8.9)

project(pdebugcpp)

include_directories(resultprinterlib)



add_library(resultprinterlib/globalloger.h resultprinterlib/resultprinter.h resultprinterlib/resultprinter.cpp)



