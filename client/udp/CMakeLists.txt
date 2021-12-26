project(daytime_client_udp)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(daytime_client_udp ${SOURCE_FILES})
target_include_directories(daytime_client_udp PRIVATE include)
target_link_libraries(daytime_client_udp Threads::Threads)
