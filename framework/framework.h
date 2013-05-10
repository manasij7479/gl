#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include <GL/glew.h>
#include<functional>
#include "shader.h"
#include "program.h"
void setup();
void draw();

namespace mm
{
	class Framework
	{
	public:
		Framework(std::string n="Manasij",int x=1000,int y=600);
		int operator()();
		void setupFunction(std::function<void()> f){setup=f;}
		void drawFunction(std::function<void()> f){draw = f;}
		int getX(){return winSizeX;};
		int getY(){return winSizeY;};
	private:
		std::function<void()> setup;
		std::function<void()> draw;
		std::function<void(int,int)> resize;
		std::function<void(int,int)> mousePressAny;
		
		std::string winName;
		int winSizeX,winSizeY;
		
	};
}
#endif