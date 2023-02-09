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
				
				//if (ImGui::TreeNode("Multi-line Text Input"))
				//{
					// Note: we are using a fixed-sized buffer for simplicity here. See ImGuiInputTextFlags_CallbackResize
					// and the code in misc/cpp/imgui_stdlib.h for how to setup InputText() for dynamically resizing strings.
					static char text[1024 * 60] =
						">>\n";

					//static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;
					//ImGui::CheckboxFlags("ImGuiInputTextFlags_ReadOnly", &flags, ImGuiInputTextFlags_ReadOnly);
					//ImGui::CheckboxFlags("ImGuiInputTextFlags_AllowTabInput", &flags, ImGuiInputTextFlags_AllowTabInput);
					//ImGui::CheckboxFlags("ImGuiInputTextFlags_CtrlEnterForNewLine", &flags, ImGuiInputTextFlags_CtrlEnterForNewLine);

					ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 30));
					
				//	ImGui::TreePop();
				//}





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