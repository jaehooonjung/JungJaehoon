#include "Card.h"

Card::Card()
{
}

void Card::init(HDC hdc, HINSTANCE hInst, int bitmapname)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_pBitMap = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(bitmapname));
	m_pBitOld = (HBITMAP)SelectObject(m_MemDC, m_pBitMap);
	BITMAP BitMap_Info;
	GetObject(m_pBitOld, sizeof(BitMap_Info), &BitMap_Info);
	m_size.cx = BitMap_Info.bmWidth;
	m_size.cy = BitMap_Info.bmHeight;
	m_iBitmapName = bitmapname;
}

void Card::CardInfoSet(int start_x, int start_y)
{
	m_iStart_x = start_x;
	m_iStart_y = start_y;
	m_bOpenFlag = false;
	m_bClearFlag = false;
}

void Card::CardDraw(HDC hdc, int x, int y, int rate_x, int rate_y)
{
	StretchBlt(hdc, x, y, m_size.cx * rate_x, m_size.cy * rate_y, m_MemDC, 0, 0, m_size.cx, m_size.cy, SRCCOPY);
}


Card::~Card()
{
}
