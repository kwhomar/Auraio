#include "stdafx.h"


extern Postac *mapa[24][79];

//Pocisk tworzy sie na wspolrzednych strzelca z jego kierunkiem
Pocisk::Pocisk(int xx, int yy, int kk)
	:Postac(20, 0, 150, 200, 50, xx, yy, kk)
{
	wczytaj('.', '.', '.', '.');
}

//Gdy pocisk przestaje istniec kasujemy go z mapy
Pocisk::~Pocisk()
{
}


//Pocisk porusza sie zgodnie z poczatkowym kierunkiem wlasciciela
void Pocisk::pruch()
{

	if (kier == 0) prawo();
	if (kier == 1) gora();
	if (kier == 2) lewo();
	if (kier == 3) dol();
}
