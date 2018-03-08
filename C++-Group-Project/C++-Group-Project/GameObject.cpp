#include "GameObject.h"
#include <SOIL.h>
#include <iostream>
using namespace std;


GameObject::GameObject() : GameObject(0, 0, 0, textureChar)
{
}

GameObject::GameObject(float initX, float initY, float initZ, char * texture)
{
	x = initX;
	y = initY;
	z = initZ;
	
	xDirection = 1;
	yDirection = 1;
	this->texture = SOIL_load_OGL_texture(texture, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y); //Indlæser teksturen og returnere et id
	
	glBindTexture(GL_TEXTURE_2D, this->texture); //Binder teksturen (dvs. indlæser den i GPU hukommelsen)
}

GameObject::~GameObject()
{
	
}

void GameObject::Update()
{

}

void GameObject::Render()
{
	glPushMatrix(); //Lægger en matrise på stakken, således kun denne manipuleres
	glTranslatef(x, y, z);
	glBindTexture(GL_TEXTURE_2D, texture); //Binder teksturen (Anvender til ved rendering af vertices)
	glBegin(GL_QUADS);
	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glPopMatrix(); // Fjerner matrisen på stakken (dvs. nulstiller til udgangspunkt)

}