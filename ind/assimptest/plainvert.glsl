#version 420
in vec3 pos;
in vec3 norm;
uniform mat4 m,v,p;
out vec4 interpol;
void main()
{
	gl_Position=p*v*m*vec4(pos,1.0f);
	interpol = vec4(1.0f,0.0f,0.0f,1.0f);
}