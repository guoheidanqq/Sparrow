
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


void mousemove_handler(GLFWwindow* window, double xpos, double ypos) {
	// mouse x: xpos 
	// mouse y: ypos

	std::cout << xpos << ", " << ypos << std::endl;
}

int main() {
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}


	//bind event 
	glfwSetCursorPosCallback(window, mousemove_handler);



	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	if (status) {
		std::cout << "glad init successfully" << std::endl;
	}
	else
	{
		std::cout << "glad failure" << std::endl;
	}
	

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
	
	glfwTerminate();


	std::cout << "hello glfw" << std::endl;
	return 0;
}