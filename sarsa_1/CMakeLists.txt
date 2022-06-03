cmake_minimum_required(VERSION 3.1)
project(sarsa_1 VERSION 0.9)

file(GLOB SOURCES "src/*.cpp")
add_executable(sarsa_1 ${SOURCES})

target_include_directories(sarsa_1 PRIVATE include)