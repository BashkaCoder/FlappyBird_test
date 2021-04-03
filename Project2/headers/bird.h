#pragma once
#include <SDL.h>

class Bird
{
public:
	Bird(SDL_Renderer* renderer);
	~Bird();
	void draw();
	void tick(bool isMouseDown);
	float y;
	float x;
private:
	SDL_Texture* bird1;
	SDL_Texture* bird2;
	SDL_Renderer* m_renderer;
	double v = 0.0f;
};