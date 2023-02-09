#include "MathUTM.h"


#pragma once
#include "MathUTM.h"
#include "MatUTM/Core/GUI/EditorLayer.h"

namespace MatUTM {


	class SettingsWindow : public Layer {
	public:
		SettingsWindow(EditorLayer* editor);


		void OnAttach()override;
		void OnDetach()override;
		void OnUpdate()override;
		void OnImGuiRender() override;


	public:


	private:
		EditorLayer* m_Editor;






	};
}