#include "AreaManager.h"

AreaManager* AreaManager::m_hThis = NULL;

AreaManager::AreaManager()
{
}

void AreaManager::AreaSet()
{
	AreaList.reserve(WIDTH_DEFUALT*HEIGHT_DEFUALT);
	for (size_t i = 0; i < length; i++)
	{

	}
	for (int i = 0; i <= AreaList.capacity(); i++)
	{
		Area*Tmp = new Area;
		Tmp->m_ix = 
		TmpList->m_MineFlag = AREASTATE_MINE_CLEAR;
		TmpList->m_CheckFlag = AREASTATE_CHECK_NO;
		AreaList.push_back(TmpList);
	}


	for (int y = 1; y < (height - 1); y++)
	{
		for (int x = 1; x < (width - 1); x++)
		{
			Area*Tmp = new Area;
			bool MineFlag;
			if (MineManager::GetInstace()->MineCheck(x, y) == NULL)
				MineFlag = false;
			else
				MineFlag = true;
			Tmp->AreaSet(x, y, MineFlag);
			Tmp->ShapeChage("бс");
		}
	}
}

string AreaShapeOutput(int x, int y);
void AreaCheck(int x, int y, int width, int height);
bool CheckFlagCheck(int width, int height);
void DeleteAreaAll();


AreaManager::~AreaManager()
{
}
