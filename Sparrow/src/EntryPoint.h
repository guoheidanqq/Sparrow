#pragma once
#include "SparrowApplication.h"

//extern Sparrow::SparrowApplication* CreateApp();
int main() {
	Sparrow::SparrowApplication* app = Sparrow::CreateApp();
	app->Tick();
	return 0;
}
