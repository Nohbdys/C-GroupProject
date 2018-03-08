#include "GameWorld.h"

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

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //Tjekker op p� at ESC er trykket ned, hvis ja luk vinduet
	{
		glfwSetWindowShouldClose(window, true);
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		tmpGO->direction = -1; // G� til venstre
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		tmpGO->direction = 1; // G� til h�jre
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

