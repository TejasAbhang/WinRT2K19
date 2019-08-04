#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("C3App");

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
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	TEXTMETRIC tm;
	//TCHAR str[] = TEXT("भारत माझा देश आहे. सारे भारतीय माझे बांधव आहेत.माझ्या देशावर माझे प्रेम आहे.\nमाझ्या देशातल्या समृद्ध आणि विविधतेने नटलेल्या परंपरांचा मला अभिमान आहे.");
	//TCHAR str1[] = TEXT("\n\nत्या परंपरांचा पाईक होण्याची पात्रता माझ्या अंगी यावी म्हणून मी सदैव प्रयत्न करेन.\nमी माझ्या पालकांचा, गुरुजनांचा आणि वडीलधा-या माणसांचा मान ठेवेन आणि प्रत्येकाशी सौजन्याने वागेन.");
	//TCHAR str2[] = TEXT("\n\n\n\nमाझा देश आणि माझे देशबांधव यांच्याशी निष्ठा राखण्याची मी प्रतिज्ञा करीत आहे.\nत्यांचे कल्याण आणि त्यांची समृद्धी ह्यांतच माझे सौख्य सामावले आहे.");
	TCHAR str[] = TEXT("भारत माझा देश आहे. सारे भारतीय माझे बांधव आहेत.माझ्या देशावर माझे प्रेम आहे.");
	TCHAR str1[] = TEXT("माझ्या देशातल्या समृद्ध आणि विविधतेने नटलेल्या परंपरांचा मला अभिमान आहे.");
	TCHAR str2[] = TEXT("त्या परंपरांचा पाईक होण्याची पात्रता माझ्या अंगी यावी म्हणून मी सदैव प्रयत्न करेन.");
	TCHAR str3[] = TEXT("मी माझ्या पालकांचा, गुरुजनांचा आणि वडीलधा-या माणसांचा मान ठेवेन आणि प्रत्येकाशी सौजन्याने वागेन.");
	TCHAR str4[] = TEXT("माझा देश आणि माझे देशबांधव यांच्याशी निष्ठा राखण्याची मी प्रतिज्ञा करीत आहे.");
	TCHAR str5[] = TEXT("त्यांचे कल्याण आणि त्यांची समृद्धी ह्यांतच माझे सौख्य सामावले आहे.");
	
	int y;
	static int myChar;
	
	switch (iMsg)
	{
	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		GetTextMetrics(hdc, &tm);
		myChar = tm.tmHeight + tm.tmExternalLeading;
		SetTextColor(hdc, RGB(255, 128, 0));
		SetBkColor(hdc, RGB(0, 0, 0));
		y = (rc.bottom - rc.top) / 3;
		
		SetTextAlign(hdc, TA_CENTER);
		
		TextOut(hdc, (rc.right - rc.left) / 2, y, str, lstrlen(str));
		y = y + myChar;

		TextOut(hdc, (rc.right - rc.left) / 2, y, str1, lstrlen(str1));
		y = y + myChar;

		SetTextColor(hdc, RGB(255, 255, 255));
		TextOut(hdc, (rc.right-rc.left)/2, y, str2, lstrlen(str2));
		y = y + myChar;

		TextOut(hdc, (rc.right - rc.left) / 2, y, str3, lstrlen(str3));
		y = y + myChar;

		SetTextColor(hdc, RGB(0, 255, 0));
		TextOut(hdc, (rc.right - rc.left) / 2, y, str4, lstrlen(str4));
		y = y + myChar;

		TextOut(hdc, (rc.right - rc.left) / 2, y, str5, lstrlen(str5));
		y = y + myChar;

		//DrawText(hdc, str, -1, &rc, DT_CENTER | DT_VCENTER);
		//SetTextColor(hdc, RGB(255, 255, 255));
		//DrawText(hdc, str1, -1, &rc, DT_CENTER | DT_VCENTER);
		//SetTextColor(hdc, RGB(0, 255, 0));
		//DrawText(hdc, str2, -1, &rc, DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}













