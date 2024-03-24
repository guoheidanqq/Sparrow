#pragma once
#ifdef SPARROW_DLLEXPORT
#define SP_API  __declspec(dllexport)
#else
#define SP_API __declspec(dllimport)
#endif
#include "Input.h"


namespace Sparrow {

	class SP_API  WindowsInput: public Input{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseLeftButtonPressedImpl() override;


	public:
		WindowsInput();


	};



}