#include "Game.h"
#include <iostream>
#include "SDL_image.h"
SDL_Texture* playerTex = nullptr;//
SDL_Rect dstRect;//
SDL_Texture* background = nullptr;//set in game treb

Game::Game(const char* title, int x_position, int y_position, int width, int height, bool fullscreen)
{
	int flag;
	if (fullscreen) {
		flag = SDL_WINDOW_FULLSCREEN;
	}
	else {
		flag = 0;
	}
	this->window = SDL_CreateWindow(title, x_position, y_position, width, height, flag);
	this->renderer = SDL_CreateRenderer(this->window, -1, 10);
	if (this->window && this->renderer) {
		//SDL_SetRenderDrawColor(renderer, 199, 209, 86, 255);
		SDL_Surface* tmpSurface = IMG_Load("assets/background.png");
		background = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);
		//SDL_RenderCopy(renderer, background, NULL, NULL);
		running = true;
	}
	else {
		running = false;
	}
	SDL_Surface* tmpSurface = IMG_Load("assets/PlayerDown.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	dstRect.w = 64;//dimension
	dstRect.h = 64;//of player in pixels
	dstRect.x = 0;//initial position 
	dstRect.y = 0;//of player
}

Game::~Game()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	//PlayerHandlEvents()treb
	//EnemyHandlEvents()treb
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
		running = false;
		break;
		case SDL_KEYDOWN:
		SDL_Surface* tmpSurface = nullptr;
		switch (event.key.keysym.sym)
		{
			case SDLK_UP:
				dstRect.y=dstRect.y-4;
				tmpSurface = IMG_Load("assets/PlayerUp.png");
				break;
			case SDLK_LEFT:
				dstRect.x=dstRect.x-4;
				tmpSurface = IMG_Load("assets/PlayerLeft.png");
				break;
			case SDLK_RIGHT:
				dstRect.x=dstRect.x+4;
				tmpSurface = IMG_Load("assets/PlayerRight.png");
				break;
			case SDLK_DOWN:
				dstRect.y=dstRect.y+4;
				tmpSurface = IMG_Load("assets/PlayerDown.png");
				break;
		}
		playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);
	}
}

void Game::update()
{
	if (dstRect.x > SDL_GetWindowSurface(window)->w - 64) {
		dstRect.x = SDL_GetWindowSurface(window)->w - 64;
	}
	if (dstRect.x< 0) {
		dstRect.x = 0;
	}
	if (dstRect.y > SDL_GetWindowSurface(window)->h- 64) {
		dstRect.y = SDL_GetWindowSurface(window)->h- 64;
	}
	if (dstRect.y <0) {
		dstRect.y=0;
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, NULL, NULL);
	SDL_RenderCopy(renderer,playerTex,NULL,&dstRect);
	
	SDL_RenderPresent(renderer);
}

//bool Game::running() {}

