#pragma once 
#include "MatUTM/Core/macros.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace MatUTM {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};

}

// Core log macros
#define LOG_TRACE(...)    ::MatUTM::Log::GetLogger()->trace(__VA_ARGS__);
#define LOG_INFO(...)     ::MatUTM::Log::GetLogger()->info(__VA_ARGS__);
#define LOG_WARN(...)     ::MatUTM::Log::GetLogger()->warn(__VA_ARGS__);
#define LOG_ERROR(...)    ::MatUTM::Log::GetLogger()->error(__VA_ARGS__);
#define LOG_CRITICAL(...) ::MatUTM::Log::GetLogger()->critical(__VA_ARGS__);






