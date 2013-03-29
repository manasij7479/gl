#include "framework.h"
#include "mesh.h"
#include <glm/glm.hpp>  
#include <glm/gtc/matrix_transform.hpp>
mm::Mesh* mesh;
void setup()
{
	glClearColor(1,1,1,1);
	mesh = new mm::Mesh("righttri","vert.glsl","frag.glsl");
}
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	mesh->draw();
}