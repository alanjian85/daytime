project(server)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(server ${SOURCE_FILES})
target_include_directories(server PRIVATE include)
target_link_libraries(server Threads::Threads)
