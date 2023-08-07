cmake_minimum_required(VERSION 3.20)
project(MxCompiler)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(MxAntlr)

include_directories(/usr/local/include/antlr4-runtime/)
include_directories(MxAntlr/)
include_directories(SYSTEM src)
include_directories(src/AST)
include_directories(src/Util)

file(GLOB_RECURSE sources src/*.cpp src/*.h)

add_executable(code ${sources})

target_link_libraries(code MxAntlr)

set(TestdataPath "${PROJECT_SOURCE_DIR}/testcases")
set(SemaPath "${TestdataPath}/sema")
file(GLOB_RECURSE test_files RELATIVE ${SemaPath} ${SemaPath}/**.mx)
foreach (test_file ${test_files})
    string(REGEX REPLACE ".*/" "" filename "${test_file}")
    set(testname "sema|${filename}")
    execute_process(COMMAND grep "Verdict: " "${SemaPath}/${test_file}" COMMAND sed "s/Verdict: //"
            OUTPUT_VARIABLE verdict)
    # message(STATUS "$<TARGET_FILE:code> <${SemaPath}/${test_file}")            
    add_test(NAME ${testname}
            COMMAND $<TARGET_FILE:code> ${SemaPath}/${test_file}
            WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/build")
    set_tests_properties(${testname} PROPERTIES LABELS "sema")
    if (NOT "${verdict}" STREQUAL "Success\n")
        set_tests_properties(${testname} PROPERTIES WILL_FAIL true)
        message(STATUS "Test ${testname} will fail")
    endif ()
endforeach ()

enable_testing()