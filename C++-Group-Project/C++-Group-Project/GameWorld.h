#pragma once


#include <GLFW\glfw3.h>
#include "GameObject.h"
#include "SoundController.h"
#include "Player.h"


class GameWorld
{
private:
	GLFWwindow * window;
	GameObject * tmpGO; //Her kunne der med fordel bruges en vector med GameObject * i stedet for
	SoundController * tmpSC; 
	Player * player;

public:
	GameWorld(GLFWwindow * windowContext);
	~GameWorld();
	void GameLoop();

private:
	void GameLogic();
	void Render();
};

