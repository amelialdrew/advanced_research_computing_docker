add_subdirectory(harmonic) # make sure that these are added in order of dependancies

add_executable(test main.cpp) 

target_link_libraries(test PRIVATE harmonic_lib)

