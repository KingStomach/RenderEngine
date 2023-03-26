#pragma once
#include "ICommand.h"
#include <concepts>
#include <memory>

namespace REModuleManager
{
	class ModuleCommand : public RenderEngine::Command<ModuleCommand>
	{
	public:
		ModuleCommand() : BaseCommand(RenderEngine::CommandType::MODULE_COMMAND), m_command(nullptr) {};
		template <class T>
		requires std::derived_from<T, ICommand>
		ModuleCommand(const T& command) : Command<ModuleCommand>(RenderEngine::CommandType::MODULE_COMMAND), m_command(std::make_unique<T>(command)) {};
		/* call Copy Constructor and Copy Assignment Operator as little as possible */
		ModuleCommand(const ModuleCommand& command) : Command<ModuleCommand>(command), m_command(command.m_command->Clone()) {};
		ModuleCommand& operator=(const ModuleCommand& command);

	private:
		std::unique_ptr<RenderEngine::ICommand> m_command;
		

		void doCommandImpl() const;
		std::unique_ptr<ICommand> CloneImpl() const
		{
			auto p = std::make_unique<ModuleCommand>();
			p->m_command = m_command->Clone();
			return p;
		}

		friend class RenderEngine::Command<ModuleCommand>;
	};
}