cmake_minimum_required(VERSION 3.26)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

project(snake)

set(CMAKE_CXX_STANDARD 23)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_executable(snake main.cpp)

target_link_libraries(snake PRIVATE sfml-system sfml-network sfml-window sfml-graphics)
