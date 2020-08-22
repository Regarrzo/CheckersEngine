cmake_minimum_required(VERSION 3.10)

project(checkers VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -lpthread")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

add_executable(checkers main.cpp checkers.cpp bitboard.cpp pos.cpp search.cpp evaluate.cpp)
target_include_directories(checkers PUBLIC "${PROJECT_BINARY_DIR}")
