cmake_minimum_required(VERSION 3.12)
project(daytime)

find_package(Threads REQUIRED)

add_subdirectory(server)
add_subdirectory(client)
