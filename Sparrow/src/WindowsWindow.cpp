
#include "MouseEvent.h"
#include "WindowsWindow.h"
#include  "KeyEvent.h"

namespace Sparrow {
	Window* Window::Create(const WindowProps& props) {
	
		Window* winptr = new WindowsWindow(props);
		if (winptr == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			
		}
		return winptr;
	
	}
	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		this->Init();
		this->props = props;
		this->window = glfwCreateWindow(this->props.width, this->props.height, this->props.title.data(), NULL, NULL);
		this->instanceMap.insert(std::make_pair(this->window,this));

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


		this->SetGLFWCallback();

		//while (!glfwWindowShouldClose(this->window)) {
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		//}


	
	}

	WindowsWindow::~WindowsWindow()
	{
		this->instanceMap.erase(this->window);
		this->Shutdown();
		delete this->window;
	}

	void WindowsWindow::Update()
	{
	}

	void WindowsWindow::Init()
	{
		glfwInit();
	}

	void  WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(this->window);
	}

	int Sparrow::WindowsWindow::GetWidth()
	{
		return this->props.width;
	}

	int Sparrow::WindowsWindow::GetHeight()
	{
		return this->props.height;
	}

	void WindowsWindow::SetEventHandler(std::function<void(Event&)>& handler)
	{

		this->EventHandler = handler;
	}

	void WindowsWindow::SetGLFWCallback()
	{
		//bind event 
		//glfwSetCursorPosCallback(this->window, &WindowsWindow::MousePosCallback);
		glfwSetCursorPosCallback(this->window, [](GLFWwindow* window, double xpos, double ypos) {
			MousePosEvent event(xpos,ypos);
			try {
				//std::cout <<&(WindowsWindow::instanceMap[window]->EventHandler) << std::endl;
				WindowsWindow::instanceMap[window]->EventHandler(event);
			}
			catch (std::bad_function_call& e) {
				std::cout << e.what() << std::endl;
			}
			
			});

		glfwSetKeyCallback(this->window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			KeyEvent event(key,scancode,action,mods);
			WindowsWindow::instanceMap[window]->EventHandler(event);
			
			
			});

			
			
			
			



	}

	void WindowsWindow::WindowPollEvent()
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

	}

	void WindowsWindow::MousePosCallback(GLFWwindow * window, double xpos, double ypos)
	{
		
			// mouse x: xpos 
			// mouse y: ypos
		    std::cout << xpos << " " << ypos << std::endl;
			MousePosEvent event(xpos,ypos);
			try
			{
				std::cout << window << std::endl;
				std::cout << instanceMap[window] << std::endl;
				std::cout << event.posx << " " << event.posy << std::endl;
				instanceMap[window]->EventHandler(event);
			}
			catch (const std::bad_function_call& e)
			{
				std::cout << e.what() << '\n';
			}

			
			//eventHandler(event);

			//std::cout << xpos << ", " << ypos << std::endl;

		
		
	}



	std::map<GLFWwindow*, WindowsWindow*> WindowsWindow::instanceMap;



}


