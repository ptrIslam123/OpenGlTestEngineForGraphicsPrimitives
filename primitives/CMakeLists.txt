cmake_minimum_required(VERSION 3.20)

project(primitives)
set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC
    primitive.cpp
    triangle.cpp
    rectangle.cpp
    quad.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ../)
target_link_libraries(${PROJECT_NAME} glm)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})