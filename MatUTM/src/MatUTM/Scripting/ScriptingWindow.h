#pragma once
#include "MathUTM.h"
#include "MatUTM/Core/GUI/EditorLayer.h"

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
		


	};
}