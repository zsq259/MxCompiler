cmake_minimum_required(VERSION 3.20)

include_directories(/usr/include/antlr4-runtime/)
include_directories(/usr/local/include/antlr4-runtime/)

file(GLOB MxAntlrSources *.cpp)

add_library(MxAntlr STATIC ${MxAntlrSources})
target_link_libraries(MxAntlr PUBLIC antlr4-runtime)