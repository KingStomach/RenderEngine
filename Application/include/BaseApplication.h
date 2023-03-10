#pragma once
#include "IRuntimeModule.h"
#include <string>

namespace REApplication
{
	class BaseApplication
	{
	public:
		BaseApplication() : m_width(0), m_height(0) {};
		BaseApplication(const std::string& name, int width, int height) :m_windowName(name), m_width(width), m_height(height) {};
		virtual ~BaseApplication() {};
		virtual int createWindow() = 0;
		virtual void destroyWindow() = 0;
		virtual void render() = 0;

		GET_AND_SET_METHOD(std::string, Name, m_windowName);
		GET_AND_SET_METHOD(int, Width, m_width);
		GET_AND_SET_METHOD(int, Height, m_height);

	private:
		std::string m_windowName;
		int m_width;
		int m_height;
	};
}