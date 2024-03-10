#pragma once
#ifdef SPARROW_DLLEXPORT
#define SP_API  __declspec(dllexport)
#else
#define SP_API __declspec(dllimport)
#endif

#include <stdio.h>
namespace  Sparrow {
	class SP_API SparrowApplication
	{
	public:
		SparrowApplication();
		virtual ~SparrowApplication();
	public:
		void RenderTick();
		void LogicTick();
		void Tick();
		void Run();
	};
	// to be defined in client
	int hello();

	SparrowApplication* CreateApp();
}








