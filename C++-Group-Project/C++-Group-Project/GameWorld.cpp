#include "GameWorld.h"
#include <conio.h>

char soundToBePlayed[12] = "Bye456.wav\0";

GameWorld::GameWorld(GLFWwindow * windowContext)
{
	window = windowContext;
	tmpGO = new GameObject();
	tmpSC = new SoundController();

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
}


void GameWorld::GameLoop()
{
	GameLogic();
	Render();
	
	glfwPollEvents();
}

void GameWorld::GameLogic()
{

	tmpGO->Update();
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
		tmpGO->xDirection = -1; // Gå til venstre
		tmpGO->horizontalPressed = true;
		tmpGO->Update();
	}

	if (rightState == GLFW_PRESS)
	{
		tmpGO->xDirection = 1; // Gå til højre
		tmpGO->horizontalPressed = true;
		tmpGO->Update();
	}

	if (upState == GLFW_PRESS)
	{
		tmpGO->yDirection = 1; // Gå op
		tmpGO->verticalPressed = true;
		tmpGO->Update();

	}

	if (downState == GLFW_PRESS)
	{
		tmpGO->yDirection = -1; // Gå ned
		tmpGO->verticalPressed = true;
		tmpGO->Update();
	}

}

void GameWorld::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity(); //Null stiller OpenGL matrise

	tmpGO->Render();

	glfwSwapBuffers(window);

}

