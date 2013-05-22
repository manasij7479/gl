#include "framework.h"
#include<SFML/Window.hpp>
#include<iostream>

void GlewInit()
{
	GLenum err = glewInit();
	if (GLEW_OK != err)
		std::cerr<<"Error "<<glewGetErrorString(err);
}

// int main()
// {
// }
namespace mm 
{
	Framework::Framework(std::string n,int x,int y):win(*new sf::Window(sf::VideoMode(x,y,32),n))
	{
		auto v = [](){std::cerr<<"Default Function.\n";};
		auto v2i=[](int,int){std::cerr<<"Default Function.\n";};
		setup=v;
		draw=v;
		resize=v2i;
		mousePressAny=v2i;
		keyPressAny=v;
		
		winName=n;
		winSizeX=x;
		winSizeY=y;
		
		GlewInit();
		
	}
	int Framework::operator()()
	{
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
					winSizeX=win.getSize().x;
					winSizeY=win.getSize().y;
					resize(winSizeX,winSizeY);
				}
				else if(eve.type==sf::Event::MouseButtonPressed)
				{
					mousePressAny(eve.mouseButton.x,eve.mouseButton.y);
				}
				else if(eve.type==sf::Event::KeyPressed)
				{
					keyPressAny();
				}
			}
		}
		return 0;
	}
	int Framework::update()
	{
		if(!win.isOpen())
			return -1;
		win.display();
		return 0;
	}
	



}