#pragma once
#include "MathUTM.h"

namespace MatUTM {
	class EditorLayer : public Layer {
	public:
		EditorLayer();


		virtual void OnAttach()override;
		virtual void OnDetach()override;
		virtual void OnUpdate()override;
		virtual void OnImGuiRender() override;

		void SetDrawScripting(std::function<void()>& drawData) { m_ImGuiDrawScriptWindow = drawData; };
		void SetDrawPloter(std::function<void()>& drawData) { m_ImGuiDrawPloterWindow = drawData; };

	public:


	private:

		std::function<void()> m_ImGuiDrawScriptWindow;
		std::function<void()> m_ImGuiDrawPloterWindow;

		void DrawMenu();
	};
}