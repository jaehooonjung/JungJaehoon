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
	int m_iAudienceSeatLength; // ���� + ���߼� ����ü�� ����
	int m_iEndLinePos_x; //��Ʈ���� �׷��� �� �ִ� �ִ���ǥ 
	int m_iMaxiumPos_x; //��Ʈ���� ������ �� �ִ� �ִ���ǥ
	int m_iMiniumPos_x; //��Ʈ���� ������ �� �ִ� �ּ���ǥ
	AudienceSeat m_AudienceSeat[AUDIENCESEAT_ARRAY];
	Bitmap m_CircusFieldBitmap[CIRCUSFIELDLENGTH];
	AniBitmap m_FireWall[FIREWALL_NUM_MAX];
	Bitmap m_End;
public:
	void BackgroundInit(HDC hdc);
	void AllBackgroundDraw(HDC hdc, int nowdistance);
	void Move(int keyflag);
	void BitMapPosUpdate(int nowdistance); // ��Ʈ���� �׷��� �� �ִ� �ּ� ��ǥ���϶� ��ġ�� ������Ʈ
	int PosXSetRandom(int min, int max);
	bool BackgroundIntersectTest(RECT rect);
	void BackgroundReset();
	void GameWin();
	Background();
	~Background();
};

