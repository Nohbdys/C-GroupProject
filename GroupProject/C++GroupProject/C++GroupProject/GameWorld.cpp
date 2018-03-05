

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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); //S�tte �vre OpenGl version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0); //S�tte nedre OpenGl Version


	GLFWwindow* window = glfwCreateWindow(800, 600, "MyGLFWGLAD1", NULL, NULL);

	if (window == NULL)
	{
		cout << "Kunne ikke oprette OpenGL Vindue" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); //S�rger for at OpenGL Bruger vinduet som renderings context

	glViewport(0, 0, 800, 600); //Oprettet en viewport gennem OpenGL kald
	glfwSetFramebufferSizeCallback(window, size_resize_callback);
	//Sikre at hvis vinduets st�rrelse �ndres �ndres viewport ogs�


	float rotation = 0;

	while (!glfwWindowShouldClose(window)) // K�re s� l�nge glfw vinduet ikke har f�et besked p� at lukke(f.eks.tryk p� X knappen)

	{ //Her starter gameloop'et

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //S�tter baggrundfarven
		glClear(GL_COLOR_BUFFER_BIT); //Nul stiller baggrunden til baggrundsfarven


									  /* Drejende firkant
									  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
									  glClear(GL_COLOR_BUFFER_BIT);
									  rotation += 0.0001f; //For�g rotation
									  glRotatef(rotation, 1, 1, 1); //Roter matricen g�ldende for efterf�lgende vertices

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

		glfwPollEvents(); //Kalder evt. callback der skal reagere p� keyboard eller mouse input
	
						  // http://www.glfw.org/docs/latest/input_guide.html
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //Tjekker op p� at ESC er trykket ned, hvis ja luk vinduet
		{
			glfwSetWindowShouldClose(window, true);
		}
	}



	glfwTerminate();
	return 0;

}

