

// Remember to add the line in input:
// Rightclick solution - properties - linker - input - additional dependencies- "glfw3.lib;opengl32.lib;irrKlang.lib;" < should be added in the beginning. in front of kernel32.lib

#include <GLFW\glfw3.h>

#include <iostream>
using namespace std;


void size_resize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	glfwInit(); //Initialisering af glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); //Sætte øvre OpenGl version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0); //Sætte nedre OpenGl Version


	GLFWwindow* window = glfwCreateWindow(800, 600, "MyGLFWGLAD1", NULL, NULL);

	if (window == NULL)
	{
		cout << "Kunne ikke oprette OpenGL Vindue" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); //Sørger for at OpenGL Bruger vinduet som renderings context

	glViewport(0, 0, 800, 600); //Oprettet en viewport gennem OpenGL kald
	glfwSetFramebufferSizeCallback(window, size_resize_callback);
	//Sikre at hvis vinduets størrelse ændres ændres viewport også


	float rotation = 0;

	while (!glfwWindowShouldClose(window)) // Køre så længe glfw vinduet ikke har fået besked på at lukke(f.eks.tryk på X knappen)

	{ //Her starter gameloop'et

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //Sætter baggrundfarven
		glClear(GL_COLOR_BUFFER_BIT); //Nul stiller baggrunden til baggrundsfarven


									  /* Drejende firkant
									  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
									  glClear(GL_COLOR_BUFFER_BIT);
									  rotation += 0.0001f; //Forøg rotation
									  glRotatef(rotation, 1, 1, 1); //Roter matricen gældende for efterfølgende vertices

									  // Makes rainbow(perfect!)
									  glBegin(GL_TRIANGLES);
									  glColor3f(1.0f, 0.0f, 0.0f); // Set color of triangle area
									  glVertex3f(-0.5f, 0.0f, 0.0f);
									  glColor3f(0.0f, 1.0f, 0.0f);
									  glVertex3f(0.0f, 0.5f, 0.0f);
									  glColor3f(0.0f, 0.0f, 1.0f);
									  glVertex3f(0.5f, 0.0f, 0.0f);
									  glEnd();
									  */
									  
		glfwSwapBuffers(window); //Bruger dobbelt buffer koncept til reducering af flicker - her byttesbufferne

		glfwPollEvents(); //Kalder evt. callback der skal reagere på keyboard eller mouse input
	
						  // http://www.glfw.org/docs/latest/input_guide.html
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //Tjekker op på at ESC er trykket ned, hvis ja luk vinduet
		{
			glfwSetWindowShouldClose(window, true);
		}
	}



	glfwTerminate();
	return 0;

}

