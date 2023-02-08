#include "mathpch.h"
#include "ScriptingWindow.h"

#include "include/imgui.h"



namespace MatUTM {


	ScriptingWindow::ScriptingWindow(EditorLayer* editor )
		:Layer("ScriptingWindow") , m_Editor(editor) 
	{
		
	}


	void ScriptingWindow::OnAttach()
	{
			std::function<void()> test = []() {
				ImGui::Begin("MainWindow");
				ImGui::Text("Test Passed");
				ImGui::End();
			};

			m_Editor->SetDrawDataImGui(test);


	
	}
	void ScriptingWindow::OnDetach()
	{
	}
	void ScriptingWindow::OnUpdate()
	{
	}
	void ScriptingWindow::OnImGuiRender()
	{

	}






}