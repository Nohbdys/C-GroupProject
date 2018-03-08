#include "Player.h"



void Player::Update()
{

		playx += xDirection * 0.001;

		playy += yDirection * 0.001;

}



Player::Player(float initX, float initY, float initZ, char * texture) : GameObject(initX, initY, initZ, texture)
{
	playx = initX;

	playy = initY;

	playz = initZ;

}
Player::~Player()
{
}
