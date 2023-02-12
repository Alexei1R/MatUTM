#pragma once
#include "MathUTM.h"
#include "MatUTM/Core/GUI/EditorLayer.h"
#include "Python.h"
#include "pybind11/pybind11.h"
#include "pybind11/embed.h"
#include "TextEditor.h"

namespace MatUTM {

	namespace py = pybind11;


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
		TextEditor m_TextEditor;

		


	};
}