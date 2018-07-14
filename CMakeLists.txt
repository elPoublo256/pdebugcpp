project(pdebugcpp)

set(pdebugcpp_VERSION 0.1)

#include(GenerateExportHeader)

add_library(pdebugfilelog globalloger.h resultprinter.h resultprinter.cpp)

set_target_properties(pdebugfilelog PROPERTIES

CXX_STANDART 11
)

