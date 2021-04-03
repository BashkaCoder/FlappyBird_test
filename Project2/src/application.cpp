#include <string>
#include <stdexcept>

#include "application.h"
#include "game.h"

Application::Application()
{
	auto res = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_EVENTS);
	if (res != 0)
	{
		throw std::runtime_error(std::string("EXCEPTION in SDL_INIT(SDL_init_audio, events, video!)!"));
	}
	if (-1 == SDL_CreateWindowAndRenderer(Width, Height, 0, &window, &renderer))
	{
		throw std::runtime_error(std::string("EXCEPTION in:SDL_CreateWindowAndRenderer()!"));
	}
	if (-1 == SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND))
	{
		throw std::runtime_error(std::string("EXCEPTION in: SDL_SetRenderDrawBlendMode()!"));
	}
	
	SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	//¬ключить пиздатый режим
	//SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
}

void Application::exec()
{
	Game g(renderer);
	g.exec();
}