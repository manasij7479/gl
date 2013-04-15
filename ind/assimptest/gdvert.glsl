#version 420
in vec3 pos;
in vec3 norm;
uniform mat4 m,v,p;
out vec4 interpol;
void main()
{
	vec4 n = normalize(p*v*m*vec4(norm,0.0f));
	vec4 l = normalize(vec4(0.0f,0.0f,-1.0f,0.0f));
	interpol = vec4(1.0f,0.0f,0.0f,1.0f)*dot(n,l);
	gl_Position=p*v*m*vec4(pos,1.0f);
}