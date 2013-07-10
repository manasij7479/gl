#ifndef MM_BUF_VBO_HPP
#define MM_BUF_VBO_HPP
#include <GL/glew.h>
namespace mm
{
	
	class VertexBufferObject
	{
	public:
		VertexBufferObject(){glGenBuffers(1,&handle);};
		VertexBufferObject(GLuint buf):handle(buf){};
		class bind
		{
		public:
			bind(GLuint h,GLenum t):target(t)
			{
				glBindBuffer(target,handle);
			}
			~bind()
			{
				glBindBuffer(target,0);
			}
		private:
			GLenum target;
		};
		GLuint getHandle()
		{
			return handle;
		}
	private:
		GLuint handle;
	};
	
	typedef VertexBufferObject VBO;
}
#endif