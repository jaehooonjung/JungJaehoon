#pragma once
#include<iostream>
#include<Windows.h>
#include<vector>
#include"resource.h"
using namespace std;

class BitmapManager
{
private:
	static BitmapManager* m_hThis;
public:
	static BitmapManager* GetInstace()
	{
		if (m_hThis == NULL)
			m_hThis = new BitmapManager;
		return m_hThis;
	}
	void BitmapOutput_Name(HDC hdc, HDC *MemDC, HINSTANCE g_hInst, HBITMAP &myBitmap, HBITMAP &oldBitmap, int bitmapname, int x, int y, int width, int height);
	BitmapManager();
	~BitmapManager();
};

