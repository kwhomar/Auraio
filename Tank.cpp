#include "stdafx.h"

extern Postac *mapa[24][79];
extern Postac *gracz1;
extern void botshoot(Strzelec *x);
extern 	Strzelec s2;

Tank::Tank(int xx, int yy)
	:Postac(300, 0, 250, 200, 300, xx, yy, 0)
	{
		wczytaj('p', 'n', 'q', 'u'); 
	}


Tank::~Tank()
{
}

void Tank::atak()
{
	if (kolizja() && mapa[polx][poly])
	{

		kolizja()->hp -= 80;
		if (kolizja()->hp <= 0)
		{
			if (kolizja() != gracz1)
				kolizja()->~Postac();
			else
			{
				cout << "Wygral gracz drugi" << endl;
				cin.get();
				cin.get();
				exit(0);
			}
		}
	}
	
}