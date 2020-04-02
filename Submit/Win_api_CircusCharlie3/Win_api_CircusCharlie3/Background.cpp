#include "Background.h"



Background::Background()
{
}

void Background::BackgroundInit(HDC hdc)
{
	POINT postmp; //임시좌표변수생성
	postmp.x = START_POS_X;
	postmp.y = START_POS_Y;

	for (int i = 0; i < AUDIENCESEAT_ARRAY; i++) //관중석 init
	{
		m_AudienceSeat[i].m_AudienceSeatDecoBitmap.Init(hdc, "back_deco.bmp", "back_deco.bmp", postmp);
		postmp.x += m_AudienceSeat[i].m_AudienceSeatDecoBitmap.BitmapSizeOutput().cx;

		for (int j = 0; j < AUDIENCESEAT_LENGTH; j++)
		{
			m_AudienceSeat[i].m_AudienceSeatBitmap[j].Init(hdc, "back_normal.bmp", "back_normal2.bmp", postmp);
			postmp.x += m_AudienceSeat[i].m_AudienceSeatBitmap[j].BitmapSizeOutput().cx;
		}
		if (i == 0)
		{
			m_iAudienceSeatLength = postmp.x;
		}
	}
	//서커스필드의 좌표 설정
	postmp.x = START_POS_X;
	postmp.y = START_POS_Y + m_AudienceSeat[0].m_AudienceSeatDecoBitmap.BitmapSizeOutput().cy;

	for (int i = 0; i < CIRCUSFIELDLENGTH; i++) //서커스필드 init
	{
		m_CircusFieldBitmap[i].Init(hdc, "back.bmp", postmp);
		postmp.x += m_CircusFieldBitmap[i].BitmapSizeOutput().cx;
	}
	m_iEndLinePos_x = postmp.x;
	m_iMiniumPos_x = -m_iAudienceSeatLength*(AUDIENCESEAT_ARRAY-2);
	m_iMaxiumPos_x = m_iAudienceSeatLength*(AUDIENCESEAT_ARRAY-1);

	int maxtmp, mintmp,xpostmp;
	maxtmp = (MOVE_DISTANCE * CIRCUSFIELDFINSHLINE) - FIREWALL_CREATE_MIN;
	mintmp = FIREWALL_CREATE_MIN;
	
	bool booltmp;

	for (int i = 0; i < FIREWALL_NUM_MAX; i++) //불기둥 init
	{
		m_FireWall[i].Init(hdc, "front.bmp", "front.bmp", "front2.bmp");

		xpostmp = PosXSetRandom(mintmp, maxtmp);
		if (i > 0)
		{
			while (true)
			{
				booltmp = true;
				for (int j = 0; j < i; j++)
				{
					if (xpostmp >= m_FireWall[j].DistancePostionOutput() - FIREWALL_INTERVAL && xpostmp <= m_FireWall[j].DistancePostionOutput() + m_FireWall[j].BitmapSizeOutput().cx + FIREWALL_INTERVAL)
					{
						booltmp = false;
						break;
					}
				}
				if (booltmp == false)
				{
					xpostmp = PosXSetRandom(mintmp, maxtmp);
				}
				else
					break;
			}

		}
		m_FireWall[i].DistancePostionSet(xpostmp);
	}

	postmp.x = m_iEndLinePos_x - 100;
	postmp.y = CHARACTER_Y_POSDEFAULT + START_POS_Y;

	m_End.Init(hdc, "end.bmp", postmp);
}

void Background::AllBackgroundDraw(HDC hdc, int nowdistance)
{
	BitMapPosUpdate(nowdistance);
	for (int i = 0; i < AUDIENCESEAT_ARRAY; i++)
	{
		m_AudienceSeat[i].m_AudienceSeatDecoBitmap.Draw(hdc, m_iEndLinePos_x);
		for (int j = 0; j < AUDIENCESEAT_LENGTH; j++)
		{
			m_AudienceSeat[i].m_AudienceSeatBitmap[j].Draw(hdc, m_iEndLinePos_x);
		}
	}
	
	for (int i = 0; i < CIRCUSFIELDLENGTH; i++)
	{
		m_CircusFieldBitmap[i].Draw(hdc);
	}
	
	for (int i = 0; i < FIREWALL_NUM_MAX; i++) //불기둥 그리기
	{
			m_FireWall[i].Draw(hdc, m_iEndLinePos_x);
	}
}

void Background::Move(int keyflag)
{
	//배경은 반대로 가니까 키보드값을 반대로 바꿈
	switch (keyflag)
	{
	case VK_LEFT:
		keyflag = VK_RIGHT;
		break;
	case VK_RIGHT:
		keyflag = VK_LEFT;
		break;
	}

	for (int i = 0; i < AUDIENCESEAT_ARRAY; i++)
	{
		m_AudienceSeat[i].m_AudienceSeatDecoBitmap.Move(keyflag);

		for (int j = 0; j < AUDIENCESEAT_LENGTH; j++)
		{
			m_AudienceSeat[i].m_AudienceSeatBitmap[j].Move(keyflag);
		}
	}
	for (int i = 0; i < FIREWALL_NUM_MAX; i++) //불기둥 이동
	{
		m_FireWall[i].Move(keyflag);
	}
}

