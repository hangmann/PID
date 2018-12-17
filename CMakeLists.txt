#  minimum required cmake version: 3.8.0
cmake_minimum_required(VERSION 3.8.0)

SET(APPNAME pid)
SET(LIBNAME vfpid)

project(${APPNAME})

add_executable(${APPNAME} ${PROJECT_SOURCE_DIR}/cpp/PID.cpp)

add_library(${LIBNAME} SHARED ${PROJECT_SOURCE_DIR}/cpp/PID.cpp ${PROJECT_SOURCE_DIR}/cpp/PID.h)

include_directories(${CMAKE_SOURCE_DIR}/cpp)
