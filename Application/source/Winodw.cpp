#include "Window.h"
#include <iostream>

REApplication::WindowsWindow::WindowsWindow(const WindwoConfig& config) : Base(config)
{
	m_window = glfwCreateWindow(config.width, config.height, this->getName().c_str(), nullptr, nullptr);
	render_engine_assert(!m_window);
	glfwMakeContextCurrent(m_window);
	this->SetVSync(true);
}

void REApplication::WindowsWindow::updateImpl()
{
	glfwPollEvents();
	glfwSwapBuffers(m_window);
}