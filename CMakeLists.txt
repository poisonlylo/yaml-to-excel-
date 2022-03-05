cmake_minimum_required(VERSION 3.20)
project(parser C)

include_directories(/usr/local/include) #include folder location
link_directories(/usr/local/lib) #lib folder location

set(CMAKE_C_STANDARD 99)

add_executable(parser main.c)

target_link_libraries(parser /usr/local/lib/libxlsxwriter.dylib)
target_link_libraries(parser /usr/local/lib/libyaml.dylib)

