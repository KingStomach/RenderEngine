#pragma once
#include <thread>
#include "IRuntimeModule.h"
#include "Window.h"

namespace REApplication
{
	class GameApplication : public RenderEngine::IRuntimeModule<GameApplication>
	{
	public:
		GameApplication() : Base() {}
		virtual ~GameApplication() { m_thread.join(); }

		void renderloop();

	private:
		bool initializeImpl();
		void finalizeImpl();

		std::unique_ptr<Window> m_window;
		std::thread m_thread;

		friend class Base;
	};
}