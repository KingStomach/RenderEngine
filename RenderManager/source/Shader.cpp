#include "Shader.h"

void RenderManager::Shader::compile() const
{
	auto p_data = m_data.c_str();
	glShaderSource(m_index, 1, &p_data, NULL);
	glCompileShader(m_index);
}

std::optional<std::string> RenderManager::Shader::error() const
{
	int success;
	char infoLog[512];
	glGetShaderiv(m_index, GL_COMPILE_STATUS, &success);
	if (success)
		return std::nullopt;
	glGetShaderInfoLog(m_index, 512, nullptr, infoLog);
	return std::string(infoLog);
}

std::optional<std::string> RenderManager::Program::error() const
{
	int success;
	char infoLog[512];
	glGetProgramiv(m_index, GL_COMPILE_STATUS, &success);
	if (success)
		return std::nullopt;
	glGetProgramInfoLog(m_index, 512, nullptr, infoLog);
	return std::string(infoLog);
}