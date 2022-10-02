#pragma once

#include "point.h"
#include "primitive.h"
#include "triangle.h"

namespace graphics {

class Rectangle : public Primitive {
public:
    typedef util::PointF32 PointF32;
    static constexpr auto vertexesCapacity = Triangle::vertexesCapacity * 2;

    Rectangle() = default;
    Rectangle(const PointF32 &pos, const PointF32 &size);
    Rectangle(Rectangle &&other) = default;
    Rectangle(const Rectangle &other) = default;
    Rectangle &operator=(Rectangle &&other) = default;
    Rectangle &operator=(const Rectangle &other) = default;
    virtual PrimitiveVertexes &getVertexes() override;
    virtual const PrimitiveVertexes &getVertexes() const override;
    virtual std::string getFigureName() const override;

private:
    std::vector<float> vertexes_;
};

} // namespace graphics {