#version 450 core
#extension GL_EXT_debug_printf : enable
layout (location = 0) in vec2 inUV;

layout (binding = 0) uniform sampler2D samplerFont;

layout (location = 0) out vec4 outFragColor;

layout(binding = 2) uniform  Color {
	vec3 fragColor;
} inputColor;


void main(void)
{
	float color = texture(samplerFont, inUV).r;
	outFragColor = vec4(color);
	outFragColor.rgb = inputColor.fragColor;
}
