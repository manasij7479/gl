#ifndef MM_SOIL_IMAGE
#define MM_SOIL_IMAGE
#include "image.h"
#include <SOIL/SOIL.h>
namespace mm
{
	class SoilImage:public Image
	{
	public:
		SoilImage(std::string filename)
		{
			load(filename);
			loaded = true;
		};
		void load(std::string filename);
		void free();
		void* data();
		int width();
		int height();
		~SoilImage(){free();};
	private:
		int w;
		int h;
		unsigned char* d;
		bool loaded;
	};
}
#endif