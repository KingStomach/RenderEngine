#include "ApplicationModule.h"

#ifdef WIN32
#include "WindowApplication.h"
#else
#include "EmptyApplication.h"
#endif

int RenderEngine::ApplicationModule::Initialize()
{
#ifdef WIN32
	m_pApplication = std::make_unique<REApplication::WindowApplication>();
#else
	application = std::make_unique<REApplication::EmptyApplication>();
#endif
	if (m_pApplication && m_pApplication->createWindow())
		return 1;
	else
		return 0;
}


void RenderEngine::ApplicationModule::Finalize()
{
	m_pApplication.release();
}


void RenderEngine::ApplicationModule::Tick()
{
	m_pApplication->render();
}