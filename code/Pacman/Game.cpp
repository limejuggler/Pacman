#include "Game.h"

Game *Game::instance = NULL;
Game::Game()
{
}

Game *Game::getInstance()
{
	if(!instance)
		instance = new Game();
	
	return instance;
}

void Game::update()
{

}

void Game::draw()
{

}

Game::~Game()
{
	
}