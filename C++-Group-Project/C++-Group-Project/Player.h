#pragma once

#include "GameObject.h"

class Player : public GameObject
{
private:
	char textureChar[24];
	float playx;
	float playy;
	float playz;

	bool horizontalPressed;
	bool verticalPressed;

public:
	void Update();
	Player(float initX, float initY, float initZ, char * texture);
	~Player();

};

