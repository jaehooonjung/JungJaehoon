#include "Bitmap.h"



Bitmap::Bitmap()
{
}

void Bitmap::init(HDC hdc, string bitmapname)
{
	LPCTSTR tmp = bitmapname.c_str();
	m_MemDC = CreateCompatibleDC(hdc);
	m_phImage = (HBITMAP)LoadImage(NULL, TEXT(tmp),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_phOldBitmap = (HBITMAP)SelectObject(m_MemDC, m_phImage);
	BITMAP bitmap;
	GetObject(m_phImage, sizeof(BITMAP), &bitmap);

	m_size.cx = bitmap.bmWidth;
	m_size.cy = bitmap.bmHeight;

	CharacterPos_x = CHARACTER_X_POSDEFAULT;
	CharacterPos_y = CHARACTER_Y_POSDEFAULT;
	CharacterDirection = CHARACTERMOTION_BOTTOM;
	CharacterMotion = CHARACTERMOTION_BOTTOM;
}

void Bitmap::Draw(HDC hdc)
{
	TransparentBlt(hdc, CharacterPos_x, CharacterPos_y, m_size.cx / 4, m_size.cy / 4, m_MemDC, (m_size.cx / 4) * CharacterMotion, (m_size.cy / 4) * CharacterDirection, m_size.cx / 4, m_size.cy / 4, RGB(255, 0, 255));
}

void Bitmap::Move(int direction)
{
	switch (direction)
	{
	case VK_LEFT:
		CharacterPos_x -= MOVE_DISTANCE;
		CharacterDirection = CHARACTERMOTION_LEFT;
		CharacterMotion++;
		if (CharacterMotion == CHARACTERMOTION_LEFT_END)
			CharacterMotion = CHARACTERMOTION_LEFT_1;
		break;
	case VK_RIGHT:
		CharacterPos_x += MOVE_DISTANCE;
		CharacterDirection = CHARACTERMOTION_RIGHT;
		CharacterMotion++;
		if (CharacterMotion == CHARACTERMOTION_RIGHT_END)
			CharacterMotion = CHARACTERMOTION_RIGHT_1;
		break;
	}

}


void Bitmap::Jump(HWND hWnd)
{
	if (CharacterDirection == CHARACTERMOTION_BOTTOM)
		return;
	float Radian;
	for (int i = 0; i <= 180; i++)
	{
		Radian = DegreeToRadian(i);
		switch (CharacterDirection)
		{
		case CHARACTERMOTION_LEFT:
			CharacterPos_x = CharacterPos_x - JUMP_DISTANCE / 50;
			CharacterPos_y = CHARACTER_Y_POSDEFAULT + JUMP_DISTANCE * -sin(Radian);
			break;
		case CHARACTERMOTION_RIGHT:
			CharacterPos_x = CharacterPos_x + JUMP_DISTANCE / 50;
			CharacterPos_y = CHARACTER_Y_POSDEFAULT + JUMP_DISTANCE * -sin(Radian);
			break;
		}
		InvalidateRect(hWnd, NULL, FALSE);
	}

}	

float Bitmap::DegreeToRadian(int degree)
{
	return (M_PI * (float)degree / 180);
}

Bitmap::~Bitmap()
{
	SelectObject(m_MemDC, m_phOldBitmap);
	DeleteObject(m_phImage);
	DeleteDC(m_MemDC);
}

/*
	switch (CharacterDirection)
			{
			case CHARACTERMOTION_BOTTOM:
				break;
			case CHARACTERMOTION_LEFT:
				for (int i = 0; i <= 180; i++)
				{
					Radian = DegreeToRadian(i);
					CharacterPos_x -= JUMP_DISTANCE / 50;
					CharacterPos_y = CHARACTER_Y_POSDEFAULT + JUMP_DISTANCE * -sin(Radian);
					CharacterMotion++;
					if (CharacterMotion == CHARACTERMOTION_LEFT_END)
						CharacterMotion = CHARACTERMOTION_LEFT_1;
					hdc = BeginPaint(hWnd, &ps);
					hMemDC = CreateCompatibleDC(hdc);
					hImage = (HBITMAP)LoadImage(NULL, TEXT(""),
						IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
					hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
					GetObject(hImage, sizeof(BITMAP), &bitmap);
					bx = bitmap.bmWidth;
					by = bitmap.bmHeight;
					TransparentBlt(hdc, CharacterPos_x, CharacterPos_y, bx / 4, by / 4, hMemDC, (bx / 4) * CharacterMotion, (by / 4) * CharacterDirection, bx / 4, by / 4, RGB(255, 0, 255));
					SelectObject(hMemDC, hOldBitmap);
					DeleteObject(hImage);
					DeleteDC(hMemDC);
					EndPaint(hWnd, &ps);
					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
			case CHARACTERMOTION_RIGHT:
				for (int i = 0; i <= 180; i++)
				{
					Radian = DegreeToRadian(i);
					CharacterPos_x = CharacterPos_x + JUMP_DISTANCE / 50;
					CharacterPos_y = CHARACTER_Y_POSDEFAULT + JUMP_DISTANCE * -sin(Radian);
					CharacterMotion++;
					if (CharacterMotion == CHARACTERMOTION_RIGHT_END)
						CharacterMotion = CHARACTERMOTION_RIGHT_1;
					hdc = BeginPaint(hWnd, &ps);
					hMemDC = CreateCompatibleDC(hdc);
					hImage = (HBITMAP)LoadImage(NULL, TEXT("image.bmp"),
						IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
					hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
					GetObject(hImage, sizeof(BITMAP), &bitmap);
					bx = bitmap.bmWidth;
					by = bitmap.bmHeight;
					TransparentBlt(hdc, CharacterPos_x, CharacterPos_y, bx / 4, by / 4, hMemDC, (bx / 4) * CharacterMotion, (by / 4) * CharacterDirection, bx / 4, by / 4, RGB(255, 0, 255));
					SelectObject(hMemDC, hOldBitmap);
					DeleteObject(hImage);
					DeleteDC(hMemDC);
					EndPaint(hWnd, &ps);
					InvalidateRect(hWnd, NULL, FALSE);
				}
			}
*/