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
	Framework::Framework(std::string n,int x,int y)
	{
		auto v = [](){std::cerr<<"Default Function.\n";};
		auto v2i=[](int,int){std::cerr<<"Default Function.\n";};
		setup=v;
		draw=v;
		resize=v2i;
		mousePressAny=v2i;
		
		winName=n;
		winSizeX=x;
		winSizeY=y;
	}
	int Framework::operator()()
	{
		sf::Window win(sf::VideoMode(winSizeX,winSizeY,32),winName);

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
					winSizeX=win.getSize().x;
					winSizeY=win.getSize().y;
					resize(winSizeX,winSizeY);
				}
				else if(eve.type==sf::Event::MouseButtonPressed)
				{
					mousePressAny(eve.mouseButton.x,eve.mouseButton.y);
				}
			}
		}
		return 0;

	}


}