#include "Bitmap.h"



Bitmap::Bitmap()
{
}

void Bitmap::init(HDC hdc)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_phImage = (HBITMAP)LoadImage(NULL, TEXT("image.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_phOldBitmap = (HBITMAP)SelectObject(m_MemDC, m_phImage);
	BITMAP bitmap;
	GetObject(m_phImage, sizeof(BITMAP), &bitmap);
	m_size.cx = bitmap.bmWidth;
	m_size.cy = bitmap.bmHeight;

	m_CharacterPos.x = CHARACTER_X_POSDEFAULT;
	m_CharacterPos .y = CHARACTER_Y_POSDEFAULT;
	m_CharacterDirection = CHARACTER_DIRECTION_BOTTOM;
}

void Bitmap::Draw(HDC hdc)
{
	TransparentBlt(hdc, m_CharacterPos.x, m_CharacterPos.y, m_size.cx / 4, m_size.cy / 4, m_MemDC, (m_size.cx / 4) * m_CharacterMotion, (m_size.cy / 4) * m_CharacterDirection, m_size.cx / 4, m_size.cy / 4, RGB(255, 0, 255));
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
	InvalidateRect(hWnd, NULL, TRUE);
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
		InvalidateRect(hWnd, NULL, TRUE);
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

	InvalidateRect(hWnd, NULL, TRUE);
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
	SelectObject(m_MemDC, m_phOldBitmap);
	DeleteObject(m_phImage);
	DeleteDC(m_MemDC);
}

/*
점프 관련
1. 범위당 시계를 여러개 만들어서 
2. 범위당 체크하기 
*/
