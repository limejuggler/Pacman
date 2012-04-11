#include "Map.h"


Map::Map()
{

}

Map::~Map()
{
	for(unsigned int i = 0; i < tiles.size(); i++)
		SAFE_DELETE( tiles.at(i) );

	//for(unsigned int i = 0; i < objects.size(); i++)
		//SAFE_DELETE( objects.at(i) );
}