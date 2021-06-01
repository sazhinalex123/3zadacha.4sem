cmake_minimum_required(VERSION 3.1)

project(zadacha3)

set(PROG_SRC Source.cpp CRatVector.cpp CRatVector0.cpp CRatVector1.cpp Creator.cpp)
set(PROG_HDR AutoTest.hpp CRatVector.h CRatVector0.h CRatVector1.h Creator.h)

configure_file(input.txt input.txt COPYONLY)

add_executable(${PROJECT_NAME} ${PROG_SRC} ${PROG_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -std=c++17")
