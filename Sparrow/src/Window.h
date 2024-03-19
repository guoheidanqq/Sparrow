#pragma once

#ifdef SPARROW_DLLEXPORT
#define SP_API  __declspec(dllexport)
#else
#define SP_API __declspec(dllimport)
#endif

#include <iostream>
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
		Window();
		virtual ~Window();

		virtual void OnUpdate() = 0;		
		virtual void OnInit() = 0;
		virtual void OnShutdown() = 0;
		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;
		static Window* Create(const WindowProps& props = WindowProps());



	};



}
