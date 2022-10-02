#include <iostream>

#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader/shader.h"
#include "window/context_window.h"
#include "graphics/graphics.h"
#include "primitives/triangle.h"
#include "primitives/rectangle.h"
#include "primitives/quad.h"

using namespace graphics;

void resizeWindowEventHandler(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "No passing input args: <vertexShaderPath> <fragmentShaderPath>"
                  << std::endl;
        return EXIT_FAILURE;
    }

    constexpr auto WINDOW_WIDTH = 800;
    constexpr auto WINDOW_HEIGHT = 600;
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGl application");
    window.registerCallbackForResizeWindow(resizeWindowEventHandler);

    Graphics graphics;
    {
        Shader shader;
        const std::string vertexShaderFileName(argv[1]);
        const std::string fragmentShaderFileName(argv[2]);
        shader.create(vertexShaderFileName, fragmentShaderFileName);
        graphics = Graphics(shader);
    }

    /**
     * @details Обычно, применение матрицы трансформации к примитивам применяется в самих шейдерах
     * (осущ применение матрицы трансформации для каждой вершины примитивов и отсылается на карточку через
     *  uniform переменные). В данном случае сделано иначе для простой демонстрации
     *  (для общего метода Primitive::transform)
     */
    {
        const util::PointF32 p1(1.0f, 1.0f);
        const util::PointF32 p2(0.0f, 0.0f);
        const util::PointF32 p3(1.0f, 0.0f);
        const auto transformMat =
                glm::scale(glm::mat4(1.0f), glm::vec3(0.75f, 0.75f, 1.0f));
        Triangle triangle(p1, p2, p3);
        triangle.transform(transformMat);
        graphics.addPrimitive(triangle);
    }
    {
        const util::PointF32 pos(-1.f, -1.f);
        const util::PointF32 size(0.25f, 0.75f);
        const auto transformMat =
                glm::rotate(glm::mat4(1.0f), 45.0f, glm::vec3(1.0f, 1.0f, 1.0f)) *
                glm::scale(glm::mat4(1.0f), glm::vec3(0.95f, 0.55f, 1.0f));
        Rectangle rectangle(pos, size);
        rectangle.transform(transformMat);
        graphics.addPrimitive(rectangle);
    }
    {
        const util::PointF32 pos(0.f, -1.f);
        constexpr auto size = 0.5f;
        Quad quad(pos, size);
        const auto transformMat =
                glm::scale(glm::mat4(1.0f), glm::vec3(0.75f, 0.75f, 1.0f)) *
                glm::translate(glm::mat4(1.0f), glm::vec3(-1.75f, 0.75f, 0.f));
        quad.transform(transformMat);
        graphics.addPrimitive(quad);
    }

    graphics.loadVertexesToVMem();
    while (!window.isClose()) {
        window.setBackgroundColor(0.2f, 0.3f, 0.3f, 1.0f);
        graphics.draw();
        window.redraw();
    }
    return EXIT_SUCCESS;
}
