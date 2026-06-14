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

# ── Sources ────────────────────────────────────────────────────────────────────
file(GLOB_RECURSE SOURCES
        "main.cpp"
        "sources/**/*.cpp"
)

add_executable(GestaoAutomobilismo ${SOURCES})

# Ensure data/ folder exists next to the binary
add_custom_command(TARGET GestaoAutomobilismo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
        $<TARGET_FILE_DIR:GestaoAutomobilismo>/data
)