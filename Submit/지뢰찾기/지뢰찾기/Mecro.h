#pragma once
#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<string>
#include<crtdbg.h>
#include<fstream>
#include<vector>
using namespace std;

#define WIDTH_DEFUALT 20
#define HEIGHT_DEFUALT 30

enum KEY
{
	KEY_LEFT = 'a',
	KEY_RIGHT = 'd',
	KEY_UP = 'w',
	KEY_DOWN = 's',
	KEY_ESC = 27,
	KEY_SPACEBAR = 32
};