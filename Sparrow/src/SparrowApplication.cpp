#include "SparrowApplication.h"

namespace Sparrow {



	SparrowApplication::SparrowApplication()
	{
	}

	SparrowApplication::~SparrowApplication()
	{
	}

	void SparrowApplication::RenderTick()
	{
		printf("Render tick\n");
	}

	void SparrowApplication::LogicTick()
	{
		printf("Logic tick\n");
	}

	void SparrowApplication::Run()
	{
		while (true) {
			//printf("\n\n--------begin frame------\n");
			//SparrowLog::GetInstance().getSparrowLogger()->info("running\n");
			SP_INFO("running\n");
			//Tick();
		}
	}

	void SparrowApplication::Tick()
	{
		LogicTick();
		RenderTick();
	}

}
