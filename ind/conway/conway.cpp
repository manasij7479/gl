#include "framework.h"
#include "oldmesh.h"
#include "conway.h"
#include <glm/glm.hpp>  
#include <glm/gtc/matrix_transform.hpp>
#include<iostream>
mm::Mesh* mesh;
mm::Grid* grid;
int init;
void setup()
{
	glClearColor(1,1,1,1);
	mesh = new mm::OldMesh("block","vert.glsl","frag.glsl");
	glm::mat4 p = glm::ortho(0.0f,1000.0f,600.0f,0.0f);
	glm::mat4 v = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f, 0.0f));
	glm::mat4 m = glm::scale(glm::mat4(1.0f),glm::vec3(10.0f));
	
	auto prog = mesh->getProgram();
	prog->uniformMat4(p,"p");
	prog->uniformMat4(m,"m");
	prog->uniformMat4(v,"v");
	
	grid = new mm::Grid(100,60);
	grid->fill_random(600);
	
	init = std::clock();
}
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	for(int i=0;i<100;++i)
		for(int j=0;j<60;++j)
		{
			if(grid->at(i,j)!=0)
			{
				glm::mat4 v = glm::translate(glm::mat4(1.0f), glm::vec3(i*10.0f,j*10.0f, 0.0f));
				mesh->getProgram()->uniformMat4(v,"v");
				mesh->draw();
			}
		}
	if(std::clock()-init > CLOCKS_PER_SEC/2)
	{
		grid->update();
		init=std::clock();
	}
}
int main()
{
	mm::Framework f;
	f.drawFunction(draw);
	f.setupFunction(setup);
	return f();
}