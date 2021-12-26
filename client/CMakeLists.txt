project(client)

add_executable(client main.cpp)
target_link_libraries(client Threads::Threads)
