##shader vertex
#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 color;


out vec4 Color;
uniform mat4 viewProjection;

void main()
{
    Color = color;
    gl_Position = viewProjection * vec4(pos, 1.0);

};

#shader fragment
#version 330 core

layout(location = 0) out vec4 col;


in vec4 Color;


void main()
{


    col = Color;

};
