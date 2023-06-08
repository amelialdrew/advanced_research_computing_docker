cmake_minimum_required(VERSION 3.15...3.26)

project(folder_example
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(src)    