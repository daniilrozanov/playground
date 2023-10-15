cmake_minimum_required(VERSION 3.15)
project(readcmd LANGUAGES C)

add_library(readcmd ./include/readcmd/readcmd.h ./src/readcmd.c ./include/readcmd/readline.h ./src/readline.c)
target_include_directories(readcmd PUBLIC ./include/)

add_executable(test-readline-interactive ./tests/readline-interactive.c)
target_link_libraries(test-readline-interactive PUBLIC readcmd)
