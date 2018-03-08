#pragma once

#include <GLFW\glfw3.h>

class GameObject
{
private:
	GLuint texture; //Texture holder
protected:
	char textureChar[24];
	float x;
	float y;
	float z;
public:
	GameObject();
	GameObject(float initX, float initY, float initZ, char * texture);
	~GameObject();
	void virtual Update();
	void virtual Render();
	int xDirection;
	int yDirection;



};

