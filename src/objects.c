#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <lua5.1/lua.h>
#include <lua5.1/lualib.h>
#include <lua5.1/lauxlib.h>

#include "./objects.h"

/*void drawSelection(float x_position, float y_position, float z_position)
{
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(x_position, y_position, z_position);
	glColor3f(255, 0, 0);
	glutWireCube(1.0);
}

void drawCube(float x_position, float y_position, float z_position)
{
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(x_position, y_position, z_position);
	glColor3f(255, 0, 0);
	glutSolidCube(1.0);
}*/

void drawSelection(lua_State *L)
{
	int x_position = luaL_checknumber (L, 1);
    int y_position = luaL_checknumber (L, 2);
	int z_position = luaL_checknumber (L, 3);
	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(x_position, y_position, z_position);
	glColor3f(255, 0, 0);
	glutWireCube(1.0);
	glPopMatrix();
}

void drawCube(lua_State *L)
{
	int x_position = luaL_checknumber (L, 1);
    int y_position = luaL_checknumber (L, 2);
	int z_position = luaL_checknumber (L, 3);
	int r = luaL_checknumber (L, 4);
    int g = luaL_checknumber (L, 5);
	int b = luaL_checknumber (L, 6);
	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(x_position, y_position, z_position);
	glColor3f(r, g, b);
	glutSolidCube(1.0);
	glPopMatrix();
}

/*
 * Still learning how GPUs and OpenGL work, so I will be actually completing this function soon...
 */
void drawCubeWithTexture(float x_position, float y_position, float z_position, const char *top_texture_filename, const char *bottom_texture_filename, const char *left_texture_filename, const char *right_texture_filename, const char *front_texture_filename, const char *back_texture_filename)
{
}