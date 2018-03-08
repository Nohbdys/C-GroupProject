#include "Player.h"


Player::Player(float initX, float initY, float initZ, float size, char * texture) : GameObject(initX, initY, initZ, size, texture)
{

	x = initX;

	y = initY;

	z = initZ;

	counter = 0;
}

Player::~Player()
{

}

void Player::Update()
{
	if (hatPickedUp)
	{
		if (x <= 1 && x >= -1)
		{
			//updates player direction on the x value
			x += xDirection * 0.001;
		}
		else if (x >= 1)
		{
			x -= 0.001;
		}
		else
		{
			x += 0.001;
		}
	}

	if (y <= 1 && y >= -0.950)
	{
		//updates player direction on the y value

		y += yDirection * 0.005;
		
		
	}
	else if (y >= 1)
	{
		y -= 0.001;
	}
	else
	{
		y += 0.002;
		jumped = false;
	}

	y -= 0.002;		//Gravity

	if (jump &&jumped)
	{
		Jump();
	}
}
void Player::Jump()
{
	if (jump && !jumped)
	{
		jumped = false;
		if (counter <= 3)
		{
			jump = false;
			counter = 0;
			y += 0.003;
		}
		counter++;
	
	}
}