#pragma once
#include "stdafx.h"

class Tiles
{
private:
	D3DXVECTOR3 position;
	D3DXVECTOR2 dimensions;
	vector<Tiles*> neighbouringTiles;
public:
	Tiles(vector<Tiles*> neighbours, D3DXVECTOR3 pos, D3DXVECTOR2 dim);
	~Tiles();

	bool checkDirection(char direction);
};