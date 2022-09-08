#include <GL/glut.h>
#include <math.h>

#include "./camera.h"

extern float angle;
extern float lx, lz;
extern float x, z;
extern float deltaAngle;
extern float deltaMove;
extern int xOrigin;

void mouseMove(int x, int y)
{ 	
    if (xOrigin >= 0)
    {
        deltaAngle = (x - xOrigin) * 0.001f;
        lx = sin(angle + deltaAngle);
        lz = -cos(angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
    {
		if (state == GLUT_UP)
        {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else
        {
			xOrigin = x;
		}
	}
}