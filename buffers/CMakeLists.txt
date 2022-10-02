cmake_minimum_required(VERSION 3.20)

project(buffers)

add_library(${PROJECT_NAME} STATIC vertex_buffer_object.cpp vertex_array_object.cpp)

target_link_libraries(${PROJECT_NAME} glad)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})