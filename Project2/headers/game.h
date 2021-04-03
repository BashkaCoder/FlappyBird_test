#pragma once
#include <SDL.h>
#include "bird.h"
#include "application.h"
#include "tube.h"
#include <vector>

class Game 
{
public:
	Game(SDL_Renderer* renderer);
	void exec();
private:
	SDL_Renderer* m_renderer;
	SDL_Texture* tubeTexture;
	Bird bird;
	std::vector<Tube> tubeList;
	bool tick(bool isMousePressed);
	int counter = 0;
};
