/*
** main.c for 206neutrinos in /home/han_d/rendu/206neutrinos
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Mon May  4 03:50:21 2015 Daniel Han
** Last update Wed May  6 17:07:08 2015 Daniel Han
*/

#include <stdlib.h>
#include "neutrinos.h"

int		main(int ac, char **av)
{
  t_neutrinos	n;
  t_save	s;

  if (ac != 5)
    {
      display_usage_error(av[0]);
      return (-1);
    }
  else
    {
      if (init(&n, &s, av + 1) == -1)
	{
	  display_usage_error(av[0]);
	  return (-1);
	}
      parser(&n, &s);
      return (0);
    }
  return (0);
}
