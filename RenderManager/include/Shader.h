#pragma once
#include <glad/glad.h>
#include <optional>
#include <string>
#include "Interface.h"

namespace RenderManager
{
	enum class ShaderType
	{
		VERTEX_SHADER = GL_VERTEX_SHADER,
		FRAGMENT_SHADER = GL_FRAGMENT_SHADER
	};

	class Shader
	{
	public:
		Shader(ShaderType type, const std::string& data) : m_index(glCreateShader((GLuint)type)), m_data(data) {}
		~Shader() { glDeleteShader(m_index); }
		void compile() const;
		std::optional<std::string> error() const;

		GET_METHOD(GLuint, Index, m_index)
	private:
		GLuint m_index;
		std::string m_data;
	};

	class Program
	{
	public:
		Program() : m_index(glCreateProgram()) {}
		~Program() { glDeleteProgram(m_index); }
		void attach(const Shader& shader) const { glAttachShader(m_index, shader.getIndex()); }
		void link() const { glLinkProgram(m_index); }
		void use() const { glUseProgram(m_index); }
		std::optional<std::string> error() const;
	private:
		GLuint m_index;
	};
}