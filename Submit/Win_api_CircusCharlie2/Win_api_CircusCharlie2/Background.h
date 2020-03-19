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
��Ŀ�� �ʵ� �ִ���� 300
������Ʈ���� ���� 40
������Ʈ�������� ���� 320

������Ʈ�������� ���� - ��Ŀ���ʵ��ִ���� 
bitmap_pos.x,(bitmap_pos.x  + 20)
*/

