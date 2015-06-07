/*
** initSDL.c for 204canards in /home/han_d/rendu/204canards/sources
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Sun Apr 12 20:59:15 2015 Daniel Han
** Last update Sun Apr 12 21:13:53 2015 Daniel Han
*/

#include <stdbool.h>
#include <stdlib.h>
#include "canard.h"
#include "SDL/SDL_gfxPrimitives.h"

void		freeSDL(t_canard *myCanard)
{
  SDL_FreeSurface(myCanard->_screen);
}

void		drawArrow(t_canard *myCanard)
{
  lineRGBA(myCanard->_screen, 100, 0, 100, 600, 200, 200, 200, 200);
  lineRGBA(myCanard->_screen, 0, 550, 1100, 550, 200, 200, 200, 200);
  lineRGBA(myCanard->_screen, 100, 0, 80, 20, 200, 200, 200, 200);
  lineRGBA(myCanard->_screen, 100, 0, 120, 20, 200, 200, 200, 200);
  lineRGBA(myCanard->_screen, 1100, 550, 1080, 570, 200, 200, 200, 200);
  lineRGBA(myCanard->_screen, 1100, 550, 1080, 530, 200, 200, 200, 200);
}

void		decorationWindow(t_canard *myCanard)
{
  drawArrow(myCanard);
  lineRGBA(myCanard->_screen,  820, 225, 870,    225, 255, 0, 0, 150);
  lineRGBA(myCanard->_screen,  820, 265, 870, 265, 100, 100, 250, 200);
  rectangleColor(myCanard->_screen, 800, 200, 1000,  300, WHITE);
  stringColor(myCanard->_screen, 880, 220, "densite",  WHITE);
  stringColor(myCanard->_screen, 880, 260, "repartition",  WHITE);
  stringColor(myCanard->_screen, 0, 200, "probabilite",  WHITE);
  stringColor(myCanard->_screen, 600, 570, "temps (minutes)", WHITE);
}

void		loopSDL(t_canard *myCanard)
{
  SDL_Event	event;
  int		ctn = 1;

  SDL_FillRect(myCanard->_screen, NULL, SDL_MapRGB(myCanard->_screen->format,
						   0, 0, 0));
  myDisplay(myCanard);
  while (42)
    {
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
	break;
      SDL_Flip(myCanard->_screen);
    }
  freeSDL(myCanard);
}

int		initSDL(t_canard *myCanard)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (-1);
  if (TTF_Init() == -1)
    return (-1);
  if (!(myCanard->_screen = SDL_SetVideoMode(1100, 600, 32, SDL_HWSURFACE |
					     SDL_RESIZABLE | SDL_DOUBLEBUF)))
    return (-1);
  SDL_WM_SetCaption("204canards", NULL);
  SDL_FillRect(myCanard->_screen, NULL, SDL_MapRGB(myCanard->_screen->format, 0, 0, 0));
  SDL_EnableUNICODE(1);
  return (0);
}
