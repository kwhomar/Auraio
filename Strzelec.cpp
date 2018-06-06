#include "stdafx.h"

extern Postac *mapa[24][79];
extern Pocisk *pociski[100];
extern Screen ekran;

//Konstruktor dziedziczony od Postaci ze stalymi wspolczynnikami. Oddzielnie wspolrzedne.
Strzelec::Strzelec(int xx, int yy, int kier)
	:Postac(100, 0, 150, 200, 50, xx, yy, kier)
{
	wczytaj('>', '^', '<', 'v');
}

Strzelec::Strzelec()
	: Postac(100, 0, 150, 200, 50, 0, 0, 0)
{
	wczytaj('>', '^', '<', 'v');
}


Strzelec::~Strzelec()
{
}

//Funkcja polimorficzna
void Strzelec::atak()
{
	if (!kolizja())
	{
		//jesli strzelec jest na mapie
		if (mapa[polx][poly])
		{
			//Tworzymy pocisk na pustym miejscu w tablicy pociskow na pozycji strzelca i ruszamy o jedno pole. 
			for (int j = 0; j < 100; j++)
				if (!pociski[j])
				{
					pociski[j] = new Pocisk(polx, poly, kier);
					pociski[j]->pruch();
					break;
				}
			//Przywracamy strzelca na mape
			mapa[polx][poly] = this;
			ekran.draw(polx, poly);
		}
	}
}