#ifndef OBJECT_ABS_H
#define OBJECT_ABS_H
/*
Abstract object class..parent of everything that goes into the scene node.
 */
namespace mm
{
	class Object
	{
	public:
		Object(Object* parent):p(parent){};
		Object* parent(){return p;};
	private:
		Object* p;
	};
}
#endif