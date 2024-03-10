#version 450

layout(binding = 1) uniform  Color {
	vec3 fragColor;
} color;

layout(location = 0) out vec4 outColor;

void main() {
	outColor = vec4(color.fragColor, 1.0);
}