cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(Seengine VERSION 0.1.0)

file(GLOB executable_source_files
    "main.c"
    "src/*.c"
    "src/seengine/*.c"
    "src/seengine/*.*.c"
    "src/seengine/*.*.*.c"
    "src/seengine/*/*.c"
)

set(executable_header_files
    include/
)

add_executable(${CMAKE_PROJECT_NAME} ${executable_source_files})

if (WIN32)

elseif(UNIX)

endif ()

include_directories(${executable_header_files})
