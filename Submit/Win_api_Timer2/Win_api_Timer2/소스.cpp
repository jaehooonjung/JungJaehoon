#include<windows.h>
#include<math.h>
#define PI 3.14
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Clock");
SYSTEMTIME st;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);
void ClockDraw(int degree, int length, float &i, float &j);
float DegreeToRadian(float degree);


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

int x = 200;
int y = 200;
float second_x, second_y;
float minute_x, minute_y;
float hour_x, hour_y;

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
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, second_x, second_y);
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
	GetLocalTime(&st);
	ClockDraw(st.wSecond, 80, second_x, second_y);
	ClockDraw(st.wMinute, 50, minute_x, minute_y);
	ClockDraw(st.wHour, 30, hour_x, hour_y);
	InvalidateRect(hWnd, NULL, TRUE);
}

void ClockDraw(int degree, int length, float &i, float &j)
{
	float a, b;
	float Radian = DegreeToRadian((float)degree*6);
	b = sin(Radian) * length;
	a = cos(Radian) * length;

	i = x + a;
	j = y + b;



	/*
		if (degree >= 15 && degree < 30)
	{
		i = x - a;
		j = y + b;
	}
	else if (degree >= 30 && degree < 45)
	{
		i = x - a;
		j = y - b;

	}
	else if (degree >= 45 && degree <  60)
	{
		i = x + a;
		j = y - b;
	}
	else
	{
		i = x + a;
		j = y + b;

	}

	*/

}


float DegreeToRadian(float degree)
{
	return degree*PI/180;
}

