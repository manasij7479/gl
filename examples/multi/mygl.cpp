#include "framework.h"
#include "assimpmesh.h"
#include <glm/glm.hpp>  
#include <glm/core/type_mat.hpp>
#include <glm/core/type_vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <ctime>
#include <cmath>
mm::Mesh* mesh1;
mm::Mesh* mesh2;
void setup()
{
	glClearColor(1,1,1,1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	
	mesh1 = new mm::AssimpMesh("foo.obj","gdvert.glsl","fvcol.glsl");
	mesh2 = new mm::AssimpMesh("cube.obj","gdvert.glsl","fvcol.glsl");
	auto prog1 = mesh1->getProgram();
	auto prog2 = mesh2->getProgram();
	
	
	glm::mat4 p = glm::perspective(60.0f,1000*1.0f/600,0.1f,100.0f);
	glm::mat4 v = glm::translate(glm::mat4(1.0f), glm::vec3(0.85f, 1.0f, -5.0f)); // translate back 5 units
	glm::mat4 m= glm::rotate(glm::mat4(1.0f),0.0f,glm::vec3(1.0f,0.0f,0.0f));
	
	prog1->uniformMat4(p,"p");
	prog1->uniformMat4(m,"m");
	prog1->uniformMat4(v,"v");
	
	v = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, -5.0f));
	m= glm::rotate(glm::mat4(1.0f),30.0f,glm::vec3(1.0f,1.0f,0.0f));
	
	prog2->uniformMat4(p,"p");
	prog2->uniformMat4(m,"m");
	prog2->uniformMat4(v,"v");
	
	prog1->uniformVec4(glm::vec4(0.0f,0.0f,-1.0f,0.0f),"lightDir");
	prog1->uniformVec4(glm::vec4(0.0f,1.0f,0.0f,0.0f),"baseColor");
	
	prog2->uniformVec4(glm::vec4(0.0f,0.0f,-1.0f,0.0f),"lightDir");
	prog2->uniformVec4(glm::vec4(1.0f,0.0f,0.0f,0.0f),"baseColor");
}
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	mesh1->draw();
	mesh2->draw();
}
int main()
{
    mm::Framework f;
    f.drawFunction(draw);
    f.setupFunction(setup);
    return f();
}