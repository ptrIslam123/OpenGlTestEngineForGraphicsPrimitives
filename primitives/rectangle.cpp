#include "rectangle.h"

namespace graphics {

Rectangle::Rectangle(const PointF32 &pos, const PointF32 &size):
Primitive(),
vertexes_(vertexesCapacity) {
    const Triangle firstHalf(pos, pos + PointF32(size.x, 0.f), pos + size);
    const Triangle secondHalf(pos, pos + PointF32(0.f, size.y), pos + size);
    const auto &firstTriangleVertexes = firstHalf.getVertexes();
    const auto &secondTriangleVertexes = secondHalf.getVertexes();
    auto start = vertexes_.begin();
    std::copy(firstTriangleVertexes.cbegin(), firstTriangleVertexes.cend(), start);
    std::advance(start, Triangle::vertexesCapacity);
    std::copy(secondTriangleVertexes.cbegin(), secondTriangleVertexes.cend(), start);
}

Primitive::PrimitiveVertexes &Rectangle::getVertexes() {
    return vertexes_;
}

const Primitive::PrimitiveVertexes &Rectangle::getVertexes() const {
    return vertexes_;
}

std::string Rectangle::getFigureName() const {
    return "Rectangle";
}

} // namespace graphics