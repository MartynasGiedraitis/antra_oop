cmake_minimum_required(VERSION 3.29)
project(strategija_list)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(strategija_list
    main.cpp
    studentas.cpp
)