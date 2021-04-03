#include <stdexcept>
#include <iostream>

#include "bird.h"
#include "load_texture.h"
#include "application.h"

Bird::Bird(SDL_Renderer* renderer) :
	m_renderer(renderer),
	bird1(loadTexture(renderer, "fb.bmp")),
	bird2(loadTexture(renderer, "fb1.bmp")),
	x(Application::Width/4), 
	y(Application::Height/2)
{

}

void Bird::draw()
{
	SDL_Rect size;
	size.x = x - 64;
	size.y = y - 64;
	size.h = 128;
	size.w = 128;
	SDL_Rect birdRect;
	birdRect.x = x - 125 / 2;
	birdRect.y = y - 104 / 2;
	birdRect.w = 125;
	birdRect.h = 104;
	//SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
	//SDL_RenderDrawRect(m_renderer, &birdRect);

	auto res = SDL_RenderCopyEx(m_renderer, SDL_GetTicks() % 250 > 125 ? bird1 : bird2, nullptr, &size, v * 26, NULL, SDL_FLIP_NONE);
	if (res != 0)
	{
		throw std::runtime_error(std::string("SDL_Render_Copy ") + SDL_GetError());
		return;
	}

}

void Bird::tick(bool isMouseDown)
{
	if (isMouseDown)
	{
		v = -0.45;
		//if (v > 0)
			//v *= -0.5;
		//v -= 0.003;
	}
	else
	{
		v -= 0;
	}
	v += 0.001;
	y += v;
}

Bird::~Bird()
{
	SDL_DestroyTexture(bird1);
	SDL_DestroyTexture(bird2);
}