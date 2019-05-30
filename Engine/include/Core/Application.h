#pragma once

namespace JM 
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Initialize() = 0;
		virtual void Run() = 0;
		virtual void Shutdown() = 0;
	};

	Application* CreateApplication();
}