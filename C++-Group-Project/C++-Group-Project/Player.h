#pragma once

#include "GameObject.h"

class Player : public GameObject
{
private:
	char textureChar[24];

	bool hatPickedUp = true;
	bool horizontalPressed;
	bool verticalPressed;
	int counter = 0;

	
public:
	void Update();
	void Jump();
	
	Player(float initX, float initY, float initZ, float size, char * texture);
	~Player();

	bool jump = false;
	bool jumped;

};

