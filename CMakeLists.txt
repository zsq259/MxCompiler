cmake_minimum_required(VERSION 3.20)
project(MxCompiler)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(MxAntlr)

include_directories(/usr/local/include/antlr4-runtime/)
include_directories(MxAntlr/)
include_directories(src/)

file(GLOB_RECURSE sources src/*.cpp src/*.h)

add_executable(code ${sources})

target_link_libraries(code MxAntlr)