#include <iostream>
#include "MainWindow.h"

int main(int argc, char** argv) {
    const std::string name("RenderEngine");
    int width = 1024, height = 768;
    REApplication::MainWindow window(name, width, height);
    window.createWindow();
    return window.loop();
}