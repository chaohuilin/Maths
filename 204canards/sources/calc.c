/*
** calc.c for 204canards in /home/han_d/rendu/204canards/sources
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Sun Apr 12 21:10:12 2015 Daniel Han
** Last update Sun Apr 12 21:14:40 2015 Daniel Han
*/

#include <stdbool.h>
#include <stdlib.h>
#include "canard.h"
#include "SDL/SDL_gfxPrimitives.h"

void		Display_graph(t_canard *myCanard, float x[], float y[])
{
  static int	time = 0;
  int		count = 1;
  int		last_x = x[0];
  int		last_y = y[0];
  int		inGame = 1;

  if (time > 1)
    return;
  while (inGame == 1)
    {
      if ((x[count] == 0) && (y[count] == 0))
	inGame = 0;
      else
      	{
	  lineRGBA(myCanard->_screen, last_x, last_y, x[count], y[count],
		   myCanard->color[time][0], myCanard->color[time][1],
		   myCanard->color[time][2], myCanard->color[time][3]);
	  last_x = x[count];
	  last_y = y[count];
	}
      count++;
    }
  time++;
}

float		f(float a, float t)
{
  float		res;
  res = (a * exp(-t));
  res += ((4 - (3 * a)) * exp(-2 * t));
  res += (((2 * a) - 4) * exp(-4 * t));
  return (res);
}

void		display_res(t_canard *myCanard)
{
  if ((int)myCanard->loop == 1)
    cas1(myCanard);
  if ((int)myCanard->loop == 2)
    cas2(myCanard);
}

void		display_res2(t_canard *myCanard)
{
  if ((int)myCanard->res + myCanard->result >= 50)
    cas3(myCanard);
  if ((int)myCanard->res + myCanard->result >= 99)
    cas4(myCanard);
}

void		myDisplay(t_canard *myCanard)
{
  int		pos = 0;
  char		dest[2];

  decorationWindow(myCanard);
  for (myCanard->loop = 0, myCanard->res = 0, myCanard->result = 0;
       myCanard->loop <= 10;
       myCanard->result += myCanard->res, myCanard->loop += 0.01, pos++)
    {
      myCanard->res = f(myCanard->number, myCanard->loop);
      myCanard->x1[pos] = myCanard->loop * 100 + 100;
      myCanard->x2[pos] = myCanard->loop * 100 + 100;
      myCanard->y1[pos] = 500 - (myCanard->res * 500);
      myCanard->y2[pos] = 500 - ((myCanard->result + myCanard->res) * 5);
      display_res(myCanard);
      display_res2(myCanard);
    }
  Display_graph(myCanard, myCanard->x1, myCanard->y1);
  Display_graph(myCanard, myCanard->x2, myCanard->y2);
}
