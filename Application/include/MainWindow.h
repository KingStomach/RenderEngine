#pragma once
#include <Windows.h>
#include <string>
#include "Interface.h"

namespace REApplication
{
	class MainWindow
	{
	public:
		explicit MainWindow(const std::string& name, int width, int height) :m_windowName(name), m_width(width), m_height(height), m_instance(0) {};
		virtual ~MainWindow() {};
		int createWindow();
		void loop();

		GET_AND_SET_METHOD(std::string, Name, m_windowName);
		GET_AND_SET_METHOD(int, Width, m_width);
		GET_AND_SET_METHOD(int, Height, m_height);

	private:
		ATOM registerClass();
		BOOL initInstance(int nCmdShow);
		static LRESULT CALLBACK callback(HWND, UINT, WPARAM, LPARAM);
		GET_CLASS_NAME(MainWindow);

		std::string m_windowName;
		int m_width;
		int m_height;
		HINSTANCE m_instance;
	};
}