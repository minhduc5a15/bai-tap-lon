cmake_minimum_required(VERSION 3.27)
project(raylib_project C)

set(CMAKE_C_STANDARD 23)

find_package(PkgConfig REQUIRED)

pkg_check_modules(RAYLIB REQUIRED raylib)
file(GLOB_RECURSE COMPONENTS "components/*.c")
file(GLOB_RECURSE WINDOW "window/*.c")
file(GLOB_RECURSE FUNCTIONS "functions/*.c")
file(GLOB_RECURSE CONSTANTS "constants/*.c")
file(GLOB_RECURSE HEADERS "./*.h")

add_executable(raylib_project main.c ${COMPONENTS} ${HEADERS} ${WINDOW} ${CONSTANTS} ${FUNCTIONS})

target_include_directories(raylib_project PRIVATE ${RAYLIB_INCLUDE_DIRS})
target_link_libraries(raylib_project PRIVATE ${RAYLIB_LIBRARIES})
