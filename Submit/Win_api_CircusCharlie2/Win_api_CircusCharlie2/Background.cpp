#include "Background.h"

Background::Background()
{
}

void Background::BackgroundInit(HDC hdc)
{
	m_AudienceSeatBitmap[CIRCUSFIELDLENGTH];
	m_CircusFieldBitmap[CIRCUSFIELDLENGTH];
	
	POINT pointtmp, pointtmp2, pointtmp3, pointtmp4;
	pointtmp.x = 0;
	pointtmp.y = 0;
	pointtmp2.x = 0;
	pointtmp2.y = 0;
	pointtmp3.x = 0;
	pointtmp3.y = 0;
	pointtmp4.x = 0;
	pointtmp4.y = 0;

	for (int i = 0; i < CIRCUSFIELDLENGTH; i++)
	{
		m_AudienceSeatBitmap[i].Init(hdc, "back_normal.bmp", pointtmp);
		pointtmp.x += m_AudienceSeatBitmap[i].BitmapSizeOutput().cx;

		pointtmp2.y = m_AudienceSeatBitmap[i].BitmapSizeOutput().cy;
		m_CircusFieldBitmap[i].Init(hdc, "back.bmp", pointtmp2);
		pointtmp2.x += m_CircusFieldBitmap[i].BitmapSizeOutput().cx;
	}

	pointtmp3.x = m_AudienceSeatBitmap[CIRCUSFIELDLENGTH-1].BitmapPointOutput().x;
	m_AudienceSeatDecoBitmap.Init(hdc, "back_deco.bmp", "back_deco.bmp", pointtmp3, pointtmp3);


	POINT postmp;

	for (int i = 0; i < AUDIENCESEAT_ARRAY; i++)
	{
		m_AudienceSeat[i].m_AudienceSeatDecoBitmap.Init(hdc, "back_deco.bmp", "back_deco.bmp", pointtmp3, pointtmp3)

	}


}

void Background::AllBackgroundDraw(HDC hdc)
{
	for (int i = 0; i < CIRCUSFIELDLENGTH; i++)
	{
		m_AudienceSeatBitmap[i].Draw(hdc);
		m_CircusFieldBitmap[i].Draw(hdc);
	}
	m_AudienceSeatDecoBitmap.Draw(hdc);
}

void Background::Move(int keyflag)
{
	m_AudienceSeatDecoBitmap.Move(keyflag);
}

Background::~Background()
{
}
