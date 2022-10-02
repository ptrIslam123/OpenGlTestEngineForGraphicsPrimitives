#include "primitive.h"

namespace graphics {

void Primitive::transform(const glm::mat4 &mat) {
    auto &vertexes = getVertexes();
    for (auto i = 0; i < vertexes.size(); i += 3) {
        const auto vec4 = glm::vec4(vertexes[i], vertexes[i + 1], vertexes[i + 2], 0.f);
        const auto newVec4 = mat * vec4;
        vertexes[i] = newVec4.x;
        vertexes[i + 1] = newVec4.y;
        vertexes[i + 2] = newVec4.z;
    }
}

std::string Primitive::getFigureName() const {
    return "Primitive";
}

} // namespace graphics