cmake_minimum_required(VERSION 3.15)
project(step4 VERSION 1.0)

add_library(compiler_flags INTERFACE)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_options(
  compiler_flags
  INTERFACE "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wunused;-Werror>"
            "$<${msvc_cxx}:-W3>")

add_executable(shifter main.cpp)

target_link_libraries(shifter PUBLIC compiler_flags)
