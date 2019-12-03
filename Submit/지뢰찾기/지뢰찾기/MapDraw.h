#pragma once
#include"Mecro.h"
class MapDraw
{
private:
	int m_iWidth;
	int m_iHeight;
	static MapDraw* m_hThis;
public:
	static MapDraw*GetInstance()
	{
		if (m_hThis == NULL)
			m_hThis = new MapDraw;
		return m_hThis;
	}
	void MapSizeSet(int width, int height);
	void GameMapDraw();

	MapDraw();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~MapDraw();
};

