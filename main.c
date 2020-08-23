#include <stdio.h>
#include <SDL2/SDL.h>

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *imgSurf = NULL;
SDL_Surface *imgSurf2 = NULL;
SDL_Surface *imgSurf3 = NULL;
SDL_Event e;
_Bool playProgram = 1;


// Инициализация SDL и открытие окна
_Bool initWindow(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{return 1;}
	gWindow = SDL_CreateWindow("SDL2 program 4",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	800, 600,
	SDL_WINDOW_SHOWN);

	if (gWindow)
	{
		gScreenSurface = SDL_GetWindowSurface(gWindow);
	}
	else {return 1;}

	printf("INIT_OK\n");
	return 0;
}

_Bool initImg1(void)
{
	imgSurf = SDL_LoadBMP("mn1.bmp");
	imgSurf2 = SDL_LoadBMP("mn2.bmp");
	imgSurf3 = SDL_LoadBMP("mn3.bmp");
	printf("INIT_FARME_OK\n");
	return 0;
}

void closesdl(void)
{
	SDL_DestroyWindow(gWindow);
	gWindow = 0;
	SDL_FreeSurface(imgSurf);
	imgSurf = 0;
	SDL_FreeSurface(imgSurf2);
	imgSurf2 = 0;
	SDL_FreeSurface(imgSurf3);
	imgSurf3 = 0;
	SDL_Quit();
}


int main(void)
{


	// Инициализация SDL
	if (initWindow())
	{
		printf("INIT_ERROR\n");
		return 1;
	}



	initImg1();

	while (playProgram)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				printf("EXIT\n");
				playProgram = 0;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
					case SDLK_1:
					SDL_BlitSurface(imgSurf, 0, gScreenSurface, 0);
					SDL_UpdateWindowSurface(gWindow);
					printf("1\n");
					break;

					case SDLK_2:
					SDL_BlitSurface(imgSurf2, 0, gScreenSurface, 0);
					SDL_UpdateWindowSurface(gWindow);
					printf("2\n");
					break;

					case SDLK_3:
					SDL_BlitSurface(imgSurf3, 0, gScreenSurface, 0);
					SDL_UpdateWindowSurface(gWindow);
					printf("3\n");
					break;

					case SDLK_q:
					playProgram = 0;
					break;

					case SDLK_ESCAPE:
					playProgram = 0;
					break;

					default:
					printf("KEY PRESSED\n");
				}
			}
		}
		SDL_Delay(1);
	}


	closesdl();
	return 0;
}
