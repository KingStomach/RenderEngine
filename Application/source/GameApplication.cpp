#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GameApplication.h"

bool REApplication::GameApplication::initializeImpl()
{
	if (!Window::initWindow())
		return false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // �������汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // ���ôΰ汾��
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // ʹ�ú���ģʽ

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
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // ���������Ļ���õ���ɫ
		glClear(GL_COLOR_BUFFER_BIT); // �����ɫ����֮��������ɫ���嶼�ᱻ���ΪglClearColor�������õ���ɫ
		m_window->update();
	}
}