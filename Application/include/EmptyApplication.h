#pragma once
#include "BaseApplication.h"

namespace REApplication
{
	class EmptyApplication : public BaseApplication
	{
	public:
		EmptyApplication() {};
		EmptyApplication(const std::string& name, int width, int height) : BaseApplication(name, width, height) {};
		virtual ~EmptyApplication() {};
		virtual int createWindow();
		virtual void destroyWindow();
		virtual void render();
	};
};