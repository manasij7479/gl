#include "SOIL/SOIL.h"
#include "soilimage.h"
namespace mm 
{
	void* SoilImage::data()
	{
		return static_cast<void*>(d);
	}
	void SoilImage::free()
	{
		if(!loaded)
			return;
		SOIL_free_image_data(d);
		loaded=false;
	}
	int SoilImage::height()
	{
		return h;
	}
	int SoilImage::width()
	{
		return w;
	}
	void SoilImage::load(std::string filename)
	{
		d = SOIL_load_image(filename.c_str(),&w,&h,0,SOIL_LOAD_RGB);
		loaded =true;
	}

}