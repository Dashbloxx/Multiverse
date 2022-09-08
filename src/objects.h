#ifndef OBJECTS_H
#define OBJECTS_H

void drawSelection(float x_position, float y_position, float z_position);
void drawCube(float x_position, float y_position, float z_position);
void drawCubeWithTexture(float x_position, float y_position, float z_position, const char *top_texture_filename, const char *bottom_texture_filename, const char *left_texture_filename, const char *right_texture_filename, const char *front_texture_filename, const char *back_texture_filename);

#endif