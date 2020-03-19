#pragma once
#include "Mecro.h"
class Bitmap
{
private:
	HDC m_MemDC;
	HBITMAP m_phImage;
	HBITMAP m_phOldBitmap;
protected:
	SIZE m_Size;
	POINT m_BitmapPos;
	LPCTSTR m_strBitmapName;
public:
	void Init(HDC hdc, LPCTSTR bitmapname, POINT pos);
	void PosChange(POINT pos);
	void Draw(HDC hdc);
	Bitmap();
	inline SIZE BitmapSizeOutput()
	{
		return m_Size;
	}
	inline LPCTSTR BitmapNameOutput()
	{
		return m_strBitmapName;
	}
	inline POINT BitmapPointOutput()
	{
		return m_BitmapPos;
	}
	~Bitmap();
};

class CharacterBitmap : public Bitmap
{
private:
	HDC m_MemDC[3];
	HBITMAP m_phImage[3];
	HBITMAP m_phOldBitmap[3];
	POINT m_BitmapStartPos;
	POINT m_BitmapEndPos;
	SIZE m_BackgroundBitmapSize;
public:
	void Init(HDC hdc, LPCTSTR backgroundbitmapname,LPCTSTR bitmapname, POINT startpos, POINT endpos);
	void Draw(HDC hdc);
	void Move(int keyflag);
	void DefaultPosChange(POINT startpos, POINT endpos);

	CharacterBitmap();
	~CharacterBitmap();
};