cmake_minimum_required(VERSION 3.26)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

# Selects a multi-threaded statically-linked runtime library
# with or without debug information depending on the configuration for all following targets.
#
# Comment this line out or add "DLL" to this variable to use dynamically linked runtime.
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

project(snake)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_executable(snake main.cpp
        player.hpp
        window.hpp
)

target_link_libraries(snake PRIVATE sfml-system sfml-window sfml-graphics)

# cl.exe or clang-cl.exe
if ((CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
        OR MSVC)
    target_compile_options(
            ${PROJECT_NAME}
            PRIVATE
            "/permissive-"
            "/W4" "/w14640"
            "/w14242" "/w14254" "/w14263" "/w14265"
            "/w14287" "/we4289" "/w14296" "/w14311"
            "/w14545" "/w14546" "/w14547" "/w14549"
            "/w14555" "/w14619" "/w14826" "/w14905"
            "/w14906" "/w14928"
    )
endif ()

# g++ or clang++
if ((CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "GNU")
        OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU"
        OR MINGW)
    target_compile_options(
            ${PROJECT_NAME}
            PRIVATE
            "-Wall" "-Wextra" "-Wshadow" "-pedantic"
            "-Wnon-virtual-dtor" "-Wunused"
            "-Wconversion" "-Wsign-conversion"
            "-Wnull-dereference" "-Wdouble-promotion"
            "-Woverloaded-virtual" "-Wpedantic"
            "-Wcast-align" "-Wformat=2"
    )
endif ()

# gcc exclusive flags
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU"
        OR MINGW)
    target_compile_options(
            ${PROJECT_NAME}
            PRIVATE
            "-Wmisleading-indentation" "-Wduplicated-cond"
            "-Wduplicated-branches" "-Wlogical-op"
            "-Wnull-dereference" "-Wuseless-cast"
    )
endif ()