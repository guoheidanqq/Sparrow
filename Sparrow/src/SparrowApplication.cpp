#include "SparrowApplication.h"
#include "KeyEvent.h"
#include <functional>

namespace Sparrow {



	SparrowApplication::SparrowApplication()
	{
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

	void SparrowApplication::Tick()
	{
		LogicTick();
		RenderTick();
	}

}
