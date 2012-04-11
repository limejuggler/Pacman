#pragma once
#include "stdafx.h"
#include "GraphicsManager.h"

class Game
{
private:
	Game();
	Game *instance;
public:
	~Game();
	Game getInstance();


};