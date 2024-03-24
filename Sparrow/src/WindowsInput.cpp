#include "WindowsInput.h"

namespace Sparrow {
	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{

		return false;
	}
	bool WindowsInput::IsMouseLeftButtonPressedImpl()
	{
		return false;
	}
	WindowsInput::WindowsInput()
	{
	}

	Input* Input::input = new WindowsInput();
}
