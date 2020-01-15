#include "ChesspieceManager.h"
#include "ChessGameManager.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("CHESSGAME");
void init(HDC hdc);



int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768,
		NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

ChesspieceManager m_ChesspieceManager;
BlockManager m_BlockManager;
ChessGameManager m_ChessGameManager;
GAMESTATE GameState = GAMESTATE_GAMEOVER;
Chesspiece* ChesspieceTmp;
int mouse_x, mouse_y;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_LBUTTONDOWN:
		if ((GameState != GAMESTATE_WHITE_THINKING) && (GameState != GAMESTATE_BLACK_THINKING))
			return 0;
		mouse_x = LOWORD(lParam);
		mouse_y = HIWORD(lParam);
		ChesspieceTmp = m_ChesspieceManager.ChesspieceSelect(GameState, mouse_x, mouse_y);
		//m_BlockManager.ShowRoad(hdc, GameState,ChesspieceTmp->ChessPieceOutput(), ChesspieceTmp->ChessPiecePositionOutput());
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		init(hdc);
		m_ChesspieceManager.ChesspieceDraw(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void init(HDC hdc)
{
	if (GameState != GAMESTATE_GAMEOVER)
		return;
	else
		GameState = GAMESTATE_WHITE_THINKING;
	m_BlockManager.BlockInit(hdc);
	m_ChesspieceManager.ChesspieceManagerInit(hdc);
	m_BlockManager.BlockDraw(hdc);
}

/*
1. �ش���ҿ� ü������ �ִ��� Ȯ��
-> return
2. ü������ �ִٸ� ü������ ��ġ�� ������ ������� ������.
3. ��Ͽ��� �⺸�� �����ش�.
*/