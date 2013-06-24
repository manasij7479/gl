#ifndef DRAWABLE_ABS_H
#define DRAWABLE_ABS_H
#include "object.h"
namespace mm
{
	class Drawable:public Object
	{
	public:
		Drawable(Object* parent):Object(parent){};
		virtual void draw()=0;
	};
}
#endif