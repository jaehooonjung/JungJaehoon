#include <windows.h>
#pragma comment(lib, "msimg32.lib")
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("TransparentBlt");

#define CHARACTER_X_POSDEFAULT 300
#define CHARACTER_Y_POSDEFAULT 350

void Init(HDC hdc, HDC hMemDC, HBITMAP hImage, HBITMAP hOldBitmap, int &bx, int &by);
void Move(int direction);

enum CHARACTERMOTION
{
	CHARACTERMOTION_BOTTOM,
	CHARACTERMOTION_TOP,
	CHARACTERMOTION_LEFT,
	CHARACTERMOTION_RIGHT
};
enum CHARACTERMOTION_BOTTOM
{
	CHARACTERMOTION_BOTTOM_1,
	CHARACTERMOTION_BOTTOM_2,
	CHARACTERMOTION_BOTTOM_3,
	CHARACTERMOTION_BOTTOM_4
};
enum CHARACTERMOTION_TOP
{
	CHARACTERMOTION_TOP_1,
	CHARACTERMOTION_TOP_2,
	CHARACTERMOTION_TOP_3,
	CHARACTERMOTION_TOP_4
};
enum CHARACTERMOTION_LEFT
{
	CHARACTERMOTION_LEFT_1,
	CHARACTERMOTION_LEFT_2,
	CHARACTERMOTION_LEFT_3,
	CHARACTERMOTION_LEFT_4
};
enum CHARACTERMOTION_RIGHT
{
	CHARACTERMOTION_RIGHT_1,
	CHARACTERMOTION_RIGHT_2,
	CHARACTERMOTION_RIGHT_3,
	CHARACTERMOTION_RIGHT_4
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
int CharacterDirection = CHARACTERMOTION_BOTTOM, CharacterMotion = CHARACTERMOTION_BOTTOM_1;
HDC hMemDC;
HBITMAP hImage, hOldBitmap;


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	int bx, by;

	switch (iMessage)
	{
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_LEFT:
			CharacterPos_x -= 10;
			Move(wParam);
			break;
		case VK_RIGHT:
			CharacterPos_x += 10;
			Move(wParam);
			break;

		case VK_UP:
			CharacterPos_y -= 10;
			Move(wParam);
			break;

		case VK_DOWN:
			CharacterPos_y += 10;
			Move(wParam);
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Init(hdc, hMemDC, hImage, hOldBitmap, bx, by);
		TransparentBlt(hdc, CharacterPos_x, CharacterPos_y, bx / 4, by / 4,hMemDC, (bx / 4) * CharacterMotion, (by / 4) * CharacterDirection, bx / 4, by / 4, RGB(255, 0, 255));
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		SelectObject(hMemDC, hOldBitmap);
		DeleteObject(hImage);
		DeleteDC(hMemDC);
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
		if (CharacterMotion == 4)
			CharacterMotion = CHARACTERMOTION_LEFT_1;
		break;
	case VK_RIGHT:
		CharacterDirection = CHARACTERMOTION_RIGHT;
		CharacterMotion++;
		if (CharacterMotion == 4)
			CharacterMotion = CHARACTERMOTION_RIGHT_1;
		break;
	case VK_UP:
		CharacterDirection = CHARACTERMOTION_TOP;
		CharacterMotion++;
		if (CharacterMotion == 4)
			CharacterMotion = CHARACTERMOTION_TOP_1;
		break;
	case VK_DOWN:
		CharacterDirection = CHARACTERMOTION_BOTTOM;
		CharacterMotion++;
		if (CharacterMotion == 4)
			CharacterMotion = CHARACTERMOTION_BOTTOM_1;
		break;
	}
}

void Init(HDC hdc, HDC hMemDC, HBITMAP hImage, HBITMAP hOldBitmap, int &bx,int &by)
{
	BITMAP bitmap;
	hMemDC = CreateCompatibleDC(hdc);
	hImage = (HBITMAP)LoadImage(NULL, TEXT("image.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	GetObject(hImage, sizeof(BITMAP), &bitmap);
	bx = bitmap.bmWidth;
	by = bitmap.bmHeight;
}