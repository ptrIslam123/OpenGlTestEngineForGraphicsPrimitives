cmake_minimum_required(VERSION 3.20)

project(graphics)

add_library(${PROJECT_NAME} STATIC graphics.cpp)

target_link_libraries(${PROJECT_NAME} glad)
target_link_libraries(${PROJECT_NAME} buffers)

target_include_directories(${PROJECT_NAME} PUBLIC ../)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})