#pragma once
#include "ICommand.h"

namespace RERenderManager
{
	class RenderCommand : public RenderEngine::Command<RenderCommand>
	{
	public:
		RenderCommand() : BaseCommand(RenderEngine::CommandType::RENDER_COMMAND) {};

		void doCommandImpl() const {};//todo
		std::unique_ptr<ICommand> CloneImpl() const
		{
			return std::make_unique<RenderCommand>();
		}

	private:
		friend RenderEngine::Command<RenderCommand>;
	};

}