# AED 2022/2023 - Aula Pratica 10
# Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

cmake_minimum_required(VERSION 3.10)
project(aed2223_p10)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Tests")

add_executable(aed2223_p10 main.cpp Tests/tests.cpp Tests/graph.cpp Tests/funWithGraphs.cpp)

target_link_libraries(aed2223_p10 gtest gtest_main)
