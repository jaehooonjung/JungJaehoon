#pragma once
#include"Mecro.h"
class MapDraw
{
public:
	void MapSizeSet(int width, int height);
	void GameMapDraw(int width, int height);
	void DrawMidText(string str,int x, int y);
	void DrawPoint(string str, int x, int y);
	void ErasePoint(int x, int y);
	void BlockDraw(int x, int y);
	MapDraw();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~MapDraw();
};

