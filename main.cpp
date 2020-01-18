#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "Game.hpp"
using namespace std;


Game* game = nullptr;

int main(int argc,const char* argv[])
{
	game = new Game();

	game->init("Tanks",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,720,false);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	return 0;
}

