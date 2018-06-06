#include "stdafx.h"



void Screen::draw(int x, int y)
{
	setCursor(x, y);
	if (!mapa[x][y]) cout << ' ';
	else
		cout << mapa[x][y]->sprite[mapa[x][y]->kier];
}


void Screen::setCursor(int x, int y)
{
	Position.Y = x;
	Position.X = y;
	SetConsoleCursorPosition(hOut, Position);
}


Screen::Screen()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hOut, &cursor_info);
	cursor_info.bVisible = 0;
	SetConsoleCursorInfo(hOut, &cursor_info);
}

void Screen::draw()
{
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 79; j++)
		{
			//jesli nic nie stoi na polu to wyswietla puste, jesli stoi to wyswietla to co tam stoi
			if (!mapa[i][j]) cout << ' ';
			else
				cout << mapa[i][j]->sprite[mapa[i][j]->kier];
		}
		cout << endl;
	}
}

Screen::~Screen()
{
}
