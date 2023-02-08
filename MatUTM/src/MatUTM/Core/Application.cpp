#include "mathpch.h"
#include "Application.h"



namespace MatUTM {
	Application::Application()
	{
		
		m_Window = new GUI();
		m_EditorLayer = new MatUTM::EditorLayer();
		m_ScriptW = new MatUTM::ScriptingWindow(m_EditorLayer);

		PushLayer(m_Window);
		PushLayer(m_EditorLayer);
		PushLayer(m_ScriptW);
		
	}


	Application::~Application()
	{
	}


	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		//layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		//layer->OnAttach();
	}



	void Application::Run()
	{
		while (!glfwWindowShouldClose(m_Window->GetWindow()))
		{
			m_Window->Update();


			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}
			m_EditorLayer->OnImGuiRender();
			
			ImGui::Begin("TEst");
			ImGui::Text("Renderer Data:");

			ImGui::End();

		



			
			
			m_Window->PoolEvents();
			

		}
	}


}









