#include "GameWorld.h"
#include <conio.h>

char soundToBePlayed[12] = "Bye456.wav\0";

GameWorld::GameWorld(GLFWwindow * windowContext)
{
	window = windowContext;

//	tmpGO = new GameObject();
	tmpSC = new SoundController();
	player = new Player(0, 0, 0, "..\\Images/BGround.png\0");

	glEnable(GL_TEXTURE_2D); //Aktivere tektur mapning
							 //Specificere hvorledes tekture interpoliseres over overflader
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	tmpSC->Initial(soundToBePlayed);
}


GameWorld::~GameWorld()
{
	//Husk at ryde op
	delete tmpGO;
	delete tmpSC;
	delete player;
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

	if (leftState == GLFW_PRESS)
	{
	//	player->xDirection = -1; // Gå til venstre
		(*player).yDirection = -1;
		player->Update();
		
	}

	if (rightState == GLFW_PRESS)
	{
		player->xDirection = 1; // Gå til højre
		
		player->Update();
	}

	if (upState == GLFW_PRESS)
	{
		player->yDirection = 1; // Gå op
	
		player->Update();

	}

	if (downState == GLFW_PRESS)
	{
		player->yDirection = -1; // Gå ned
		
		player->Update();
	}
	player->yDirection = 0;
	player->xDirection = 0;

}

void GameWorld::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity(); //Null stiller OpenGL matrise

	player->Render();

	glfwSwapBuffers(window);

}

