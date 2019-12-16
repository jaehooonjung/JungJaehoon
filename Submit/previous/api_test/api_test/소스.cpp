#include<windows.h>
#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("TextOut");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
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

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	int Extent_Tmp;
	/*
	int Circle_X = 200, Circle_Y = 200; //시작좌표
	int Circle_r = 100;	  //반지름
	int Circle_Middle_X = Circle_X + Circle_r, Circle_Middle_Y = Circle_Y + Circle_r;	//원점좌표
	int Circle_Extent = (Circle_r* Circle_r)*M_PI;

	*/

	
	int Ellipse_X = 200, Ellipse_Y = 200;
	int Ellipse_A = 150, Ellipse_B = 100;
	int Ellipse_Middle_X = Ellipse_A + Ellipse_X;
	int Ellipse_Middle_Y = Ellipse_Y + Ellipse_B;
	int Ellipse_Extent = M_PI * Ellipse_A*Ellipse_B;


	

	switch (iMessage)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		/*
				for (int y = Circle_Y; y <= Circle_Y+(Circle_r*2); y++)
		{
			for (int x = Circle_X; x <= Circle_X+(Circle_r*2); x++)
			{
				Extent_Tmp = ((x - Circle_Middle_X)*(x - Circle_Middle_X) + (y - Circle_Middle_Y)*(y - Circle_Middle_Y)) * M_PI;
				if(Extent_Tmp == Circle_Extent)
					SetPixel(hdc, x, y, RGB(50, 0, 50));
			}
		}
		*/
		 /*
		  		for (int y = Ellipse_Y; y <= Ellipse_Y+(Ellipse_Middle_Y*2); y++)
		{
			for (int x = Ellipse_X; x <= Ellipse_X + (Ellipse_Middle_X * 2); x++)
			{
				Extent_Tmp = ((x - Ellipse_Middle_X)*(x - Ellipse_Middle_X) / (Ellipse_A* Ellipse_A)) + (y - Ellipse_Middle_Y)*(y - Ellipse_Middle_Y) / (Ellipse_Middle_Y*Ellipse_Middle_Y);
						if(Extent_Tmp == 1)
							SetPixel(hdc, x, y, RGB(50, 0, 50));
			}
		}

		

		 */

		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}