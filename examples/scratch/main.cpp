#include "framework.h"
#include "oldmesh.h"
#include <glm/glm.hpp>  
#include <glm/gtc/matrix_transform.hpp>
#include "vector/vector.hpp"


mm::Mesh* mesh;
void setup()
{
	glClearColor(1,1,1,1);
	mesh = new mm::OldMesh("righttri","vert.glsl","frag.glsl");
	mat::Vector<float,4> col = mat::make_vector<float,4>({1.0f,0.3f,0.5f,1.0f});
	
	glUseProgram(mesh->getProgram()->getHandle());
	auto loc = glGetUniformLocation(mesh->getProgram()->getHandle(),"mixcol");
// 	glUniform4f(loc,0.2f,0.3f,0.5f,1.0f);
	glUniform4fv(loc,1,col.begin());
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
	{
		draw();
		f.placeHolderEventHandler();
	}
    return 0;
}