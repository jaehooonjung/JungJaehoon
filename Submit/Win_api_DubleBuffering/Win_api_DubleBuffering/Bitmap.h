#pragma once
#pragma comment(lib, "msimg32.lib")
#include <windows.h>
#include<string>
#define _USE_MATH_DEFINES
#include <math.h>
#include<vector>
using namespace std;

#define CHARACTER_X_POSDEFAULT 300
#define CHARACTER_Y_POSDEFAULT 300
#define JUMP_DISTANCE 50
#define MOVE_DISTANCE 7

enum CHARACTER_DIRECTION
{
	CHARACTER_DIRECTION_BOTTOM,
	CHARACTER_DIRECTION_UP,
	CHARACTER_DIRECTION_LEFT,
	CHARACTER_DIRECTION_RIGHT,
	CHARACTER_DIRECTION_UNKNOWN
};

enum CHARACTER_MOTION
{
	CHARACTER_MOTION_1,
	CHARACTER_MOTION_2,
	CHARACTER_MOTION_3,
	CHARACTER_MOTION_4

};

struct TimeInfo
{
	int Second;
	int MiSecond;
};

class Bitmap
{
private:
	HDC m_MemDC[3];
	HBITMAP m_phImage[3];
	HBITMAP m_phOldBitmap[3];
	SIZE m_size;
	POINT m_CharacterPos;
	int m_JumpLinePos;
	CHARACTER_DIRECTION m_CharacterDirection;
	CHARACTER_MOTION m_CharacterMotion;
public:
	void init(HDC hdc);
	void Draw(HDC hdc);
	void Move(HWND hWnd);
	void MotionChange(CHARACTER_DIRECTION nextdirection, HWND hWnd);
	bool Jump(HWND hWnd, TimeInfo timeinfo);
	float DegreeToRadian(int degree);
	void JumpLineSet();
	bool DoulbeKeyCheck();
	Bitmap();
	~Bitmap();
};

