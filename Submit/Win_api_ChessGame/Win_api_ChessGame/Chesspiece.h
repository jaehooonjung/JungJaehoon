#pragma once
#include<Windows.h>
#include<string>
#include<time.h>
using namespace std;

enum CHESSPIECESTATUS
{
	CHESSPIECESTATUS_DEAD,
	CHESSPIECESTATUS_LIVE
};

class Chesspiece
{
private:
	HDC m_MemDC;
	HBITMAP hImage;
	HBITMAP hOldBitmap;
	SIZE m_size;
	string m_stringBitmapName;
	int m_iChesspiece_Pos_x;
	int m_iChesspiece_Pos_y;
public:
	Chesspiece();
	~Chesspiece();
};

