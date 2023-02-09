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
			
			{
				static float arr[100];
				for (int i = 0; i < 100; i++)
					arr[i] = (sin(i / 10.0f) + 0.5)* 0.3;
				ImVec2 window_size = ImGui::GetWindowSize();
				ImGui::PlotLines("My Plot", arr, IM_ARRAYSIZE(arr), 0, NULL, 0, FLT_MAX, window_size);

			}
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