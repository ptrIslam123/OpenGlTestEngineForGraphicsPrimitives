#include "quad.h"

namespace graphics {

Quad::Quad(const Quad::PointF32 &pos, const float size):
Primitive(),
vertexes_(vertexesCapacity) {
    const Triangle firstHalf(pos, pos + PointF32(size, 0.f), pos + PointF32(size, size));
    const Triangle secondHalf(pos, pos + PointF32(0.f, size), pos + PointF32(size, size));
    const auto &firstTriangleVertexes = firstHalf.getVertexes();
    const auto &secondTriangleVertexes = secondHalf.getVertexes();
    auto start = vertexes_.begin();
    std::copy(firstTriangleVertexes.cbegin(), firstTriangleVertexes.cend(), start);
    std::advance(start, Triangle::vertexesCapacity);
    std::copy(secondTriangleVertexes.cbegin(), secondTriangleVertexes.cend(), start);
}

Primitive::PrimitiveVertexes &Quad::getVertexes() {
    return vertexes_;
}

const Primitive::PrimitiveVertexes &Quad::getVertexes() const {
    return vertexes_;
}

std::string Quad::getFigureName() const {
    return "quad";
}

} // namespace graphics