project(client)

find_package(Threads REQUIRED)

add_executable(client main.cpp)
target_link_libraries(client Threads::Threads)
