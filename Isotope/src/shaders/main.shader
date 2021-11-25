#shader vertex
#version 330 core

layout(location = 0) in vec4 pos;
layout(location = 1) in vec2 vertexUV;

out vec2 UV;
uniform mat4 MVP;

void main()
{
    gl_Position = MVP * pos;
    UV = vertexUV;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 col;

in vec2 UV;

uniform vec4 u_color;

uniform sampler2D u_texture;

void main()
{
    vec4 texColor = texture(u_texture, UV);

    col = texColor * u_color;
    return;

    col = u_color;
};

