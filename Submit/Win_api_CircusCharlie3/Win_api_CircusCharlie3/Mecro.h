#pragma once
#pragma comment(lib, "msimg32.lib")
#include <windows.h>
#include<string>
#define _USE_MATH_DEFINES
#include <math.h>
#include<vector>
using namespace std;

#define START_POS_X 0
#define START_POS_Y 25

#define AUDIENCESEAT_LENGTH 3
#define AUDIENCESEAT_ARRAY 3


#define CHARACTER_X_POSDEFAULT 20
#define CHARACTER_Y_POSDEFAULT 160
#define JUMP_DISTANCE 50
#define MOVE_DISTANCE 1
#define CIRCUSFIELDLENGTH 7
#define CIRCUSFIELDFINSHLINE 100 

enum CHARACTER_STATE
{
	CHARACTER_STATE_STAY,
	CHARACTER_STATE_MOVE,
	CHARACTER_STATE_JUMP
};

enum GAMESTATE
{
	GAMEINIT,
	GAMEOVER,
	GAMEPLAYING
};

enum CHARACTER_MOTION_MOVE
{
	CHARACTER_MOTION_MOVE_1,
	CHARACTER_MOTION_MOVE_2,
	CHARACTER_MOTION_MOVE_END
};

struct TimeInfo
{
	int Second;
	int MiSecond;
};
