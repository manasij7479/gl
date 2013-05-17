#ifndef TEXTURE_H
#define TEXTURE_H
#include<GL/glew.h>
#include<string>
#include<utility>
#include "image.h"
namespace mm
{
	 /* Just a placeholder for experiment,
		Must design a more sophiticated policy based one in far future.*/ 
	class Texture2D
	{
	public:
		Texture2D(std::string imgfile,GLenum wrap,GLenum filter);
		Texture2D(mm::Image& img,GLenum wrap,GLenum filter);
		GLuint getHandle(){return tex;}
		std::pair<int,int> size(){return {width,height};};
	private:
		GLuint tex;//make this a vector later, to support texture units
		int width,height; // not necessarily a part of the texture,later convert Image loading into a template policy
	};
	typedef Texture2D Texture;//Only one needed atm
}
#endif
