//#include ".\..\..\Sparrow\src\test.h"
//#pragma comment(lib, "Sparrow.lib")  

//namespace Sparrow {
//	__declspec(dllimport) void sayhello();
//
//}
//#pragma comment(lib, "Sparrow.lib") 

#pragma once
#include <stdio.h>
#include "..\..\Sparrow\src\EntryPoint.h"
//#pragma comment(lib, "Sparrow.lib") 
//extern Sparrow::SparrowApplication* CreateApp();
//namespace Sparrow {
//	__declspec(dllimport) void sayhello();
//	class __declspec(dllimport) SparrowApplication
//	{
//	public:
//		SparrowApplication();
//		~SparrowApplication();
//	public:
//		void Tick();
//	};
//
//	
//
//}


class SanboxApp : public Sparrow::SparrowApplication {
public:
	SanboxApp() {
	}

	void Run() {
		while (true) {
			this->Tick();

		}

	}

	~SanboxApp() {
	}


};


Sparrow::SparrowApplication* CreateApp() {
	Sparrow::SparrowApplication* app = new SanboxApp();
	return app;

}