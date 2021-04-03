#include "tube.h"
#include <stdexcept>
#include <string>
#include "load_texture.h"

Tube::Tube(SDL_Renderer* renderer, SDL_Texture* texture, int y, bool isUp) :
	renderer(renderer),
	m_texture(texture),
	y(y),
	isUp(isUp)
{

}

void Tube::tick()
{
	x -= 0.35;
}

void Tube::draw()
{
	SDL_Rect size;
	size.x = x - 64;
	size.w = 128;
	size.h = 256;
	if (!isUp)
	{
		size.y = y;
		//size.y = Application::Height - y - size.h;
		//
	}
	else
	{
		size.y = Application::Height - y - size.h;
	}
	auto res = SDL_RenderCopyEx(renderer, m_texture, nullptr, &size, isUp ? 0 : 180, 0, SDL_FLIP_NONE);
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	//SDL_RenderDrawRect(renderer, &size);
	if (res != 0)
	{
		throw std::runtime_error(std::string("SDL_Render_Copy ") + SDL_GetError());
	}
}