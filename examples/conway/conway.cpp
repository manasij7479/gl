#include "framework.h"
#include "oldmesh.h"
#include "conway.h"
#include <glm/glm.hpp>  
#include <glm/gtc/matrix_transform.hpp>
#include<iostream>
mm::Mesh* mesh;
mm::Grid* grid;
int init;
bool paused=false;
float winX=1000.0f;
float winY=600.0f;

void setup()
{
	
	grid = new mm::Grid(100,60);
	grid->fill_random(1000);
	
	glClearColor(1,1,1,1);
	mesh = new mm::OldMesh("block","vert.glsl","frag.glsl");
	
	glm::mat4 p = glm::ortho(0.0f,winX,winY,0.0f);
	glm::mat4 v = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f, 0.0f));
	glm::mat4 m = glm::scale(glm::mat4(1.0f),glm::vec3(winX*1.0f/grid->getX(),winY*1.0f/grid->getY(),1.0f));
	
	auto prog = mesh->getProgram();
	prog->uniformMat4(p,"p");
	prog->uniformMat4(m,"m");
	prog->uniformMat4(v,"v");
	
	
	
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
				glm::mat4 v = glm::translate(glm::mat4(1.0f), glm::vec3(i*winX/grid->getX(),j*winY/grid->getY(),0.0f));
// 				std::cerr<<winX<<'\t'<<winY<<'\t'<<winX*1.0f/grid->getX()<<'\t'<<winY*1.0f/grid->getY()<<std::endl;
				mesh->getProgram()->uniformMat4(v,"v");
				mesh->draw();
			}
		}
	if(std::clock()-init > CLOCKS_PER_SEC/3 && !paused)
	{
		grid->update();
		init=std::clock();
	}
}
void mouse(int x,int y)
{
	grid->toggle(x/10,y/10);
}
void resize(int x,int y)//Doesn't work as expected, becasue winX and winY are not getting updated.
{
	winX =x;
	winY =y;
	
	glm::mat4 p = glm::ortho(0.0f,winX,winY,0.0f);
// 	glm::mat4 v = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f, 0.0f));
	glm::mat4 m = glm::scale(glm::mat4(1.0f),glm::vec3(winX*1.0f/grid->getX(),winY*1.0f/grid->getY(),1.0f));
	
	auto prog = mesh->getProgram();
	prog->uniformMat4(p,"p");
	prog->uniformMat4(m,"m");
// 	prog->uniformMat4(v,"v");
	
}
void toggle()
{
	paused=!paused;
}
int main()
{
	mm::Framework f("Conway",winX,winY);
	f.drawFunction(draw);
	f.setupFunction(setup);
	f.mouseAnyFunction(mouse);
	f.keyAnyFunction(toggle);
	f.resizeFunction(resize);
	return f();
}