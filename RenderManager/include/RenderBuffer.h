#pragma once
#include <glad/glad.h>
#include <concepts>
#include <vector>
#include "Interface.h"

namespace RenderManager
{
	template <class T, class Derived>
	class RenderBuffer
	{
	public:
		RenderBuffer(const T* data, size_t n) : m_data(data, data + n) { glGenBuffers(1, &m_index); }
		virtual ~RenderBuffer() { glDeleteBuffers(1, &m_index); }
		void bind() const { static_cast<const Derived*>(this)->bindImpl(); }

		GET_METHOD(GLuint, Index, m_index)
		GET_METHOD(std::vector<T>, Data, m_data)

	private:
		GLuint m_index;
		std::vector<T> m_data;
	};

	template <class T, GLint Dimension>
	requires (Dimension > 0) && std::floating_point<T> && std::_Not_same_as<T, long double>
	class VBO : public RenderBuffer<T, VBO<T, Dimension>>
	{
	public:
		VBO(const T* data, size_t n) : RenderBuffer<T, VBO<T, Dimension>>(data, n) {}
		virtual ~VBO() {}
		void unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

	private:
		void bindImpl() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, this->getIndex());
			glBufferData(GL_ARRAY_BUFFER, this->getData().size() * sizeof(T), this->getData().data(), GL_STATIC_DRAW);
			constexpr GLenum type = std::is_same<T, float>::value ? GL_FLOAT : GL_DOUBLE;
			glVertexAttribPointer(0, Dimension, type, GL_FALSE, Dimension * sizeof(T), (void*)0);
			glEnableVertexAttribArray(0);
		}

		friend class RenderBuffer<T, VBO<T, Dimension>>;
	};

	template <class T>
	class VAO
	{
	public:
		VAO() { glGenVertexArrays(1, &m_index); }
		~VAO() { glDeleteVertexArrays(1, &m_index); }
		void bind(bool value) const { glBindVertexArray(value ? m_index : 0); }
	private:
		GLuint m_index;
	};

	template <class T>
	requires std::unsigned_integral<T>
	class EBO : public RenderBuffer<T, EBO<T>>
	{
	public:
		EBO(const T* data, size_t n) : RenderBuffer<T, EBO<T>>(data, n) {}
	private:
		void bindImpl() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->getIndex());
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->getData().size() * sizeof(T), this->getData().data(), GL_STATIC_DRAW);
		}

	friend class RenderBuffer<T, EBO<T>>;
	};

}