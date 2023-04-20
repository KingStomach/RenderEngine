#include "Window.h"
#include <iostream>

RenderManager::WindowsWindow::WindowsWindow(const WindwoConfig& config) : Base(config), m_window(nullptr)
{
	m_window = glfwCreateWindow(config.width, config.height, this->getName().c_str(), nullptr, nullptr);
	render_engine_assert(!m_window);
	this->SetVSync(true);
}