cmake_minimum_required(VERSION 3.16)
project(Famil)

set(CMAKE_CXX_STANDARD 17)

# Add main exe file
add_executable(Famil famil.cpp)

# Add subfolders
add_subdirectory(inc)
add_subdirectory(source)
