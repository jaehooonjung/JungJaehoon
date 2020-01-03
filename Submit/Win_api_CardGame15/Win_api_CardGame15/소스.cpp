#include"CardManager.h"
#define PENAITYTIME 1

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("BitMap");
SYSTEMTIME st;
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);
void Gameinit(HWND hWnd, HINSTANCE g_hInst, GAMESTATE& gamestate);
void StartTimeSet();
void TimeIntervalCalculation(int nowmin, int nowsec, int& standardmin, int& standardsec);
void PenaityTimeSet();
bool PenaityCheck();

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

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return (int)Message.wParam;
}

int mouse_x, mouse_y;
GAMESTATE gamestate = GAMESTATE_GAMEOVER;
static TCHAR sTime[128];
CardManager M_CardManager;
int StartMinute;
int StartSecond;
int PenaityTime_Second;
int PenaityTime_Minute;

RECT rt = { 500 , 600 , 600, 650 };
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, MemDC;
	PAINTSTRUCT ps;
	HBITMAP MyBitMap, OldBitMap;
	switch (iMessage)
	{
	case WM_CREATE:
		Gameinit(hWnd, g_hInst, gamestate);
		SetTimer(hWnd, 1, 100, TimeProc);
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;
	case WM_LBUTTONDOWN:
		if (gamestate == GAMESTATE_PAUSE)
			return 0;
		else
		{
			mouse_x = LOWORD(lParam);
			mouse_y = HIWORD(lParam);
			M_CardManager.CardOpen(mouse_x, mouse_y);
			InvalidateRect(hWnd, NULL, TRUE);
			return 0;
		}
	case WM_PAINT:
		Gameinit(hWnd, g_hInst, gamestate);
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 500, 600, sTime, lstrlen(sTime));

		if (gamestate == GAMESTATE_PAUSE)
		{
			if (PenaityCheck() == false)
			{
				EndPaint(hWnd, &ps);
				return 0;
			}
			else
			{
				gamestate = GAMESTATE_PLAYING;
				InvalidateRect(hWnd, NULL, TRUE);
			}
		}
		M_CardManager.CardDrawAll(hdc);
		EndPaint(hWnd, &ps);
		if (M_CardManager.OpenCardCheck(gamestate) == true)
			PenaityTimeSet();
		M_CardManager.ClearCheck(gamestate);

		if (gamestate == GAMESTATE_GAMEOVER)
		{
			if (MessageBox(hWnd, TEXT("계속하시겠습니까?"), TEXT("게임오버"), MB_YESNO) == IDNO)
				exit(1);
		}

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
	int MinTmp = StartMinute, SecTmp = StartSecond;
	TimeIntervalCalculation(st.wMinute, st.wSecond, MinTmp, SecTmp);
	wsprintf(sTime, TEXT("Time : %d  :  %d"), MinTmp, SecTmp);
	InvalidateRect(hWnd, &rt, TRUE);
}

void Gameinit(HWND hWnd, HINSTANCE g_hInst, GAMESTATE& gamestate)
{
	StartTimeSet();
	M_CardManager.CardListSet(hWnd, g_hInst, gamestate);
}

void TimeIntervalCalculation(int nowmin, int nowsec, int& standardmin, int& standardsec)
{
	int MinTmp, SecTmp;
	if (nowmin > standardmin) // 분단위 차이날경우
	{
		if (nowsec >= standardsec)
			MinTmp = nowmin - standardmin;
		else
			MinTmp = nowmin - standardmin - 1;
		if (nowsec < standardsec)
			SecTmp = (nowsec + 60) - standardsec;
		else
			SecTmp = nowsec - standardsec;

		standardmin = MinTmp;
	}
	else if (nowmin == standardmin)
	{
		standardmin = 0;
		SecTmp = nowsec - standardsec;
	}
	standardsec = SecTmp;
}

void StartTimeSet()
{
	if (gamestate != GAMESTATE_GAMEOVER)
		return;
	GetLocalTime(&st);
	StartMinute = st.wMinute;
	StartSecond = st.wSecond;
}

void PenaityTimeSet()
{
	GetLocalTime(&st);
	PenaityTime_Minute = st.wMinute;
	PenaityTime_Second = st.wSecond;
}

bool PenaityCheck()
{
	GetLocalTime(&st);

	int MinTmp, SecTmp;
	int interval = 0;

	if (st.wMinute > PenaityTime_Minute) // 분단위 차이날경우
		interval = (st.wMinute - PenaityTime_Minute) * 60;

	if ((PenaityTime_Second + PENAITYTIME) < (st.wSecond + interval))
		return true;
	else
		return false;

}
