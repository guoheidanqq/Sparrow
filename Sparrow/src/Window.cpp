#include "Window.h"

namespace Sparrow {




	Window::Window()
	{

	}

	Window::~Window()
	{
	}



	WindowProps::WindowProps(const std::string& title,const int height, const int width)
	{
		this->height = height;
		this->width = width;
		this->title = title;
	}

}