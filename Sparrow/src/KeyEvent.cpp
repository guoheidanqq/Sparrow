#include "KeyEvent.h"

Sparrow::KeyEvent::KeyEvent(int key, int scancode, int action, int mods)
{
	this->key = key;
	this->scancode = scancode;
	this->action = action;
	this->mods = mods;
}

Sparrow::KeyEvent::~KeyEvent()
{
}

std::string Sparrow::KeyEvent::TypeName() const
{
	return std::string("KeyEvent");
}
