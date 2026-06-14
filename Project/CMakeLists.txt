cmake_minimum_required(VERSION 3.20)
project(GestaoAutomobilismo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ── Include directories ────────────────────────────────────────────────────────
include_directories(
        ${CMAKE_SOURCE_DIR}/headers/model
        ${CMAKE_SOURCE_DIR}/headers/dto
        ${CMAKE_SOURCE_DIR}/headers/exceptions
        ${CMAKE_SOURCE_DIR}/headers/mappers
        ${CMAKE_SOURCE_DIR}/headers/repo
        ${CMAKE_SOURCE_DIR}/headers/services
        ${CMAKE_SOURCE_DIR}/headers/views
        ${CMAKE_SOURCE_DIR}/headers/controllers
)

# ── Shared sources (no main.cpp) ──────────────────────────────────────────────
file(GLOB_RECURSE LIB_SOURCES "sources/**/*.cpp")

# ── Main application ──────────────────────────────────────────────────────────
add_executable(GestaoAutomobilismo main.cpp ${LIB_SOURCES})

add_custom_command(TARGET GestaoAutomobilismo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
        $<TARGET_FILE_DIR:GestaoAutomobilismo>/data
)

# ── Google Test ───────────────────────────────────────────────────────────────
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# ── ProjectTester ─────────────────────────────────────────────────────────────
file(GLOB_RECURSE TEST_SOURCES "../ProjectTester/sources/*.cpp")

add_executable(ProjectTester
        ../ProjectTester/test_main.cpp
        ${TEST_SOURCES}
        ${LIB_SOURCES}
)

target_include_directories(ProjectTester PRIVATE
        ${CMAKE_SOURCE_DIR}/headers/model
        ${CMAKE_SOURCE_DIR}/headers/dto
        ${CMAKE_SOURCE_DIR}/headers/exceptions
        ${CMAKE_SOURCE_DIR}/headers/mappers
        ${CMAKE_SOURCE_DIR}/headers/repo
        ${CMAKE_SOURCE_DIR}/headers/services
        ${CMAKE_SOURCE_DIR}/headers/views
        ${CMAKE_SOURCE_DIR}/headers/controllers
        ${CMAKE_SOURCE_DIR}/../ProjectTester
)

target_link_libraries(ProjectTester GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(ProjectTester)
