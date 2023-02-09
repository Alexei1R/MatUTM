#include "mathpch.h"
#include "PloterWindow.h"

#include "include/imgui.h"
#include "include/implot.h"


namespace MatUTM {


	PloterWindow::PloterWindow(EditorLayer* editor)
		:Layer("PloterWindow"), m_Editor(editor)
	{

	}


	void PloterWindow::OnAttach()
	{
		std::function<void()> ploterWindow = []() {


			ImGui::Begin("PloterWindow");
			
			static float arr[1000];
			for (int i = 0; i < 1000; i++)
				arr[i] = sin(i / 10.0f);
			//ImVec2 window_size = ImGui::GetWindowSize();
			//ImGui::PlotLines("My Plot", arr, IM_ARRAYSIZE(arr), 0, NULL, 0, FLT_MAX, window_size);


			int   bar_data[11] = { 1,2,34,5,6,7,8,8,9,0,1 };
			
			if (ImPlot::BeginPlot("My Plot")) {
				ImPlot::PlotBars("My Bar Plot", arr, 1000);
				
				ImPlot::EndPlot();
			}
			


			float x_data[1000];
			float y_data[1000];


			for (size_t i = 0; i < 1000; i++)
			{
				x_data[i] = i ;
				
			}
			for (size_t i = 0; i < 1000; i++)
			{
				y_data[i] = sin(i / 10.0f);
			}
			


			if (ImPlot::BeginPlot("My sec Plot")) {
				ImPlot::PlotLine("My Line Plot", x_data, y_data, 1000);
				
				ImPlot::EndPlot();
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