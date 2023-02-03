cmake_minimum_required(VERSION 3.25.0)
project(rpsbot)
set(CMAKE_CXX_STANDARD 20)

set(
    SOURCES
    src/main.cpp
    src/move.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-fsanitize=address,undefined,integer -g")

add_compile_options(
    -Wall -Wextra -Wpedantic -Weffc++ -Wshadow -Wformat
    -Wconversion -Wuninitialized -march=native
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE 
    ${PROJECT_SOURCE_DIR}/src
)
