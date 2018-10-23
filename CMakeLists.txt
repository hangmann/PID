#  minimum required cmake version: 3.8.0
cmake_minimum_required(VERSION 3.8.0)

SET(APPNAME pid)

project(${APPNAME})

MESSAGE ("Source path: ${PROJECT_SOURCE_DIR}")
add_executable(${APPNAME} ${PROJECT_SOURCE_DIR}/cpp/PID.cpp)

include_directories(${CMAKE_SOURCE_DIR}/cpp)