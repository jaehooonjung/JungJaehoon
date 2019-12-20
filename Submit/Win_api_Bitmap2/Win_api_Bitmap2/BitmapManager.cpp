#include "BitmapManager.h"

BitmapManager* BitmapManager::m_hThis = NULL;


BitmapManager::BitmapManager()
{
}

void BitmapManager::BitmapOutput_Name(HDC hdc, HDC *MemDC, HINSTANCE g_hInst, HBITMAP &myBitmap, HBITMAP &oldBitmap, int bitmapname, int x, int y, int width, int height)
{
	*MemDC = CreateCompatibleDC(hdc);
	myBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(bitmapname));
	oldBitmap = (HBITMAP)SelectObject(*MemDC, myBitmap);
	BitBlt(hdc, x, y, width, height, *MemDC, 0, 0, SRCCOPY);
	SelectObject(*MemDC, oldBitmap);
	DeleteObject(myBitmap);
	DeleteDC(*MemDC);
}

BitmapManager::~BitmapManager()
{
	delete BitmapManager::GetInstace();
}
