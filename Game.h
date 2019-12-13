#pragma once
#include "SDL.h"
#include "SDL_image.h"
class Game {
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	Game(const char* title, int x_position, int y_position,int width, int height, bool fullscreen);
	~Game();
	void handleEvents();
	void update();
	void render();
	bool running;
};
