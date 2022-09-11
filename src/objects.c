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

void drawSphere(lua_State *L)
{
	int x = luaL_checknumber (L, 1);
	int y = luaL_checknumber (L, 2);
	int z = luaL_checknumber (L, 3);
	int r = luaL_checknumber (L, 4);
	int g = luaL_checknumber (L, 5);
	int b = luaL_checknumber (L, 6);
	int w = luaL_checknumber (L, 7);
	int t = luaL_checknumber (L, 8);
	int f = luaL_checknumber (L, 9);

	glPushMatrix();
	glScalef(1.0,1.0,1.0);
	glTranslatef (x, y, z);
	glColor3f(r, g, b); 
	glutSolidSphere(w, t, f);
	glPopMatrix();
}

void drawTriangle(lua_State *L)
{
	int a_x = luaL_checknumber (L, 1);
	int a_y = luaL_checknumber (L, 2);
	int a_z = luaL_checknumber (L, 3);
	int a_r = luaL_checknumber (L, 4);
	int a_g = luaL_checknumber (L, 5);
	int a_b = luaL_checknumber (L, 6);
	int b_x = luaL_checknumber (L, 7);
	int b_y = luaL_checknumber (L, 8);
	int b_z = luaL_checknumber (L, 9);
	int b_r = luaL_checknumber (L, 10);
	int b_g = luaL_checknumber (L, 11);
	int b_b = luaL_checknumber (L, 12);
	int c_x = luaL_checknumber (L, 13);
	int c_y = luaL_checknumber (L, 14);
	int c_z = luaL_checknumber (L, 15);
	int c_r = luaL_checknumber (L, 16);
	int c_g = luaL_checknumber (L, 17);
	int c_b = luaL_checknumber (L, 18);

	glBegin(GL_TRIANGLES);
	glColor3f(a_r, a_g, a_b);
	glVertex3f(a_x, a_y, a_z);
	glColor3f(b_r, b_g, b_b);
	glVertex3f(b_x, b_y, b_z);
	glColor3f(c_r, c_g, c_b);
	glVertex3f(c_x, c_y, c_z);
	glEnd();
}

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
void drawCubeWithTexture(float x_position, float y_position, float z_position, const char *top_texture_filename, const char *bottom_texture_filename, const char *left_texture_filename, const char *right_texture_filename, const char *front_texture_filename, const char *back_texture_filename) { }
