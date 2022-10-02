#include "vertex_buffer_object.h"

#include "glad/glad.h"

namespace graphics {

VertexBufferObject::VertexBufferObject():
id_(0) {
    glGenBuffers(1, &id_);
}

void VertexBufferObject::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, id_);
}

void VertexBufferObject::fill(const char *const buff, unsigned int size) {
    glBufferData(GL_ARRAY_BUFFER, size, buff, GL_STREAM_DRAW);
}

VertexBufferObject::VBOId VertexBufferObject::getId() const {
    return id_;
}

void VertexBufferObject::setAttrs(const unsigned int attrId, const unsigned int vertexSize,
                                  const unsigned int step, const unsigned int *offset) {
    glVertexAttribPointer(attrId, vertexSize, GL_FLOAT, GL_FALSE, step, (void*)offset);
}

} // namespace graphics
