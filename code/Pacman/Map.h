#pragma once
#include "Tiles.h"
//#include "GameObject"

class Map
{
private:
	//vector<GameObject*> objects;
	vector<Tiles*> tiles;
public:
	Map();
	~Map();
};