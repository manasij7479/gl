#include MM_OBJ_GL_TYPE_TRAITS_HPP
#define MM_OBJ_GL_TYPE_TRAITS_HPP
#include <GL/glew.h>
namespace mm
{
	
	template<typename T> class type_value;
	
	template<> class type_value<GLbyte>
	{
		static const GLenum value = GL_BYTE;
	};
	template<> class type_value<GLubyte>
	{
		static const GLenum value = GL_UNSIGNED_BYTE;
	};
	template<> class type_value<GLshort>
	{
		static const GLenum value = GL_SHORT;
	};
	template<> class type_value<GLushort>
	{
		static const GLenum value = GL_UNSIGNED_SHORT;
	};
	template<> class type_value<GLint>
	{
		static const GLenum value = GL_INT;
	};
	template<> class type_value<GLuint>
	{
		static const GLenum value = GL_UNSIGNED_INT;
	};
	template<> class type_value<GLhalfARB>
	{
		static const GLenum value = GL_HALF_FLOAT;
	};
	template<> class type_value<GLfloat>
	{
		static const GLenum value = GL_FLOAT;
	};
	template<> class type_value<GLdouble>
	{
		static const GLenum value = GL_DOUBLE;
	};
		
	//Not sure if I'd need any more
}
#endif