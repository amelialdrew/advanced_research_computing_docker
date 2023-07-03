cmake_minimum_required(VERSION 3.15...3.26)

project(folder_example
    VERSION 1.0
    LANGUAGES CXX
)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include(Doxygen)
include(ClangFormat)
include(ClangTidy)

Doxygen(src docs)

add_subdirectory(src)  
add_subdirectory(test)    