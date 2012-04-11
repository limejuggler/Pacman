#pragma once
#include "Map.h"
#include "stdafx.h"
#include "GraphicsManager.h"

class Game
{
private:
	Map map;
	static Game *instance;
	
	Game();
public:
	~Game();
	static Game *getInstance();

	void update();
	void draw();
};