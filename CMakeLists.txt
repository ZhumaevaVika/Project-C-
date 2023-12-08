cmake_minimum_required(VERSION 3.10)

project(project)

set(PROGRAM_SRCS
    coding/Animation.cpp
    coding/Collider.cpp
    coding/Platform.cpp
    coding/Player.cpp
    coding/main.cpp
)

include_directories(
    extra-libs/
    coding/
)

find_package(SFML 2.6.1 COMPONENTS graphics REQUIRED)

add_executable(project ${PROGRAM_SRCS})

target_link_libraries(project sfml-graphics)
