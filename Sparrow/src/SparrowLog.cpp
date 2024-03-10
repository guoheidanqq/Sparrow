#include "SparrowLog.h"
namespace Sparrow {
	
	SparrowLog::SparrowLog()
	{
		spdlog::set_pattern("%^[%T] %n: %v %$");
		clientLogger = spdlog::stdout_color_mt("client");
		spLogger = spdlog::stdout_color_mt("spcore");
		clientFileLogger = spdlog::basic_logger_mt("clientFilelogger","../x64/Debug/clientlog.txt");
		spFileLogger = spdlog::basic_logger_mt("spfilelogger","../x64/Debug/splog.txt");
		
	}

	SparrowLog& SparrowLog::GetInstance()
	{
		// TODO: insert return statement here
		return SparrowLog::logger;
	}

	std::shared_ptr<spdlog::logger>& SparrowLog::getClientLogger()
	{
		// TODO: insert return statement here
		return this->clientLogger;
	}

	std::shared_ptr<spdlog::logger>& SparrowLog::getSparrowLogger()
	{
		// TODO: insert return statement here
		return spLogger;
	}

	std::shared_ptr<spdlog::logger>& SparrowLog::getClientFileLogger()
	{
		// TODO: insert return statement here
		return this->clientFileLogger;
	}

	std::shared_ptr<spdlog::logger>& SparrowLog::getSparrowFileLogger()
	{
		// TODO: insert return statement here
		return this->spFileLogger;
	}

	SparrowLog::~SparrowLog()
	{
	}
	SparrowLog   SparrowLog::logger;

}
