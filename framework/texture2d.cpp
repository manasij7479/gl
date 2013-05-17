#include "texture2d.h"
#include<SOIL/SOIL.h>
namespace mm 
{
	Texture2D::Texture2D(std::string imgfile,GLenum wrap, GLenum filter)
	{
		glGenTextures(1,&tex);
		glBindTexture(GL_TEXTURE_2D,tex);
		
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,wrap);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,wrap);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,filter);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,filter);
		
		int width, height;
		unsigned char* image =
		SOIL_load_image( imgfile.c_str(), &width, &height, 0, SOIL_LOAD_RGB );
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,GL_UNSIGNED_BYTE, image );
		
		SOIL_free_image_data(image);

	}

}