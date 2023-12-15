cmake_minimum_required(VERSION 3.10)

project(project)

set(CMAKE_CXX_STANDARD 17)

set(PROGRAM_SRCS
    coding/Animation.cpp
    coding/Collider.cpp
    coding/Platform.cpp
    coding/Player.cpp
    coding/main.cpp
    coding/Enemy.cpp
    coding/Weapon.cpp
    coding/Whip.cpp
    coding/Gem.cpp
    coding/visuals.cpp
)

include_directories(
    src/include/
    coding/
)

find_package(SFML 2.6.1 COMPONENTS graphics REQUIRED)

add_executable(project ${PROGRAM_SRCS})

target_link_libraries(project sfml-graphics)