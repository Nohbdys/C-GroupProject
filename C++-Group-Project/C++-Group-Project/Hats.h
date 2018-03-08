#pragma once

#include "Player.h"

class Hats : public Player
{

private:
	char textureChar[24];

public:
	Hats(float initX, float initY, float initZ, float size, char * texture);
	~Hats();
};

