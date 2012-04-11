#pragma once
#include "stdafx.h"

class Tiles
{
private:
	vector<Tiles*> neighbouringTiles;
public:
	Tiles();
	~Tiles();
};