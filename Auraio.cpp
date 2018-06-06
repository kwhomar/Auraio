// Auraio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void rysuj();
void lot();
void botshoot(Strzelec *x);

//tablica przechowujaca wskazniki do postaci, 0 - puste
Postac *mapa[24][79];
//tablica przechowujaca aktywne pociski
Pocisk *pociski[100];

Postac *gracz1;
Postac *gracz2;

Screen ekran;


int main()
{
	srand(time(NULL));
	cout << "w,a,s,d -ruch, e-strzelanie. i,j,k,l - ruch druga postacia, o-cios (niedokonczony)" << endl;
	cin.get();
	system("cls");
	char wybor;
	Strzelec s2(8, 20);
	Strzelec s3(5, 32, 3);
	Strzelec s(12, 14);
	Tank t(20, 8);
	gracz1 = &s;
	gracz2 = &t;
	/* singleplayer
	cout << "Wybierz postac:\n1. Strzelec\n2. Tank\n";
	cin >> wybor;
	if (wybor == '1')
	gracz = &s;
	else if (wybor == '2')
	gracz = &t;
	else
	{
	cout << "Brak innych postaci";
	exit(0);
	}*/
	ekran.draw();
	auto startTime = chrono::system_clock::now();
	int random = 0;
	while (1)
	{
		//singleplayer
		//gracz->ruch();
		//ekran.draw();
		//pociski leca
		long long x = (chrono::system_clock::now() - startTime).count();
		if (x  > 300000)
		{	
			random = rand() % 10;	
			if (random > 3)
				botshoot(&s3);
			if (random > 2)
				botshoot(&s2);
			lot();
			startTime = chrono::system_clock::now();

		}

		char klawisz;
		if (_kbhit())
		{
			klawisz = _getch();
			if (klawisz == 'w') gracz1->gora();
			if (klawisz == 'a') gracz1->lewo();
			if (klawisz == 's') gracz1->dol();
			if (klawisz == 'd') gracz1->prawo();
			if (klawisz == 'e') gracz1->atak();
			/////////////////////////////////////////////
			if (klawisz == 'i') gracz2->gora();
			if (klawisz == 'j') gracz2->lewo();
			if (klawisz == 'k') gracz2->dol();
			if (klawisz == 'l') gracz2->prawo();
			if (klawisz == 'o') gracz2->atak();
		}
		
	}





	
    return 0;
}

//wyswietla mape
void rysuj()
{
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 79; j++)
		{
			//jesli nic nie stoi na polu to wyswietla puste, jesli stoi to wyswietla to co tam stoi
			if (!mapa[i][j]) cout << ' ';
		}
		cout << endl;
	}
}

void lot()
{
	for (int i = 0; i < 100; i++)
	{
		if (pociski[i])
		{
			if ((pociski[i]->polx == 23) || (pociski[i]->polx == 1) || (pociski[i]->poly == 1) || (pociski[i]->poly == 78) || (pociski[i]->kolizja()))
			{
				//jesli uderzy w postac, zabiera jej 50hp
				if (pociski[i]->kolizja())
				{
					pociski[i]->kolizja()->hp -= 50;
					if (pociski[i]->kolizja()->hp <= 0)
					{
						if ((pociski[i]->kolizja() != gracz1) && (pociski[i]->kolizja() != gracz2))
							pociski[i]->kolizja()->~Postac();
						else
						{
							if (pociski[i]->kolizja() == gracz1)
								cout << "Wygral gracz drugi" << endl;
							else
								cout << "Wygral gracz pierwszy" << endl;
							cin.get();
							cin.get();
							exit(0);
						}

					}
				}
				mapa[pociski[i]->polx][pociski[i]->poly] = 0;
				ekran.draw(pociski[i]->polx, pociski[i]->poly);
				pociski[i] = 0;
			}
			else
				pociski[i]->pruch();
		}
	}
}

void botshoot( Strzelec *x)
{
	static int strzal = 0;

	strzal++;
	if (strzal == 10)
	{
		x -> atak();
		strzal = 0;
	}
}
