#include "GameWorld.h"
#include <conio.h>
#include <list>
#include <iostream>
#include <vector>
using namespace std;

char soundToBePlayed[12] = "Music5.wav\0";

vector<Platform> platformList;

GameWorld::GameWorld(GLFWwindow * windowContext)
{
	window = windowContext;

 	//tmpGO = new GameObject(0, 0, 0, "..\\Images/BGround.png\0");
	tmpSC = new SoundController();
	player = new Player(1, 0, 0,5, "..\\Images/Child67.png\0");
	background = new Background(0, 0, 0,100, "..\\Images/BGround.png\0");
	platform1 = new Platform(-0.8, -0.8, 0, 15, "..\\Images/Platfor.png\0");
	platform2 = new Platform(-0.4, -0.8, 0, 15, "..\\Images/Platfor.png\0");
	platform3 = new Platform(0, -0.8, 0, 15, "..\\Images/Platfor.png\0");
	platform4 = new Platform(0.4, -0.8, 0, 15, "..\\Images/Platfor.png\0");
	platform5 = new Platform(0.8, -0.8, 0, 15, "..\\Images/Platfor.png\0");


	glEnable(GL_TEXTURE_2D); //Aktivere tektur mapning
							 //Specificere hvorledes tekture interpoliseres over overflader
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	tmpSC->Initial(soundToBePlayed);
	

	platformList.push_back(*platform1);
	platformList.push_back(*platform2);
	platformList.push_back(*platform3);
	platformList.push_back(*platform4);
	platformList.push_back(*platform5);

}


GameWorld::~GameWorld()
{
	//Husk at ryde op
	delete tmpGO;
	delete tmpSC;
	delete player;
	delete background;

	delete platform1;
	delete platform2;
	delete platform3;
	delete platform4;
	delete platform5;
}


void GameWorld::GameLoop()
{
	GameLogic();
	Render();
	
	glfwPollEvents();
}

void GameWorld::GameLogic()
{

	player->Update();
	
	tmpSC->PlaySound();

	int upState = glfwGetKey(window, GLFW_KEY_UP);
	int downState = glfwGetKey(window, GLFW_KEY_DOWN);
	int leftState = glfwGetKey(window, GLFW_KEY_LEFT);
	int rightState = glfwGetKey(window, GLFW_KEY_RIGHT);


	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //Tjekker op på at ESC er trykket ned, hvis ja luk vinduet
	{
		glfwSetWindowShouldClose(window, true);
	}

	player->yDirection = 0;
	player->xDirection = 0;

	if (leftState == GLFW_PRESS)
	{
		player->xDirection = -1; // Gå til venstre
	}

	if (rightState == GLFW_PRESS)
	{
		player->xDirection = 1; // Gå til højre
	}

	if (upState == GLFW_PRESS)
	{
		player->jump = true;
		player->yDirection = 1; // Gå op
	}

	if (downState == GLFW_PRESS)
	{
		player->yDirection = -1; // Gå ned
	}


}

void GameWorld::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity(); //Null stiller OpenGL matrise

	background->Render();
	vector<Platform>::iterator it;
	for (it = platformList.begin(); it != platformList.end(); ++it) 
	{
		it->Render();
	}



	player->Render();

	glfwSwapBuffers(window);

}

