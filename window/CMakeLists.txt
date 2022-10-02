cmake_minimum_required(VERSION 3.20)

project(window)

add_library(${PROJECT_NAME} STATIC context_window.cpp)

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glad)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})