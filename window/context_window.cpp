#include "context_window.h"

#include <stdexcept>

namespace graphics {

Window::Window(const unsigned short width, const unsigned short height,
               const std::string_view title):
contextWindow_(nullptr) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    contextWindow_ = glfwCreateWindow(width, height, title.data(), NULL, NULL);
    if (contextWindow_ == NULL) {
        glfwTerminate();
        throw std::runtime_error("Can`t create glfw context window");
    }

    glfwMakeContextCurrent(contextWindow_);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }
}

Window::~Window() {
    glfwTerminate();
}

void Window::registerCallbackForResizeWindow(Window::ResizeWindowCallback callback) {
    glfwSetFramebufferSizeCallback(contextWindow_, callback);
}

GLFWwindow *Window::getContext() const {
    return contextWindow_;
}

void Window::redraw() {
    glfwSwapBuffers(contextWindow_);
    glfwPollEvents();
}

bool Window::isClose() const {
    if(glfwGetKey(contextWindow_, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(contextWindow_, true);
    }
    return glfwWindowShouldClose(contextWindow_);
}

void Window::setBackgroundColor(const float r, const float g, const float b, const float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

} // namespace graphics