#version 430
in vec2 pos;
in vec2 texc;
out vec2 itexc;
void main()
{
	gl_Position = vec4(pos,0.0f,1.0f);
	itexc = texc;
}

