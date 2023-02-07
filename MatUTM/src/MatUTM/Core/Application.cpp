#include "mathpch.h"
#include "Application.h"



namespace MatUTM {
	Application* Application::s_Instance = nullptr;
	Application::Application()
	{
		s_Instance = (Application*)this;
		
		m_Window = new GUI();
		m_EditorLayer = new MatUTM::EditorLayer();
		
		PushOverlay(m_EditorLayer);
		PushOverlay(m_Window);
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
			





			m_Window->PoolEvents();
			

		}
	}


}









