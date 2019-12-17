#include<windows.h>
#include<math.h>
#define PI 3.14
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Clock");
SYSTEMTIME st;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);
void PosSet();
float DegreeToRadian(int degree);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

int x = 100;
int y = 100;
float second_x, second_y, minute_x, minute_y, hour_x, hour_y;


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static TCHAR sTime[128];
	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 100, TimeProc);
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc,second_x, second_y);
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, minute_x, minute_y);
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, hour_x, hour_y);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	PosSet();
	InvalidateRect(hWnd, NULL, TRUE);
}

void PosSet()
{
	GetLocalTime(&st);
	second_x = cos(DegreeToRadian(st.wSecond * 6)) * 100;
	second_y = sin(DegreeToRadian(st.wSecond*6))*100;
	minute_x = cos(DegreeToRadian(st.wMinute * 6)) * 60;
	minute_y = sin(DegreeToRadian(st.wMinute * 6)) * 60; 
	hour_x = cos(DegreeToRadian(st.wHour * 30)) * 20;
	hour_y = sin(DegreeToRadian(st.wHour * 30)) * 20;

	if ((st.wHour >= 0 && st.wHour < 3) || (st.wHour >= 12 && st.wHour < 15))
	{

	}
	else if ((st.wHour >= 3 && st.wHour < 6) || (st.wHour > 15 && st.wHour < 18))
	{
		
	}
	else if ((st.wHour >= 9 && st.wHour < 12) || (st.wHour > 18 && st.wHour < 21))
	{
		hour_y = -hour_y;
	}

	if ((st.wMinute >= 0 && st.wMinute < 3) || (st.wMinute >= 12 && st.wMinute < 15))
	{

	}
	else if ((st.wMinute >= 3 && st.wHour < 6) || (st.wMinute > 15 && st.wMinute < 18))
	{

	}
	else if ((st.wMinute >= 9 && st.wMinute < 12) || (st.wMinute > 18 && st.wMinute < 21))
	{
		minute_y = -minute_y;
	}
			
	second_x += x;
	second_y += y;
	minute_x += x;
	minute_y += y;
	hour_x += x;
	hour_y += y;

}			 

float DegreeToRadian(int degree)
{
	return (PI * (float)degree/180);
}

/*if (st.wSecond >= 15 && st.wSecond < 30)
{
	second_x += x;
	second_y += y;

}
else if (st.wSecond >= 15 && st.wSecond < 30)
{

}
else if (st.wSecond >= 15 && st.wSecond < 30)
{

}
else
{
	second_x += x;
	second_y += y;
}
if (st.wSecond >= 15 && st.wSecond < 30)
{
	second_x += x;
	second_y += y;

}
else if (st.wSecond >= 15 && st.wSecond < 30)
{

}
else if (st.wSecond >= 15 && st.wSecond < 30)
{

}
else
{
	second_x += x;
	second_y += y;
}
   */