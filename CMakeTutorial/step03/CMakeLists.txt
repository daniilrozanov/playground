cmake_minimum_required(VERSION 3.15)
project(
  step3
  VERSION 1.0
  LANGUAGES CXX)

option(USE_LIBMATH "Use library implementation on math if true" ON)

add_library(compiler_flags INTERFACE)

target_compile_features(compiler_flags INTERFACE cxx_std_17)

add_subdirectory(./math ./math_build)

add_executable(calc main.cpp)

if(USE_LIBMATH)
  target_compile_definitions(math PRIVATE "USE_LIBMATH")
endif()

target_link_libraries(calc PUBLIC math compiler_flags)

target_include_directories(calc PUBLIC "${PROJECT_BINARY_DIR}")
