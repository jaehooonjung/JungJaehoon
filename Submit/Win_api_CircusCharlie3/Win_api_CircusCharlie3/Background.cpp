#include "Background.h"



Background::Background()
{
}

void Background::BackgroundInit(HDC hdc)
{
	POINT postmp; //�ӽ���ǥ��������
	postmp.x = START_POS_X;
	postmp.y = START_POS_Y;

	for (int i = 0; i < AUDIENCESEAT_ARRAY; i++) //���߼� init
	{
		m_AudienceSeat[i].m_AudienceSeatDecoBitmap.Init(hdc, "back_deco.bmp", "back_deco.bmp", postmp);
		postmp.x += m_AudienceSeat[i].m_AudienceSeatDecoBitmap.BitmapSizeOutput().cx;

		for (int j = 0; j < AUDIENCESEAT_LENGTH; j++)
		{
			m_AudienceSeat[i].m_AudienceSeatBitmap[j].Init(hdc, "back_normal.bmp", "back_normal2.bmp", postmp);
			postmp.x += m_AudienceSeat[i].m_AudienceSeatBitmap[j].BitmapSizeOutput().cx;
		}
	}

	//��Ŀ���ʵ��� ��ǥ ����
	postmp.x = START_POS_X;
	postmp.y = START_POS_Y + m_AudienceSeat[0].m_AudienceSeatDecoBitmap.BitmapSizeOutput().cy;

	for (int i = 0; i < CIRCUSFIELDLENGTH; i++) //��Ŀ���ʵ� init
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
	//����� �ݴ�� ���ϱ� Ű���尪�� �ݴ�� �ٲ�
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
