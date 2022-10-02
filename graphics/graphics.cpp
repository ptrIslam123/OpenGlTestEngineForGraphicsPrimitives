#include "graphics.h"

#include <glad/glad.h>

namespace graphics {

Graphics::Graphics(const Shader &shader):
shader_(shader),
buffer_(),
vertexArrayObject_(),
vertexes_(),
vertexCount_(0) {
}

void Graphics::addPrimitive(const Primitive &primitive) {
    auto &vertexes = primitive.getVertexes();
    std::for_each_n(vertexes.cbegin(), vertexes.size(), [this](const auto &vertex){
        vertexes_.push_back(vertex);
    });

    vertexCount_ += vertexes.size();
}

void Graphics::draw() {
    vertexArrayObject_.bind();
    glDrawArrays(GL_TRIANGLES, 0, vertexCount_);
}

void Graphics::loadVertexesToVMem() {
    buffer_.bind();
    buffer_.fill((char*)vertexes_.data(), sizeof(float) * vertexes_.size());

    vertexArrayObject_.bind();
    buffer_.setAttrs(0, 3, 0, nullptr);
    vertexArrayObject_.enableAttr(0);
    shader_.use();
}

void Graphics::setShader(const Shader &shader) {
    shader_ = shader;
}

} // namespace graphics