#include "framework.h"
#include "oldmesh.h"
#include "texture2d.h"
#include <glm/glm.hpp>  
#include <glm/gtc/matrix_transform.hpp>
#include<iostream>
#include<ctime>
#include<cmath>
#include "soilimage.h"
mm::Mesh* mesh;
void setup()
{
	glClearColor(1,1,1,1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	mesh = new mm::OldMesh("squaredata","tvert.glsl","tfrag.glsl");
	auto prog = mesh->getProgram();
	
// 	glGenTextures(1,&tex);
// 	glBindTexture(GL_TEXTURE_2D,tex);
// 	
// 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
// 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
// 	
// 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
// 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
// 	
// 	int width, height;
// 	unsigned char* image =
//     SOIL_load_image( "square2.jpeg", &width, &height, 0, SOIL_LOAD_RGB );
// 	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,GL_UNSIGNED_BYTE, image );
	
// 	
	mm::Image* img = new mm::SoilImage("square.jpg");
	mm::Texture tex(*img,GL_CLAMP_TO_EDGE,GL_LINEAR);
	
	glm::mat4 p = glm::perspective(60.0f,1000*1.0f/600,0.1f,100.0f);
	glm::mat4 v = glm::translate(glm::mat4(1.0f), glm::vec3(-5.0f, -5.0f, -10.0f)); // Create our view matrix which will translate us back 5 units  
	glm::mat4 m= glm::rotate(glm::mat4(1.0f),0.0f,glm::vec3(1.0f,0.0f,0.0f));
	
	prog->uniformMat4(p,"p");
	prog->uniformMat4(m,"m");
	prog->uniformMat4(v,"v");
}
void draw()
{
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