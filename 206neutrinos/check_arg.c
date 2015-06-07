/*
** check_arg.c for 206neutrinos in /home/han_d/rendu/206neutrinos
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Mon May  4 03:50:30 2015 Daniel Han
** Last update Wed May  6 17:06:08 2015 Daniel Han
*/

#include <stdlib.h>
#include "neutrinos.h"

int		is_integer(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
      return (-1);
  if (str[0] == '\0')
      return (-1);
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      ++i;
    }
  return (0);
}
