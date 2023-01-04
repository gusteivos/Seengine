cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(Seengine VERSION 0.1.0)

file(GLOB executable_source_files
    "main.c"
    "src/*.c"
    "src/service/*.c"
    "src/service/*.*.c"
)

set(executable_header_files
    include
    include/service
)

add_executable(Seengine ${executable_source_files})

include_directories(${executable_header_files})
