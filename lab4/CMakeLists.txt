cmake_minimum_required(VERSION 3.10)
project(Lab4DynamicLibraries)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

# Create dynamic libraries
add_library(area SHARED area.c)
add_library(sort SHARED sort.c)

# Include directories
target_include_directories(area PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories(sort PUBLIC ${CMAKE_SOURCE_DIR})

# Link object files to executables
add_executable(app_compile.out main_compile.c area.c sort.c)
target_link_libraries(app_compile.out PRIVATE area sort)

add_executable(app_dl.out main_dl.c)
target_link_libraries(app_dl.out PRIVATE dl)

# Google Test configuration
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
add_executable(unit_tests unit_tests.cpp area.c sort.c)
target_link_libraries(unit_tests PRIVATE GTest::GTest GTest::Main)

# tests
add_test(NAME RunTests COMMAND unit_tests)
