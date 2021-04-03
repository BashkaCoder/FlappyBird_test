#include <load_texture.h>
#include <string>
#include <stdexcept>
#include <iostream>

SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* fileName)
{
	auto surface = SDL_LoadBMP(fileName);
	if (!surface)
	{
		std::cout << "\aCannot create surface: " << fileName << " !\n";
		return nullptr;
	}
	else
	{
		std::cout << "Surface: " << fileName << " was created successfully!\n";
	}
	auto res = SDL_CreateTextureFromSurface(renderer, surface);
	if (NULL == res)
	{
		std::cout << "\aCannot create texture with surface: " << fileName << " !\n";
		return nullptr;
	}
	else
	{
		std::cout << "Texture: " << fileName << " was created successfully!\n";
	}
	SDL_FreeSurface(surface);

	return res;
}