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

class DubleBufferingBitmap : public Bitmap
{
private:
	HDC m_MemDC[3];
	HBITMAP m_phImage[3];
	HBITMAP m_phOldBitmap[3];
	//SIZE m_BackgroundBitmapSize;
public:
	void Init(HDC hdc, LPCTSTR backgroundbitmapname, LPCTSTR bitmapname, POINT pos);
	void Draw(HDC hdc, int endline);
	void Move(int keyflag);

	DubleBufferingBitmap();
	~DubleBufferingBitmap();
};

class AniBitmap : public DubleBufferingBitmap
{
private:
	HDC m_MemDC[4];
	HBITMAP m_phImage[4];
	HBITMAP m_phOldBitmap[4];
	BITMAP_CHANGE m_BitmapChangeNum;
	int m_iDistancePostion;
	bool m_bCreateCheckFlag;
	RECT m_ObjectArea;
public:
	void Init(HDC hdc, LPCTSTR backgroundbitmapname, LPCTSTR bitmapname1, LPCTSTR bitmapname2);
	void Draw(HDC hdc, int endline);
	void DistancePostionSet(int pos_x);
	void CreateCheckFlagChange();
	void ObjectAreaChange(int left,int top, int right, int bottom);
	AniBitmap();
	inline int DistancePostionOutput()
	{
		return m_iDistancePostion;
	}
	inline bool CreateCheckFlagOutput()
	{
		return m_bCreateCheckFlag;
	}
	inline RECT ObjectAreaOutput()
	{
		return m_ObjectArea;
	}
	~AniBitmap();
};

