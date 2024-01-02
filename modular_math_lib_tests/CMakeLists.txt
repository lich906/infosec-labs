cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(modular_math_lib_tests CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(INCLUDE_DIR include)
set(SOURCE_DIR src)

set(sources main.cpp ${MODULAR_MATH_LIB_DIR}/include/modular_math_lib.h)

add_executable(modular_math_lib_tests ${sources} ${includes})

target_include_directories(modular_math_lib_tests PRIVATE ${MODULAR_MATH_LIB_DIR}/include)

target_link_libraries(modular_math_lib_tests PRIVATE modular_math_lib)

set_target_properties(modular_math_lib_tests PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)
