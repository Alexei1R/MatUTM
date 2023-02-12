#include "mathpch.h"
#include "SettingsWindow.h"

#include "include/imgui.h"
#include "include/implot.h"


namespace MatUTM {


	SettingsWindow::SettingsWindow(EditorLayer* editor)
		:Layer("SettingsWindow"), m_Editor(editor)
	{

	}


	void SettingsWindow::OnAttach()
	{
		std::function<void()> SettingsWindow = [&]() {
			ImGui::Begin("Setings");
			if (ImGui::Button("Close")) {
				m_Editor->SetSettingsFalse();
			}


			


			//ImGui::ListBoxHeader
			// for vector items
			//ImGui::ListBoxFooter







			

			ImGui::End();
		};
		m_Editor->SetDrawSettings(SettingsWindow);



	}
	void SettingsWindow::OnDetach()
	{
	}
	void SettingsWindow::OnUpdate()
	{
	}
	void SettingsWindow::OnImGuiRender()
	{

	}






}