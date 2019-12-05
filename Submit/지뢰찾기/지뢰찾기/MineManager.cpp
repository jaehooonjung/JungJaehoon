#include "MineManager.h"

MineManager* MineManager::m_hThis = NULL;


MineManager::MineManager()
{
}

void MineManager::MineCreate(int width, int height)
{
	int MinePosition_X_tmp;
	int MinePosition_Y_tmp;
	Mine*Tmp = new Mine;
	m_iMineNumMaxium = (width*height)*0.35f;
	for (int i = 0; i < m_iMineNumMaxium; i++)
	{
		do
		{
			MinePosition_X_tmp = rand() % width;
			MinePosition_Y_tmp = rand() % (height - 1);
			if (MinePosition_X_tmp < 1)
				MinePosition_X_tmp++;
			if (MinePosition_Y_tmp < 1)
				MinePosition_Y_tmp++;
		} while (MineOverLapCheck(MinePosition_X_tmp, MinePosition_Y_tmp));
		Tmp.
		MineList.push_back(Tmp);
	}
}

bool MineManager::MineOverLapCheck(int x, int y)
{
	for (auto iter = MineList.begin(); iter != MineList.end(); iter++)
	{
		if ((*iter)->MineCheck(x, y) == true)
			return true;
	}
	return false;
}

MineManager::~MineManager()
{
}
