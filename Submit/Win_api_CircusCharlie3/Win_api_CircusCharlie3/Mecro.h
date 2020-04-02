#pragma once
#pragma comment(lib, "msimg32.lib")
#include <windows.h>
#include<string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
using namespace std;


#define START_POS_X 0 
#define START_POS_Y 70
#define AUDIENCESEAT_LENGTH 4
#define AUDIENCESEAT_ARRAY 4
#define CHARACTER_X_POSDEFAULT 20 // 캐릭터 고정 x 좌표
#define CHARACTER_Y_POSDEFAULT 160 // 캐릭터 고정 y 좌표
#define JUMP_DISTANCE 80 //점프 높이
#define MOVE_DISTANCE 5 //이동속도
#define CIRCUSFIELDLENGTH 7 
#define CIRCUSFIELDFINSHLINE 1000 //서커스필드 거리
#define JUMPINGTIMESECOND 2 //체공시간 초단위
#define FIREWALL_NUM_MAX 12 // 불기둥 최대 생성 수 
#define FIREWALL_INTERVAL 75 // 불기둥 사이거리의 최소
#define FIREWALL_CREATE_MIN 50 //불기둥이 나오못하는 처음과 끝의 값
#define FIREWALL_POS_Y 250

#define FIRERING_NUM_MAX 4 // 화염링 최대 생성 수
#define FIRERING_INTERVAL 30 // 불기둥 사이거리의 최소

enum CHARACTER_STATE
{
	CHARACTER_STATE_STAY,
	CHARACTER_STATE_MOVE,
	CHARACTER_STATE_JUMP,
	CHARACTER_STATE_DEAD
};

enum GAMESTATE
{
	GAMEINIT,
	GAMEOVER,
	GAMEPLAYING,
	GAMEPAUSE,
};

enum CHARACTER_MOTION_MOVE
{
	CHARACTER_MOTION_MOVE_1,
	CHARACTER_MOTION_MOVE_2,
	CHARACTER_MOTION_JUMP,
	CHARACTER_MOTION_MOVE_END,
	CHARACTER_MOTION_DEAD
};

enum BITMAP_CHANGE
{
	BITMAP_CHANGE_1 = 2,
	BITMAP_CHANGE_2,
	BITMAP_CHANGE_END
};

/*




*/