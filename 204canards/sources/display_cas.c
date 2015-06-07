/*
** display_cas.c for 204canards in /home/han_d/rendu/204canards/sources
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Sun Apr 12 21:10:24 2015 Daniel Han
** Last update Sun Apr 12 21:10:24 2015 Daniel Han
*/

#include <stdbool.h>
#include <stdlib.h>
#include "canard.h"
#include "SDL/SDL_gfxPrimitives.h"

void		cas1(t_canard *myCanard)
{
  static int	time = 0;

  if (time == 0)
    printf("pourcentage de canards revenus apres 1 minutes\t\t: %d%%\n",
	   (int)(myCanard->res + myCanard->result));
  time++;
}

void		cas2(t_canard *myCanard)
{
  static int	time = 0;

  if (time == 0)
    printf("pourcentage de canards revenus apres 2 minutes\t\t: %d%%\n",
	   (int)(myCanard->res + myCanard->result));
  time++;
}

void		cas3(t_canard *myCanard)
{
  static int	time = 0;

  if (time == 0)
    printf("temps au bout duquel 50%% des canards sont revenus\t: %d minute(s) et %d secondes\n",
	   (int)myCanard->loop, (int)(60 * myCanard->loop) % 60);
  time++;
}

void		cas4(t_canard *myCanard)
{
  static int	time = 0;

  if (time == 0)
    printf("temps au bout duquel 99%% des canards sont revenus\t: %d minute(s) et %d secondes\n",
	   (int)myCanard->loop, (int)(60 * myCanard->loop) % 60);
  time++;
}
