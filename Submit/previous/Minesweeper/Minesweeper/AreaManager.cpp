#include "AreaManager.h"

AreaManager* AreaManager::m_hThis = NULL;

AreaManager::AreaManager()
{
}

void AreaManager::AreaSet()
{
	AreaList.reserve(WIDTH_DEFUALT*HEIGHT_DEFUALT);
	
	for (int y = 0; y <= HEIGHT_DEFUALT; y++)
	{
		for (int x = 0; x <= WIDTH_DEFUALT; x++)
		{
			Area*Tmp = new Area;
			Tmp->m_ix = x;
			Tmp->m_iy = y;
			if( x==0 || x == WIDTH_DEFUALT )
			Tmp->m_strShape = "бс";
			Tmp->m_MineFlag = AREASTATE_MINE_CLEAR;
			Tmp->m_CheckFlag = AREASTATE_CHECK_NO;
			AreaList.push_back(Tmp);
		}
	}
	int MinePosition_X_tmp;
	int MinePosition_Y_tmp;
	for (int i = 0; i <= AreaList.capacity()*MINE_CREATE_RATE; i++)
	{
		MinePosition_X_tmp = rand() % (width - 1);
		MinePosition_Y_tmp = rand() % (height - 1);

	}

}

string AreaShapeOutput(int x, int y);
void AreaCheck(int x, int y, int width, int height);
bool CheckFlagCheck(int width, int height);
void DeleteAreaAll();


AreaManager::~AreaManager()
{
}
