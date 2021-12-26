project(tcp_client)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(tcp_client ${SOURCE_FILES})
target_include_directories(tcp_client PRIVATE include)
target_link_libraries(tcp_client Threads::Threads)
