#include "Bitmap.h"



Bitmap::Bitmap()
{
}

void Bitmap::init(HDC hdc)
{

	m_MemDC[0] = CreateCompatibleDC(hdc);
	m_phImage[0] = CreateCompatibleBitmap(hdc, 1024, 768);
	m_phOldBitmap[0] = (HBITMAP)SelectObject(m_MemDC[0], m_phImage[0]);

	m_MemDC[1] = CreateCompatibleDC(m_MemDC[0]);
	m_phImage[1] = (HBITMAP)LoadImage(NULL, "back.bmp", IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_phOldBitmap[1] = (HBITMAP)SelectObject(m_MemDC[1], m_phImage[1]);

	m_MemDC[2] = CreateCompatibleDC(m_MemDC[0]);
	m_phImage[2] = (HBITMAP)LoadImage(NULL, TEXT("image.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_phOldBitmap[2] = (HBITMAP)SelectObject(m_MemDC[2], m_phImage[2]);

	BITMAP bitmap;
	GetObject(m_phImage[2], sizeof(BITMAP), &bitmap);
	m_size.cx = bitmap.bmWidth;
	m_size.cy = bitmap.bmHeight;

	m_CharacterPos.x = CHARACTER_X_POSDEFAULT;
	m_CharacterPos .y = CHARACTER_Y_POSDEFAULT;
	m_CharacterDirection = CHARACTER_DIRECTION_BOTTOM;
}

void Bitmap::Draw(HDC hdc)
{
	BitBlt(m_MemDC[0], 0, 0, 1024, 768, m_MemDC[1], 0, 0, SRCCOPY);
	TransparentBlt(m_MemDC[0], m_CharacterPos.x, m_CharacterPos.y, m_size.cx / 4, m_size.cy / 4, m_MemDC[2], (m_size.cx / 4) * m_CharacterMotion, (m_size.cy / 4) * m_CharacterDirection, m_size.cx / 4, m_size.cy / 4, RGB(255, 0, 255));
	BitBlt(hdc, 0, 0, 1024, 768, m_MemDC[0], 0, 0, SRCCOPY);
}

void Bitmap::Move(HWND hWnd)
{
	CHARACTER_DIRECTION direction = CHARACTER_DIRECTION_UNKNOWN;
	int keyflag =  0;
		if (GetKeyState(VK_LEFT) & 0x8000)
		{
			m_CharacterPos.x -= MOVE_DISTANCE;
			if (keyflag == 0)
			{
				direction = CHARACTER_DIRECTION_LEFT;
			}
			keyflag++;
			//MotionChange(CHARACTER_DIRECTION_LEFT, hWnd);
		}
		if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			m_CharacterPos.x += MOVE_DISTANCE;
			if (keyflag == 0)
			{
				direction = CHARACTER_DIRECTION_RIGHT;
			}
			keyflag++;
			//MotionChange(CHARACTER_DIRECTION_RIGHT, hWnd);
		}
		if (GetKeyState(VK_UP) & 0x8000)
		{
			m_CharacterPos.y -= MOVE_DISTANCE;
			if (keyflag == 0)
			{
				direction = CHARACTER_DIRECTION_UP;
			}
			keyflag++;
			//MotionChange(CHARACTER_DIRECTION_UP, hWnd);
		}
		if (GetKeyState(VK_DOWN) & 0x8000)
		{
			m_CharacterPos.y += MOVE_DISTANCE;
			if (keyflag == 0)
			{
				direction = CHARACTER_DIRECTION_BOTTOM;
			}
			keyflag++;
		}
		MotionChange(direction, hWnd);
}

void Bitmap::MotionChange(CHARACTER_DIRECTION nextdirection, HWND hWnd)
{
	if (nextdirection == CHARACTER_DIRECTION_UNKNOWN)
		return;
	if (m_CharacterDirection != nextdirection)
	{
		if (DoulbeKeyCheck() == false)
		{
			m_CharacterDirection = nextdirection;
			m_CharacterMotion = CHARACTER_MOTION_1;
			return;
		}
	}
		switch (m_CharacterMotion)
		{
		case CHARACTER_MOTION_1:
			m_CharacterMotion = CHARACTER_MOTION_2;
			break;
		case CHARACTER_MOTION_2:
			m_CharacterMotion = CHARACTER_MOTION_3;
			break;
		case CHARACTER_MOTION_3:
			m_CharacterMotion = CHARACTER_MOTION_4;
			break;
		case CHARACTER_MOTION_4:
			m_CharacterMotion = CHARACTER_MOTION_1;
			break;
		}
	//InvalidateRect(hWnd, NULL, TRUE);
}

bool Bitmap::Jump(HWND hWnd, TimeInfo timeinfo)
{
	if (m_CharacterDirection == CHARACTER_DIRECTION_BOTTOM || m_CharacterDirection == CHARACTER_DIRECTION_UP)
		return true;
	if (timeinfo.MiSecond >= 800)
	{
		switch (m_CharacterDirection)
		{
		case CHARACTER_DIRECTION_LEFT:
			m_CharacterPos.x = m_CharacterPos.x - 5;
			break;
		case CHARACTER_DIRECTION_RIGHT:
			m_CharacterPos.x = m_CharacterPos.x + 5;
			break;
		}
		m_CharacterPos.y = m_JumpLinePos;
		//InvalidateRect(hWnd, NULL, TRUE);
		return true;
	}
	float dgree = (float)timeinfo.MiSecond / 100 * 18;
	float Radian = DegreeToRadian(dgree);
	switch (m_CharacterDirection)
	{
	case CHARACTER_DIRECTION_LEFT:
		m_CharacterPos.x = m_CharacterPos.x - 5;
		m_CharacterPos.y = m_JumpLinePos + JUMP_DISTANCE * -sin(Radian);
		break;
	case CHARACTER_DIRECTION_RIGHT:
		m_CharacterPos.x = m_CharacterPos.x + 5;
		m_CharacterPos.y = m_JumpLinePos + JUMP_DISTANCE * -sin(Radian);
		break;
	}
	if (m_CharacterPos.y > m_JumpLinePos)
		m_CharacterPos.y = m_JumpLinePos;

	//InvalidateRect(hWnd, NULL, TRUE);
	return false;
}

float Bitmap::DegreeToRadian(int degree)
{
	return (M_PI * (float)degree / 180);
}

void Bitmap::JumpLineSet()
{
	m_JumpLinePos = m_CharacterPos.y;
}

bool Bitmap::DoulbeKeyCheck()
{
	int keyflag = 0;
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		if (m_CharacterDirection != CHARACTER_DIRECTION_LEFT)
			m_CharacterDirection = CHARACTER_DIRECTION_LEFT;
		keyflag++;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		if (m_CharacterDirection != CHARACTER_DIRECTION_RIGHT)
			m_CharacterDirection = CHARACTER_DIRECTION_RIGHT;
		keyflag++;
	}
	if (GetKeyState(VK_UP) & 0x8000)
	{
		if (m_CharacterDirection != CHARACTER_DIRECTION_UP)
			m_CharacterDirection = CHARACTER_DIRECTION_UP;
		keyflag++;
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		if (m_CharacterDirection != CHARACTER_DIRECTION_BOTTOM)
			m_CharacterDirection = CHARACTER_DIRECTION_BOTTOM;
		keyflag++;
	}
	if (keyflag >= 2)
		return true;
	else
	return false;
}

Bitmap::~Bitmap()
{
	for (int i = 0; i < 3; i++)
	{
		SelectObject(m_MemDC[i], m_phOldBitmap[i]);
		DeleteObject(m_phImage[i]);
		DeleteDC(m_MemDC[i]);
	}
}

/*
���� ����
1. ������ �ð踦 ������ ���� 
2. ������ üũ�ϱ� 
*/
