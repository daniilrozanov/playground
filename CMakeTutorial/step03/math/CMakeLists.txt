add_library(math ./src/constant.cpp)

target_include_directories(math
                           INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(math PUBLIC compiler_flags)
