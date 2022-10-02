#include "shader.h"

#include "glad/glad.h"

#include <array>
#include <stdexcept>
#include <fstream>
#include <sstream>

namespace {
    typedef std::array<char, 512> StatusBuff;
} // namespace

namespace graphics {

Shader::Shader() :
        id_(0),
        vertexProgramId_(glCreateShader(GL_VERTEX_SHADER)),
        fragmentProgramId_(glCreateShader(GL_FRAGMENT_SHADER)) {
}

Shader::~Shader() {
    if (vertexProgramId_ >= 0 && fragmentProgramId_ >= 0) {
        glDeleteShader(vertexProgramId_);
        glDeleteShader(fragmentProgramId_);
    }
}

void Shader::create(const std::string_view vertexShProgramPath,
                    const std::string_view fragmentShProgramPath) {
    compile(readProgram(vertexShProgramPath), readProgram(fragmentShProgramPath));
    link();
}

void Shader::compile(const std::string_view vertexShProgram,
                     const std::string_view fragmentShProgram) const {
    const auto vertexProgramSrc = vertexShProgram.data();
    const auto fragmentProgramSrc = fragmentShProgram.data();
    auto status = 1;
    StatusBuff statusBuff = {0};

    glShaderSource(vertexProgramId_, 1, &vertexProgramSrc, NULL);
    glCompileShader(vertexProgramId_);
    glGetShaderiv(vertexProgramId_, GL_COMPILE_STATUS, &status);

    if (!status) {
        glGetShaderInfoLog(vertexProgramId_, statusBuff.size(), NULL, statusBuff.data());
        throw std::runtime_error("Error when try compile vertex shader program: " +
                                 std::string(statusBuff.data()));
    }

    glShaderSource(fragmentProgramId_, 1, &fragmentProgramSrc, NULL);
    glCompileShader(fragmentProgramId_);
    glGetShaderiv(fragmentProgramId_, GL_COMPILE_STATUS, &status);

    if (!status) {
        glGetShaderInfoLog(fragmentProgramId_, statusBuff.size(), NULL, statusBuff.data());
        throw std::runtime_error("Error when try compile fragment shader program : " +
                                 std::string(statusBuff.data()));
    }
}

void Shader::link() {
    StatusBuff statusBuff = {0};
    auto status = 1;
    id_ = glCreateProgram();
    glAttachShader(id_, vertexProgramId_);
    glAttachShader(id_, fragmentProgramId_);
    glLinkProgram(id_);
    glGetShaderiv(id_, GL_LINK_STATUS, &status);

    if (!status) {
        glGetShaderInfoLog(id_, statusBuff.size(), NULL, statusBuff.data());
        throw std::runtime_error("Link error in the shader program: " +
                                 std::string(statusBuff.data()));
    }
}

Shader::ShaderProgramId Shader::getId() const {
    return id_;
}

std::string Shader::readProgram(const std::string_view filePath) const {
    std::ifstream file(filePath.data());
    if (!file.is_open()) {
        throw std::runtime_error(std::string(filePath) + ": file not fount");
    }

    std::stringstream streamData;
    streamData << file.rdbuf();
    return streamData.str();
}

void Shader::use() const {
    glUseProgram(id_);
}

} // namespace graphics
