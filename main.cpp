#include <iostream>
#include "ModuleManager.h"

using namespace RenderEngine;

int main(int argc, char** argv) {
    ModuleManger manager;
    if (manager.Initialize())
    {
        std::cout << "Fail initialize application" << std::endl;
    }

    while (true)
    {
        manager.Tick();
    }

    manager.Finalize();

    return 0;
}