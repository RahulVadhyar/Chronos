#version 450
#extension GL_EXT_debug_printf : enable
layout(binding = 0) uniform UniformBufferObject {
    mat4 model;
    mat4 view;
    mat4 proj;
} ubo;

layout(location = 0) in vec2 inPosition;
layout(location = 1) in vec2 inTexCoord;

layout(location = 0) out vec2 fragTexCoord;

void main() {
    debugPrintfEXT("inPosition is %f and %f", inPosition.x, inPosition.y);
    gl_Position = ubo.proj * ubo.view * ubo.model * vec4(inPosition, 0.0, 1.0);
    fragTexCoord = inTexCoord;
}