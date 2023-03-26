#pragma once
#include "IRuntimeModule.h"
#include "RenderCommand.h"

MATCH_MODULE_AND_COMMAND(RERenderManager, RenderManager, RenderCommand)

namespace RERenderManager
{
	class RenderManager : public RenderEngine::IRuntimeModule<RenderManager, RenderCommand>
	{
	public:
		constexpr RenderManager() : IRuntimeModule<RenderManager, RenderCommand>() {};
		virtual ~RenderManager() {};

	private:
		int InitializeImpl();
		void FinalizeImpl();
		void TickImpl();

		friend class IRuntimeModule<RenderManager, RenderCommand>;
	};

}