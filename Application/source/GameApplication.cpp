#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GameApplication.h"

bool REApplication::GameApplication::initializeImpl()
{
	if (!Window::initWindow())
		return false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // 配置主版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // 配置次版本号
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 使用核心模式

	m_window = std::make_unique<Window>();
	if (!m_window)
		return false;

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return false;
	glViewport(0, 0, 800, 600);
	return true;
}

void REApplication::GameApplication::finalizeImpl()
{
	glfwTerminate();
}

void REApplication::GameApplication::renderloop()
{
	while (!m_window->close())
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // 设置清空屏幕所用的颜色
		glClear(GL_COLOR_BUFFER_BIT); // 清除颜色缓冲之后，整个颜色缓冲都会被填充为glClearColor里所设置的颜色
		m_window->update();
	}
}