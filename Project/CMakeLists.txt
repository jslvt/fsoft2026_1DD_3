cmake_minimum_required(VERSION 3.20)
project(GestaoAutomobilismo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ── Shared sources (everything except main.cpp) ───────────────────────────────
file(GLOB_RECURSE LIB_SOURCES
        "model/*.cpp"
        "store/*.cpp"
        "controller/*.cpp"
        "ui/*.cpp"
)

# ── Main application ──────────────────────────────────────────────────────────
add_executable(GestaoAutomobilismo main.cpp ${LIB_SOURCES})

target_include_directories(GestaoAutomobilismo PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/model
        ${CMAKE_SOURCE_DIR}/store
        ${CMAKE_SOURCE_DIR}/controller
        ${CMAKE_SOURCE_DIR}/ui
)

# Ensure the data/ folder exists next to the binary at runtime
add_custom_command(TARGET GestaoAutomobilismo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
        $<TARGET_FILE_DIR:GestaoAutomobilismo>/data
)

# ── Test application ──────────────────────────────────────────────────────────
file(GLOB TESTER_SOURCES
        "../ProjectTester/test_main.cpp"
        "../ProjectTester/sources/*.cpp"
)

add_executable(ProjectTester ${TESTER_SOURCES} ${LIB_SOURCES})

target_include_directories(ProjectTester PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/model
        ${CMAKE_SOURCE_DIR}/store
        ${CMAKE_SOURCE_DIR}/controller
        ${CMAKE_SOURCE_DIR}/ui
)