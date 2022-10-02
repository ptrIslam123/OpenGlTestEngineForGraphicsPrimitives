#version 330 core

layout(location = 0) in vec3 vertexPos;

out vec3 Color;

void main() {
    gl_Position = vec4(vertexPos.x, vertexPos.y, vertexPos.z, 1.0);
    Color = vec3(0.75f, 0.25f, 0.45f);
}