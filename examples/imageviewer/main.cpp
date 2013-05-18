#include "framework.h"
#include <iostream>
#include "texture2d.h"
#include "soilimage.h"
#include "oldmesh.h"

#include <glm/glm.hpp>  
#include <glm/gtc/matrix_transform.hpp>

mm::Mesh* mesh;
mm::Image* img;
void setup()
{
	glClearColor(1,1,1,1);
	mesh = new mm::OldMesh("simpledata","v.glsl","f.glsl");
	mm::Texture tex(*img,GL_CLAMP_TO_EDGE,GL_LINEAR);
	
}
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	mesh->draw();
}

int main(int argc,char** argv)
{
	std::string name;
	if(argc<2)
	{
		std::cerr<<"Usage: \"./view filename\"\n";
		return -1;
	}
	name = argv[1];
	img = new mm::SoilImage(name);
	
	mm::Framework frame(name,img->width(),img->height());
	frame.drawFunction(draw);
	frame.setupFunction(setup);
	return frame();
}