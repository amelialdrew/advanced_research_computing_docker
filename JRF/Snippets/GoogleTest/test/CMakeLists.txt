include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test_harm test_harmonic.cpp)
target_link_libraries(test_harm 
    PRIVATE harmonic_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_harm)