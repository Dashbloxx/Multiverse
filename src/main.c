#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <lua5.1/lua.h>
#include <lua5.1/lualib.h>
#include <lua5.1/lauxlib.h>

#include "./camera.h"
#include "./render.h"
#include "./keys.h"

float angle = 0.0f;
float lx = 0.0f, lz = -1.0f;
float x = 0.0f, z = 5.0f;
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;
lua_State *LuaInstance;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("Multiverse 1.1");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	LuaInstance = luaL_newstate();
  	luaL_openlibs(LuaInstance);
  	luaL_dofile(LuaInstance, argv[1]);

	glutIdleFunc(renderScene);
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	lua_close(LuaInstance);
	return 1;
}
