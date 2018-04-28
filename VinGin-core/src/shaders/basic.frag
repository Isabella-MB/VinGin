#version 330 core

layout (location = 0) out vec4 color;

in vec4 pos;
in vec4 col;

uniform vec2 light_position;

void main()
{
	float intensity = 1.0 / length(pos.xy - light_position);
	color = col * intensity;
}