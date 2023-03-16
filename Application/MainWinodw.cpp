#include "MainWindow.h"
#include <iostream>

int REApplication::MainWindow::createWindow()
{
	m_instance = ::GetModuleHandle(nullptr);
	this->registerClass();
	if (!initInstance(SW_SHOW))
		return 1;
	return 0;
}

ATOM REApplication::MainWindow::registerClass()
{
	std::string className = this->getClassName();
	WNDCLASSEXA wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = &REApplication::MainWindow::callback;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_instance;
	wcex.hIcon = LoadIcon(m_instance, nullptr);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = className.c_str();
	wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr);

	return RegisterClassExA(&wcex);
}

BOOL REApplication::MainWindow::initInstance(int nCmdShow)
{
	RECT R = { 0, 0, this->getWidth(), this->getHeight() };
	AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
	int width = R.right - R.left;
	int height = R.bottom - R.top;

	HWND m_RenderWnd = CreateWindowA(
		getClassName().c_str(),
		this->getName().c_str(),
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		width,
		height,
		nullptr,
		nullptr,
		m_instance,
		nullptr
	);

	ShowWindow(m_RenderWnd, SW_SHOW);
	UpdateWindow(m_RenderWnd);
	return TRUE;
}

LRESULT CALLBACK REApplication::MainWindow::callback(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 在此处添加使用 hdc 的任何绘图代码...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void REApplication::MainWindow::loop()
{
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}