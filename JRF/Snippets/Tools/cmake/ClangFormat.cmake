function(ClangFormat target directory)
    find_program(CLANG-FORMAT_PATH clang-format REQUIRED)

    # define a list of suffixes for files ot be considered
    set(EXPRESSION h hpp hh c cc cxx cpp)
    # prepend the directory to the list
    list(TRANSFORM EXPRESSION PREPEND "${directory}/*.")
    
    # create list of files to format recuresivly and following symboloc links
    file(GLOB_RECURSE SOURCE_FILES FOLLOW_SYMLINKS
        LIST_DIRECTORIES false ${EXPRESSION}
    )

    # Add command to run clang-format on list of files before build
    add_custom_command(TARGET ${target} PRE_BUILD COMMAND
        ${CLANG-FORMAT_PATH} -i --style=Google ${SOURCE_FILES}
    )
endfunction()

