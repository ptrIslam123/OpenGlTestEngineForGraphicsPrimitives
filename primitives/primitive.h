#pragma once

#include <vector>
#include <string>
#include "glm/glm/mat4x4.hpp"

namespace graphics {

class Primitive {
public:
    typedef std::vector<float> PrimitiveVertexes;

    Primitive() = default;
    virtual ~Primitive() = default;
    virtual PrimitiveVertexes &getVertexes() = 0;
    virtual const PrimitiveVertexes &getVertexes() const = 0;
    virtual std::string getFigureName() const;
    void transform(const glm::mat4 &mat);
};

} // namespace graphics