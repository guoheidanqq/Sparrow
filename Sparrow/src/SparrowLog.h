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
		static SparrowLog& GetInstance();
		std::shared_ptr<spdlog::logger>& getClientLogger();
		std::shared_ptr<spdlog::logger>& getSparrowLogger();
		std::shared_ptr<spdlog::logger>& getClientFileLogger();
		std::shared_ptr<spdlog::logger>& getSparrowFileLogger();
		
	private:
		static SparrowLog   logger;
		std::shared_ptr<spdlog::logger> clientLogger;
		std::shared_ptr<spdlog::logger> spLogger;
		std::shared_ptr<spdlog::logger> clientFileLogger;
		std::shared_ptr<spdlog::logger> spFileLogger;
	private:
		SparrowLog();
		~SparrowLog();
		SparrowLog(const SparrowLog& logger)=delete;
		SparrowLog& operator=(const SparrowLog& logger)=delete;
	};
	

}


#define SP_INFO(...) Sparrow::SparrowLog::GetInstance().getSparrowLogger()->info(__VA_ARGS__)
#define CLIENT_INFO(...) Sparrow::SparrowLog::GetInstance().getClientLogger()->info(__VA_ARGS__)
#define SP_FILE_INFO(...) Sparrow::SparrowLog::GetInstance().getSparrowFileLogger()->info(__VA_ARGS__); \
							Sparrow::SparrowLog::GetInstance().getSparrowFileLogger()->flush()
#define CLIENT_FILE_INFO(...) Sparrow::SparrowLog::GetInstance().getClientFileLogger()->info(__VA_ARGS__); \
								Sparrow::SparrowLog::GetInstance().getClientFileLogger()->flush()