#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include <GL/glew.h>

#include "shader.h"
#include "program.h"
void setup();
void draw();

class global
{   
public:
    static int winSizeX;
    static int winSizeY;
};
#endif