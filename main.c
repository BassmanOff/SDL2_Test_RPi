//
//  main.c
//  SDL1
//
//  Created by BassmanOff on 20.08.2020.
//

#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, const char * argv[]) {
	SDL_Window* window = NULL;
	
	SDL_Surface* screenSurface = NULL;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("INIT ERROR\n");
		printf("Err code: %s\n", SDL_GetError());
		return 1;
	}
	else {printf("VIDEO_INIT_OK!\n"); }
	
	window = SDL_CreateWindow("TESTWINDOW",
							  SDL_WINDOWPOS_CENTERED,
							  SDL_WINDOWPOS_CENTERED,
							  800,
							  600,
							  SDL_WINDOW_SHOWN);
	if (window)
	{
		printf("WINDOW_INIT_OK!\n");
	}
	else {return 2;}
	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, 0, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);
	
	SDL_Delay(5000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
