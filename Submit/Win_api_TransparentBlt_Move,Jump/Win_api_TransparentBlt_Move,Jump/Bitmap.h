#pragma once
#pragma comment(lib, "msimg32.lib")
#include <windows.h>
#include<string>
using namespace std;

class Bitmap
{
private:
	HDC m_MemDC;
	HBITMAP m_phImage;
	HBITMAP m_phOldBitmap;
	SIZE m_size;
public:
	void init(HDC hdc, HBITMAP hImage, HBITMAP hOldBitmap, string bitmapname);
	Bitmap();
	~Bitmap();
};

