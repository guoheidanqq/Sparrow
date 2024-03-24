#include "Event.h"

namespace Sparrow {




	Event::Event()
	{
	}

	Event::~Event()
	{
	}

	std::string Event::TypeName() const
	{
		return std::string("Event");
	}

}