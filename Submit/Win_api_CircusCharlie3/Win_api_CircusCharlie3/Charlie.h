#pragma once
#include"Bitmap.h"
#include "TimeManager.h"
struct JumpTimeInfo
{
	Time StartTime;
	Time EndTime;
	Time PassTime;
};

class Charlie
{
private:
	RECT m_ObjectArea;
	JumpTimeInfo m_JumpTimeInfo;
	Bitmap m_CharlieDie;
	DubleBufferingBitmap m_Charlie0;
	DubleBufferingBitmap m_Charlie1;
	DubleBufferingBitmap m_Charlie2;
	DubleBufferingBitmap m_CharlieWin1;
	DubleBufferingBitmap m_CharlieWin2;
	CHARACTER_MOTION_MOVE m_CharacterMotion;
public:
	void CharlieInit(HDC hdc);
	void CharlieDraw(HDC hdc);
	void CharlieMove(int keyflag);
	bool CharlieJump();
	void JumpStartTimeSet();
	void CharlieStateChange(CHARACTER_STATE state);
	void CharlieReset();
	Charlie();
	inline RECT CharlieObjectAreaOutput()
	{
		return m_ObjectArea;
	}
	~Charlie();
};

