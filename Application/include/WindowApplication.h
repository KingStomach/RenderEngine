#pragma once
#include "BaseApplication.h"

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
	};
};