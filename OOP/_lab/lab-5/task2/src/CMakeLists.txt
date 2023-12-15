cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(test VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
# add_executable(test ${SRC_FILES})
add_executable(test main.cpp sweet_roll.cpp ware.cpp)
target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
