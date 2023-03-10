#include "WindowApplication.h"
#include <iostream>

int REApplication::WindowApplication::createWindow()
{
	std::cout << "Create windows application" << std::endl;
	m_instance = ::GetModuleHandle(nullptr);
	this->registerClass();
	if (!initInstance(SW_SHOW))
		return 1;
	return 0;
}


void REApplication::WindowApplication::destroyWindow()
{
	std::cout << "Destroy windows application" << std::endl;
}

void REApplication::WindowApplication::render()
{
	MSG msg;
	if (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

ATOM REApplication::WindowApplication::registerClass()
{
	WNDCLASSEXA wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = &REApplication::WindowApplication::callback;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_instance;
	wcex.hIcon = LoadIcon(m_instance, nullptr);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = "this->getName().c_str()";
	wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr);

	return RegisterClassExA(&wcex);
}

LRESULT CALLBACK REApplication::WindowApplication::callback(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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

BOOL REApplication::WindowApplication::initInstance(int nCmdShow)
{
	RECT R = { 0, 0, this->getWidth(), this->getWidth()};
	AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
	int width = R.right - R.left;
	int height = R.bottom - R.top;

	m_RenderWnd = CreateWindowA(
		"this->getName().c_str()",
		"title",
		WS_OVERLAPPEDWINDOW,
		1000,
		300,
		width,
		height,
		nullptr,
		nullptr,
		m_instance,
		nullptr
	);

	if (!m_RenderWnd)
	{
		MessageBox(0, "CreateWindow Failed.", 0, 0);
		return FALSE;
	}

	ShowWindow(m_RenderWnd, SW_SHOW);
	UpdateWindow(m_RenderWnd);

	return TRUE;
}