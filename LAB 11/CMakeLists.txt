#fetch Google Test
include(FetchContent)
    FetchContent_Declare(
        googletest
            URL https
        : //github.com/google/googletest/archive/refs/tags/release-1.10.0.zip
        )
#For Windows : Prevent overriding the parent project’s compiler / linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
            FetchContent_MakeAvailable(googletest)
                enable_testing()
#add an executable test target
                    add_executable(
                        arrray_tests
                            array_tests.cpp)
#link the Google Test library
                        target_link_libraries(
                            array_tests
                                gtest_main)
#enable CMake’s test runner to discover the tests included in the binary,
#using the GoogleTest CMake module
                            include(GoogleTest)
                                gtest_discover_tests(array_tests)