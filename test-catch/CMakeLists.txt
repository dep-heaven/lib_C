cmake_minimum_required(VERSION 3.16)

include(CTest)

################################################################################
# Define Unit Tests  
################################################################################

function(define_unit_test)
    set(options IGNORED)
    set(oneValueArgs NAME)
    set(multiValueArgs FILES)
    
    cmake_parse_arguments(DEFINE_UNIT_TEST "${options}" "${oneValueArgs}"
                          "${multiValueArgs}" ${ARGN})

    message(STATUS "DEFINE_UNIT_TEST_NAME = ${DEFINE_UNIT_TEST_NAME}")
    message(STATUS "DEFINE_UNIT_TEST_FILES = ${DEFINE_UNIT_TEST_FILES}")    
    
    add_executable(${DEFINE_UNIT_TEST_NAME} ${DEFINE_UNIT_TEST_FILES})

    target_link_libraries(${DEFINE_UNIT_TEST_NAME}
        PUBLIC
        Catch2::Catch2
        lib_C
        fmt::fmt
        $<BUILD_INTERFACE:Daixtrose::CxxFlags>
    )
endfunction()

################################################################################
# Some test

define_unit_test(
    NAME test_lib_c 
    FILES
    test_main.cpp
    test_lib_c.cpp
    )

catch_discover_tests(test_lib_c)

