#include "Bitmap.h"



Bitmap::Bitmap()
{
}

void Bitmap::init(HDC hdc, HBITMAP hImage, HBITMAP hOldBitmap, string bitmapname)
{
	m_MemDC = CreateCompatibleDC(hdc);
	hImage = (HBITMAP)LoadImage(NULL, TEXT("image.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hOldBitmap = (HBITMAP)SelectObject(m_MemDC, hImage);
	BITMAP bitmap;
	GetObject(hImage, sizeof(BITMAP), &bitmap);

	m_size.cx = = bitmap.bmWidth;

	bx 
	by = bitmap.bmHeight;


}


Bitmap::~Bitmap()
{
}
