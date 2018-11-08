cmake_minimum_required(VERSION 2.8)

#option(test "Build all tests." OFF)

set(PROJECT_NAME my_vector)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_FLAGS "-g -Wall")

add_library(my_vector_lib my_vector.h my_vector.cpp)
add_executable(my_vector main.cpp)

target_link_libraries(my_vector my_vector_lib)

add_subdirectory(lib/gtest-1.6.0)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runUnitTests vector_test.cpp)

target_link_libraries(runUnitTests gtest gtest_main)

target_link_libraries(runUnitTests my_vector_lib)


