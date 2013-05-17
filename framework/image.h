#ifndef MM_IMAGE_H
#define MM_IMAGE_H
#include<string>
namespace mm
{
	class Image
	{
	public:
		Image(){};
// 		Image (std::string filename)
// 		{
// 			load(filename);
// 		};
		virtual void load(std::string filename)=0;
		virtual void free()=0;
		virtual void* data()=0;
		virtual int width()=0;
		virtual int height()=0;
		virtual ~Image(){};
	private:
	};
}
#endif