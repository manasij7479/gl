#version 420
in vec3 pos;
in vec3 norm;
uniform mat4 m,v,p;
void main()
{
	gl_Position=p*v*m*vec4(pos,1.0f);
}