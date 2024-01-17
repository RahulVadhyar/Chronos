#version 450 core
#extension GL_EXT_debug_printf : enable
layout (location = 0) in vec2 inPos;
layout (location = 1) in vec2 inUV;
layout (location = 0) out vec2 outUV;

layout(binding = 1) uniform UniformBufferObject {
    mat4 model;
    mat4 view;
    mat4 proj;
} ubo;

out gl_PerVertex 
{
	vec4 gl_Position;   
};

void main(void)
{   

	gl_Position = ubo.proj * ubo.view * ubo.model * vec4(inPos, 0.0, 1.0);

	outUV = inUV;
}