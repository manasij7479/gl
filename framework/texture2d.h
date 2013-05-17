#ifndef TEXTURE_H
#define TEXTURE_H
#include<GL/glew.h>
#include<string>
namespace mm
{
	 /* Just a placeholder for experiment,
		Must design a more sophiticated policy based one in far future.*/ 
	class Texture2D
	{
	public:
		Texture2D(std::string imgfile,GLenum wrap,GLenum filter);
		GLuint getHandle(){return tex;}
	private:
		GLuint tex;//make this a vector later, to support texture units
	};
	typedef Texture2D Texture;//Only one needed atm
}
#endif
