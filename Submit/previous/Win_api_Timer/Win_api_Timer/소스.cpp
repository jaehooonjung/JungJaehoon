#include<windows.h>
#include<time.h>
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("BallMove");
void CircleMove();
void MoveDirectionChage(DIRECTION flag);

enum DIRECTION
{
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_TOPLEFT,
	DIRECTION_TOPRIGHT,
	DIRECTION_LEFTDOWN,
	DIRECTION_RIGHTDOWN
};

DIRECTION DirectionFlag = DIRECTION_LEFT;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

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
RECT rt = { 100 ,100, 300,400 };


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	SYSTEMTIME st;
	static TCHAR sTime[128];
	srand(time(NULL));
	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 100, TimeProc);
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Rectangle(hdc, 100, 100, 300, 400);
		Ellipse(hdc, x-50, y-50, x + 50, y + 50);
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
		CircleMove();
		InvalidateRect(hWnd, NULL, TRUE);
}



void MoveDirectionChage(DIRECTION flag)
{
		int randTmp;
		switch (flag)
		{
		case DIRECTION_LEFT:
			switch (rand() % 3)
			{
			case 0:
				DirectionFlag = DIRECTION_RIGHT;
				break;
			case 1:
				DirectionFlag = DIRECTION_TOPRIGHT;
				break;
			case 2:
				DirectionFlag = DIRECTION_RIGHTDOWN;
				break;
			}
			break;
		case DIRECTION_RIGHT:
			switch (rand() % 3)
			{
			case 0:
				DirectionFlag = DIRECTION_LEFT;
				break;
			case 1:
				DirectionFlag = DIRECTION_LEFTDOWN;
				break;
			case 2:
				DirectionFlag = DIRECTION_TOPLEFT;
				break;
			}
			break;
		case DIRECTION_UP:
			switch (rand() % 3)
			{
			case 0:
				DirectionFlag = DIRECTION_DOWN;
				break;
			case 1:
				DirectionFlag = DIRECTION_LEFTDOWN;
				break;
			case 2:
				DirectionFlag = DIRECTION_RIGHTDOWN;
				break;
			}
			break;
		case DIRECTION_DOWN:
			switch (rand() % 3)
			{
			case 0:
				DirectionFlag = DIRECTION_UP;
				break;
			case 1:
				DirectionFlag = DIRECTION_TOPLEFT;
				break;
			case 2:
				DirectionFlag = DIRECTION_TOPRIGHT;
					break;
			}
			break;
		}
}

void CircleMove()
{
	if ((x - 50) <= rt.left)
		MoveDirectionChage(DIRECTION_LEFT);
	else if((x + 50) >= rt.right)
		MoveDirectionChage(DIRECTION_RIGHT);
	else if ((y - 50) <= rt.top)
		MoveDirectionChage(DIRECTION_UP);
	else if (((y + 50) >= rt.bottom))
		MoveDirectionChage(DIRECTION_DOWN);


	switch (DirectionFlag)
	{
	case DIRECTION_LEFT:
		x -= 7;
		break;
	case DIRECTION_RIGHT:
		x += 7;
		break;
	case DIRECTION_UP:
		y -= 7;
		break;
	case DIRECTION_DOWN:
		y += 7;
		break;
	case DIRECTION_TOPLEFT:
		x -= 3;
		y -= 3;
		break;
	case DIRECTION_TOPRIGHT:
		x += 3;
		y -= 3;
		break;
	case DIRECTION_LEFTDOWN:
		x -= 3;
		y += 3;
		break;
	case DIRECTION_RIGHTDOWN:
		x += 3;
		y += 3;
		break;
	}
}



