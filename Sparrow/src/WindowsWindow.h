#pragma once

#ifdef SPARROW_DLLEXPORT
#define SP_API  __declspec(dllexport)
#else
#define SP_API __declspec(dllimport)
#endif

#include "Window.h"
#include <GLFW/glfw3.h>
namespace Sparrow {

	class SP_API WindowsWindow : public Window {

	public:
		WindowsWindow();
		~WindowsWindow();


	private:






	};




}

