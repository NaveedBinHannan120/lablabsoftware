cmake_minimum_required(VERSION 3.10)
project(MyGTestProject)

set(CMAKE_CXX_STANDARD 17)

# Add GoogleTest
add_subdirectory(googletest)

# Your main app (optional)
add_executable(main main.cpp)

# Test executable
enable_testing()
add_executable(runTests tests/sample_test.cpp)

target_link_libraries(runTests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)