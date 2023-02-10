#include "mathpch.h"
#include "ScriptingWindow.h"

#include "include/imgui.h"



namespace MatUTM {


	ScriptingWindow::ScriptingWindow(EditorLayer* editor )
		:Layer("ScriptingWindow") , m_Editor(editor) 
	{
		m_lua = new ScriptingLua();
		
	}


	void ScriptingWindow::OnAttach()
	{
			std::function<void()> scriptWindow = [&]() {
				
				ImGui::Begin("ScriptingWindow");
				
				
				static char text[1024 * 30] = ">>\n";


				if(ImGui::Button("Run")) {
					LOG_WARN("{0}",text);
					m_lua->SetLuaScriptDataString(text);
					m_lua->LuaExec();
					double data = m_lua->GetLuaVariable("x");
					LOG_WARN("Lua data = {0}", data);

				}
				
				
				
			
				
					
					ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 30));
				
			





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