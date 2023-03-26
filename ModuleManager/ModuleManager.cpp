#include "ModuleManager.h"
#include "RenderManager.h"

int REModuleManager::ModuleManger::InitializeImpl()
{
	m_thread = std::thread(&ModuleManger::runThread, this);
	m_state = RenderEngine::MODULE_STATE::LOOPING;
	if (m_render_mamanger.Initialize())
		return 1;
	return 0;
}

void REModuleManager::ModuleManger::FinalizeImpl()
{
	m_render_mamanger.Finalize();
	return;
}

REModuleManager::ModuleManger& REModuleManager::ModuleManger::getInstance()
{
	static ModuleManger manager;
	return manager;
}

void REModuleManager::ModuleManger::TickImpl()
{
	if (m_pipe.empty())
		return;
	MCommand command;
	if (!m_pipe.try_pop(command))
		return;

	return;
}