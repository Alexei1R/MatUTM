#include "mathpch.h"
#include "Application.h"
#include "pybind11/pybind11.h"



namespace MatUTM {
	Application::Application()
	{
		pybind11::initialize_interpreter();
		m_Window = new GUI();
		m_EditorLayer = new MatUTM::EditorLayer();
		m_ScriptW = new MatUTM::ScriptingWindow(m_EditorLayer);
		m_PloterW = new MatUTM::PloterWindow(m_EditorLayer);
		m_SettingsW = new MatUTM::SettingsWindow(m_EditorLayer);

		PushLayer(m_Window);
		PushLayer(m_EditorLayer);
		PushLayer(m_ScriptW);
		PushLayer(m_PloterW);
		PushLayer(m_SettingsW);
		
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









