#include "MineManager.h"

MineManager* MineManager::m_hThis = NULL;


MineManager::MineManager()
{
}

void MineManager::MineCreate(int width, int height)
{
	int MinePosition_X_tmp;
	int MinePosition_Y_tmp;
	m_iMineNumMaxium = (width*height)*0.35f;
	for (int i = 0; i < m_iMineNumMaxium; i++)
	{
		Mine*Tmp = new Mine;
		do
		{
			MinePosition_X_tmp = rand() % width;
			MinePosition_Y_tmp = rand() % (height - 1);
			if (MinePosition_X_tmp < 1)
				MinePosition_X_tmp++;
			if (MinePosition_Y_tmp < 1)
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
