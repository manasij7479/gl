#include "framework.h"
#include "oldmesh.h"
#include <glm/glm.hpp>  
#include <glm/gtc/matrix_transform.hpp>
mm::Mesh* mesh;
void setup()
{
	glClearColor(1,1,1,1);
	mesh = new mm::OldMesh("righttri","vert.glsl","frag.glsl");
}
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	mesh->draw();
}
int main()
{
    mm::Framework f;
	setup();
	while(f.update()!=-1)
		draw();
    return 0;
}