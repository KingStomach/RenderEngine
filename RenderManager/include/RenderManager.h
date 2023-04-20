#pragma once
#include "IRuntimeModule.h"
#include "RenderTask.h"

namespace RenderManager
{
	class RenderManager : public RenderEngine::IRuntimeModule<RenderManager>
	{
	public:
		RenderManager() : Base() {}
		~RenderManager() {}

		auto render() { return m_task->run(); }

	private:
		bool initializeImpl();
		void finalizeImpl();

		std::unique_ptr<RenderTask> m_task;
		std::unique_ptr<WindowsWindow> m_window;

		friend class Base;
	};
}