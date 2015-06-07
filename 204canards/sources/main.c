/*
** main.c for 204canards in /home/han_d/rendu/204canards/sources
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Sun Apr 12 21:09:59 2015 Daniel Han
** Last update Sun Apr 12 21:12:52 2015 Daniel Han
*/

#include <stdio.h>
#include <stdlib.h>
#include "canard.h"

void		cleanStruct(t_canard *myCanard)
{
  free(myCanard);
  free(myCanard->x1);
  free(myCanard->x2);
  free(myCanard->y1);
  free(myCanard->y2);
}

void		initColor(t_canard *myCanard)
{
  myCanard->color[0][0] = 255;
  myCanard->color[0][1] = 0;
  myCanard->color[0][2] = 0;
  myCanard->color[0][3] = 150;
  myCanard->color[1][0] = 100;
  myCanard->color[1][1] = 100;
  myCanard->color[1][2] = 255;
  myCanard->color[1][3] = 200;
}

int		main(int ac, char **av, char **env)
{
  t_canard	myCanard;

  if ((ac != 2) || (atof(av[1]) < 0) || (atof(av[1]) > 2.5) || env[0] == NULL)
    {
      printf("Usage: ./204canards [NB]\n");
      printf("With [NB] > 0 AND [NB] <= 2.5\n");
      return (-1);
    }
  if (strspn(av[1], ".0123456789") != strlen(av[1]))
    return (-1);
  myCanard.number = atof(av[1]);
  initColor(&myCanard);
  initSDL(&myCanard);
  loopSDL(&myCanard);
  return (0);
}
