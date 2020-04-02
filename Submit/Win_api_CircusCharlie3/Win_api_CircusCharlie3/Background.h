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
	int m_iAudienceSeatLength; // 데코 + 관중석 구조체의 길이
	int m_iEndLinePos_x; //비트맵이 그려질 수 있는 최대좌표 
	int m_iMaxiumPos_x; //비트맵이 움직일 수 있는 최대좌표
	int m_iMiniumPos_x; //비트맵이 움직일 수 있는 최소좌표
	AudienceSeat m_AudienceSeat[AUDIENCESEAT_ARRAY];
	Bitmap m_CircusFieldBitmap[CIRCUSFIELDLENGTH];
	AniBitmap m_FireWall[FIREWALL_NUM_MAX];
	Bitmap m_End;
public:
	void BackgroundInit(HDC hdc);
	void AllBackgroundDraw(HDC hdc, int nowdistance);
	void Move(int keyflag);
	void BitMapPosUpdate(int nowdistance); // 비트맵이 그려질 수 있는 최소 좌표값일때 위치를 업데이트
	int PosXSetRandom(int min, int max);
	bool BackgroundIntersectTest(RECT rect);
	void BackgroundReset();
	void GameWin();
	Background();
	~Background();
};

