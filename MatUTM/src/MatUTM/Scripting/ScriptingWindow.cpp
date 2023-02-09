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
			std::function<void()> scriptWindow = []() {
				
				ImGui::Begin("ScriptingWindow");
				ImVec2 window_size = ImGui::GetWindowSize();
					
				ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 2));
				ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, ImVec2(0, 0));
				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
				auto& colors = ImGui::GetStyle().Colors;
				const auto& buttonHovered = colors[ImGuiCol_ButtonHovered];
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(buttonHovered.x, buttonHovered.y, buttonHovered.z, 0.5f));
				const auto& buttonActive = colors[ImGuiCol_ButtonActive];
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(buttonActive.x, buttonActive.y, buttonActive.z, 0.5f));


				ImVec4 tintColor = ImVec4(1, 1, 1, 1);
				if (!true)
					tintColor.w = 0.5f;

				float size = ImGui::GetWindowHeight() - 4.0f;
				ImGui::SetCursorPosX((ImGui::GetWindowContentRegionMax().x * 0.5f) - (size * 0.5f));


				ImVec2 zero = { 0,0 };

				if (true)
				{
					if (ImGui::Button("ImT", ImVec2(size, size)))
					{
						LOG_CRITICAL("test {0} {1} {2}",size,window_size.x,window_size.y);
					}
				}

				if (true)
				{
					if (true)
						ImGui::SameLine();

					if (ImGui::Button("nuic", ImVec2(size, size)))
					{
						LOG_CRITICAL("test");
					}
				}

				ImGui::PopStyleVar(2);
				ImGui::PopStyleColor(3);





				ImGui::End();

			};

			m_Editor->SetDrawScripting(scriptWindow);


	
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