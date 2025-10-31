cmake_minimum_required(VERSION 3.10)
project(MyProject C)

set(CMAKE_C_STANDARD 99)

add_executable(MyProject calculator.c)
target_link_libraries(MyProject m)
