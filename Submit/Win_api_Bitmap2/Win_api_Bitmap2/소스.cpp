#include "resource.h"
#include<windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("BitMap");

class BitmapOutput
{
private:
	HDC m_MemDC;
	HBITMAP m_myBitmap;
	HBITMAP	m_oldBitmap;
private:
	BitmapOutput() {};
	void BitmapOutputAct(HDC hdc, int x, int y, int width, int height, int bitmapname)
	{
		m_MemDC = CreateCompatibleDC(hdc);
		m_myBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(bitmapname));
		m_oldBitmap = (HBITMAP)SelectObject(m_MemDC, m_myBitmap);
		BitBlt(hdc, x, y, width, height, m_MemDC, 0, 0, SRCCOPY);
		SelectObject(m_MemDC, m_oldBitmap);
		DeleteObject(m_myBitmap);
		DeleteDC(m_MemDC);
	}
	~BitmapOutput() {};
};

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
	HDC hdc;
	PAINTSTRUCT ps;
	//HBITMAP myBitmap, oldBitmap;

	switch (iMessage)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		BitmapOutput::BitmapOutputAct(hdc, 100, 100, 145, 235, IDB_BITMAP1);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

