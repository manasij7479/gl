#version 420
in vec3 pos;
in vec3 norm;
uniform mat4 m,v,p;
uniform vec4 lightDir,baseColor;
out vec4 interpol;

void main()
{
	vec4 n = normalize(p*v*m*vec4(norm,0.0f));
	vec4 l = normalize(lightDir);
	interpol = baseColor*dot(n,l);
	gl_Position=p*v*m*vec4(pos,1.0f);
}