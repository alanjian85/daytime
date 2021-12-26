project(daytime_server)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(daytime_server ${SOURCE_FILES})
target_include_directories(daytime_server PRIVATE include)
target_link_libraries(daytime_server Threads::Threads)
