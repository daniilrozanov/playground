cmake_minimum_required(VERSION 3.15)
project(
  step2
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(USE_LIBMATH "Use library implementation on math if true" ON)

add_subdirectory(./math ./math_build)

add_executable(calc main.cpp)

if(USE_LIBMATH)
  target_compile_definitions(math PRIVATE "USE_LIBMATH")
endif()

target_link_libraries(calc PUBLIC math)

target_include_directories(calc PUBLIC "${PROJECT_BINARY_DIR}"
                                       "${PROJECT_SOURCE_DIR}/math")
