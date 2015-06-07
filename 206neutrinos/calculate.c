/*
** calculate.c for 206neutrinos in /home/han_d/rendu/206neutrinos
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Wed May  6 18:29:55 2015 Daniel Han
** Last update Wed May  6 19:11:04 2015 Daniel Han
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "neutrinos.h"

void		calculate(t_neutrinos *n, t_save *s, double nb)
{
  double somme;

  somme = 0;

  s->cste = (pow(n->et, 2) + pow(n->moy_a, 2)) * n->popu;
  s->save_a += nb;
  s->save_h += (1.f / nb);
  ++n->popu;
  n->moy_a = (double)s->save_a / n->popu;
  n->moy_h = n->popu / s->save_h;
  n->et = sqrt((((double)s->cste + pow(nb, 2)) / n->popu) - pow(n->moy_a, 2));
  n->moy_q = sqrt(((double)s->cste + pow(nb, 2)) / n->popu);

}

void		init_save(t_neutrinos *n, t_save *s)
{
  unsigned int	i;

  i = 0;
  s->save_a = 0;
  s->save_h = 0;
  while (i < n->popu)
    {
      s->save_a += n->moy_a;
      s->save_h += (1 / n->moy_h);
      ++i;
    }
}

int	        init_neutrinos(char **av)
{
  int		i;
  int		error;

  i = 0;
  error = 0;
  while (i < 4)
    {
      if (is_integer(av[i]) == -1)
	{
	  display_av_error(i, av[i]);
	  ++error;
	}
      ++i;
    }
  if (error > 0)
    return (-1);
  return (0);
}

int		init(t_neutrinos *n, t_save *s, char **av)
{
  if (init_neutrinos(av) == -1)
    return (-1);
  n->popu = atoi(av[0]);
  n->moy_a = atof(av[1]);
  n->moy_h = atof(av[2]);
  n->et = atof(av[3]);
  init_save(n, s);
  return (0);
}
