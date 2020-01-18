#include "Game.hpp"
#include <iostream>
using namespace std;

Game::Game()
{
	isRunning = true;
	renderer = NULL;
	window = NULL;

}
Game::~Game()
{

}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags=0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsystems Initialized!..." << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			cout << "Window Created!" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, flags);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 120, 200, 170, 255);
			cout << "Renderer Created!" << endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

}

void Game::update()
{


}
void Game::render()
{
	SDL_RenderClear(renderer);
	//inja render mikonim chizairo ke mikhaym//
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleaned!" << endl;
	
}
