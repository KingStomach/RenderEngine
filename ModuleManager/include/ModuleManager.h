#pragma once
#include "IRuntimeModule.h"
#include <memory>
#include <vector>

namespace RenderEngine
{
	class ModuleManger : public IRuntimeModule
	{
	public:
		ModuleManger();
		virtual ~ModuleManger() {};

		virtual int Initialize();
		virtual void Finalize();
		virtual void Tick();

	private:
		std::vector<std::unique_ptr<IRuntimeModule>> m_modules;
	};
};