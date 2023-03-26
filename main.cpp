#include <iostream>
#include "MainWindow.h"
#include "ModuleManager.h"

int main(int argc, char** argv) {
    const std::string name("RenderEngine");
    int width = 1024, height = 768;
    REApplication::MainWindow window(name, width, height);
    window.createWindow();
    REModuleManager::ModuleManger::getInstance().Initialize();
    window.loop();
    REModuleManager::ModuleManger::getInstance().Finalize();
    return 0;
}