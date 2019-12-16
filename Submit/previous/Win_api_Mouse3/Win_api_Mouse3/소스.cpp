#include<windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Input_Mouse");

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

bool leftin = false;
bool rightin = false;

int x;
int y;
int realX = 0;
int realY = 0;
bool flag;

RECT rect = { 200, 200 , 300 , 400 };
bool ShapeFlag = false;
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;


	switch (iMessage)
	{
	case WM_MOUSEMOVE:
		flag = true;
		x = LOWORD(lParam);
		y = HIWORD(lParam);

		if (x < rect.left)
			leftin = true;

		if (x > rect.right)
			rightin = true;

		if (x <= rect.right && x > rect.right)
			x = rect.right;
		else if (x >= rect.left && x < rect.right)
			x = rect.left;

		InvalidateRect(hWnd, NULL, TRUE);

		return 0;
	case WM_LBUTTONDOWN:
		if (MessageBox(hWnd, TEXT("모양바꾸기"), TEXT("MessageBox"), MB_OK) == IDOK)
		{
			if (ShapeFlag == true)
				ShapeFlag = false;
			else
				ShapeFlag = true;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		//if (flag == true)
		//{
			if (ShapeFlag == false)
				Ellipse(hdc, x - 50, y - 50, x + 50, y + 50);
			else
				Rectangle(hdc, x - 50, y - 50, x + 50, y + 50);

		//}
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

