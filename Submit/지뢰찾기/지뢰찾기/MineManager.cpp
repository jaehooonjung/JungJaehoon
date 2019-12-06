#include "MineManager.h"

MineManager* MineManager::m_hThis = NULL;


MineManager::MineManager()
{
}

void MineManager::MineCreate(int width, int height)
{
	int MinePosition_X_tmp;
	int MinePosition_Y_tmp;
	m_iMineNumMaxium = (width*height)*MINE_CREATE_RATE;
	for (int i = 0; i < m_iMineNumMaxium; i++)
	{
		Mine*Tmp = new Mine;
		do
		{
			MinePosition_X_tmp = rand() % (width-1);
			MinePosition_Y_tmp = rand() % (height-1);
			if (MinePosition_X_tmp == 0)
				MinePosition_X_tmp++;
			if (MinePosition_Y_tmp == 0)
				MinePosition_Y_tmp++;

		} while (MineCheck(MinePosition_X_tmp, MinePosition_Y_tmp) != NULL);
		Tmp->MinePositionSet(MinePosition_X_tmp, MinePosition_Y_tmp);
		MineList.push_back(Tmp);
	}
}


Mine*MineManager::MineCheck(int x, int y)
{
	for (auto iter = MineList.begin(); iter != MineList.end(); iter++)
	{
		if ((*iter)->MineCheck(x, y) == true)
			return (*iter);
	}
	return NULL;
}

int MineManager::FindSurroindingMine(int x, int y)
{
	int HIntFlag = 0;
	for (auto iter = MineList.begin(); iter != MineList.end(); iter++)
	{
		for (int tmp_y = y - 1; tmp_y <= y + 1; tmp_y++)
		{
			for (int tmp_x = x - 1; tmp_x <= x + 1; tmp_x++)
			{
				if (tmp_x == x && tmp_y == y)
					continue;

				if ((*iter)->MineCheck(tmp_x, tmp_y) == true)
					HIntFlag++;
			}
		}
	}
	return HIntFlag;
}


void MineManager::DeleteMineAll()
{
	for (auto iter = MineList.begin(); iter != MineList.end(); iter++)
	{
		delete (*iter);
	}
	MineList.clear();
}

MineManager::~MineManager()
{
}
