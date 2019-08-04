#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("C3CafeApp");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_HAND);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

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
		NULL);

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
	HBRUSH hbrush;
	HDC hdc;
	PAINTSTRUCT ps;
	static RECT rc;

	static int iPaintFlag;

	switch (iMsg)
	{
	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		switch (iPaintFlag)
		{
		case 0:
			hbrush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;

		case 1:
			hbrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;

		case 2:
			hbrush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;

		case 3:
			hbrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;

		case 4:
			hbrush = CreateSolidBrush(RGB(0, 255, 255));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;

		case 5:
			hbrush = CreateSolidBrush(RGB(255, 0, 255));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;

		case 6:
			hbrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;

		case 7:
			hbrush = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;
		}
		EndPaint(hwnd, &ps);
		break;

	case WM_CHAR:
		switch (LOWORD(wParam))
		{
		case 'R':
		case 'r':
			iPaintFlag = 1;
			InvalidateRect(hwnd, &rc, true);
			break;

		case 'G':
		case 'g':
			iPaintFlag = 2;
			InvalidateRect(hwnd, &rc, true);
			break;

		case 'B':
		case 'b':
			iPaintFlag = 3;
			InvalidateRect(hwnd, &rc, true);
			break;

		case 'C':
		case 'c':
			iPaintFlag = 4;
			InvalidateRect(hwnd, &rc, true);
			break;

		case 'M':
		case 'm':
			iPaintFlag = 5;
			InvalidateRect(hwnd, &rc, true);
			break;

		case 'Y':
		case 'y':
			iPaintFlag = 6;
			InvalidateRect(hwnd, &rc, true);
			break;

		case 'W':
		case 'w':
			iPaintFlag = 7;
			InvalidateRect(hwnd, &rc, true);
			break;

		default:
			iPaintFlag = 0;
			InvalidateRect(hwnd, &rc, true);
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}



