#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

out vec4 pos;
out vec4 col;

uniform mat4 model = mat4(1.0f);
uniform mat4 view = mat4(1.0f);
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * position;
	pos = position;
	col = color;
}