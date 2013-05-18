#include "framework.h"
#include "oldmesh.h"
#include <glm/glm.hpp>  
#include <glm/gtc/matrix_transform.hpp>
#include<iostream>
#include<ctime>
#include<cmath>
mm::Mesh* mesh;
std::clock_t init;
float omega =30.0f;
void setup()
{
    init=std::clock();
	glClearColor(1,1,1,1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	mesh = new mm::OldMesh("datafile","vvec3mvp.glsl","fvcol.glsl");
	auto prog = mesh->getProgram();
	
	glm::mat4 p = glm::perspective(60.0f,1000*1.0f/600,0.1f,100.0f);
	glm::mat4 v = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f)); // Create our view matrix which will translate us back 5 units  
	glm::mat4 m= glm::rotate(glm::mat4(1.0f),30.0f,glm::vec3(1.0f,0.0f,0.0f));
	
	prog->uniformMat4(p,"p");
	prog->uniformMat4(m,"m");
	prog->uniformMat4(v,"v");
}
void draw()
{
    float t = static_cast<float>(std::clock()-init)/CLOCKS_PER_SEC;
    glm::mat4 m= glm::rotate(glm::mat4(1.0f),omega*t,glm::vec3(0.5f,0.3f,0.8f));
    mesh->getProgram()->uniformMat4(m,"m");
	glClear(GL_COLOR_BUFFER_BIT);
	mesh->draw();
}
int main()
{
    mm::Framework f;
    f.drawFunction(draw);
    f.setupFunction(setup);
    return f();
}