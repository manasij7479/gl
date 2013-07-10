#include "framework.h"
#include "oldmesh.h"


#include "vector/vector.hpp"
#include "matrix/matrix.hpp"

mm::Mesh* mesh;
void setup()
{
	glClearColor(1,1,1,1);
	mesh = new mm::OldMesh("righttri","vert.glsl","frag.glsl");
	
	mat::Vector<float,4> col = mat::make_vector<float,4>({1.0f,0.3f,0.5f,1.0f});
	mat::Matrix<float,4,4> m = mat::make_matrix<float,4,4>
	({
		1.5f,0.0f,0.0f,0.0f,
		0.0f,1.5f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f,
	});
	
	
	glUseProgram(mesh->getProgram()->getHandle());
	auto loc = glGetUniformLocation(mesh->getProgram()->getHandle(),"mixcol");
	glUniform4fv(loc,1,col.begin());
	
	loc = glGetUniformLocation(mesh->getProgram()->getHandle(),"m");
	glUniformMatrix4fv(loc,1,GL_FALSE,m.begin());
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