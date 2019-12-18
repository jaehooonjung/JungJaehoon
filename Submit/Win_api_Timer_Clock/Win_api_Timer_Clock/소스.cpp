#include<windows.h>
#include<math.h>
#define PI 3.14
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Clock");
SYSTEMTIME st;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);
void ClockSet();
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

int x = 200;
int y = 200;
float second_x, second_y, second_r = 100;
float minute_x, minute_y, minute_r = 70;
float hour_x, hour_y, hour_r = 40;


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
	ClockSet();
	InvalidateRect(hWnd, NULL, TRUE);
}

void ClockSet()
{
	GetLocalTime(&st);
	float Radian;

	//초 설정
	Radian = DegreeToRadian((st.wSecond*6.00));
	second_x = x + second_r * cos(Radian - PI / 2);
	second_y = y + second_r * sin(Radian - PI / 2);
	//분 설정
	Radian = DegreeToRadian((st.wMinute*6.00));
	minute_x = x + second_r * cos(Radian - PI / 2);
	minute_y = y + second_r * sin(Radian - PI / 2);
	//시 설정
	Radian = DegreeToRadian((st.wHour*30.00));
	hour_x = x + hour_r * cos(Radian - PI / 2);
	hour_y = y + hour_r * sin(Radian - PI / 2);
}


float DegreeToRadian(int degree)
{
	return (PI * (float)degree/180);
}

