#pragma once
#include "MathUTM.h"
#include "include/implot.h"

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
		void SetDrawSettings(std::function<void()>& drawData) { m_ImGuiDrawSettingsWindow = drawData; };

	public:

		void SetSettingsFalse() {
			m_Settings = false;
		}


	private:

		std::function<void()> m_ImGuiDrawScriptWindow;
		std::function<void()> m_ImGuiDrawPloterWindow;
		std::function<void()> m_ImGuiDrawSettingsWindow;

		void DrawMenu();





	private:
		bool m_Settings = false;
	};
}