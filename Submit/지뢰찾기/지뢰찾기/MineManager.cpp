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
	SetHint();
}

void MineManager::SetHint() // 주변에 있는 지뢰 갯수 등록
{
	int Hint, Mine_X_Pos_Tmp, Mine_Y_Pos_Tmp;
	for (auto iter = MineList.begin(); iter != MineList.end(); iter++)
	{
		Hint = 0;
		Mine_X_Pos_Tmp = (*iter)->Mine_X_Position_Output();
		Mine_Y_Pos_Tmp = (*iter)->Mine_Y_Position_Output();

		for (int y = Mine_Y_Pos_Tmp-1; y <= Mine_Y_Pos_Tmp + 1; y++)
		{
			for (int x = Mine_Y_Pos_Tmp - 1; x <= Mine_Y_Pos_Tmp + 1; x++)
			{
				if (y == Mine_Y_Pos_Tmp && x == Mine_X_Pos_Tmp)
					continue;
				if(MineCheck(x, y) != NULL);
					Hint++;
			}		
		}
		(*iter)->HintSet(Hint);
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
