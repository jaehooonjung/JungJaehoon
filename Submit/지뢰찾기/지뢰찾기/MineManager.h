#pragma once
#include"Mine.h"

class MineManager
{
private:
	static MineManager* m_hThis;
	int m_iMineNumMaxium;
	vector<Mine*>MineList;
public:
	static MineManager* GetInstace()
	{
		if (m_hThis == NULL)
			m_hThis = new MineManager;
		return m_hThis;
	}
	void MineCreate(int width, int height);
	Mine*MineCheck(int x, int y);
	void DeleteMineAll();
	MineManager();
	~MineManager();
};

