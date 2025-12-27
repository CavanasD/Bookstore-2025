cmake_minimum_required(VERSION 3.16)
project(Bookstore)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include/)

add_executable(cleanup src/cleanup.cpp)

add_executable(code src/bookmanager.cpp src/cmdparser.cpp src/logmanager.cpp src/usermanager.cpp src/main.cpp)