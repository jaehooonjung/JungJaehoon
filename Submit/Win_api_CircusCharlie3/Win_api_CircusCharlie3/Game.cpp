#include "Game.h"



Game::Game()
{
	m_Gamestate = GAMEINIT;
	m_Charaterstate = CHARACTER_STATE_MOVE;
	srand((unsigned)time(NULL));
}

void Game::init(HDC hdc)
{
	if (m_Gamestate != GAMEINIT)
		return;

	m_BackgroundManager.BackgroundInit(hdc);
	m_CharlieManager.CharlieInit(hdc);
	m_Gamestate = GAMEPLAYING;
	m_iMoveDistance = 0;
}

void Game::Draw(HDC hdc)
{
	if (m_Gamestate == GAMEOVER)
	{
		m_BackgroundManager.AllBackgroundDraw(hdc, m_iMoveDistance);
		m_CharlieManager.CharlieDraw(hdc);
		GameReset();
	}

	if (GetKeyState(VK_RETURN) & 0x8000)
		m_Gamestate = GAMEPLAYING;
	

	if (m_Gamestate != GAMEPLAYING)
		return;
	m_BackgroundManager.AllBackgroundDraw(hdc, m_iMoveDistance);
	//�Ÿ� ǥ�ñ� �׸���
	m_CharlieManager.CharlieDraw(hdc);

}

void Game::KeyboardInputCheck(HWND hWnd)
{
	if (m_Gamestate != GAMEPLAYING)
		return;
	IntersectTest();
	if (m_Charaterstate == CHARACTER_STATE_JUMP)
	{
		Jump(hWnd);
		return;
	}

	if (m_Charaterstate != CHARACTER_STATE_MOVE)
		return;

	int keyflag = NULL;

	if (GetKeyState(VK_LEFT) & 0x8000)
		keyflag = VK_LEFT;
	if (GetKeyState(VK_RIGHT) & 0x8000)
		keyflag = VK_RIGHT;

	if (GetKeyState(VK_SPACE) & 0x8000) //����Ű ������ �� 
	{
		keyflag = VK_SPACE;
		m_Charaterstate = CHARACTER_STATE_JUMP;
		m_CharlieManager.JumpStartTimeSet();
	}
	
	if (keyflag == VK_LEFT || keyflag == VK_RIGHT) //�¿� �̵� �� ���� �� ���ϰ� ��ȯ
	{
		Move(keyflag);
	}

}

void Game::Move(int keyflag)
{
	m_BackgroundManager.Move(keyflag);
	m_CharlieManager.CharlieMove(keyflag);
	DistanceUpdate(keyflag); // ������ �Ÿ� ������Ʈ
}

void Game::Jump(HWND hWnd)
{
	if (m_CharlieManager.CharlieJump() == false)
	{
		m_Charaterstate = CHARACTER_STATE_MOVE;
	}
	m_BackgroundManager.Move(VK_RIGHT);
}

void Game::DistanceUpdate(int keyflag)
{
	switch (keyflag)
	{
	case VK_LEFT:
		m_iMoveDistance--;
		if (m_iMoveDistance < 0)
			m_iMoveDistance = 0;
		break;
	case VK_SPACE:
	case VK_RIGHT:
		m_iMoveDistance++;
		if (m_iMoveDistance >= CIRCUSFIELDFINSHLINE)
		{
			//  // // // //
			// ��ǥ����  //
			// // // //  //
		}
		break;
	}
}

void Game::IntersectTest()
{
	if (m_BackgroundManager.BackgroundIntersectTest(m_CharlieManager.CharlieObjectAreaOutput()) == true)
	{
		m_CharlieManager.CharlieStateChange(CHARACTER_STATE_DEAD);
		m_Gamestate = GAMEOVER;
	}
	else
		return;
}

void Game::GameReset()
{
	if (m_Gamestate != GAMEOVER)
		return;

	m_BackgroundManager.BackgroundReset();
	m_CharlieManager.CharlieReset();
	m_Gamestate = GAMEPAUSE;
	m_iMoveDistance = 0;
}

Game::~Game()
{
}
