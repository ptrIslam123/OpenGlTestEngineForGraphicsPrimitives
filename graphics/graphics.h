#pragma once

#include <vector>

#include "shader/shader.h"
#include "buffers/vertex_buffer_object.h"
#include "buffers/vertex_array_object.h"
#include "primitives/primitive.h"

namespace graphics {

class Graphics {
public:

    Graphics() = default;
    Graphics(const Shader &shader);

    void addPrimitive(const Primitive &primitive);
    void loadVertexesToVMem();
    void draw();
    void setShader(const Shader &shader);

private:
    Shader shader_;
    VertexBufferObject buffer_;
    VertexArrayObject vertexArrayObject_;
    std::vector<float> vertexes_;
    size_t vertexCount_;
};

} // namespace graphics