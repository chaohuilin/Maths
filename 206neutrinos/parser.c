/*
** parser.c for 206neutrinos in /home/han_d/rendu/206neutrinos
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Mon May  4 03:50:16 2015 Daniel Han
** Last update Wed May  6 19:07:29 2015 Daniel Han
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "neutrinos.h"

int     get_cmd(char *buffer)
{
  if (strcmp(buffer, "ende") == 0)
    {
      display_goodbye();
      return (1);
    }
  else
    display_parser_error();
  return (0);
}

void	parser(t_neutrinos *n, t_save *s)
{
  int	ret;
  char	buffer[4096];

  memset(buffer, '\0', 4096);
  display_prompt();
  while ((ret = read(0, buffer, 4095)) > 0)
    {
      if (buffer[ret - 1] == '\n')
	     buffer[ret - 1] = '\0';
      if (is_integer(buffer) == 0)
	{
	  calculate(n, s, atof(buffer));
	  display_result(n);
	}
      else if (get_cmd(buffer) == 1)
	return;
      memset(buffer, '\0', 4096);
      display_prompt();
    }
}
