#version 430
in vec2 pos;
in vec2 texc;
out vec2 itexc;
uniform mat4 m,v,p;
void main()
{
	gl_Position = p*v*m*vec4(pos,0.0f,1.0f);
	itexc = texc;
}

