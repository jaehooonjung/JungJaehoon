#pragma once
#include"Mecro.h"
#define UP 'w'
#define DOWN 's'
#define ENTER 13

enum GATENUMMARK
{
	GATENUMMARK_START,
	GATENUMMARK_1,
	GATENUMMARK_2,
	GATENUMMARK_3,
	GATENUMMARK_MAX
};

class MapDraw
{
public:
	void DrawMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void DrawPoint(string str, int x, int y);
	void ErasePoint(int x, int y);
	void EraseText(string Text, int x, int y);
	int  MenuSelectCursor(int MenuLen, int AddCol, int x, int y); //메뉴창갯수, 메뉴창끼리의 높이거리, 화살표생성 가로위치, 화살표생성 높이위치
	void MenuDraw();
	void GateDraw();
	MapDraw();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~MapDraw();
};

