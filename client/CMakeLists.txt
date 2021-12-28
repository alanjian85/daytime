project(daytime_client)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(daytime_client ${SOURCE_FILES})
target_include_directories(daytime_client PRIVATE include)
target_link_libraries(daytime_client Threads::Threads)
