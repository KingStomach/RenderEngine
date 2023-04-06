#include "Application/include/GameApplication.h"

int main(int argc, char** argv)
{
    REApplication::GameApplication::instance().initialize();
    REApplication::GameApplication::instance().renderloop();
    REApplication::GameApplication::instance().finalize();
    return 0;
}