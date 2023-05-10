#pragma once
#include "ILoopingTask.h"
#include "RenderBuffer.h"
#include "Shader.h"
#include "Window.h"

namespace RenderManager
{
	class RenderTask : public RenderEngine::ILoopingTask<RenderTask>
	{
	public:
		RenderTask(const Window& window) : Base(), m_window(window) {}
		~RenderTask();

	private:
		void startImpl();
		void updateImpl();

		unsigned int shaderProgram;
		unsigned int VBO, VAO, EBO;
		const Window& m_window;

		friend class Base;
	};
}