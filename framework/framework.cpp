#include "framework.h"
#include<SFML/Window.hpp>
#include<iostream>

int global::winSizeX;
int global::winSizeY;

void GlewInit()
{
	GLenum err = glewInit();
	if (GLEW_OK != err)
		std::cerr<<"Error "<<glewGetErrorString(err);
}

int main()
{
	sf::Window win(sf::VideoMode(1000,600,32),"Manasij");
	global::winSizeX=win.getSize().x;
	global::winSizeY=win.getSize().y;
	GlewInit();
	setup();
	while(win.isOpen())
	{
		win.display();
		draw();
		sf::Event eve;
		while(win.pollEvent(eve))
		{
			if(eve.type==sf::Event::Closed)
				win.close();
			else if (eve.type==sf::Event::Resized)
			{
				global::winSizeX=win.getSize().x;
				global::winSizeY=win.getSize().y;
			}
		}
	}
	return 0;
}