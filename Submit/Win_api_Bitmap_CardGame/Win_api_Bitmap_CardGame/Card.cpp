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

void Card::CardInfoSet(int CardPosition_x, int CardPosition_y)
{
	m_iCardPosition_x = CardPosition_x;
	m_iCardPosition_y = CardPosition_y;
	m_bOpenFlag = false;
	m_bClearFlag = false;
}

void Card::CardDraw(HDC hdc)
{
	BitBlt(hdc, m_iCardPosition_x, m_iCardPosition_y, m_size.cx*200, m_size.cy*250 , m_MemDC, 0, 0, SRCCOPY);
}

void Card::CardOpenFlagChange()
{
	if (m_bOpenFlag == false)
		m_bOpenFlag = true;
	else
		m_bOpenFlag = false;

}

Card::~Card()
{
}
