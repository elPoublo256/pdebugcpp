project(pdebugcpp)

set(pdebugcpp_VERSION 0.1)

add_executable(main_cli main.cpp)

#include(GenerateExportHeader)

add_library(pdebugfilelog globalloger.h resultprinter.h resultprinter.cpp)



