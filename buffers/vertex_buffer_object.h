#pragma once

namespace graphics {

class VertexBufferObject {
public:
    typedef unsigned int VBOId;
    VertexBufferObject();

    void bind();
    void fill(const char *buff, unsigned int size);
    void setAttrs(unsigned int attrId, unsigned int vertexSize, unsigned int step,
                  const unsigned int *offset);
    VBOId getId() const;

private:
    VBOId id_;
};

} // namespace graphics