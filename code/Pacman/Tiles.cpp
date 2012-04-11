#include "Tiles.h"


Tiles::Tiles(vector<Tiles*> neighbours, D3DXVECTOR3 pos, D3DXVECTOR2 dim)
{
	position = pos;
	dimensions = dim;
	neighbouringTiles = neighbours;
}

bool Tiles::checkDirection(char direction)
{
	switch(direction)
	{
		case 'n':
			if(neighbouringTiles.at(0))
				return true;
			break;
		case 's':
			if(neighbouringTiles.at(1))
				return true;
			break;
		case 'e':
			if(neighbouringTiles.at(2))
				return true;
			break;
		case 'w':
			if(neighbouringTiles.at(3))
				return true;
			break;
	}
	return false;
}

Tiles::~Tiles()
{
	for(int i = 0; i < 4; i++)
		SAFE_DELETE( neighbouringTiles.at(i) );
}