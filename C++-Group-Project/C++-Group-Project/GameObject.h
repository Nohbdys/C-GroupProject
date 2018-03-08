#pragma once

#include <GLFW\glfw3.h>

class GameObject
{
private:
	GLuint texture; //Texture holder
	float x;
	float y;
	float z;
public:
	GameObject();
	GameObject(float initX, float initY, float initZ);
	~GameObject();
	void virtual Update();
	void virtual Render();
	int xDirection;
	int yDirection;
	bool horizontalPressed;
	bool verticalPressed;
};

