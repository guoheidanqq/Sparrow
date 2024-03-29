#include "SparrowApplication.h"
#include "KeyEvent.h"
#include "Input.h"
#include  "SparrowLog.h"
#include <functional>
#include <glfw/glfw3.h>

namespace Sparrow {
	SparrowApplication* SparrowApplication::app = nullptr;


	SparrowApplication::SparrowApplication()
	{
		this->app = this;
		std::cout << "begin to bind" << std::endl;
		WindowProps winprops("sparrow application",600,800);


		this->app_window = std::unique_ptr<Window>(Window::Create(winprops));
		
		std::function<void(Event&)> func = std::bind(&SparrowApplication::WindowEventHandler, this, std::placeholders::_1);
		std::cout << "begin to set event handler" << std::endl;
		this->app_window->SetEventHandler(func);

		
	}

	SparrowApplication::~SparrowApplication()
	{
	}

	void SparrowApplication::RenderTick()
	{
		printf("Render tick\n");
	}

	void SparrowApplication::LogicTick()
	{
		printf("Logic tick\n");
	}

	void SparrowApplication::Run()
	{
		
		while (true) {
			//printf("\n\n--------begin frame------\n");
			//SparrowLog::GetInstance().getSparrowLogger()->info("running\n");
			//SP_INFO("running\n");
			//Tick();

			///* Render here */
			//glClear(GL_COLOR_BUFFER_BIT);

			///* Swap front and back buffers */
			//glfwSwapBuffers(window);

			/* Poll for and process events */
			//glfwPollEvents();
			bool isKeyPressed = Input::IsKeyPressed(GLFW_KEY_SPACE);
			bool isMLPressed = Input::IsMouseLeftButtonPressed();
			//std::cout << "code 10 " << isKeyPressed << std::endl;
			SP_INFO("keypressed {}",isKeyPressed);
			//std::cout << "left button is pressed " << isMLPressed << std::endl;
			SP_INFO("left button is {}",isMLPressed);
			
			this->app_window->WindowPollEvent();
			

		}
	}

	void SparrowApplication::WindowEventHandler(Event & event)
	{
		std::string classtype(event.TypeName());

		if (classtype == "KeyEvent") {
			KeyEvent* pe = dynamic_cast<KeyEvent*>(&event);
			std::cout << pe->key << std::endl;

		}
		if (classtype == "MousePosEvent") {
			auto p = dynamic_cast<MousePosEvent*>(&event);
			std::cout << p->posx << " " << p->posy << std::endl;
		
		}

		std::cout << event.TypeName() << std::endl;
	}

	SparrowApplication & SparrowApplication::GetInstance()
	{
		// TODO: insert return statement here
		return *app;
	}

	void SparrowApplication::Tick()
	{
		LogicTick();
		RenderTick();
	}

	

}
