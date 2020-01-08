#pragma once
#pragma comment(lib, "msimg32.lib")
#include <windows.h>
#include<string>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

#define CHARACTER_X_POSDEFAULT 300
#define CHARACTER_Y_POSDEFAULT 300
#define JUMP_DISTANCE 50
#define MOVE_DISTANCE 10


enum CHARACTERMOTION
{
	CHARACTERMOTION_BOTTOM = 0,
	CHARACTERMOTION_LEFT = 2,
	CHARACTERMOTION_RIGHT
};

enum CHARACTERMOTION_LEFT
{
	CHARACTERMOTION_LEFT_1,
	CHARACTERMOTION_LEFT_2,
	CHARACTERMOTION_LEFT_3,
	CHARACTERMOTION_LEFT_4,
	CHARACTERMOTION_LEFT_END

};

enum CHARACTERMOTION_RIGHT
{
	CHARACTERMOTION_RIGHT_1,
	CHARACTERMOTION_RIGHT_2,
	CHARACTERMOTION_RIGHT_3,
	CHARACTERMOTION_RIGHT_4,
	CHARACTERMOTION_RIGHT_END

};


class Bitmap
{
private:
	HDC m_MemDC;
	HBITMAP m_phImage;
	HBITMAP m_phOldBitmap;
	SIZE m_size;
	int CharacterPos_x;
	int CharacterPos_y;
	int CharacterDirection;
	int CharacterMotion;
	int m_iJumpStartTime;
public:
	void init(HDC hdc, string bitmapname);
	void Draw(HDC hdc);
	void Move(int direction);
	void Jump(HWND hWnd,int time);
	float DegreeToRadian(int degree);
	Bitmap();
	~Bitmap();
};

