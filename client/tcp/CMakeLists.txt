project(daytime_client_tcp)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(daytime_client_tcp ${SOURCE_FILES})
target_include_directories(daytime_client_tcp PRIVATE include)
target_link_libraries(daytime_client_tcp Threads::Threads)
