cmake_minimum_required (VERSION 2.6)
project (BoostTest)
# The version number.
set (BoostTest_VERSION_MAJOR 1)
set (BoostTest_VERSION_MINOR 0)
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/BoostTestConfig.h.in"
    "${PROJECT_BINARY_DIR}/BoostTestConfig.h"
    )
# add the binary tree to the search path for include files
# so that we will find BoostTestConfig.h
include_directories("${PROJECT_BINARY_DIR}")
# boost cmake
set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.63.0 COMPONENTS date_time filesystem system thread)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    # add the executable
    add_executable(BoostTest thread.cpp)
    target_link_libraries(BoostTest ${Boost_LIBRARIES})
endif()
