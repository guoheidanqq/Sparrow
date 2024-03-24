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

	class SP_API  MousePosEvent : public Event{
	public:
		MousePosEvent();
		MousePosEvent(double posx,double posy);
		virtual ~MousePosEvent();
		std::string TypeName() const override;
	public:
		unsigned int posx;
		unsigned int posy;

		


	};


}
