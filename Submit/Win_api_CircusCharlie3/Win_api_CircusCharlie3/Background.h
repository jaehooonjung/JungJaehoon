#pragma once
#include "Bitmap.h"

struct AudienceSeat
{
	DubleBufferingBitmap m_AudienceSeatDecoBitmap;
	DubleBufferingBitmap m_AudienceSeatBitmap[AUDIENCESEAT_LENGTH];
};

class Background
{
private:
	int m_iEndLinePos_x;
	AudienceSeat m_AudienceSeat[AUDIENCESEAT_ARRAY];
	Bitmap m_CircusFieldBitmap[CIRCUSFIELDLENGTH];
public:
	void BackgroundInit(HDC hdc);
	void AllBackgroundDraw(HDC hdc);
	void Move(int keyflag);
	Background();
	~Background();
};

