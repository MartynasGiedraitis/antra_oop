cmake_minimum_required(VERSION 3.10)
project(oop)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project main.cpp studentas.cpp studentas.h mylib.h)
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})


add_executable(test_student tests.cpp)
target_link_libraries(test_student ${GTEST_LIBRARIES} pthread)
