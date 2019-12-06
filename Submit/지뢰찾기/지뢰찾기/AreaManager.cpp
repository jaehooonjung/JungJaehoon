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
			Tmp->ShapeChage("■");
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
			return (*iter)->ShapeOutput();
			
		}
	}
}
				 /*
				 void MineManager::SetHint() // 주변에 있는 지뢰 갯수 등록
{
	int Hint, Mine_X_Pos_Tmp, Mine_Y_Pos_Tmp;
	for (auto iter = MineList.begin(); iter != MineList.end(); iter++)
	{
		Hint = 0;
		Mine_X_Pos_Tmp = (*iter)->Mine_X_Position_Output();
		Mine_Y_Pos_Tmp = (*iter)->Mine_Y_Position_Output();

		for (int y = Mine_Y_Pos_Tmp - 1; y <= Mine_Y_Pos_Tmp + 1; y++)
		{
			for (int x = Mine_Y_Pos_Tmp - 1; x <= Mine_Y_Pos_Tmp + 1; x++)
			{
				if (y == Mine_Y_Pos_Tmp && x == Mine_X_Pos_Tmp)
					continue;
				if (MineCheck(x, y) != NULL)
					Hint++;
			}
		}
		(*iter)->HintSet(Hint);
	}
}

				 */



AreaManager::~AreaManager()
{
}
