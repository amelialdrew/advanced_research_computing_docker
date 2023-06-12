cmake_minimum_required(VERSION 3.15...3.26)

project(library_example
    VERSION 1.0
    LANGUAGES CXX
)

# This would work, but wouldn't build a library:
# add_executable(test main.cpp harmonic.cpp)
# Instead do this:

add_library(harmonic_lib
    STATIC 
    harmonic.cpp 
    harmonic.hpp
)

add_executable(test main.cpp) 

target_link_libraries(test PRIVATE harmonic_lib)