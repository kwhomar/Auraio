#pragma once
#include "stdafx.h"

using namespace std;
extern Postac *mapa[24][79];

class Screen
{
	HANDLE hOut;
	COORD Position;
	CONSOLE_CURSOR_INFO cursor_info;
public:
	void draw();
	void draw(int x, int y);
	void setCursor(int x = 0, int y = 0);
	Screen();
	~Screen();
};

