#pragma once

#ifdef SPARROW_DLLEXPORT
#define SP_API  __declspec(dllexport)
#else
#define SP_API __declspec(dllimport)
#endif
#include "Event.h"

#include <iostream>
#include <functional>
namespace Sparrow {


	class SP_API WindowProps {
	public:
		int height;
		int width;
		std::string title;
	public:
		WindowProps(const std::string& title = "Sparrow",const int height =600, const int width = 800);
	};
	class SP_API Window {

	public:
		//using EventHandlerType = std::function<void(Event&)>;
		Window();
		virtual ~Window();

		virtual void Update() = 0;		
		virtual void Init() = 0;
		virtual void Shutdown() = 0;
		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;
		virtual void SetEventHandler(std::function<void(Event&)>& handler) = 0;
		virtual void WindowPollEvent() = 0;
		virtual void* GetNativeWindow() = 0;
		static Window* Create(const WindowProps& props = WindowProps());



	};



}
