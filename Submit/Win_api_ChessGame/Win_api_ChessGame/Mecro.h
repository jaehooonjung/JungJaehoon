#pragma once
#pragma comment(lib, "msimg32.lib")
#include<Windows.h>
#include<string>
#include<vector>
using namespace std;

#define CHESSBOARDDRAWSTARTPOSX 0
#define CHESSBOARDDRAWSTARTPOSY 0
#define CHESSBOARDWIDTH 8
#define CHESSBOARDHEIGHT 8
#define CHESSBOARDBLOCKSIZE 50
#define CHESSPIECESIZE 50
#define MOVEPOSSIBILITYMAX 27

struct Position
{
	int Position_x;
	int Position_y;
};

enum GAMESTATE
{
	GAMESTATE_GAMEOVER,
	GAMESTATE_WHITE_THINKING,
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
	CHESSPIECECOLOR_WHITE,
	CHESSPIECECOLOR_BLACK
};

enum CHESSPIECESTATE
{
	CHESSPIECESTATUS_DEAD,
	CHESSPIECESTATUS_LIVE,
	CHESSPIECESTATUS_MOVE
};

enum CHESSPIECENUM
{
	CHESSPIECENUM_PAWN = 8,
	CHESSPIECENUM_KNIGHT = 2,
	CHESSPIECENUM_BISHOP = 2,
	CHESSPIECENUM_ROOK = 2,
	CHESSPIECENUM_QUEEN = 1,
	CHESSPIECENUM_KING = 1
};

enum BLOCKCOLOR
{
	BLOCKCOLOR_WHITE,
	BLOCKCOLOR_BLACK,
	BLOCKCOLOR_MAKER
};
