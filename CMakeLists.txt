cmake_minimum_required(VERSION 3.16)
project(Snake CXX)
set(CMAKE_CXX_STANDARD 20)
find_package(raylib REQUIRED)
include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreAudio"
    "-framework CoreVideo"
)

add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)