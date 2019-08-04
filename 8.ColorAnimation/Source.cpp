#include <Windows.h>
#define timerID 1032

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
	HDC hdc;
	PAINTSTRUCT ps;
	static RECT rc, rc_temp, rc_temp1;
	HBRUSH hbrush;
	static int iPaintFlag;

	switch (iMsg)
	{
	case WM_CREATE:
		SetTimer(hwnd, timerID, 500, NULL);
		iPaintFlag = 0;
		break;

	case WM_TIMER:
		KillTimer(hwnd, timerID);
		iPaintFlag++;
		if (iPaintFlag > 7)
		{
			iPaintFlag = 0;
			InvalidateRect(hwnd, &rc_temp1, true);
		}
		InvalidateRect(hwnd, &rc, true);
		SetTimer(hwnd, timerID, 500, NULL);
		break;

	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		GetClientRect(hwnd, &rc_temp1);
		hdc = BeginPaint(hwnd, &ps);
		switch (iPaintFlag)
		{
		case 0:  //Black
			rc_temp.left = rc.left;
			rc_temp.bottom = rc.bottom;
			rc_temp.right = rc.right/8;
			rc_temp.top = rc.top;
			hbrush = CreateSolidBrush(RGB(192, 192, 192));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc_temp, hbrush);
			break;

		case 1:  //Red
			rc_temp.left = rc_temp.right;
			rc_temp.bottom = rc.bottom;
			rc_temp.right = rc.right / 8 + rc_temp.right;
			rc_temp.top = rc.top;
			hbrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc_temp, hbrush);
			break;

		case 2:  //Green
			rc_temp.left = rc_temp.right;
			rc_temp.bottom = rc.bottom;
			rc_temp.right = rc.right / 8 + rc_temp.right;
			rc_temp.top = rc.top;
			hbrush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc_temp, hbrush);
			break;

		case 3:  //Blue
			rc_temp.left = rc_temp.right;
			rc_temp.bottom = rc.bottom;
			rc_temp.right = rc.right / 8 + rc_temp.right;
			rc_temp.top = rc.top;
			hbrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc_temp, hbrush);
			break;

		case 4:  //Cyan
			rc_temp.left = rc_temp.right;
			rc_temp.bottom = rc.bottom;
			rc_temp.right = rc.right / 8 + rc_temp.right;
			rc_temp.top = rc.top;
			hbrush = CreateSolidBrush(RGB(0, 255, 255));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc_temp, hbrush);
			break;

		case 5:  //Magenta
			rc_temp.left = rc_temp.right;
			rc_temp.bottom = rc.bottom;
			rc_temp.right = rc.right / 8 + rc_temp.right;
			rc_temp.top = rc.top;
			hbrush = CreateSolidBrush(RGB(255, 0, 255));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc_temp, hbrush);
			break;

		case 6:  //Yellow
			rc_temp.left = rc_temp.right;
			rc_temp.bottom = rc.bottom;
			rc_temp.right = rc.right / 8 + rc_temp.right;
			rc_temp.top = rc.top;
			hbrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc_temp, hbrush);
			break;

		case 7:  //White
			rc_temp.left = rc_temp.right;
			rc_temp.bottom = rc.bottom;
			rc_temp.right = rc.right / 8 + rc_temp.right;
			rc_temp.top = rc.top;
			hbrush = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc_temp, hbrush);
			break;
		}
		rc.left = rc_temp.right;
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}









