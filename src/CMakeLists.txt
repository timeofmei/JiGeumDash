cmake_minimum_required(VERSION 3.29)
project(JiGeumDash C)

set(CMAKE_C_STANDARD 11)

find_package(raylib REQUIRED)
find_package(cJSON REQUIRED)

add_executable(${PROJECT_NAME} main.c game.c util.c)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib cJSON)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()