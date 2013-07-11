#ifndef MM_OBJ_VAO_HPP
#define MM_OBJ_VAO_HPP
#include "vbo.hpp"
namespace mm
{
	class VertexArrayObject
	{
	public:
		GLuint getHandle(){return handle;}
	private:
		GLuint handle;
		std::vector<VBO> buffers;
	};
}
#endif