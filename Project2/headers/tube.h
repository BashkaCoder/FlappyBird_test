#pragma once
#include <SDL.h>
#include "application.h"

class Tube
{
public:
	Tube(SDL_Renderer* renderer, SDL_Texture* texture, int y, bool isUp);
	void tick();
	void draw();
	float x = Application::Width + 128;
	float y;
	bool isUp;
private:
	SDL_Renderer* renderer;
	SDL_Texture* m_texture;
};
