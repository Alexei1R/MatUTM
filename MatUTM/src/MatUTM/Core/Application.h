#pragma once
#include "MathUTM.h"
#include "MatUTM/Core/Layers/Layer.h"
#include "MatUTM/Core/Layers/LayerStack.h"
#include "MatUTM/Core/Log/Log.h"

#include "MatUTM/Core/GUI/EditorLayer.h"
#include "MatUTM/Core/GUI/GUI.h"

#include "mathpch.h"

#include "MatUTM/Scripting/ScriptingWindow.h"



namespace MatUTM {
	class Application {
	public:

		Application();
		~Application();


		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);


		
		


	private:
		bool isRunnig = true;


	private:
		LayerStack m_LayerStack;
		EditorLayer* m_EditorLayer;
		GUI* m_Window;
		ScriptingWindow* m_ScriptW;
		

		
		

	};
	
}