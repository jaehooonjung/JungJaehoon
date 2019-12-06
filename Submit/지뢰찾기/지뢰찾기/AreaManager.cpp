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
			Tmp->ShapeChage("��");
			AreaList.push_back(Tmp);
		}
	}
}

void AreaManager::AreaCheck(int x, int y)
{
	for (auto iter = AreaList.begin(); iter != AreaList.end(); iter++)
	{
		if ((*iter)->X_Pos_Output() == x && (*iter)->Y_Pos_Output() == y)
		{
			(*iter)->CheckFlagChange();
			int MineNumTmp = MineManager::GetInstace()->FindSurroindingMine(x, y);
			(*iter)->HintSet(MineNumTmp);
			m_MapDraw.DrawPoint((*iter)->ShapeOutput(), x, y);
			if (MineNumTmp == 0)
			{
				for (int i = (y - 1); i <= (y + 1); i++)
				{
					for (int j = (x - 1); j <= (x + 1); j++)
					{
						AreaCheck(i, j);
					}
				}
			}
			return;
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
