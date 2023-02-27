cmake_minimum_required(VERSION 3.26)
project(vector)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDRD_REQUIRED False)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
