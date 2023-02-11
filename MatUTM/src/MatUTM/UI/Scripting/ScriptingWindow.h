#pragma once
#include "MathUTM.h"
#include "MatUTM/Core/GUI/EditorLayer.h"
#include "Python.h"
#include "pybind11/pybind11.h"
#include "pybind11/embed.h"

namespace py = pybind11;
namespace MatUTM {


	class ScriptingWindow : public Layer {
	public:
		ScriptingWindow(EditorLayer* editor);


		void OnAttach()override;
		void OnDetach()override;
		void OnUpdate()override;
		void OnImGuiRender() override;


	public:


	private:
		EditorLayer *m_Editor;


		int run_python_code(const char* data) {
			py::scoped_interpreter guard{};
			std::string text = data;
			py::exec(text);
			//py::object add_func = py::globals()["add"];
			return 1;// add_func(1, 2).cast<int>();
		}


	};
}