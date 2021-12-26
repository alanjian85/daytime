project(udp_client)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(udp_client ${SOURCE_FILES})
target_include_directories(udp_client PRIVATE include)
target_link_libraries(udp_client Threads::Threads)
