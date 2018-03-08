#include "Platform.h"
#include <SOIL.h>
#include <iostream>

Platform::Platform(float initX, float initY, float initZ, float size, char * texture) : GameObject(initX, initY, initZ, size, texture)
{
	x = initX;
	y = initY;
	z = initZ;
	this->texture = SOIL_load_OGL_texture(texture, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y); //Indlæser teksturen og returnere et id
}


Platform::~Platform()
{
}

void Platform::Render() 
{
	glPushMatrix(); //Lægger en matrise på stakken, således kun denne manipuleres
	glTranslatef(x, y, z);
	glBindTexture(GL_TEXTURE_2D, texture); //Binder teksturen (Anvender til ved rendering af vertices)
	glBegin(GL_QUADS);
	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.2f, -0.05f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.2f, -0.05f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.2f, 0.05f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.2f, 0.05f, 1.0f);
	glEnd();
	glPopMatrix(); // Fjerner matrisen på stakken (dvs. nulstiller til udgangspunkt)
}