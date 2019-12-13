#include "SDL.h"
#include "Game.h"
int main(int argc, char* argv[]) {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	Uint32 frameTime;
	Game game = Game("Game.exe",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 720,1);
	while (game.running) {
		frameStart = SDL_GetTicks();
		game.handleEvents();
		game.update();
		game.render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	return 0;
}