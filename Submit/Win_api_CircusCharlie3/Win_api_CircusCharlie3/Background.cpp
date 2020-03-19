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
}

void Background::AllBackgroundDraw(HDC hdc)
{
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
}


Background::~Background()
{
}
