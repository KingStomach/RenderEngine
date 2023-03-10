#include "ModuleManager.h"
#include "ApplicationModule.h"

RenderEngine::ModuleManger::ModuleManger()
{
	m_modules.emplace_back(std::make_unique<ApplicationModule>());
}

int RenderEngine::ModuleManger::Initialize()
{
	for (auto it = m_modules.begin(); it != m_modules.end(); ++it)
	{
		if ((*it)->Initialize())
			return 1;
	}
	return 0;
}

void RenderEngine::ModuleManger::Finalize()
{
	for (auto it = m_modules.rbegin(); it != m_modules.rend();++it)
	{
		(*it)->Initialize();
	}
	return;
}

void RenderEngine::ModuleManger::Tick()
{
	for (auto it = m_modules.begin(); it != m_modules.end(); ++it)
	{
		(*it)->Tick();
	}
	return;
}