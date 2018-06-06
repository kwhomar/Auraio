#pragma once
#include "Postac.h"
#include "Strzelec.h"
class Pocisk :
	public Postac
{
public:
	void pruch();
	Pocisk(int xx, int yy, int kk);
	~Pocisk();
	friend class Strzelec;
};

