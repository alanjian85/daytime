cmake_minimum_required(VERSION 3.12)
project(daytime)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Threads REQUIRED)

add_subdirectory(server)
add_subdirectory(client)
