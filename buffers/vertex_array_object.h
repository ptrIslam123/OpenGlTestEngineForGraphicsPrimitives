#pragma once

namespace graphics {

class VertexArrayObject {
public:
    typedef unsigned int VAOId;

    VertexArrayObject();
    void bind();
    void enableAttr(unsigned int attrId);
    VAOId getId() const;
private:
    VAOId id_;
};

} // namespace graphics