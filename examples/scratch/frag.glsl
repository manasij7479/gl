#version 420

uniform vec4 mixcol;

in vec4 interpol;
out vec4 outcol;

void main()
{
	outcol = mix(interpol,mixcol,0.5f);
}