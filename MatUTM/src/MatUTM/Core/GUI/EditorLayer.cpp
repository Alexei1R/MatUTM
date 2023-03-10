#include "mathpch.h"
#include "EditorLayer.h"





namespace MatUTM {


	EditorLayer::EditorLayer()
		:Layer("EditorLayer")
	{
	}


	void EditorLayer::OnAttach()
	{
	}
	void EditorLayer::OnDetach()
	{
	}
	void EditorLayer::OnUpdate()
	{
	}
	void EditorLayer::OnImGuiRender()
	{

		// Note: Switch this to true to enable dockspace
		static bool dockingEnabled = true;
		if (dockingEnabled) {
			static bool dockspaceOpen = true;
			static bool opt_fullscreen_persistant = true;
			bool opt_fullscreen = opt_fullscreen_persistant;
			static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

			// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
			// because it would be confusing to have two docking targets within each others.
			ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
			if (opt_fullscreen)
			{
				ImGuiViewport* viewport = ImGui::GetMainViewport();
				ImGui::SetNextWindowPos(viewport->Pos);
				ImGui::SetNextWindowSize(viewport->Size);
				ImGui::SetNextWindowViewport(viewport->ID);
				ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
				ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
				window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
				window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
			}

			// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
			if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
				window_flags |= ImGuiWindowFlags_NoBackground;

			// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
			// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive, 
			// all active windows docked into it will lose their parent and become undocked.
			// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise 
			// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
			ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
			ImGui::PopStyleVar();

			if (opt_fullscreen)
				ImGui::PopStyleVar(2);

			// DockSpace
			ImGuiIO& io = ImGui::GetIO();
			if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
			{
				ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
				ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
			}

			ImGuiStyle* style = &ImGui::GetStyle();
			style->Colors[ImGuiCol_Button] = ImColor(23, 38, 37,100);
			style->Colors[ImGuiCol_ButtonActive] = ImColor(36, 66, 64);
			style->Colors[ImGuiCol_ButtonHovered] = ImColor(31, 54, 52);

			DrawMenu();

			//ImGui::Begin("Settings");
			//ImGui::Text("Renderer Data:");
			//ImGui::End();


			//bool show = false;
			//ImGui::ShowDemoWindow(&show);
			


			if (m_ImGuiDrawScriptWindow)
			{
				m_ImGuiDrawScriptWindow();
			}


			if (m_ImGuiDrawPloterWindow)
			{
				m_ImGuiDrawPloterWindow();
			}

			if (m_ImGuiDrawSettingsWindow && m_Settings)
			{
				m_ImGuiDrawSettingsWindow();
			}


			ImGui::End();

		}
	}






	void MatUTM::EditorLayer::DrawMenu() {



		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{


				if (ImGui::MenuItem("Open Fille"))
				{
					LOG_CRITICAL("Open Fille");
				};
				if (ImGui::MenuItem("Exit")) LOG_CRITICAL("Close");
				ImGui::EndMenu();
			}


			if (ImGui::BeginMenu("Settings"))
			{
				if (ImGui::MenuItem("Open Settings"))
				{
					m_Settings = true;
					LOG_CRITICAL("Settings Open")
				};
				ImGui::EndMenu();
			}


			if (ImGui::BeginMenu("Script"))
			{
				if (ImGui::MenuItem("New Script", "Ctrl+Shift+n")) {
					LOG_CRITICAL("New Script");
				};

				if (ImGui::MenuItem("Save Script", "Ctrl+Shift+n")) {
					LOG_CRITICAL("Save Script");
				};
				

				ImGui::EndMenu();
			}



			ImGui::EndMenuBar();
		}
	}
	




}