#include "mathpch.h"
#include "ScriptingWindow.h"

#include "include/imgui.h"



namespace MatUTM {

	


	void add(py::module_& m) {
		m.def("add", []() { LOG_WARN("Function called") });
	}

	PYBIND11_MODULE(test, m) {
		add(m);
	}

	ScriptingWindow::ScriptingWindow(EditorLayer* editor )
		:Layer("ScriptingWindow") , m_Editor(editor) 
	{
		
	}

	void test(char * data) {
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
				
				
				

				static char text[1024 * 30] = R"(array = [232,4,254,3,23,2,3,455,3,5,546,6,7,7,8,34,35,67,8,9,2,2,3,4,5,6,7,8]


len = len(array)

for x in array:
  print(x)

print("\n")
print(len))";

				
				

				if(ImGui::Button("Run")) {
					if (text) {
						LOG_INFO("{0}",text);
						std::string res;

						test(text);
						

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