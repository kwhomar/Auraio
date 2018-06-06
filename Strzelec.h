#pragma once
#include "Postac.h"
class Strzelec :
	public Postac
{
public:
	void atak();
	Strzelec(int xx, int yy, int kier = 0);
	Strzelec();
	~Strzelec();
};

