#pragma once

#include "SparrowApplication.h"
#include "SparrowLog.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>


int main() {
	//Sparrow::SparrowLog& logger = Sparrow::SparrowLog::GetInstance();
	//auto clientLogger = logger.getClientLogger();
	//auto spLogger = logger.getSparrowLogger();
	//auto clientFileLogger = logger.getClientFileLogger();
	//auto spFileLogger = logger.getSparrowFileLogger();
	//spLogger->info("hello splogger");	
	//clientLogger->info("hello client loggger");
	//spFileLogger->info("hello sp file logger");
	//clientFileLogger->info("hello client  file loggger");
	//spFileLogger->flush();
	//clientFileLogger->flush();
	SP_INFO("hello splogger");
	CLIENT_INFO("hello client loger");
	SP_FILE_INFO("hello spfile logger");
	CLIENT_FILE_INFO("hello client file logger");

	Sparrow::SparrowApplication* app = Sparrow::CreateApp();
	Sparrow::hello();
	app->Run();
	delete app;
	return 0;
}
