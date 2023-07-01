cmake_minimum_required(VERSION 3.15)
project(
  ex1
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ex1_VERSION_ENABLE "Project version" ON)
if(ex1_VERSION_ENABLE)
  set(ex1_VERSION_STRING "${ex1_VERSION_MAJOR}.${ex1_VERSION_MINOR}")
endif()

configure_file(config.hpp.in config.hpp)

add_executable(root main.cpp)
target_include_directories(root PUBLIC "${PROJECT_BINARY_DIR}")
