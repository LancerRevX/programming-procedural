cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)

project(programming-procedural-tests)

include_directories(../)
add_executable(
    programming-procedural-tests 
    main.cpp
    test_file.cpp
    matrix.cpp
    square_matrix.cpp
    diagonal_matrix.cpp
    lower_triangular_matrix.cpp
    container.cpp
    ../matrix.c 
    ../square_matrix.c
    ../diagonal_matrix.c
    ../lower_triangular_matrix.c
    ../container.c
)

target_link_libraries(programming-procedural-tests gtest)