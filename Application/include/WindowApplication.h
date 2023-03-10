#pragma once
#include "BaseApplication.h"
#include <Windows.h>

namespace REApplication
{
	class WindowApplication : public BaseApplication
	{
	public:
		WindowApplication() {};
		WindowApplication(const std::string& name, int width, int height) : BaseApplication(name, width, height) {};
		virtual ~WindowApplication() {};
		virtual int createWindow();
		virtual void destroyWindow();
		virtual void render();

	private:
		HINSTANCE m_instance;
		HWND m_RenderWnd;
		ATOM registerClass();
		static LRESULT CALLBACK callback(HWND, UINT, WPARAM, LPARAM);
		BOOL initInstance(int nCmdShow);
	};
};
