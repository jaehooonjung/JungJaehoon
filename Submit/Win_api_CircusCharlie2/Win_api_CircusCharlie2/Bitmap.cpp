#include "Bitmap.h"

Bitmap::Bitmap()
{
}

void Bitmap::Init(HDC hdc, LPCTSTR bitmapname, POINT pos)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_phImage = (HBITMAP)LoadImage(NULL, bitmapname, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_phOldBitmap = (HBITMAP)SelectObject(m_MemDC, m_phImage);

	BITMAP bitmap;
	GetObject(m_phImage, sizeof(BITMAP), &bitmap);
	m_Size.cx = bitmap.bmWidth;
	m_Size.cy = bitmap.bmHeight;
	PosChange(pos);
	m_strBitmapName = bitmapname;
}

void Bitmap::PosChange(POINT pos)
{
	m_BitmapPos.x = pos.x;
	m_BitmapPos.y = pos.y;
}

void Bitmap::Draw(HDC hdc)
{
	TransparentBlt(hdc, m_BitmapPos.x, m_BitmapPos.y, m_Size.cx, m_Size.cy, m_MemDC, 0, 0, m_Size.cx, m_Size.cy, RGB(255, 0, 255));
}

Bitmap::~Bitmap()
{
}


CharacterBitmap::CharacterBitmap()
{

}

void CharacterBitmap::Init(HDC hdc, LPCTSTR backgroundbitmapname, LPCTSTR bitmapname, POINT startpos, POINT endpos)
{
	m_MemDC[0] = CreateCompatibleDC(hdc);
	m_phImage[0] = CreateCompatibleBitmap(hdc, 1024, 768);
	m_phOldBitmap[0] = (HBITMAP)SelectObject(m_MemDC[0], m_phImage[0]);


	m_MemDC[1] = CreateCompatibleDC(m_MemDC[0]);
	m_phImage[1] = (HBITMAP)LoadImage(NULL, backgroundbitmapname, IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_phOldBitmap[1] = (HBITMAP)SelectObject(m_MemDC[1], m_phImage[1]);

	m_MemDC[2] = CreateCompatibleDC(m_MemDC[0]);
	m_phImage[2] = (HBITMAP)LoadImage(NULL, bitmapname, IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_phOldBitmap[2] = (HBITMAP)SelectObject(m_MemDC[2], m_phImage[2]);

	BITMAP bitmaptmp;
	GetObject(m_phImage[2], sizeof(BITMAP), &bitmaptmp);
	m_Size.cx = bitmaptmp.bmWidth;
	m_Size.cy = bitmaptmp.bmHeight;
	PosChange(startpos);
	DefaultPosChange(startpos, endpos);
	m_strBitmapName = bitmapname;

}

void CharacterBitmap::Draw(HDC hdc)
{
	BitBlt(m_MemDC[0], 0, 0, 1024, 768, m_MemDC[1], 0, 0, SRCCOPY);
	TransparentBlt(m_MemDC[0], m_BitmapPos.x, m_BitmapPos.y, m_Size.cx, m_Size.cy, m_MemDC[2], 0, 0, m_Size.cx, m_Size.cy, RGB(255, 0, 255));
	TransparentBlt(hdc, m_BitmapPos.x, m_BitmapPos.y, m_Size.cx, m_Size.cy, m_MemDC[0], 0, 0, m_Size.cx, m_Size.cy, RGB(255, 0, 255));

}

void CharacterBitmap::Move(int keyflag)
{
	switch (keyflag)
	{
	case VK_LEFT:
		m_BitmapPos.x -= MOVE_DISTANCE;
		break;
	case VK_RIGHT:
		m_BitmapPos.x += MOVE_DISTANCE;
		break;
	}
	if (m_BitmapPos.x == -(m_Size.cx))
		m_BitmapPos.x = m_BitmapStartPos.x;
	if (m_BitmapPos.x > m_BitmapEndPos.x)
		m_BitmapPos.x = -m_Size.cx;
}

void CharacterBitmap::DefaultPosChange(POINT startpos, POINT endpos)
{
	m_BitmapStartPos.x = startpos.x;
	m_BitmapStartPos.y = startpos.y;
	m_BitmapEndPos.x = endpos.x;
	m_BitmapEndPos.y = endpos.y;
}



CharacterBitmap::~CharacterBitmap()
{

}


