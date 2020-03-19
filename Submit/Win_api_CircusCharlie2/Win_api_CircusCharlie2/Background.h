#pragma once
#include "Bitmap.h"

struct AudienceSeat
{
	CharacterBitmap m_AudienceSeatDecoBitmap;
	CharacterBitmap m_AudienceSeatBitmap[AUDIENCESEAT_LENGTH];
};

class Background
{
private:
	AudienceSeat m_AudienceSeat[AUDIENCESEAT_ARRAY];

	Bitmap m_AudienceSeatBitmap[CIRCUSFIELDLENGTH];
	Bitmap m_CircusFieldBitmap[CIRCUSFIELDLENGTH];
	CharacterBitmap m_AudienceSeatDecoBitmap;
public:
	void BackgroundInit(HDC hdc);
	void AllBackgroundDraw(HDC hdc);
	void Move(int keyflag);
	Background();
	~Background();
};

/*
서커스 필드 최대길이 300
관객비트맵의 길이 40
관객비트맵집합의 길이 320

관객비트맵집합의 길이 - 서커스필드최대길이 
bitmap_pos.x,(bitmap_pos.x  + 20)
*/

