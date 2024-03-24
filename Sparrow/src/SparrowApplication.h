#pragma once
#ifdef SPARROW_DLLEXPORT
#define SP_API  __declspec(dllexport)
#else
#define SP_API __declspec(dllimport)
#endif

#include <stdio.h>
#include "SparrowLog.h"
#include "Window.h"
#include "WindowsWindow.h"
#include "Event.h"
#include "MouseEvent.h"
namespace  Sparrow {
	class SP_API SparrowApplication
	{
	public:
		SparrowApplication();
		virtual ~SparrowApplication();
	public:
		void RenderTick();
		void LogicTick();
		void Tick();
		void Run();

		void WindowEventHandler(Event& event);
	

	private:
		std::unique_ptr<Window> app_window;

	};
	// to be defined in client
	int hello();
	


	SparrowApplication* CreateApp();
}








