#pragma once
#pragma comment(lib, "msimg32.lib")
#include<Windows.h>
#include<string>
#include<vector>
using namespace std;


enum GAMESTATE
{
	GAMESTATE_GAMEOVER,
	GAMESTATE_PLAYING,
	GAMESTATE_WHITHT_THINKING,
	GAMESTATE_BLACK_THINKING,
	GAMESTATE_MOVEPHASE
};

enum CHESSPIECE
{
	CHESSPIECE_PAWN,
	CHESSPIECE_KNIGHT,
	CHESSPIECE_BISHOP,
	CHESSPIECE_ROOK,
	CHESSPIECE_QUEEN,
	CHESSPIECE_KING
};

enum CHESSPIECECOLOR
{
	CHESSPIECECOLOR_WHITHT,
	CHESSPIECECOLOR_BLACK
};

enum CHESSPIECESTATE
{
	CHESSPIECESTATUS_DEAD,
	CHESSPIECESTATUS_LIVE,
	CHESSPIECESTATUS_MOVE
};


/*
체스판의 크기 8x8
프로모션 제외한 다른 특수룰 제외

*/