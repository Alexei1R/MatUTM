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

		void SetDrawDataImGui(std::function<void()>& drawData) { m_ImGuiDraw = drawData; };

	public:


	private:

		std::function<void()> m_ImGuiDraw;


	};
}