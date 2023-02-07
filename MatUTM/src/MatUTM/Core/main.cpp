#include "mathpch.h"
#include "MatUTM/Core/Log/Log.h"
#include "Application.h"






int main() {


	MatUTM::Log::Init();
	LOG_INFO("Log Init")
	MatUTM::Application* app = new MatUTM::Application();
	app->Run();
	delete app;


	return 0;
}



