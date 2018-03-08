#pragma once

#include "GameObject.h"

class Background : public GameObject
{
private:
	char textureChar[24];


public:

	Background(float initX, float initY, float initZ, float size, char * texture);
	~Background();
};

