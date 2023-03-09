#include "WindowApplication.h"
#include <iostream>

int REApplication::WindowApplication::createWindow()
{
	std::cout << "Create windows application" << std::endl;
	return 0;
}


void REApplication::WindowApplication::destroyWindow()
{
	std::cout << "Destroy windows application" << std::endl;
}

void REApplication::WindowApplication::render()
{
	std::cout << "Rendering" << std::endl;
}