cmake_minimum_required(VERSION 3.16)
project(Puzzle8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

add_executable(puzzle8 src/main.cpp)
target_link_libraries(puzzle8 PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)