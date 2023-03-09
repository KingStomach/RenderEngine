#pragma once
#include "IRuntimeModule.h"
#include <string>

namespace REApplication
{
	class BaseApplication
	{
	public:
		BaseApplication() {};
		BaseApplication(const std::string& name, int width, int height) :m_windowName(name), m_width(width), m_height(height) {};
		virtual ~BaseApplication() {};
		virtual int createWindow() = 0;
		virtual void destroyWindow() = 0;
		virtual void render() = 0;

	private:
		std::string m_windowName;
		int m_width;
		int m_height;
	};
}