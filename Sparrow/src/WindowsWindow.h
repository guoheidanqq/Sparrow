#pragma once

#ifdef SPARROW_DLLEXPORT
#define SP_API  __declspec(dllexport)
#else
#define SP_API __declspec(dllimport)
#endif

#include "Window.h"
#include "Event.h"
#include "MouseEvent.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <map>
namespace Sparrow {

	class SP_API WindowsWindow : public Window {

	public:
		
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();
		void Update() override;
		void Init() override;
		void Shutdown() override;
		int GetWidth() override;
		int GetHeight() override;
		void SetEventHandler(std::function<void(Event&)>& handler) override;
	public:
		static std::map<GLFWwindow*, WindowsWindow*> instanceMap;
		
		static void MousePosCallback(GLFWwindow* window, double xpos, double ypos);

		void SetGLFWCallback(); 
		void WindowPollEvent() override;
		virtual void* GetNativeWindow() override;

		

	private:
		std::function<void(Event&)> EventHandler;
		GLFWwindow* window;
		WindowProps props;






	};




}

