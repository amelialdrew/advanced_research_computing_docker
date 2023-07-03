function(ClangTidy target)
    find_program(CLANG-TIDY_PATH clang-tidy REQUIRED)

    set_target_properties(${target}
        PROPERTIES CXX_CLANG_TIDY
        "${CLANG-TIDY_PATH};-checks=clang-analyzer-*,bugprone-*,cppcoreguidelines-*,modernize-*,readability-*"
    )
endfunction()