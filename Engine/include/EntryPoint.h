#pragma once

extern JM::Application* JM::CreateApplication();

int main()
{
	auto app = JM::CreateApplication();

	app->Initialize();

	app->Run();

	app->Shutdown();

	delete app;

	return 0;
}