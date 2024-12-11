cmake_minimum_required(VERSION 3.10)
project(TestProject)

set(CMAKE_CXX_STANDARD 11)

# Rasti Google Test biblioteką
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

# Sukurti testų vykdomąjį failą
add_executable(test_student tests.cpp)

# Susieti Google Test ir pthread su vykdomuoju failu
target_link_libraries(test_student ${GTEST_LIBRARIES} pthread)
