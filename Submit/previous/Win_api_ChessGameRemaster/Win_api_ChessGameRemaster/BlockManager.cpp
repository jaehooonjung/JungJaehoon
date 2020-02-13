#include "BlockManager.h"



BlockManager::BlockManager()
{
}

void BlockManager::BlockInit(HDC hdc)
{
	POINT pos;
	pos.x = CHESSBOARDDRAWSTARTPOSX, pos.y = CHESSBOARDDRAWSTARTPOSY;

	for (int j = 0; j < CHESSBOARDHEIGHT; j++)
	{
		for (int i = 0; i < CHESSBOARDWIDTH; i++)
		{
			Block*Tmp = new Block;
			if ((i + j) % 2 == 0)
				Tmp->BlockInit(hdc, BLOCKCOLOR_WHITE, pos);
			else
				Tmp->BlockInit(hdc, BLOCKCOLOR_BLACK, pos);
			pos.x += CHESSBOARDBLOCKSIZE;
			BlockList.push_back(Tmp);
		}
		pos.x = CHESSBOARDDRAWSTARTPOSX;
		pos.y += CHESSBOARDBLOCKSIZE;
	}
}

void BlockManager::BlockDelete()
{
	for (auto iter = BlockList.begin(); iter != BlockList.end(); iter++)
	{
		delete (*iter);
	}
	BlockList.clear();
}

void BlockManager::BlockDraw(HDC hdc)
{
	for (auto iter = BlockList.begin(); iter != BlockList.end(); iter++)
	{
		(*iter)->BlockDraw(hdc);
	}
}

void BlockManager::MarkingBlockInit(HDC hdc)
{
	POINT pos;
	pos.x = NULL;
	pos.y = NULL;
	m_MarkingBlock = new Block;
	m_MarkingBlock->BlockInit(hdc, BLOCKCOLOR_MAKER, pos);
}

void BlockManager::MarkingBlockDraw(HDC hdc, POINT pos)
{
	m_MarkingBlock->BlockPositionChange(pos);
	m_MarkingBlock->BlockDraw(hdc);
}

BlockManager::~BlockManager()
{
	BlockDelete();
}


