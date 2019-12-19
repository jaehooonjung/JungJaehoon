#include "resource.h"
#include<windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("BitMap");

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

int x, y;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, MemDC;
	PAINTSTRUCT ps;
	HBITMAP myBitmap, oldBitmap;

	switch (iMessage)
	{
	case WM_MOUSEMOVE:
	{		
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		return 0;
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		MemDC = CreateCompatibleDC(hdc);
		myBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		oldBitmap = (HBITMAP)SelectObject(MemDC, myBitmap);
		BitBlt(hdc, 100, 100, 145, 235, MemDC, 0, 0, SRCCOPY);

		myBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));
		oldBitmap = (HBITMAP)SelectObject(MemDC, myBitmap);
		BitBlt(hdc, 250, 100, 145, 235, MemDC, 0, 0, SRCCOPY);

		myBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP3));
		oldBitmap = (HBITMAP)SelectObject(MemDC, myBitmap);
		BitBlt(hdc, 400, 100, 145, 235, MemDC, 0, 0, SRCCOPY);

		myBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP4));
		oldBitmap = (HBITMAP)SelectObject(MemDC, myBitmap);
		BitBlt(hdc, 550, 100, 145, 235, MemDC, 0, 0, SRCCOPY);

		SelectObject(MemDC, oldBitmap);
		DeleteObject(myBitmap);
		DeleteDC(MemDC);

		EndPaint(hWnd, &ps);
		return 0;

	case WM_LBUTTONDOWN:

		if ((x >= 100 && x <= 245) && (y >= 100 && y <= 335))
		{
			MessageBox(hWnd, TEXT("강아지입니다."), TEXT("MessageBox"), MB_OK)  ;
		}
		if ((x >= 250 && x <= 250+145) && (y >= 100 && y <= 335))
		{
			MessageBox(hWnd, TEXT("호랑이입니다."), TEXT("MessageBox"), MB_OK);
		}
		if ((x >= 400 && x <= 400+145) && (y >= 100 && y <= 335))
		{
			MessageBox(hWnd, TEXT("오리입니다."), TEXT("MessageBox"), MB_OK);
		}
		if ((x >= 550 && x <= 550+145) && (y >= 100 && y <= 335))
		{
			MessageBox(hWnd, TEXT("코끼리입니다."), TEXT("MessageBox"), MB_OK);
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
