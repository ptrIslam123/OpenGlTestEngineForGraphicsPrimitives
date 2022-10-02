#pragma once

#include <array>

#include "primitive.h"
#include "point.h"

namespace graphics {

class Triangle : public  Primitive {
public:
    static constexpr auto vertexesCapacity = 9;
    typedef std::vector<float> Vertexes;
    typedef util::PointF32 PointF32;

    Triangle() = default;
    Triangle(const PointF32 &p1, const PointF32 &p2, const PointF32 &p3);
    Triangle(const Triangle &other) = default;
    Triangle(Triangle &&other) = default;
    Triangle &operator=(const Triangle &other) = default;
    Triangle &operator=(Triangle &&other) = default;
    virtual PrimitiveVertexes &getVertexes() override;
    virtual const PrimitiveVertexes &getVertexes() const override;
    virtual std::string getFigureName() const override;

private:
    void replaceVertex(unsigned int vertexIndex, const PointF32 &point);
    Vertexes vertexes_;
};

} // namespace graphics