#include "mathpch.h"
#include "Log.h"

namespace MatUTM {
	std::shared_ptr<spdlog::logger> Log::s_Logger;
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_Logger = spdlog::stdout_color_mt("Bright");
		s_Logger->set_level(spdlog::level::trace);
	}
}