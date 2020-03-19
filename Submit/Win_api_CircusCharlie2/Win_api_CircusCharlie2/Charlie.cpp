#include "Charlie.h"



Charlie::Charlie()
{
}

void Charlie::CharlieInit(HDC hdc)
{
	//.Init(HDC hdc, LPCTSTR bitmapname, POINT pos)
	//.Init(HDC hdc, LPCTSTR backgroundbitmapname, LPCTSTR bitmapname, POINT startpos, POINT endpos)
	m_CharacterMotion = CHARACTER_MOTION_MOVE_END;
	POINT postmp;
	postmp.x = CHARACTER_X_POSDEFAULT;
	postmp.y = CHARACTER_Y_POSDEFAULT;

	m_Charlie0.Init(hdc, "player0.bmp", "player0.bmp", postmp, postmp);
	m_Charlie1.Init(hdc, "player1.bmp", "player1.bmp", postmp, postmp);
	m_Charlie2.Init(hdc, "player2.bmp", "player2.bmp", postmp, postmp);

	m_iMoveDistance = 0;
}

void Charlie::CharlieDraw(HDC hdc)
{
	switch (m_CharacterMotion)
	{
	case CHARACTER_MOTION_MOVE_1:
		m_Charlie0.Draw(hdc);
		break;
	case CHARACTER_MOTION_MOVE_2:
		m_Charlie1.Draw(hdc);
		break;
	case CHARACTER_MOTION_MOVE_END:
		m_Charlie2.Draw(hdc);
		break;
	}
}

void Charlie::CharlieMove(int keyflag)
{
	switch (m_CharacterMotion)
	{
	case CHARACTER_MOTION_MOVE_1:
		m_CharacterMotion = CHARACTER_MOTION_MOVE_2;
		break;
	case CHARACTER_MOTION_MOVE_2:
		m_CharacterMotion = CHARACTER_MOTION_MOVE_END;
		break;
	case CHARACTER_MOTION_MOVE_END:
		m_CharacterMotion = CHARACTER_MOTION_MOVE_1;
		break;
	}

	switch (keyflag)
	{
	case VK_LEFT:
		m_iMoveDistance--;
		if (m_iMoveDistance < 0)
			m_iMoveDistance = 0;
		break;
	case VK_RIGHT:
		m_iMoveDistance++;
		if (m_iMoveDistance >= 100)
		{
			//  // // // //
			// ¸ñÇ¥µµÂø  //
			// // // //  //
		}

		break;
	}
}

Charlie::~Charlie()
{
}
