/*
** display_error.c for 206neutrinos in /home/han_d/rendu/206neutrinos
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Wed May  6 16:48:13 2015 Daniel Han
** Last update Wed May  6 17:06:56 2015 Daniel Han
*/

#include <stdio.h>
#include "neutrinos.h"

void	display_parser_error()
{
  fprintf(stderr, "%sFejl : du skal indtaste en hele antal%s\n",
	  YELLOW, BLACK);
}

void	display_av_error(int nb, char *arg)
{
  char	*error[4];

  error[0] = "Fejl : antal mãlinder er ugyldig";
  error[1] = "Fejl : aritmetisk gennemsnit er ugyldig";
  error[2] = "Fejl : harmonisk gennemsnit er ugyldig";
  error[3] = "Fejl : standardafvilgelse er ugyldig";
  fprintf(stderr, "%s%s : %s%s\n", RED, error[nb], arg, BLACK);
}

void	display_usage_error(char *exe)
{
  fprintf(stderr, "%sBrug : %s <antal mãlinder>\
 <aritmetisk gennemsnit> <harmonisk gennemsnit> <standardafvilgelse>%s\n",
	  YELLOW, exe, BLACK);
}
