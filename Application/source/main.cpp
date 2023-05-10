#include "RenderApplication.h"
#include "RenderManager.h"

int main(int argc, char** argv)
{
    RenderManager::RenderManager::instance().initialize();
    Application::RenderApplication::instance().initialize();

    auto future =  RenderManager::RenderManager::instance().render();

    Application::RenderApplication::instance().finalize();
    RenderManager::RenderManager::instance().finalize();
    return 0;
}