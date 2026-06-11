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

add_executable(GestaoAutomobilismo ${SOURCES}
        sources/views/view.cpp
        headers/views/view.h
        sources/views/Utils.cpp
        headers/views/Utils.h
        sources/views/PilotoView.cpp
        headers/views/PilotoView.h
        headers/dto/PilotoInDTO.h
        headers/dto/PilotoOutDTO.h
        sources/services/PilotoService.cpp
        headers/services/PilotoService.h
        sources/repo/RacingRepositoryBin.cpp
        headers/repo/RacingRepositoryBin.h
        headers/repo/IRacingRepository.h
        sources/model/RacingApp.cpp
        headers/model/RacingApp.h
        sources/model/PilotoContainer.cpp
        headers/model/PilotoContainer.h
        sources/model/Piloto.cpp
        headers/model/Piloto.h
        sources/mappers/PilotoMapper.cpp
        headers/mappers/PilotoMapper.h
        sources/controllers/Controller.cpp
        headers/controllers/Controller.h
        headers/exceptions/InvalidDataException.h
        headers/exceptions/NoDataException.h
        headers/exceptions/DuplicatedDataException.h
        headers/exceptions/DataConsistencyException.h
        headers/model/Equipa.h
        headers/model/EquipaContainer.h
        headers/dto/EquipaInDTO.h
        headers/dto/EquipaOutDTO.h
        headers/mappers/EquipaMapper.h
        headers/services/EquipaService.h
        sources/model/EquipaContainer.cpp
        sources/mappers/EquipaMapper.cpp
        sources/services/EquipaService.cpp
        sources/views/EquipaView.cpp
)

# Ensure data/ folder exists next to the binary
add_custom_command(TARGET GestaoAutomobilismo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
        $<TARGET_FILE_DIR:GestaoAutomobilismo>/data
)
