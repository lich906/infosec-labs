cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(infosec_labs CXX)

set(MODULAR_MATH_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modular_math_lib)

add_subdirectory(key_encryption)
add_subdirectory(modular_math_lib)
add_subdirectory(key_finder)

if ( BUILD_TESTS )
    add_subdirectory(modular_math_lib_tests)
endif()
