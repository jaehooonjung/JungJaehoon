#include"Bitmap.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("TransparentBlt");
SYSTEMTIME st;
Bitmap BitmapManager;

void TimeIntervalCalculation(int nowsec,int nowmisec,int & standardsec,int& standardmisec);
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

int StartSec,StartMiSec;
int SecTmp,MiSecTmp;
CHARACTERSTATE CharacterState = CHARACTERSTATE_MOVE;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 1, NULL);
		SendMessage(hWnd, WM_TIMER, 10, 0);
	case WM_TIMER:
		if (CharacterState != CHARACTERSTATE_JUMP)
			return 0;
		GetLocalTime(&st);
		MiSecTmp = StartMiSec;
		SecTmp = StartSec;
		TimeIntervalCalculation(st.wSecond , st.wMilliseconds, SecTmp, MiSecTmp);
		BitmapManager.Jump(hWnd, MiSecTmp);
		InvalidateRect(hWnd, NULL, TRUE);
		if (MiSecTmp >= 950)
			CharacterState = CHARACTERSTATE_MOVE;
		return 0;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
		case VK_RIGHT:
			if (CharacterState == CHARACTERSTATE_JUMP)
				return 0; //점프 중 이동 예외처리 
			BitmapManager.Move(wParam);
			break;
		case VK_SPACE:
			if (CharacterState == CHARACTERSTATE_JUMP)
				return 0; //더블점프 예외처리 
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

void TimeIntervalCalculation(int nowsec, int nowmisec, int & standardsec, int& standardmisec)
{

	if (nowsec >= standardsec)
	{
		standardsec = nowsec - standardsec;
	}
	else
	{
		standardsec = (nowsec + 60) - standardsec;
	}

	if (nowmisec >= standardmisec)
	{
		standardmisec = nowmisec - standardmisec;
	}
	else 
	{
		standardmisec = (nowmisec + 1000) - standardmisec;
	}
}

void SetStartTime()
{
	GetLocalTime(&st);
	StartSec = st.wSecond;
	StartMiSec = st.wMilliseconds;
}