void Background::BitMapPosUpdate(int nowdistance) // 비트맵이 그려질 수 있는 최소 좌표값일때 위치를 업데이트
{
	POINT postmp;
	postmp.x = 0;
	postmp.y = 0;

	for (int i = 0; i < AUDIENCESEAT_ARRAY; i++)
	{
		if (m_AudienceSeat[i].m_AudienceSeatDecoBitmap.BitmapPointOutput().x >= m_iMaxiumPos_x)
		{
			postmp.x = -m_iAudienceSeatLength;
			postmp.y = m_AudienceSeat[i].m_AudienceSeatDecoBitmap.BitmapPointOutput().y;
			m_AudienceSeat[i].m_AudienceSeatDecoBitmap.PosChange(postmp);
			postmp.x += m_AudienceSeat[i].m_AudienceSeatDecoBitmap.BitmapSizeOutput().cx;
			for (int j = 0; j < AUDIENCESEAT_LENGTH; j++)
			{
				m_AudienceSeat[i].m_AudienceSeatBitmap[j].PosChange(postmp);
				postmp.x += m_AudienceSeat[i].m_AudienceSeatBitmap[j].BitmapSizeOutput().cx;
			}
		}
		if (m_AudienceSeat[i].m_AudienceSeatDecoBitmap.BitmapPointOutput().x <= m_iMiniumPos_x)
		{
			postmp.x = m_iAudienceSeatLength*2;
			postmp.y = m_AudienceSeat[i].m_AudienceSeatDecoBitmap.BitmapPointOutput().y;
			m_AudienceSeat[i].m_AudienceSeatDecoBitmap.PosChange(postmp);
			postmp.x += m_AudienceSeat[i].m_AudienceSeatDecoBitmap.BitmapSizeOutput().cx;
			for (int j = 0; j < AUDIENCESEAT_LENGTH; j++)
			{
				m_AudienceSeat[i].m_AudienceSeatBitmap[j].PosChange(postmp);
				postmp.x += m_AudienceSeat[i].m_AudienceSeatBitmap[j].BitmapSizeOutput().cx;
			}
		}
	}
	//불기둥 업데이트

	postmp.x = m_iEndLinePos_x;
	postmp.y = FIREWALL_POS_Y;

	for (int i = 0; i < FIREWALL_NUM_MAX; i++) //불기둥 이동
	{
		if (m_FireWall[i].DistancePostionOutput() == (nowdistance*MOVE_DISTANCE) && m_FireWall[i].CreateCheckFlagOutput() == false)
		{
			m_FireWall[i].PosChange(postmp);
			m_FireWall[i].CreateCheckFlagChange();
		}
	}
}

int Background::PosXSetRandom(int min, int max)
{
	int answer;

	do 
	{
			answer = (rand() % (max - min) + min);
	} while (answer % MOVE_DISTANCE != 0);

	return answer;

}

bool Background::BackgroundIntersectTest(RECT rect)
{
	RECT recttmp;
	for (int i = 0; i < FIREWALL_NUM_MAX; i++)
	{
		if (IntersectRect(&recttmp, &m_FireWall[i].ObjectAreaOutput(), &rect) == true)
			return true;
	}
	return false;
}

void Background::BackgroundReset()
{
	POINT postmp; //임시좌표변수생성
	postmp.x = START_POS_X;
	postmp.y = START_POS_Y;

	for (int i = 0; i < AUDIENCESEAT_ARRAY; i++) //관중석 init
	{
		m_AudienceSeat[i].m_AudienceSeatDecoBitmap.PosChange(postmp);
		postmp.x += m_AudienceSeat[i].m_AudienceSeatDecoBitmap.BitmapSizeOutput().cx;

		for (int j = 0; j < AUDIENCESEAT_LENGTH; j++)
		{
			m_AudienceSeat[i].m_AudienceSeatBitmap[j].PosChange(postmp);
			postmp.x += m_AudienceSeat[i].m_AudienceSeatBitmap[j].BitmapSizeOutput().cx;
		}
		if (i == 0)
		{
			m_iAudienceSeatLength = postmp.x;
		}
	}
	//서커스필드의 좌표 설정
	postmp.x = START_POS_X;
	postmp.y = START_POS_Y + m_AudienceSeat[0].m_AudienceSeatDecoBitmap.BitmapSizeOutput().cy;

	for (int i = 0; i < CIRCUSFIELDLENGTH; i++) //서커스필드 init
	{
		m_CircusFieldBitmap[i].PosChange(postmp);
		postmp.x += m_CircusFieldBitmap[i].BitmapSizeOutput().cx;
	}

	int maxtmp, mintmp, xpostmp;
	bool booltmp;
	maxtmp = (MOVE_DISTANCE * CIRCUSFIELDFINSHLINE) - FIREWALL_CREATE_MIN;
	mintmp = FIREWALL_CREATE_MIN;

	POINT pointtmp;
	pointtmp.x = NULL;
	pointtmp.y = NULL;

	for (int i = 0; i < FIREWALL_NUM_MAX; i++)
	{
		m_FireWall[i].DistancePostionSet(NULL);
		m_FireWall[i].PosChange(pointtmp);
		m_FireWall[i].ObjectAreaChange(NULL, NULL, NULL, NULL);
	}

	for (int i = 0; i < FIREWALL_NUM_MAX; i++) //불기둥 init
	{
		xpostmp = PosXSetRandom(mintmp, maxtmp);
		if (i > 0)
		{
			while (true)
			{
				booltmp = true;
				for (int j = 0; j < i; j++)
				{
					if (xpostmp >= m_FireWall[j].DistancePostionOutput() - FIREWALL_INTERVAL && xpostmp <= m_FireWall[j].DistancePostionOutput() + m_FireWall[j].BitmapSizeOutput().cx + FIREWALL_INTERVAL)
					{
						booltmp = false;
						break;
					}
				}
				if (booltmp == false)
				{
					xpostmp = PosXSetRandom(mintmp, maxtmp);
				}
				else
					break;
			}

		}
		m_FireWall[i].DistancePostionSet(xpostmp);
	}
}

void Background::GameWin()
{

}

Background::~Background()
{
}
