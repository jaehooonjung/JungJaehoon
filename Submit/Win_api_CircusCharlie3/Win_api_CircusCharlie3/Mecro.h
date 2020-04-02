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
#define CHARACTER_X_POSDEFAULT 20 // ĳ���� ���� x ��ǥ
#define CHARACTER_Y_POSDEFAULT 160 // ĳ���� ���� y ��ǥ
#define JUMP_DISTANCE 80 //���� ����
#define MOVE_DISTANCE 5 //�̵��ӵ�
#define CIRCUSFIELDLENGTH 7 
#define CIRCUSFIELDFINSHLINE 1000 //��Ŀ���ʵ� �Ÿ�
#define JUMPINGTIMESECOND 2 //ü���ð� �ʴ���
#define FIREWALL_NUM_MAX 12 // �ұ�� �ִ� ���� �� 
#define FIREWALL_INTERVAL 75 // �ұ�� ���̰Ÿ��� �ּ�
#define FIREWALL_CREATE_MIN 50 //�ұ���� �������ϴ� ó���� ���� ��
#define FIREWALL_POS_Y 250

#define FIRERING_NUM_MAX 4 // ȭ���� �ִ� ���� ��
#define FIRERING_INTERVAL 30 // �ұ�� ���̰Ÿ��� �ּ�

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