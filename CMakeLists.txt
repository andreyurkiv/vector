cmake_minimum_required(VERSION 2.8)

# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(test "Build all tests." OFF) # Makes boolean 'test' available.

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME my_vector)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_FLAGS "-g -Wall")

## force static runtime libraries for msvc builds
#if(MSVC)
#  set(variables
#    CMAKE_CXX_FLAGS_DEBUG
#    CMAKE_CXX_FLAGS_RELEASE
#	CMAKE_CXX_FLAGS_RELWITHDEBINFO
#	CMAKE_CXX_FLAGS_MINSIZEREL
#  )
#  foreach(variable ${variables})
#	if(${variable} MATCHES "/MD")
#	  string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
#	endif()
#  endforeach()
#endif()

# If you want your own include/ directory, set this, and then you can do
# include_directories(${COMMON_INCLUDES}) in other CMakeLists.txt files.
# set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

################################
# Normal Libraries & Executables
################################

add_library(my_vector_lib my_vector.h my_vector.cpp)
add_executable(my_vector main.cpp)

# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere.

target_link_libraries(my_vector my_vector_lib)

################################
# Testing
################################

#  if (APPLE)
#    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
#    add_definitions(-D__GLIBCXX__)
#  endif (APPLE)

  # This adds another subdirectory, which has 'project(gtest)'.
add_subdirectory(lib/gtest-1.6.0)

enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  ##############
  # Unit Tests
  ##############
add_executable(runUnitTests vector_test.cpp)

  # Standard linking to gtest stuff.
target_link_libraries(runUnitTests gtest gtest_main)

  # Extra linking for the project.
target_link_libraries(runUnitTests my_vector_lib)

#  # This is so you can do 'make test' to see all your tests run, instead of
#  # manually running the executable runUnitTests to see those specific tests.
#  add_test(NAME that-test-I-made COMMAND runUnitTests)
#
#  # You can also omit NAME and COMMAND. The second argument could be some other
#  # test executable.
#  add_test(that-other-test-I-made runUnitTests)

