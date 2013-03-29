#ifndef MM_SHADER
#define MM_SHADER
#include <string>
#include <GL/glew.h>
namespace mm
{
	class Shader
	{
	public:
		Shader(GLenum Type,std::string filename);
		~Shader();
		GLuint getHandle();
	private:
		GLuint handle;
		GLenum shader_type;
	};
}
#endif