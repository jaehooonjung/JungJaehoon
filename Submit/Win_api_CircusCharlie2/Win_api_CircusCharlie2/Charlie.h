#pragma once
#include "Bitmap.h"
class Charlie
{
private:
	Bitmap m_CharlieDie;
	CharacterBitmap m_Charlie0;
	CharacterBitmap m_Charlie1;
	CharacterBitmap m_Charlie2;
	CharacterBitmap m_CharlieWin1;
	CharacterBitmap m_CharlieWin2;
	CHARACTER_MOTION_MOVE m_CharacterMotion;
	int m_iMoveDistance;
public:
	Charlie();
	void CharlieInit(HDC hdc);
	void CharlieDraw(HDC hdc);
	void CharlieMove(int keyflag);

	~Charlie();
};
