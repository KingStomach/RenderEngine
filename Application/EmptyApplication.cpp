#include "EmptyApplication.h"
#include <iostream>

int REApplication::EmptyApplication::createWindow()
{
	std::cout << "Create empty application" << std::endl;
	return 0;
}


void REApplication::EmptyApplication::destroyWindow()
{
	std::cout << "Destroy empty application" << std::endl;
}

void REApplication::EmptyApplication::render()
{
	std::cout << "Rendering" << std::endl;
}