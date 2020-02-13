#include "Block.h"

Block::Block()
{
}

void Block::BlockInit(HDC hdc, BLOCKCOLOR blockcolor, POINT pos)
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
	BlockPositionChange(pos);
}

void Block::BlockDraw(HDC hdc)
{
	TransparentBlt(hdc, m_BlockPos.x, m_BlockPos.y, CHESSBOARDBLOCKSIZE, CHESSBOARDBLOCKSIZE, m_MemDC, 0, 0, m_size.cx, m_size.cy, RGB(255, 0, 255));
}

void Block::BlockPositionChange(POINT pos)
{
	m_BlockPos.x = pos.x;
	m_BlockPos.y = pos.y;
}

Block::~Block()
{
}
