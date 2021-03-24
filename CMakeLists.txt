cmake_minimum_required(VERSION 3.16)
project(lib_C VERSION 1.0.0 LANGUAGES CXX)

################################################################################
# Dependencies via list in file

include(FetchContent)

FetchContent_Declare(
  cmake_utilities
  GIT_REPOSITORY https://github.com/daixtrose/cmake_utilities
  GIT_TAG        main
)

FetchContent_MakeAvailable(cmake_utilities)

fetchcontent_dependencies(
    FILENAME dependencies.txt 
    WORKSPACE ws)


################################################################################
# the library

add_library(${PROJECT_NAME}
    src/lib_C.cpp
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC 
    include
    )

target_link_libraries(
    ${PROJECT_NAME} 
    PUBLIC
    $<BUILD_INTERFACE:Daixtrose::CxxFlags>
    fmt::fmt-header-only
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) 
    enable_testing()
    add_subdirectory(test-catch)
endif()

# Packaging omitted  