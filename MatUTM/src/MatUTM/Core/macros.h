#pragma once
#include "Log/Log.h"
#include <memory>

namespace MatUTM {

	

}


#define APP_ASSERT(x, ...) { if(!(x)) { LOG_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }