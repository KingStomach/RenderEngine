#pragma once
#include "Interface.h"
#include <memory>
#include <string>
#include <GLFW/glfw3.h>

#ifdef WIN32
#define Window WindowsWindow
#endif

namespace REApplication
{
	struct WindwoConfig
	{
		unsigned int width;
		unsigned int height;
		std::string windowName;

		WindwoConfig(std::string name = "RenderEngine", unsigned int width = 1024, unsigned int height = 768)
			: width(width), height(height), windowName(name) {};
	};

	template <class Derived>
	class IWindow
	{
	public:
		explicit IWindow(const WindwoConfig& config = WindwoConfig())
			: m_windowName(config.windowName) {}
		virtual ~IWindow() {}

		GET_AND_SET_METHOD(std::string, Name, m_windowName)

		void update() { static_cast<Derived*>(this)->updateImpl(); }
		bool close() { return static_cast<Derived*>(this)->closeImpl(); }
		void SetVSync(bool option) { static_cast<Derived*>(this)->SetVSyncImpl(option); }

	protected:
		using Base = IWindow<Derived>;

	private:
		std::string m_windowName;
	};

	class WindowsWindow : public IWindow<WindowsWindow>
	{
	public:
		explicit WindowsWindow(const WindwoConfig& config = WindwoConfig());
		virtual ~WindowsWindow() { glfwDestroyWindow(m_window); }

		static WindowsWindow createWindow(const WindwoConfig& config = WindwoConfig()) { return WindowsWindow(config); }
		static int initWindow() { return glfwInit(); }

		explicit operator bool() const { return m_window; }

	private:
		GLFWwindow* m_window;

		void updateImpl();
		bool closeImpl() { return glfwWindowShouldClose(m_window); }
		void SetVSyncImpl(bool option) { glfwSwapInterval(option); }

		friend class Base;
	};
}