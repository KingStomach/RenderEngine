#include "ModuleCommand.h"

REModuleManager::ModuleCommand& REModuleManager::ModuleCommand::operator=(const ModuleCommand& command)
{
	//Command<ModuleCommand>::operator=(command); no need to call it now
	auto p = command.Clone();
	m_command.swap(p);
	return *this;
}

void REModuleManager::ModuleCommand::doCommandImpl() const
{
	switch (m_command->getType())
	{
	case RenderEngine::CommandType::MODULE_COMMAND:
		break;
	default:
		break;
	}
	return;
}