#ifndef MM_PROGRAM
#define MM_PROGRAM
#include "shader.h"
#include <vector>
#include <type_traits>
#include <glm/glm.hpp>  
namespace mm
{
	class Program
	{
	public:
		Program(const std::vector<Shader>& input);
		~Program();
		GLuint getHandle();
		
		
		template <typename Function>
		typename  std::result_of<Function()>::type
		useFor(Function foo)
		{
			Use use(handle);
			return foo();
		}
		
		void uniformMat4(glm::mat4 m,std::string name);
	private:
		GLuint handle;
		const std::vector<Shader>& shader_list;
		
		class Use
		{
		public:
			Use(GLuint p){glUseProgram(p);};
			~Use(){glUseProgram(0);};
		};
	};
	
	
	
}
#endif
