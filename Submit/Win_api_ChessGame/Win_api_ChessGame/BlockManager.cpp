#include "BlockManager.h"



BlockManager::BlockManager()
{
}

void BlockManager::BlockInit(HDC hdc)
{
	int x = CHESSBOARDDRAWSTARTPOSX, y = CHESSBOARDDRAWSTARTPOSY;

	for (int j = 0; j < CHESSBOARDHEIGHT; j++)
	{
		for (int i = 0; i < CHESSBOARDWIDTH; i++)
		{
			Block*Tmp = new Block;
			if ((i+j)%2 == 0)
				Tmp->BlockInit(hdc, BLOCKCOLOR_WHITE, x, y);
			else
				Tmp->BlockInit(hdc, BLOCKCOLOR_BLACK, x, y);
			x += CHESSBOARDBLOCKSIZE;
			BlockList.push_back(Tmp);
		}
		y += CHESSBOARDBLOCKSIZE;
		x = CHESSBOARDDRAWSTARTPOSX;
	}
	
	Block*MarkingBlock = new Block;
	MarkingBlock->BlockInit(hdc, BLOCKCOLOR_MAKER, 0, 0);
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

BlockManager::~BlockManager()
{
	BlockDelete();
}


