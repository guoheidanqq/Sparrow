#pragma once
#pragma comment(lib, "Sparrow.lib")
#include "SparrowApplication.h"
#include "EntryPoint.h"

class SanboxApp : public Sparrow::SparrowApplication {
public:
	SanboxApp() {
	}

	~SanboxApp() {
	}


};



int  Sparrow::hello() {
	printf("hello \n");
	return 1;
}



Sparrow::SparrowApplication* Sparrow::CreateApp() {
	Sparrow::SparrowApplication* app = new SanboxApp();
	app->Run();
	return app;

}


