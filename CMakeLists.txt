cmake_minimum_required(VERSION 3.0.0)

project(openGlApplication)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(glfw-3.3.5)
add_subdirectory(glad)
add_subdirectory(glm)
add_subdirectory(shader)
add_subdirectory(window)
add_subdirectory(buffers)
add_subdirectory(graphics)
add_subdirectory(primitives)

add_executable(${PROJECT_NAME}
    main.cpp
)


target_include_directories(${PROJECT_NAME} PUBLIC glad/include)
target_include_directories(${PROJECT_NAME} PUBLIC glm)

target_link_libraries(${PROJECT_NAME} primitives)
target_link_libraries(${PROJECT_NAME} graphics)
target_link_libraries(${PROJECT_NAME} buffers)
target_link_libraries(${PROJECT_NAME} window)
target_link_libraries(${PROJECT_NAME} shader)
target_link_libraries(${PROJECT_NAME} glm)