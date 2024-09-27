cmake_minimum_required(VERSION 3.29)
project(JiGeumDash C)

set(CMAKE_C_STANDARD 11)
set(raylib_USE_STATIC_LIBS 1)

find_package(raylib REQUIRED)
find_package(cJSON REQUIRED)

add_executable(${PROJECT_NAME} main.c game.c util.c)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib cJSON)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE gdi32 winmm)
elseif(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
endif()