cmake_minimum_required(VERSION 4.1)
project(Project)

set(CMAKE_CXX_STANDARD 20)

# Main app
add_executable(Project main.cpp)

# Test app
add_executable(ProjectTester
    ../ProjectTester/test_main.cpp
    ../ProjectTester/sources/Menu_test.cpp
    ../ProjectTester/sources/PilotoUI_test.cpp
)