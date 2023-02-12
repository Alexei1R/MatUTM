#include "mathpch.h"
#include "ScriptingWindow.h"

#include "include/imgui.h"



namespace MatUTM {

	


	

	ScriptingWindow::ScriptingWindow(EditorLayer* editor )
		:Layer("ScriptingWindow") , m_Editor(editor) 
	{

		
	}

	void test(const char * data) {
		py::initialize_interpreter();
		try {
			py::object mainScope = py::module::import("__main__").attr("__dict__");
			py::exec(data,mainScope);
		}
		catch (py::error_already_set const& pythonErr) {
			LOG_CRITICAL("{0}", pythonErr.what());
		}
		py::finalize_interpreter();
	}
	

	void ScriptingWindow::OnAttach()
	{
		std::function<void()> scriptWindow = [&]() {

			ImGui::Begin("ScriptingWindow");
			ImVec2 m_WSize = ImGui::GetWindowSize();
			float m_Button = 33;



			/*ImGui::Columns(2);
			ImGui::SetColumnOffset(1,300)*/
			//ImGui::SameLine(0.0, -1.0);
			ImGui::Spacing();
			/*if(ImGui::BeginCombo("##ScriptCombo", "Internal")) {
				ImGui::EndCombo();
			}; */

			/*ImGui::SameLine();*/
			if (ImGui::Button("Open", ImVec2((m_Button * 2), (m_Button)))) {};
			ImGui::SameLine();
			if (ImGui::Button("Run", ImVec2((m_Button * 2), (m_Button)))) {

				//LOG_INFO("{0}",m_TextEditor.GetText());
				test(m_TextEditor.GetText().c_str());
			};
			ImGui::SameLine();
			if (ImGui::Button("Stop", ImVec2((m_Button * 2), (m_Button)))) {};





			ImGui::Spacing();
			m_TextEditor.SetShowWhitespaces(false);
			m_TextEditor.SetReadOnly(false);
			m_TextEditor.SetPalette(TextEditor::GetDarkPalette());
			m_TextEditor.SetLanguageDefinition(TextEditor::LanguageDefinition::CPlusPlus());

			m_TextEditor.Render("Scripting", ImVec2(m_WSize.x - 18, (m_WSize.y - m_Button) - 50));
				
				

				
				
				
				
			
				
					
				
			





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