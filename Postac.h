#pragma once
#include "stdafx.h"
class Postac
{
protected:
	int mana, stamina, atk, def, kier, hp;
	char sprite[4];

public:
	int polx, poly;
	virtual void atak();
	void ruch();
    void gora();
	void dol();
	void lewo();
	void prawo();
	void wczytaj(char, char, char, char);
	Postac *kolizja();
	Postac(int h, int m, int s, int a, int d, int x, int y, int k);
	~Postac();
	friend void lot();
	friend class Tank;
	friend class Screen;
};

