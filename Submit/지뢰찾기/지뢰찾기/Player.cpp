#include "Player.h"



Player::Player()
{
	PlayerInitialize("¡Ù", WIDTH_DEFUALT, HEIGHT_DEFUALT);
}

void Player::PlayerInitialize(string cursorshape,int width, int height)
{
	m_iCursorPosition_X = width / 2;
	m_iCursorPosition_Y = height / 2;
	m_iCursorShape = cursorshape;
}

void Player::DrawCursor()
{
	m_MapDraw.DrawPoint(m_iCursorShape , m_iCursorPosition_X, m_iCursorPosition_Y);
}

void Player::EraseCursor()
{
	m_MapDraw.ErasePoint(m_iCursorPosition_X, m_iCursorPosition_Y);
}

void Player::CursorMove(char ch, int width, int height)
{
	EraseCursor();
	switch (ch)
	{
	case KEY_LEFT:
		if (m_iCursorPosition_X - 1 > 0)
			m_iCursorPosition_X--;
		break;
	case KEY_RIGHT:
		if (m_iCursorPosition_X + 1 < width)
			m_iCursorPosition_X++;
		break;
	case KEY_UP:
		if (m_iCursorPosition_Y - 1 > 0)
			m_iCursorPosition_Y--;
		break;
	case KEY_DOWN:
		if (m_iCursorPosition_Y + 1 < height-1)
			m_iCursorPosition_Y++;
		break;
	}
}

Player::~Player()
{
}
