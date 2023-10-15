cmake_minimum_required(VERSION 3.15)
project(ish LANGUAGES C)

add_subdirectory(lib)

add_executable(ish ./src/main.c)
