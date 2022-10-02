#pragma once
#include <string_view>

namespace graphics {

class Shader {
public:
    typedef unsigned int ShaderProgramId;

    Shader();
    ~Shader();
    Shader(Shader &&other) = default;
    Shader &operator=(Shader &&other) = default;
    Shader(const Shader &other) = default;
    Shader &operator=(const Shader &other) = default;

    void create(std::string_view vertexShProgramPath, std::string_view fragmentShProgramPath);
    void use() const;
    ShaderProgramId getId() const;

private:
    void compile(std::string_view vertexShProgram, std::string_view fragmentShProgram) const;
    void link();
    std::string readProgram(std::string_view filePath) const;

    ShaderProgramId id_;
    ShaderProgramId vertexProgramId_;
    ShaderProgramId fragmentProgramId_;
};

} // namespace graphics