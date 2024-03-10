#pragma once

#include "SparrowApplication.h"
#include "SparrowLog.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>


int main() {
	Sparrow::SparrowLog logger;
	auto clientLogger = logger.getClientLogger();
	auto spLogger = logger.getSparrowLogger();
	auto clientFileLogger = logger.getClientFileLogger();
	auto spFileLogger = logger.getSparrowFileLogger();
	spLogger->info("hello splogger");	
	clientLogger->info("hello client loggger");
	spFileLogger->info("hello sp file logger");
	clientFileLogger->info("hello client  file loggger");
	spFileLogger->flush();
	clientFileLogger->flush();

	Sparrow::SparrowApplication* app = Sparrow::CreateApp();
	Sparrow::hello();
	app->Run();
	delete app;
	return 0;
}
