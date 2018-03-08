#pragma once
#include "GameObject.h"

class Platform : public GameObject
{
private:
	char textureChar[24];

	float x;
	float y;
	float z;


	GLuint texture; //Texture holder

public:
	Platform(float initX, float initY, float initZ, float size, char * texture);
	~Platform();
	void Render();
};

