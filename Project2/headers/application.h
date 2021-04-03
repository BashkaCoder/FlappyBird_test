#pragma once
#include <SDL.h>

class Application 
{
public:
	static const int Width = 1024;
	static const int Height = 600;
	Application();
	void exec();
	SDL_Window* window;
private:
	SDL_Renderer* renderer;
};
