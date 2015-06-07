/*
** main.c for 205QI in /home/han_d/rendu/205QI
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Mon Apr 13 15:32:08 2015 Daniel Han
** Last update Mon Apr 13 16:38:05 2015 Daniel Han
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qi.h"

void	bad_arg(int error)
{
  fprintf(stderr, "\033[0;31mError : %d mauvais argument(s)\033[0;m\n", error);
}

void	usage()
{
  fprintf(stderr, "\033[0;33mUsage : ./205QI [moyenne] [écart-type] ");
  fprintf(stderr, "[0 à 2 valeurs de QI]\033[0;m\n");
}

int	check_arg(int ac, char **av)
{
  int	i;
  int	error;

  if (ac <= 1 || ac >= 5)
    {
      usage();
      return (EXIT_FAILURE);
    }
  i = 0;
  error = 0;
  while (i < ac)
    {
      if (strspn(av[i], "0123456789.") != strlen(av[i]))
	++error;
      ++i;
    }
  if (error > 0)
    {
      bad_arg(error);
      usage();
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
  if (check_arg(ac - 1, av + 1) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  else
    {
      if (ac == 3)
	courbe_repartition_qi(atof(av[1]), atof(av[2]));
      else if (ac == 4)
	pourcentage_inferieur_qi(atof(av[1]), atof(av[2]), atof(av[3]));
      else if (ac == 5)
	pourcentage_intervalle_qi(atof(av[1]), atof(av[2]), atof(av[3]),
				  atof(av[4]));
    }
  return (EXIT_SUCCESS);
}
