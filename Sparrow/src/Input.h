#pragma once
#ifdef SPARROW_DLLEXPORT
#define SP_API  __declspec(dllexport)
#else
#define SP_API __declspec(dllimport)
#endif

namespace Sparrow {
	class SP_API Input {
	public:
		static bool IsKeyPressed(int keycode) { return input->IsKeyPressedImpl(keycode);}
		static bool IsMouseLeftButtonPressed() { return input->IsMouseLeftButtonPressedImpl(); }
		static Input* GetInstance() { return input; }
	

	protected: 
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseLeftButtonPressedImpl() = 0;


	protected:
		Input() {}
	private:
		static Input* input;
	};
	




}
