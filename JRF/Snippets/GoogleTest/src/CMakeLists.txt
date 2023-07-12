add_subdirectory(harmonic) # make sure that these are added in order of dependancies

add_executable(main main.cpp) 
ClangTidy(main)
ClangFormat(main .)

target_link_libraries(main PRIVATE harmonic_lib)

