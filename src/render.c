#include <GL/glut.h>
#include <lua5.1/lua.h>
#include <lua5.1/lualib.h>
#include <lua5.1/lauxlib.h>

#include "./render.h"
#include "./objects.h"

extern float angle;
extern float lx, lz;
extern float x, z;
extern float deltaAngle;
extern float deltaMove;
extern int xOrigin;

void changeSize(int w, int h)
{
	if (h == 0)
    {
        h = 1;
    }
	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void computePos(float deltaMove)
{
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void renderScene(void)
{
	if (deltaMove)
    {
        computePos(deltaMove);
    }
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, 1.0f, z, x + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);

	glColor3f(0.9f, 0.9f, 0.9f);
	/*
	 * Draw squares to make a small plane surface
	 */
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f,  100.0f);
	glVertex3f( 100.0f, 0.0f,  100.0f);
	glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();
	/*
	 * Here, we draw stuff, like cubes, spheres, etc.
	 */
	drawSelection(0, 1, 0);
	drawSelection(1, 1, 0);
	/*
	 * Here, we end the drawing.
	 */
    glutSwapBuffers();
} 