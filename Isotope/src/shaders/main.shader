#shader vertex
#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 color;


out vec4 Color;
uniform mat4 MVP;

void main()
{
    gl_Position = vec4(pos,1.0);
    Color = color;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 col;


in vec4 Color;


void main()
{


   col = Color;

};

