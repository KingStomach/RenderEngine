#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "RenderManager.h"

bool RenderManager::RenderManager::initializeImpl()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = std::make_unique<Window>();
	m_task = std::make_unique<RenderTask>(*m_window.get());
	return true;
}

void RenderManager::RenderManager::finalizeImpl()
{

}