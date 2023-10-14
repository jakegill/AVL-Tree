cmake_minimum_required(VERSION 3.24)
project(AVL)

set(CMAKE_CXX_STANDARD 14)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1
)
FetchContent_MakeAvailable(Catch2)

include_directories(test-unit)

add_executable(Main
        src/main.cpp
        src/AVLTree.cpp src/AVLTree.h src/Parser.cpp src/AVLTree.h)

add_executable(Tests
        test-unit/test.cpp
        src/AVLTree.cpp src/AVLTree.h src/Parser.cpp src/Parser.h src/AVLTree.h)

target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)