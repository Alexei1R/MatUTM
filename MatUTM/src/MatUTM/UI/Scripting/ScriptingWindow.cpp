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
			std::function<void()> scriptWindow = [&]() {
				
				ImGui::Begin("ScriptingWindow");
				
				
				

				static char text[1024 * 30] = "";


				

				if(ImGui::Button("Run")) {
					if (text) {
						LOG_CRITICAL("{0}",text);
						std::string res;

						try
						{
							res = run_python_code(text);
						}
						catch (const std::exception&)
						{

						}

						LOG_WARN("{0}", res);
					}

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