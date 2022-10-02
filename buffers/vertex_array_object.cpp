#include "vertex_array_object.h"

#include "glad/glad.h"

namespace graphics {

VertexArrayObject::VertexArrayObject():
id_(0) {
    glGenVertexArrays(1, &id_);
}

void VertexArrayObject::bind() {
    glBindVertexArray(id_);
}

VertexArrayObject::VAOId VertexArrayObject::getId() const {
    return id_;
}

void VertexArrayObject::enableAttr(unsigned int attrId) {
    glEnableVertexAttribArray(attrId);
}

} // namespace graphics