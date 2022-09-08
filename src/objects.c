#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#include "./objects.h"

void drawSelection(float x_position, float y_position, float z_position)
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
}

/*
 * Still learning how GPUs and OpenGL work, so I will be actually completing this function soon...
 */
void drawCubeWithTexture(float x_position, float y_position, float z_position, const char *top_texture_filename, const char *bottom_texture_filename, const char *left_texture_filename, const char *right_texture_filename, const char *front_texture_filename, const char *back_texture_filename) { }