#include "AreaManager.h"

AreaManager* AreaManager::m_hThis = NULL;


AreaManager::AreaManager()
{
}

string AreaManager::AreaShapeOutput(int x, int y)
{
	for (auto iter = AreaList.begin(); iter != AreaList.end(); iter++)
	{
		if ((*iter)->X_Pos_Output() == x && (*iter)->Y_Pos_Output() == y)
		{
			return (*iter)->ShapeOutput();

		}
	}

}

void AreaManager::AreaSet(int width, int height)
{
	for (int y = 1; y < height; y++)
	{
		for (int x = 1; x < width; x++)
		{
			Area*Tmp = new Area;
			bool MineFlag;
			if (MineManager::GetInstace()->MineCheck(x, y) == NULL)
				MineFlag = false;
			else
				MineFlag = true;
			Tmp->AreaSet(x, y, MineFlag);
			Tmp->ShapeChage("бс");
			AreaList.push_back(Tmp);
		}
	}
}

string AreaManager::AreaCheck(int x, int y)
{
	for (auto iter = AreaList.begin(); iter != AreaList.end(); iter++)
	{
		if ((*iter)->X_Pos_Output() == x && (*iter)->Y_Pos_Output() == y)
		{
			(*iter)->CheckFlagChange();
			(*iter)->HintSet(MineManager::GetInstace()->FindSurroindingMine(x, y));
			return (*iter)->ShapeOutput();
		}
	}
}

void AreaManager::DeleteAreaAll()
{
	for (auto iter = AreaList.begin(); iter != AreaList.end(); iter++)
	{
		delete(*iter);
	}
	AreaList.clear();

}
				
AreaManager::~AreaManager()
{
}
