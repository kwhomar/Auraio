#include "stdafx.h"

extern Postac *mapa[24][79];
extern Screen ekran;

//konstruktor postaci
Postac::Postac(int h, int m, int s, int a, int d, int x, int y, int k)
{
	hp = h;
	mana = m;
	stamina = s;
	atk = a;
	def = d;
	polx = x;
	poly = y;
	kier = k;
	//zapisuje wskaznik do postaci na mapie
	mapa[x][y] = this;
}


Postac::~Postac()
{
	mapa[polx][poly] = 0;
}

//ruch zgodny z kierunkiem lub obrót
void Postac::gora()
{
	kier = 1;
	if (!kolizja())
	{
		//kasuje wspolrzedne opuszczanego pola z mapy
		mapa[polx][poly] = 0;
		//czysci z ekranu to miejsce
		ekran.draw(polx, poly);
		//rusza sie
		if (polx > 0) polx--;
		//wpisuje obecne wspolrzedne na mape
		mapa[polx][poly] = this;
	}
	//rysuje gracza na ekranie
	ekran.draw(polx, poly);
}

void Postac::dol()
{
	kier = 3;
	if (!kolizja())
	{
		mapa[polx][poly] = 0;
		//czysci z ekranu to miejsce
		ekran.draw(polx, poly);
		if (polx < 23) polx++;
		mapa[polx][poly] = this;
	}
	//rysuje gracza na ekranie
	ekran.draw(polx, poly);
}

void Postac::lewo()
{
	kier = 2;
	if (!kolizja())
	{
		mapa[polx][poly] = 0;
		//czysci z ekranu to miejsce
		ekran.draw(polx, poly);
		if (poly > 0) poly--;
		mapa[polx][poly] = this;
	}
	//rysuje gracza na ekranie
	ekran.draw(polx, poly);
}

void Postac::prawo()
{
	kier = 0;
	if (!kolizja())
	{
		mapa[polx][poly] = 0;
		//czysci z ekranu to miejsce
		ekran.draw(polx, poly);
		if (poly < 78) poly++;
		mapa[polx][poly] = this;
	}
	//rysuje gracza na ekranie
	ekran.draw(polx, poly);
}

void Postac::atak()
{
}

void Postac::ruch()
{
	char klawisz;
	//rysuj();
	if (_kbhit())
	{
		klawisz = _getch();
		if (klawisz == 'w') gora();
		if (klawisz == 'a') lewo();
		if (klawisz == 's') dol();
		if (klawisz == 'd') prawo();
		if (klawisz == 'e') atak();
/////////////////////////////////////////////
		if (klawisz == 'i') gora();
		if (klawisz == 'j') lewo();
		if (klawisz == 'k') dol();
		if (klawisz == 'l') prawo();
		if (klawisz == 'o') atak();
	}
}



void Postac::wczytaj(char a, char b, char c, char d)
{
	sprite[0] = a;
	sprite[1] = b;
	sprite[2] = c;
	sprite[3] = d;
}

//Zwraca 0 jesli nie ma nic przed nim, wskaznik do postaci jesli jest ona przed nim
Postac *Postac::kolizja()
{
	if (kier == 0) return mapa[polx][poly + 1];
	if (kier == 1) return mapa[polx - 1][poly];
	if (kier == 2) return mapa[polx][poly - 1];
	if (kier == 3) return mapa[polx + 1][poly];
}