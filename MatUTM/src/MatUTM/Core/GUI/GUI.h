#pragma once
#include "MatUTM/Core/Layers/Layer.h"
#include "GLFW/glfw3.h"
#include "MathUTM.h"



namespace MatUTM {
	class GUI : public Layer
	{
	public:
		GUI();
		~GUI() = default;

		void OnAttach() override;
		void OnDetach() override;



		void Begin();
		void End();
		void Update();
		void PoolEvents();
		
		void SetDarkThemeColors();

		inline GLFWwindow* GetWindow() { return window; }

	private:
		void init();

		std::string name = "MatUTM";
		int m_width = 1080;
		int m_height = 720;
		GLFWwindow* window;

		
	};
}
