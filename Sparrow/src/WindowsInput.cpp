#include "WindowsInput.h"
#include "SparrowApplication.h"
#include "DeviceCodes.h"
#include <glfw/glfw3.h>


namespace Sparrow {
	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(SparrowApplication::GetInstance().GetAppWindow().GetNativeWindow());
		
		int state = glfwGetKey(window,keycode);
		return state == SP_PRESS;
	}
	bool WindowsInput::IsMouseLeftButtonPressedImpl()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(SparrowApplication::GetInstance().GetAppWindow().GetNativeWindow());
		int state = glfwGetMouseButton(window, SP_MOUSE_BUTTON_LEFT);
		return state == SP_PRESS;
	}
	WindowsInput::WindowsInput()
	{
	}

	Input* Input::input = new WindowsInput();
}
