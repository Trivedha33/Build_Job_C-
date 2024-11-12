cmake_minimum_required(VERSION 3.10)
project(my-cpp-project)

# Enable testing
enable_testing()

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
FetchContent_MakeAvailable(googletest)

# Create library from source files
add_library(mycode
    src/MyCode.cpp
)

target_include_directories(mycode
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Create main executable
add_executable(main_app
    src/main.cpp
)

target_link_libraries(main_app
    PRIVATE
        mycode
)

# Create test executable
add_executable(unit_tests
    tests/example_test.cpp
)

target_link_libraries(unit_tests
    PRIVATE
        mycode
        gtest
        gtest_main
)

# Add test to CTest
add_test(NAME unit_tests COMMAND unit_tests)
