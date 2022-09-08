#include <stdlib.h>
#include <GL/glut.h>

#include "./keys.h"

extern float angle;
extern float lx, lz;
extern float x, z;
extern float deltaAngle;
extern float deltaMove;
extern int xOrigin;

void processNormalKeys(unsigned char key, int xx, int yy)
{ 	
    if (key == 27)
    {
        exit(0);
    }
} 

/*
 * This is the special function that is used by GL/glut.h for processing special keys. We
 * will use this for processing keys like W, A, S, and D, and also SPACE.
 */
void pressKey(int key, int xx, int yy)
{
    switch (key) 
    {
        case GLUT_KEY_UP : deltaMove = 0.5f; break;
        case GLUT_KEY_DOWN : deltaMove = -0.5f; break;
    }
} 

void releaseKey(int key, int x, int y)
{ 	
    switch (key) 
    {
        case GLUT_KEY_UP :
        case GLUT_KEY_DOWN : deltaMove = 0; break;
    }
}