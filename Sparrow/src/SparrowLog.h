#pragma once

#ifdef SPARROW_DLLEXPORT
#define SP_API  __declspec(dllexport)
#else
#define SP_API __declspec(dllimport)
#endif

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
namespace Sparrow {
	class SP_API SparrowLog {
	public:
		
		SparrowLog();
		std::shared_ptr<spdlog::logger>& getClientLogger();
		std::shared_ptr<spdlog::logger>& getSparrowLogger();
		std::shared_ptr<spdlog::logger>& getClientFileLogger();
		std::shared_ptr<spdlog::logger>& getSparrowFileLogger();
		

		~SparrowLog();
	private:
		std::shared_ptr<spdlog::logger> clientLogger;
		std::shared_ptr<spdlog::logger> spLogger;
		std::shared_ptr<spdlog::logger> clientFileLogger;
		std::shared_ptr<spdlog::logger> spFileLogger;


	};

}
