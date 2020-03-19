#pragma once
#include "Bitmap.h"
class Charlie
{
private:
	Bitmap m_CharlieDie;
	DubleBufferingBitmap m_Charlie0;
	DubleBufferingBitmap m_Charlie1;
	DubleBufferingBitmap m_Charlie2;
	DubleBufferingBitmap m_CharlieWin1;
	DubleBufferingBitmap m_CharlieWin2;
	CHARACTER_MOTION_MOVE m_CharacterMotion;
	int m_iMoveDistance;
public:
	Charlie();
	void CharlieInit(HDC hdc);
	void CharlieDraw(HDC hdc);
	void CharlieMove(int keyflag);

	~Charlie();
};
