#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <string_view>

namespace graphics {

class Window {
public:
    typedef void (*ResizeWindowCallback)(GLFWwindow* window, int width, int height);

    Window(unsigned short width, unsigned short height, std::string_view title);
    ~Window();
    GLFWwindow *getContext() const;

    void setBackgroundColor(float r, float g, float b, float a);
    void registerCallbackForResizeWindow(ResizeWindowCallback callback);
    void redraw();
    bool isClose() const;

private:
    GLFWwindow *contextWindow_;
};

} // namespace graphics
