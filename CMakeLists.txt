cmake_minimum_required(VERSION 4.1)

include(FetchContent)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# ============================================
#                   Project 
# ============================================
project(
    tetris
    VERSION 0.1.0
    LANGUAGES CXX 
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ============================================
#                Dependencies
# ============================================
FetchContent_Declare(
    sdl
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git 
    GIT_TAG 96292a5b464258a2b926e0a3d72f8b98c2a81aa6 # 3.2.20
)
FetchContent_MakeAvailable(sdl)


# ============================================
#                  Targets 
# ============================================
add_executable(tetris)


# ============================================
#                Source Files 
# ============================================
set(
    TETRIS_SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/game.cpp
)

target_sources(
    tetris 
    PRIVATE
    ${TETRIS_SOURCES}
)


# ============================================
#             Include Directories 
# ============================================
target_include_directories(
    tetris 
    PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)


# ============================================
#                Configuration 
# ============================================
target_compile_options(
    tetris 
    PRIVATE
    $<$<CONFIG:Debug>:
        -O0 
        -g3 
        -fsanitize=address 
        -fsanitize=undefined
        -Wall 
        -Werror
        -Wextra
        -Wpedantic
        -Wshadow
        -Wconversion
        -Wformat=2
        -fno-omit-frame-pointer
        -fcolor-diagnostics
    >

    $<$<CONFIG:Release>:
        -O3 
        -DNDEBUG
        -Wall 
        -Werror
        -Wextra
        -Wpedantic
        -Wshadow
        -Wconversion
        -Wformat=2
        -fcolor-diagnostics
    >
)


# ============================================
#                  Linking 
# ============================================
target_link_options(
    tetris
    PRIVATE
    $<$<CONFIG:Debug>:-fsanitize=address>
)
target_link_libraries(
    tetris 
    PRIVATE
    SDL3::SDL3
)
