#pragma comment(lib, "msimg32.lib")
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("TransparentBlt");

#define CHARACTER_X_POSDEFAULT 300
#define CHARACTER_Y_POSDEFAULT 350
#define JUMP_DISTANCE 1
#define MOVE_DISTANCE 10

void Move(int direction);
void Jump(int direction,HWND hWnd);
float DegreeToRadian(int degree);

enum CHARACTERMOTION
{
	CHARACTERMOTION_BOTTOM = 0,
	CHARACTERMOTION_LEFT = 2,
	CHARACTERMOTION_RIGHT
};

enum CHARACTERMOTION_LEFT
{
	CHARACTERMOTION_LEFT_1,
	CHARACTERMOTION_LEFT_2,
	CHARACTERMOTION_LEFT_3,
	CHARACTERMOTION_LEFT_4,
	CHARACTERMOTION_LEFT_END

};

enum CHARACTERMOTION_RIGHT
{
	CHARACTERMOTION_RIGHT_1,
	CHARACTERMOTION_RIGHT_2,
	CHARACTERMOTION_RIGHT_3,
	CHARACTERMOTION_RIGHT_4,
	CHARACTERMOTION_RIGHT_END

};

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

int CharacterPos_x = CHARACTER_X_POSDEFAULT;
int CharacterPos_y = CHARACTER_Y_POSDEFAULT;
int CharacterDirection = CHARACTERMOTION_BOTTOM, CharacterMotion = CHARACTERMOTION_BOTTOM;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HDC hMemDC;
	HBITMAP hImage, hOldBitmap;
	BITMAP bitmap;
	int bx, by;

	switch (iMessage)
	{
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_LEFT:
			CharacterPos_x -= MOVE_DISTANCE;
			Move(wParam);
			break;
		case VK_RIGHT:
			CharacterPos_x += MOVE_DISTANCE;
			Move(wParam);
			break;
		case VK_SPACE:
			switch (CharacterDirection)
			{
			case CHARACTERMOTION_BOTTOM:
				break;
			case CHARACTERMOTION_LEFT:
				Jump(CHARACTERMOTION_LEFT, hWnd);
				break;
			case CHARACTERMOTION_RIGHT:
				Jump(CHARACTERMOTION_RIGHT, hWnd);
			}
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		hMemDC = CreateCompatibleDC(hdc);
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
		GetObject(hImage, sizeof(BITMAP), &bitmap);
		bx = bitmap.bmWidth;
		by = bitmap.bmHeight; 
		TransparentBlt(hdc, CharacterPos_x, CharacterPos_y, bx / 4, by / 4,hMemDC, (bx / 4) * CharacterMotion, (by / 4) * CharacterDirection, bx / 4, by / 4, RGB(255, 0, 255));
		SelectObject(hMemDC, hOldBitmap);
		DeleteObject(hImage);
		DeleteDC(hMemDC);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void Move(int direction)
{
	switch (direction)
	{
	case VK_LEFT:
		CharacterDirection = CHARACTERMOTION_LEFT;
		CharacterMotion++;
		if (CharacterMotion == CHARACTERMOTION_LEFT_END)
			CharacterMotion = CHARACTERMOTION_LEFT_1;
		break;
	case VK_RIGHT:
		CharacterDirection = CHARACTERMOTION_RIGHT;
		CharacterMotion++;
		if (CharacterMotion == CHARACTERMOTION_RIGHT_END)
			CharacterMotion = CHARACTERMOTION_RIGHT_1;
		break;
	}
}

void Jump(int direction, HWND hWnd)
{
	float Radian;
<<<<<<< HEAD
	for (int i = 0; i <= 270; i+=90)
=======
	for (int i = 0; i <= 180; i++)
>>>>>>> e809c88bef0b764c6615d91478e57142c97bfe0a
	{
		Radian = DegreeToRadian(i);
		if (CharacterDirection == CHARACTERMOTION_LEFT)
		{
<<<<<<< HEAD
			CharacterPos_x -= (JUMP_DISTANCE / 4);
			CharacterPos_y -= JUMP_DISTANCE * sin(Radian);
=======
			CharacterPos_x -= JUMP_DISTANCE * cos(Radian - M_PI);
			CharacterPos_y += JUMP_DISTANCE * sin(Radian - M_PI);
>>>>>>> e809c88bef0b764c6615d91478e57142c97bfe0a
			CharacterMotion++;
			if (CharacterMotion == CHARACTERMOTION_LEFT_END)
				CharacterMotion = CHARACTERMOTION_LEFT_1;

		}
		if (CharacterDirection == CHARACTERMOTION_RIGHT)
		{
<<<<<<< HEAD
			CharacterPos_x -= (JUMP_DISTANCE / 4);
			CharacterPos_y -= JUMP_DISTANCE * sin(Radian - M_PI / 2);
=======
			CharacterPos_x += JUMP_DISTANCE;
			CharacterPos_y -= JUMP_DISTANCE * sin(Radian);
>>>>>>> e809c88bef0b764c6615d91478e57142c97bfe0a
			CharacterMotion++;
			if (CharacterMotion == CHARACTERMOTION_RIGHT_END)
				CharacterMotion = CHARACTERMOTION_RIGHT_1;

		}
		InvalidateRect(hWnd, NULL, FALSE);
	}
}

float DegreeToRadian(int degree)
{
	return (M_PI * (float)degree / 180);
}