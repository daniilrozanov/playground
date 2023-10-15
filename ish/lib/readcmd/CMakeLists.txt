cmake_minimum_required(VERSION 3.15)
project(readcmd LANGUAGES C)

add_library(readcmd ./include/readcmd/readcmd.h ./src/readcmd.c ./include/readcmd/readline.h ./src/readline.c ./include/readcmd/buffer_list.h ./src/buffer_list.c)
target_include_directories(readcmd PUBLIC ./include/)

add_executable(test-readline-interactive ./tests/readline-interactive.c)
target_link_libraries(test-readline-interactive PUBLIC readcmd)

add_executable(test-readcmd-interactive ./tests/readcmd-interactive.c)
target_link_libraries(test-readcmd-interactive PUBLIC readcmd)
