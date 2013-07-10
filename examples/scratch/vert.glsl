#version 420
in vec2 pos;
in vec4 col;
out vec4 interpol;
uniform mat4 m;
void main()
{
	gl_Position=m*vec4(pos,0.0f,1.0f);
	interpol = col;
}