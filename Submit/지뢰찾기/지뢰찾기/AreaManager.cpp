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
			return (*iter)->ShapeOutput();
	}
}

void AreaManager::AreaSet(int width, int height)
{
	for (int y = 1; y < (height-1); y++)
	{
		for (int x = 1; x < (width-1); x++)
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

void AreaManager::AreaCheck(int x, int y, int width, int height)
{
	for (auto iter = AreaList.begin(); iter != AreaList.end(); iter++)
	{
		if ((*iter)->X_Pos_Output() == x && (*iter)->Y_Pos_Output() == y)
		{
			if ((*iter)->CheckFlagOutput() == true)
				return;
			(*iter)->CheckFlagChange();
			int MineNumTmp = MineManager::GetInstace()->FindSurroindingMine(x, y);
			(*iter)->HintSet(MineNumTmp);
			m_MapDraw.DrawPoint((*iter)->ShapeOutput(), x, y);
			if (MineNumTmp == 0)
			{
				for (int j = (y - 1); j <= (y + 1); j++)
				{
					for (int i = (x - 1); i <= (x + 1); i++)
					{
						AreaCheck(i, j,width,height);
					}
				}
			}
			return;
		}
	}
}

bool AreaManager::CheckFlagCheck(int width, int height)
{
	int FlagCount = 0;
	for (auto iter = AreaList.begin(); iter != AreaList.end(); iter++)
	{
		if ((*iter)->CheckFlagOutput() == true)
			FlagCount++;
	}
	if ((FlagCount + MineManager::GetInstace()->MineNumOutput()) == (width - 2)*(height - 2))
		return true;
	else
		false;

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
