#include"Bitmap.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("TransparentBlt");
SYSTEMTIME st;
Bitmap BitmapManager;

void TimeIntervalCalculation(int nowmisec, int& mistandardsec);
void SetStartTime();

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
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

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768,
		NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

enum CHARACTERSTATE
{
	CHARACTERSTATE_MOVE,
	CHARACTERSTATE_JUMP
};

int StartMiSec;
int MiSecTmp;
CHARACTERSTATE CharacterState = CHARACTERSTATE_MOVE;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 100, NULL);
		SendMessage(hWnd, WM_TIMER, 100, 0);
	case WM_TIMER:
		if (CharacterState != CHARACTERSTATE_JUMP)
			return 0;
		GetLocalTime(&st);
		MiSecTmp = StartMiSec;

		TimeIntervalCalculation(st.wMilliseconds, MiSecTmp);
		if (SecTmp == 0)
			return 0;
		BitmapManager.Jump(hWnd, SecTmp);
		InvalidateRect(hWnd, NULL, TRUE);
		if (SecTmp == 6)
			CharacterState = CHARACTERSTATE_MOVE;
		return 0;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
		case VK_RIGHT:
			BitmapManager.Move(wParam);
			break;
		case VK_SPACE:
			CharacterState = CHARACTERSTATE_JUMP;
			SetStartTime();
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		BitmapManager.init(hdc, "image.bmp");
		BitmapManager.Draw(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void TimeIntervalCalculation(int nowmisec, int& mistandardsec)
{
	if (nowmisec >= mistandardsec)
	{
		mistandardsec = nowmisec - mistandardsec;
	}
	else 
	{
		mistandardsec = (nowmisec + 1000) - mistandardsec;
	}
}

void SetStartTime()
{
	GetLocalTime(&st);
	StartMiSec = st.wMilliseconds;
}