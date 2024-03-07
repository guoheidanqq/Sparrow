#pragma once
#include <stdio.h>

#ifdef SPARROW_DLLEXPORT
	#define SP_API  __declspec(dllexport)
#else
	#define SP_API __declspec(dllimport)
#endif

namespace  Sparrow {
	class SP_API SparrowApplication
	{
	public:
		SparrowApplication();
		~SparrowApplication();
	public:
		void Tick();
	};

	SparrowApplication* CreateApp();
}








