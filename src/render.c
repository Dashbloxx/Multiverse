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
extern lua_State *LuaInstance;

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
	/*int _d567a34c = 0;
	if(_d567a34c == 0)
	{
		luaL_dofile(LuaInstance, "./scripts/render.lua");
		_d567a34c = 1;
	}*/
	if (deltaMove)
    	{
        	computePos(deltaMove);
    	}
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, 1.0f, z, x + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);
	/*
	 * Here, we draw stuff, like cubes, spheres, etc.
	 */
	lua_getglobal(LuaInstance, "render");
	lua_call(LuaInstance, 0, 0);
	/*
	 * Here, we end the drawing.
	 */
    	glutSwapBuffers();
}
