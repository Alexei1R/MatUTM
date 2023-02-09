#include "mathpch.h"
#include "PloterWindow.h"

#include "include/imgui.h"



namespace MatUTM {


	PloterWindow::PloterWindow(EditorLayer* editor)
		:Layer("PloterWindow"), m_Editor(editor)
	{

	}


	void PloterWindow::OnAttach()
	{
		std::function<void()> ploterWindow = []() {

			ImGui::Begin("PloterWindow");
			ImGui::Text("Test");
			ImGui::End();

		};

		m_Editor->SetDrawPloter(ploterWindow);



	}
	void PloterWindow::OnDetach()
	{
	}
	void PloterWindow::OnUpdate()
	{
	}
	void PloterWindow::OnImGuiRender()
	{

	}






}