#ifndef MM_BUF_VBO_HPP
#define MM_BUF_VBO_HPP
#include <GL/glew.h>
namespace mm
{
	class VertexBufferObject
	{
	public:
		GLuint handle;
		GLenum target;
		
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
	};
	typedef VertexBufferObject VBO;
}
#endif