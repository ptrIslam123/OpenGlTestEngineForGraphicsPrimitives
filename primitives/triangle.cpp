#include "triangle.h"
#include <glm/vec4.hpp>

namespace graphics {

Triangle::Triangle(const PointF32 &p1, const PointF32 &p2,
                   const PointF32 &p3):
Primitive(),
vertexes_(vertexesCapacity) {
    auto index = 0;
    replaceVertex(index, p1);
    index += 3;

    replaceVertex(index, p2);
    index += 3;

    replaceVertex(index, p3);
}

void Triangle::replaceVertex(unsigned int vertexIndex, const Triangle::PointF32 &point) {
    vertexes_[vertexIndex + 0] = point.x;
    vertexes_[vertexIndex + 1] = point.y;
    vertexes_[vertexIndex + 2] = 0.0f;
}

Primitive::PrimitiveVertexes &Triangle::getVertexes() {
    return vertexes_;
}

const Primitive::PrimitiveVertexes &Triangle::getVertexes() const {
    return vertexes_;
}

std::string Triangle::getFigureName() const {
    return "Triangle";
}

} // namespace graphics