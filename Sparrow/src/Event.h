#pragma once
#ifdef SPARROW_DLLEXPORT
#define SP_API  __declspec(dllexport)
#else
#define SP_API __declspec(dllimport)
#endif
#include <iostream>

namespace Sparrow {

	class SP_API Event {
	public:
		Event();
		virtual ~Event();
		virtual std::string TypeName() const;




	};



}
