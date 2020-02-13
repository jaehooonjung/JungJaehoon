#include"Bitmap.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("DubleBuffering");
SYSTEMTIME st;
Bitmap BitmapManager;

void init(HDC hdc, HWND hWnd);
void Draw(HDC hdc);
void Move(HWND hWnd);
void Jump(HWND hWnd);
void SetTime(TimeInfo& timeinfo);
TimeInfo TimeIntervalCalculation(TimeInfo starttime, SYSTEMTIME st);

enum CHARACTERSTATE
{
	CHARACTERSTATE_MOVE,
	CHARACTERSTATE_JUMP
};

enum GAMESTATE
{
	GAMEOVER,
	GAMEINIT,
	GAMEPLAYING
};

CHARACTERSTATE CharaterState;
GAMESTATE GameState;
TimeInfo StartTime;

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 10, NULL);
		SendMessage(hWnd, WM_TIMER, 10, 0);
		CharaterState = CHARACTERSTATE_MOVE;
		GameState = GAMEINIT;
	case WM_TIMER:
		Move(hWnd);
		Jump(hWnd);
		InvalidateRect(hWnd, NULL, false);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		init(hdc, hWnd);
		Draw(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void init(HDC hdc, HWND hWnd)
{
	if (GameState != GAMEINIT)
		return;
	hdc = GetDC(hWnd);
	BitmapManager.init(hdc);
	ReleaseDC(hWnd, hdc);
	GameState = GAMEPLAYING;
}

void Draw(HDC hdc)
{
	if (GameState != GAMEPLAYING)
		return;
	BitmapManager.Draw(hdc);
}

void Move(HWND hWnd)
{
	if (!(GameState == GAMEPLAYING && CharaterState == CHARACTERSTATE_MOVE))
		return;
	BitmapManager.Move(hWnd);
}

void Jump(HWND hWnd)
{
	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (CharaterState == CHARACTERSTATE_JUMP) //더블점프 예외처리
			return;
		CharaterState = CHARACTERSTATE_JUMP;
		SetTime(StartTime); //점프시작시간 설정
		BitmapManager.JumpLineSet(); //점프직전 y좌표를 저장
	}

	if (CharaterState == CHARACTERSTATE_JUMP)
	{
		if(BitmapManager.Jump(hWnd, TimeIntervalCalculation(StartTime, st)) == true)
			CharaterState = CHARACTERSTATE_MOVE;
	}
}

void SetTime(TimeInfo& timeinfo)
{
	GetLocalTime(&st);
	timeinfo.MiSecond = st.wMilliseconds;
	timeinfo.Second = st.wSecond;
}

TimeInfo TimeIntervalCalculation(TimeInfo starttime, SYSTEMTIME st)
{
	TimeInfo IntervalTime;
	GetLocalTime(&st);
		if (st.wSecond >= starttime.Second)
		IntervalTime.Second = st.wSecond - starttime.Second;
	else
		IntervalTime.Second = (st.wSecond + 60) - starttime.Second;

	if (st.wMilliseconds >= starttime.MiSecond)
		IntervalTime.MiSecond = st.wMilliseconds - starttime.MiSecond;
	else
		IntervalTime.MiSecond = (st.wMilliseconds + 1000) - starttime.MiSecond;

	return IntervalTime;
}
