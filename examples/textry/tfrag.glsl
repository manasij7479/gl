#version 430
in vec2 itexc;
uniform sampler2D tex;
out vec4 col;
void main()
{
	col = texture(tex,itexc);
}