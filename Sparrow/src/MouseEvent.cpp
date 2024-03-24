#include "MouseEvent.h"

Sparrow::MousePosEvent::MousePosEvent()
{
}

Sparrow::MousePosEvent::MousePosEvent(double posx, double posy)
{
	this->posx = posx;
	this->posy = posy;
}

Sparrow::MousePosEvent::~MousePosEvent()
{
}

std::string Sparrow::MousePosEvent::TypeName() const
{
	return std::string("MousePosEvent");
}
