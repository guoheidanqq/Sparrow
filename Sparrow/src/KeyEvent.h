#pragma once
#pragma once
#include "Event.h"
#ifdef SPARROW_DLLEXPORT
#define SP_API  __declspec(dllexport)
#else
#define SP_API __declspec(dllimport)
#endif
#include <iostream>
#include "Event.h"

namespace Sparrow {

	class SP_API  KeyEvent : public Event {
	public:
		KeyEvent(int key ,int scancode, int action, int mods);		
		virtual ~KeyEvent();
		std::string TypeName() const override;
	public:
		int key; 
		int scancode;
		int action; 
		int mods;




	};


}
