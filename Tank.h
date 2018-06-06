#pragma once
#include "Postac.h"
class Tank :
	public Postac
{
public:
	void atak();
	Tank(int xx, int yy);
	~Tank();
};

