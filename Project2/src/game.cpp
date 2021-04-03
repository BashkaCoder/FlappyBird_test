	#include "game.h"
	#include "load_texture.h"
	#include <ctime>
	#include <cstdlib>
	#include <iostream>

	Game::Game(SDL_Renderer* renderer) :
		m_renderer(renderer),
		tubeTexture(loadTexture(m_renderer, "tube.bmp")),
		bird(m_renderer),
		counter(0)
	{
		srand(time(0));
	}

	bool Game::tick(bool isMousePressed)
	{
		if (counter++ % 1500 == 0)
		{
			int y = (rand() % 50)*1.5 - 100;
			tubeList.emplace_back(m_renderer, tubeTexture, y, false);
			tubeList.emplace_back(m_renderer, tubeTexture, y, true);
		}
		bird.tick(isMousePressed);
		SDL_Rect birdRect;
		birdRect.x = bird.x - (125 / 2)-64;
		birdRect.y = bird.y - (104 / 2);
		birdRect.w = 114;
		birdRect.h = 104;
		try
		{
			bird.draw();
		}
		catch (const std::exception&)
		{
			std::cout << "FAILED TO DRAW BIRD!\n";
			return false;
		}
		SDL_Rect res;
		for (auto &tube : tubeList)
		{
			tube.tick();
			SDL_Rect size;
			size.x = tube.x - 128;
			size.w = 128;
			size.h = 228;
			if (!tube.isUp)
			{
				size.y = tube.y;
				//size.y = Application::Height - y - size.h;
				//
			}
			else
			{
				size.y = Application::Height - tube.y - size.h;
			}
			if (!tube.isUp)
			{
				/*SDL_Rect tubeRect;
				tubeRect.x = tube.x-64;
				tubeRect.y = tube.y;
				tubeRect.w = 128;
				tubeRect.h = 256;*/
				if (SDL_IntersectRect(&birdRect, &size, &res))
				{
					return false;
				}
			}
			else
			{
				/*SDL_Rect tubeRect;
				tubeRect.x = tube.x - 64;
				tubeRect.y = Application::Height - tube.y - 256;
				tubeRect.w = 128;
				tubeRect.h = 256;*/
				if (SDL_IntersectRect(&birdRect, &size, &res))
				{
					return false;
				}
			}
			
		}
		
		return (bird.y < Application::Height);
	}

	void Game::exec()
	{
		SDL_Event e;
		bool quit = false;
		bool isMouseDown = false;
		auto oldTick = SDL_GetTicks();
		while (!quit)
		{
			while (SDL_PollEvent(&e)) {
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					isMouseDown = true;
				}
				if (e.type == SDL_MOUSEBUTTONUP)
				{
					isMouseDown = false;
				}
			}

			auto currentTick = SDL_GetTicks();
			for (auto i = oldTick; i < currentTick; i++)
			{
				if (!tick(isMouseDown))
				{
					SDL_Delay(1500);
					return;
				}
			}
			oldTick = currentTick; 

			SDL_SetRenderDrawColor(m_renderer, 46, 128, 128, 255);
			SDL_RenderClear(m_renderer);
			for (auto& tube : tubeList)
				tube.draw();
			bird.draw();
			
			SDL_RenderPresent(m_renderer);
		}
		SDL_DestroyRenderer(m_renderer);
		//SDL_DestroyWindow(window);
		SDL_Quit();
	}
