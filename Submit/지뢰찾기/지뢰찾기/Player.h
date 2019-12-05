#pragma once
#include"MapDraw.h"



class Player
{
private:
	int m_iCursorPosition_X;
	int m_iCursorPosition_Y;
	string m_iCursorShape;
	MapDraw m_MapDraw;
public:
	void PlayerInitialize(string cursorshape,int width, int height);
	void DrawCursor();
	//void EraseCursor();
	void CursorMove(char ch, int width, int height);
	Player();
	inline int CursorPosition_X_Output()
	{
		return m_iCursorPosition_X;
	}
	inline int CursorPosition_Y_Output()
	{
		return m_iCursorPosition_Y;
	}
	~Player();
};

