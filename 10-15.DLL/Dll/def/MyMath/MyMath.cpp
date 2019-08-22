#include <Windows.h>

extern "C" BOOL IsNumberNegative(int num);

BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}

extern "C" INT MakeSquare(int num)	//declspec:: Declaration Specific
{
	if (IsNumberNegative(num))
		return 0;
	else
		return (num * num);
}

extern "C" BOOL IsNumberNegative(int num)
{
	if (num < 0)
		return TRUE;
	else
		return FALSE;
}








