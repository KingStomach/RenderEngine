#pragma once
#include "IRuntimeModule.h"

namespace Application
{
	class RenderApplication : public RenderEngine::IRuntimeModule<RenderApplication>
	{
	public:
		RenderApplication() : Base() {}
		~RenderApplication() {}

	private:
		bool initializeImpl();
		void finalizeImpl();

		friend class Base;
	};
}