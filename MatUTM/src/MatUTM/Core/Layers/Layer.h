#pragma once
#include "mathpch.h"


namespace MatUTM {
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		

		inline const std::string& GetName() const { return m_Name; }
	protected:
		std::string m_Name;
	};

}