#include "Game.h"


Game::Game()
{
}

Game::~Game()
{
	SAFE_DELETE( instance );
}