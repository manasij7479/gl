#version 420
in vec2 pos;
in vec4 col;
out vec4 interpol;
uniform mat4 m,v,p;
void main()
{
	gl_Position=p*v*m*vec4(pos,0.0f,1.0f);
	interpol = col;
}