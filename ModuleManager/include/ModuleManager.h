#pragma once
#include "IRuntimeModule.h"
#include "ModuleCommand.h"
#include "RenderManager.h"

MATCH_MODULE_AND_COMMAND(REModuleManager, ModuleManger, ModuleCommand)

namespace REModuleManager
{
	class ModuleManger : public RenderEngine::IRuntimeModule<ModuleManger, ModuleCommand>
	{
	public:
		constexpr ModuleManger() : IRuntimeModule<ModuleManger, ModuleCommand>() {};
		virtual ~ModuleManger() {};
		static ModuleManger& getInstance();

	private:
		RERenderManager::RenderManager m_render_mamanger;

		int InitializeImpl();
		void FinalizeImpl();
		void TickImpl();

		friend class IRuntimeModule<ModuleManger, ModuleCommand>;
	};

};