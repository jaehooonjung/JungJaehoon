#include "Block.h"

Block::Block()
{
}

void Block::BlockInit(HDC hdc, BLOCKCOLOR blockcolor, int x, int y)
{
	m_BlockColor = blockcolor;
	m_MemDC = CreateCompatibleDC(hdc);
	switch (m_BlockColor)
	{
	case BLOCKCOLOR_WHITE:
		m_phImage = (HBITMAP)LoadImage(NULL, TEXT("block00.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		break;
	case BLOCKCOLOR_BLACK:
		m_phImage = (HBITMAP)LoadImage(NULL, TEXT("block01.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		break;
	case BLOCKCOLOR_MAKER:
		m_phImage = (HBITMAP)LoadImage(NULL, TEXT("block02.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		break;
	}
	m_phOldBitmap = (HBITMAP)SelectObject(m_MemDC, m_phImage);
	BITMAP bitmap;
	GetObject(m_phImage, sizeof(BITMAP), &bitmap);
	m_size.cx = bitmap.bmWidth;
	m_size.cy = bitmap.bmHeight;
	m_BlockPos.Position_x = x;
	m_BlockPos.Position_y = y;
}

void Block::BlockDraw(HDC hdc)
{
	TransparentBlt(hdc, m_BlockPos.Position_x, m_BlockPos.Position_y, CHESSBOARDBLOCKSIZE, CHESSBOARDBLOCKSIZE, m_MemDC, 0,0, m_size.cx, m_size.cy, RGB(255, 0, 255));
}

Block::~Block()
{
}
