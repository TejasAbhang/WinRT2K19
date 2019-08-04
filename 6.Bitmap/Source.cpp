#include <Windows.h>
#include "Header.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("C3Cafe");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_HAND);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(
		szAppName,
		TEXT("C3 Cafe"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, cdc;
	BITMAP bmp;
	static HBITMAP hbmp;
	RECT rc;
	static HINSTANCE hinstance;
	PAINTSTRUCT ps;

	switch (iMsg)
	{
	case WM_CREATE:
		hinstance = GetModuleHandle(NULL);
		break;

	case WM_PAINT:
		hbmp = LoadBitmap(hinstance, MAKEINTRESOURCE(MYBITMAP));
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		cdc = CreateCompatibleDC(hdc);
		SelectObject(cdc, hbmp);
		GetObject(hbmp, sizeof(BITMAP), &bmp);
		StretchBlt(hdc, 0, 0, rc.right - rc.left, rc.bottom - rc.top, cdc, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);
		DeleteDC(cdc);
		DeleteObject(hbmp);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}




