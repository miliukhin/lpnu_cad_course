# PROJECT(meow)
# CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# SET(mylibSRCS my_math.cpp)
# SET(myprogSRCS main.cpp)

# find_package(PkgConfig REQUIRED)
# pkg_check_modules(GTK REQUIRED gtkmm-3.0)

# ADD_LIBRARY(mylib SHARED ${mylibSRCS})
# ADD_EXECUTABLE(myprog ${myprogSRCS})
# target_link_libraries(myprog PRIVATE ${GTKMM_LIBRARIES})

# TARGET_LINK_LIBRARIES(myprog mylib)

# # Add other flags to the compiler
# target_compile_definitions(myprog PRIVATE ${GTKMM_CFLAGS_OTHER})
# # Setup CMake to use GTK+, tell the compiler where to look for headers
# # and to the linker where to look for libraries
# target_include_directories(myprog PRIVATE ${GTKMM_INCLUDE_DIRS})
# target_link_directories(myprog PRIVATE ${GTKMM_LIBRARY_DIRS})
project(test-app C CXX)

set(PROJECT_TARGET test_app)

# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 3.10)

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

set (HEADERS
 ../include/window.h
 ../include/my_math.h
)

set (LIBS
	my_math.cpp
)

set(SOURCES
  main.cc
  window.cc
  ${HEADERS}
)

ADD_LIBRARY(mylib SHARED ${LIBS})
# Create the executable
add_executable(${PROJECT_TARGET} ${SOURCES})
target_link_libraries(${PROJECT_TARGET} PRIVATE ${GTKMM_LIBRARIES} mylib)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
target_include_directories(${PROJECT_TARGET} PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_directories(${PROJECT_TARGET} PRIVATE ${GTKMM_LIBRARY_DIRS})
target_compile_options(${PROJECT_TARGET} PRIVATE ${GTKMM_CFLAGS_OTHER})
